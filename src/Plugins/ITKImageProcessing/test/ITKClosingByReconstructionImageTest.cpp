#include <catch2/catch.hpp>

#include "ITKImageProcessing/Common/sitkCommon.hpp"
#include "ITKImageProcessing/Filters/ITKClosingByReconstructionImage.hpp"
#include "ITKImageProcessing/ITKImageProcessing_test_dirs.hpp"
#include "ITKTestBase.hpp"

#include "complex/Parameters/BoolParameter.hpp"
#include "complex/Parameters/ChoicesParameter.hpp"
#include "complex/Parameters/DataObjectNameParameter.hpp"
#include "complex/Parameters/VectorParameter.hpp"
#include "complex/UnitTest/UnitTestCommon.hpp"

#include <filesystem>

namespace fs = std::filesystem;

using namespace complex;

TEST_CASE("ITKImageProcessing::ITKClosingByReconstructionImageFilter(ClosingByReconstruction)", "[ITKImageProcessing][ITKClosingByReconstructionImage][ClosingByReconstruction]")
{
  DataStructure dataStructure;
  ITKClosingByReconstructionImage filter;

  const DataPath inputGeometryPath({ITKTestBase::k_ImageGeometryPath});
  const DataPath cellDataPath = inputGeometryPath.createChildPath(ITKTestBase::k_ImageCellDataPath);
  const DataPath inputDataPath = cellDataPath.createChildPath(ITKTestBase::k_InputDataPath);
  const DataObjectNameParameter::ValueType outputArrayName = ITKTestBase::k_OutputDataPath;

  { // Start Image Comparison Scope
    const fs::path inputFilePath = fs::path(unit_test::k_SourceDir.view()) / unit_test::k_DataDir.view() / "JSONFilters" / "Input/STAPLE1.png";
    Result<> imageReadResult = ITKTestBase::ReadImage(dataStructure, inputFilePath, inputGeometryPath, cellDataPath, inputDataPath);
    COMPLEX_RESULT_REQUIRE_VALID(imageReadResult)
  } // End Image Comparison Scope

  Arguments args;
  args.insertOrAssign(ITKClosingByReconstructionImage::k_SelectedImageGeomPath_Key, std::make_any<DataPath>(inputGeometryPath));
  args.insertOrAssign(ITKClosingByReconstructionImage::k_SelectedImageDataPath_Key, std::make_any<DataPath>(inputDataPath));
  args.insertOrAssign(ITKClosingByReconstructionImage::k_OutputImageDataPath_Key, std::make_any<DataObjectNameParameter::ValueType>(outputArrayName));
  args.insertOrAssign(ITKClosingByReconstructionImage::k_KernelRadius_Key, std::make_any<VectorParameter<uint32>::ValueType>(std::vector<uint32>{1, 1, 1}));
  args.insertOrAssign(ITKClosingByReconstructionImage::k_KernelType_Key, std::make_any<ChoicesParameter::ValueType>(itk::simple::sitkBall));

  auto preflightResult = filter.preflight(dataStructure, args);
  COMPLEX_RESULT_REQUIRE_VALID(preflightResult.outputActions)

  auto executeResult = filter.execute(dataStructure, args);
  COMPLEX_RESULT_REQUIRE_VALID(executeResult.result)

  const std::string md5Hash = ITKTestBase::ComputeMd5Hash(dataStructure, cellDataPath.createChildPath(outputArrayName));
  REQUIRE(md5Hash == "095f00a68a84df4396914fa758f34dcc");
}
