#include <catch2/catch.hpp>

#include "complex/Parameters/ArraySelectionParameter.hpp"
#include "complex/Parameters/BoolParameter.hpp"
#include "complex/Parameters/FileSystemPathParameter.hpp"
#include "complex/Parameters/StringParameter.hpp"
#include "complex/UnitTest/UnitTestCommon.hpp"

#include "ComplexCore/ComplexCore_test_dirs.hpp"
#include "ComplexCore/Filters/WriteAvizoRectilinearCoordinateFilter.hpp"

#include <filesystem>
namespace fs = std::filesystem;

using namespace complex;
using namespace complex::Constants;

TEST_CASE("ComplexCore::WriteAvizoRectilinearCoordinateFilter: Valid Filter Execution", "[ComplexCore][WriteAvizoRectilinearCoordinateFilter][.][UNIMPLEMENTED][!mayfail]")
{
  const std::string kDataInputArchive = "6_6_avizo_writers.tar.gz";
  const std::string kExpectedOutputTopLevel = "6_6_avizo_writers";
  const complex::UnitTest::TestFileSentinel testDataSentinel1(complex::unit_test::k_CMakeExecutable, complex::unit_test::k_TestFilesDir, kDataInputArchive, kExpectedOutputTopLevel);

  // Read Exemplar DREAM3D File Filter
  auto exemplarFilePath = fs::path(fmt::format("{}/6_6_avizo_writers/6_6_avizo_writers_input.dream3d", unit_test::k_TestFilesDir));
  DataStructure dataStructure = UnitTest::LoadDataStructure(exemplarFilePath);

  // Instantiate the filter, a DataStructure object and an Arguments Object
  WriteAvizoRectilinearCoordinateFilter filter;
  DataStructure ds;
  Arguments args;

  fs::path exemplarOutputPath = fs::path(fmt::format("{}/6_6_avizo_writers/6_6_avizo_rectilinear_coordinate_writer.am", unit_test::k_TestFilesDir));
  fs::path computedOutputPath(fmt::format("{}/NX_AvisoRectilinearOutput.am", unit_test::k_BinaryTestOutputDir));
  fs::path exemplarBinaryOutputPath = fs::path(fmt::format("{}/6_6_avizo_writers/6_6_avizo_rectilinear_coordinate_writer_binary.am", unit_test::k_TestFilesDir));
  fs::path computedBinaryOutputPath(fmt::format("{}/NX_AvisoRectilinearOutput_binary.am", unit_test::k_BinaryTestOutputDir));

  // Create default Parameters for the filter.
  args.insertOrAssign(WriteAvizoRectilinearCoordinateFilter::k_OutputFile_Key, std::make_any<FileSystemPathParameter::ValueType>(computedOutputPath));
  args.insertOrAssign(WriteAvizoRectilinearCoordinateFilter::k_WriteBinaryFile_Key, std::make_any<bool>(false));
  args.insertOrAssign(WriteAvizoRectilinearCoordinateFilter::k_GeometryPath_Key, std::make_any<DataPath>(DataPath({k_SmallIN100})));
  args.insertOrAssign(WriteAvizoRectilinearCoordinateFilter::k_FeatureIdsArrayPath_Key, std::make_any<DataPath>(DataPath({k_SmallIN100, k_EbsdScanData, k_FeatureIds})));
  args.insertOrAssign(WriteAvizoRectilinearCoordinateFilter::k_Units_Key, std::make_any<StringParameter::ValueType>("microns"));

  // Preflight the filter and check result
  auto preflightResult = filter.preflight(dataStructure, args);
  COMPLEX_RESULT_REQUIRE_VALID(preflightResult.outputActions)

  // Execute the filter and check the result
  auto executeResult = filter.execute(dataStructure, args);
  COMPLEX_RESULT_REQUIRE_VALID(executeResult.result)

  args.insertOrAssign(WriteAvizoRectilinearCoordinateFilter::k_OutputFile_Key, std::make_any<FileSystemPathParameter::ValueType>(computedBinaryOutputPath));
  args.insertOrAssign(WriteAvizoRectilinearCoordinateFilter::k_WriteBinaryFile_Key, std::make_any<bool>(true));

  preflightResult = filter.preflight(dataStructure, args);
  COMPLEX_RESULT_REQUIRE_VALID(preflightResult.outputActions)

  executeResult = filter.execute(dataStructure, args);
  COMPLEX_RESULT_REQUIRE_VALID(executeResult.result)

  std::vector<size_t> linesToSkip{8, 9}; // skip the author & DateTime lines
  std::ifstream computedFile(computedOutputPath);
  std::ifstream exemplarFile(exemplarOutputPath);
  UnitTest::CompareAsciiFiles(computedFile, exemplarFile, linesToSkip);
  std::ifstream computedBinaryFile(computedBinaryOutputPath, std::ios::binary);
  std::ifstream exemplarBinaryFile(exemplarBinaryOutputPath, std::ios::binary);
  UnitTest::CompareAsciiFiles(computedBinaryFile, exemplarBinaryFile, linesToSkip);
}
