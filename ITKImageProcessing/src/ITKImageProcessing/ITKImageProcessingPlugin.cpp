#include "ITKImageProcessingPlugin.hpp"

#include <itkBMPImageIOFactory.h>
#include <itkBioRadImageIOFactory.h>
#include <itkGE4ImageIOFactory.h>
#include <itkGE5ImageIOFactory.h>
#include <itkGiplImageIOFactory.h>
#include <itkJPEGImageIOFactory.h>
#include <itkMRCImageIOFactory.h>
#include <itkMetaImageIOFactory.h>
#include <itkNiftiImageIOFactory.h>
#include <itkNrrdImageIOFactory.h>
#include <itkPNGImageIOFactory.h>
#include <itkStimulateImageIOFactory.h>
#include <itkTIFFImageIOFactory.h>
#include <itkVTKImageIOFactory.h>

using namespace complex;

namespace
{
// Plugin Uuid
constexpr AbstractPlugin::IdType k_ID = *Uuid::FromString("115b0d10-ab97-5a18-88e8-80d35056a28e");
} // namespace

ITKImageProcessingPlugin::ITKImageProcessingPlugin()
: AbstractPlugin(k_ID, "ITKImageProcessing", "<<--Description was not read-->>", "BlueQuartz Software")
{
  registerFilters();
  RegisterITKImageIO();
}

ITKImageProcessingPlugin::~ITKImageProcessingPlugin() noexcept = default;

void ITKImageProcessingPlugin::RegisterITKImageIO()
{
  itk::JPEGImageIOFactory::RegisterOneFactory();
  itk::NrrdImageIOFactory::RegisterOneFactory();
  itk::PNGImageIOFactory::RegisterOneFactory();
  itk::TIFFImageIOFactory::RegisterOneFactory();
  itk::JPEGImageIOFactory::RegisterOneFactory();
  itk::BMPImageIOFactory::RegisterOneFactory();
  itk::MetaImageIOFactory::RegisterOneFactory();
  itk::NiftiImageIOFactory::RegisterOneFactory();
  itk::GiplImageIOFactory::RegisterOneFactory();
  itk::VTKImageIOFactory::RegisterOneFactory();
  itk::StimulateImageIOFactory::RegisterOneFactory();
  itk::BioRadImageIOFactory::RegisterOneFactory();
  itk::GE4ImageIOFactory::RegisterOneFactory();
  itk::GE5ImageIOFactory::RegisterOneFactory();
  itk::MRCImageIOFactory::RegisterOneFactory();
}

std::vector<complex::H5::IDataFactory*> ITKImageProcessingPlugin::getDataFactories() const
{
  return {};
}

std::vector<std::string> ITKImageProcessingPlugin::GetList2DSupportedFileExtensions()
{
  return {".png", ".tif", ".jpg", ".jpeg", ".bmp"};
}

COMPLEX_DEF_PLUGIN(ITKImageProcessingPlugin)

// The below file is generated at CMake configure time. This is done because
// the cmake system knows what filters are being compiled. This saves the
// developer from having to upkeep these lists.
#include "ITKImageProcessing/plugin_filter_registration.h"
