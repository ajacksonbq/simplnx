#include "ImportPrintRiteHDF5File.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Filter/Actions/EmptyAction.hpp"
#include "complex/Parameters/FileSystemPathParameter.hpp"
#include "complex/Parameters/StringParameter.hpp"

#include <filesystem>
namespace fs = std::filesystem;

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string ImportPrintRiteHDF5File::name() const
{
  return FilterTraits<ImportPrintRiteHDF5File>::name.str();
}

//------------------------------------------------------------------------------
std::string ImportPrintRiteHDF5File::className() const
{
  return FilterTraits<ImportPrintRiteHDF5File>::className;
}

//------------------------------------------------------------------------------
Uuid ImportPrintRiteHDF5File::uuid() const
{
  return FilterTraits<ImportPrintRiteHDF5File>::uuid;
}

//------------------------------------------------------------------------------
std::string ImportPrintRiteHDF5File::humanName() const
{
  return "Import PrintRite HDF5 File";
}

//------------------------------------------------------------------------------
std::vector<std::string> ImportPrintRiteHDF5File::defaultTags() const
{
  return {"#IO", "#Input", "#Read", "#Import"};
}

//------------------------------------------------------------------------------
Parameters ImportPrintRiteHDF5File::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insert(std::make_unique<FileSystemPathParameter>(k_InputFile_Key, "Input TDMS-HDF5 File", "", fs::path("<default file to read goes here>"), FileSystemPathParameter::PathType::InputFile));
  params.insert(std::make_unique<StringParameter>(k_HFDataContainerName_Key, "High Frequency Data Container", "", "SomeString"));
  params.insertSeparator(Parameters::Separator{"Vertex Data"});
  params.insert(std::make_unique<StringParameter>(k_HFDataName_Key, "High Frequency Vertex Attribute Matrix", "", "SomeString"));
  params.insert(std::make_unique<StringParameter>(k_HFSliceIdsArrayName_Key, "High Frequency Slice Ids", "", "SomeString"));
  params.insertSeparator(Parameters::Separator{"Vertex Feature Data"});
  params.insert(std::make_unique<StringParameter>(k_HFSliceDataName_Key, "High Frequency Slice Attribute Matrix", "", "SomeString"));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer ImportPrintRiteHDF5File::clone() const
{
  return std::make_unique<ImportPrintRiteHDF5File>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult ImportPrintRiteHDF5File::preflightImpl(const DataStructure& dataStructure, const Arguments& filterArgs, const MessageHandler& messageHandler,
                                                                const std::atomic_bool& shouldCancel) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pInputFileValue = filterArgs.value<FileSystemPathParameter::ValueType>(k_InputFile_Key);
  auto pHFDataContainerNameValue = filterArgs.value<StringParameter::ValueType>(k_HFDataContainerName_Key);
  auto pHFDataNameValue = filterArgs.value<StringParameter::ValueType>(k_HFDataName_Key);
  auto pHFSliceIdsArrayNameValue = filterArgs.value<StringParameter::ValueType>(k_HFSliceIdsArrayName_Key);
  auto pHFSliceDataNameValue = filterArgs.value<StringParameter::ValueType>(k_HFSliceDataName_Key);

  // Declare the preflightResult variable that will be populated with the results
  // of the preflight. The PreflightResult type contains the output Actions and
  // any preflight updated values that you want to be displayed to the user, typically
  // through a user interface (UI).
  PreflightResult preflightResult;

  // If your filter is making structural changes to the DataStructure then the filter
  // is going to create OutputActions subclasses that need to be returned. This will
  // store those actions.
  complex::Result<OutputActions> resultOutputActions;

  // If your filter is going to pass back some `preflight updated values` then this is where you
  // would create the code to store those values in the appropriate object. Note that we
  // in line creating the pair (NOT a std::pair<>) of Key:Value that will get stored in
  // the std::vector<PreflightValue> object.
  std::vector<PreflightValue> preflightUpdatedValues;

  // If the filter needs to pass back some updated values via a key:value string:string set of values
  // you can declare and update that string here.
  // None found in this filter based on the filter parameters

  // If this filter makes changes to the DataStructure in the form of
  // creating/deleting/moving/renaming DataGroups, Geometries, DataArrays then you
  // will need to use one of the `*Actions` classes located in complex/Filter/Actions
  // to relay that information to the preflight and execute methods. This is done by
  // creating an instance of the Action class and then storing it in the resultOutputActions variable.
  // This is done through a `push_back()` method combined with a `std::move()`. For the
  // newly initiated to `std::move` once that code is executed what was once inside the Action class
  // instance variable is *no longer there*. The memory has been moved. If you try to access that
  // variable after this line you will probably get a crash or have subtle bugs. To ensure that this
  // does not happen we suggest using braces `{}` to scope each of the action's declaration and store
  // so that the programmer is not tempted to use the action instance past where it should be used.
  // You have to create your own Actions class if there isn't something specific for your filter's needs

  // Store the preflight updated value(s) into the preflightUpdatedValues vector using
  // the appropriate methods.
  // None found based on the filter parameters

  // Return both the resultOutputActions and the preflightUpdatedValues via std::move()
  return {std::move(resultOutputActions), std::move(preflightUpdatedValues)};
}

//------------------------------------------------------------------------------
Result<> ImportPrintRiteHDF5File::executeImpl(DataStructure& dataStructure, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler,
                                              const std::atomic_bool& shouldCancel) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pInputFileValue = filterArgs.value<FileSystemPathParameter::ValueType>(k_InputFile_Key);
  auto pHFDataContainerNameValue = filterArgs.value<StringParameter::ValueType>(k_HFDataContainerName_Key);
  auto pHFDataNameValue = filterArgs.value<StringParameter::ValueType>(k_HFDataName_Key);
  auto pHFSliceIdsArrayNameValue = filterArgs.value<StringParameter::ValueType>(k_HFSliceIdsArrayName_Key);
  auto pHFSliceDataNameValue = filterArgs.value<StringParameter::ValueType>(k_HFSliceDataName_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
