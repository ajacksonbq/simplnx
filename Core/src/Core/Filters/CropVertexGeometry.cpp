#include "CropVertexGeometry.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Filter/Actions/CreateDataGroupAction.hpp"
#include "complex/Filter/Actions/EmptyAction.hpp"
#include "complex/Parameters/DataGroupCreationParameter.hpp"
#include "complex/Parameters/DataGroupSelectionParameter.hpp"
#include "complex/Parameters/NumberParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string CropVertexGeometry::name() const
{
  return FilterTraits<CropVertexGeometry>::name.str();
}

//------------------------------------------------------------------------------
std::string CropVertexGeometry::className() const
{
  return FilterTraits<CropVertexGeometry>::className;
}

//------------------------------------------------------------------------------
Uuid CropVertexGeometry::uuid() const
{
  return FilterTraits<CropVertexGeometry>::uuid;
}

//------------------------------------------------------------------------------
std::string CropVertexGeometry::humanName() const
{
  return "Crop Geometry (Vertex)";
}

//------------------------------------------------------------------------------
std::vector<std::string> CropVertexGeometry::defaultTags() const
{
  return {"#Core", "#Croping Cutting"};
}

//------------------------------------------------------------------------------
Parameters CropVertexGeometry::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insert(std::make_unique<DataGroupSelectionParameter>(k_DataContainerName_Key, "Vertex Geometry to Crop", "", DataPath{}));
  params.insert(std::make_unique<Float32Parameter>(k_XMin_Key, "X Min", "", 1.23345f));
  params.insert(std::make_unique<Float32Parameter>(k_YMin_Key, "Y Min", "", 1.23345f));
  params.insert(std::make_unique<Float32Parameter>(k_ZMin_Key, "Z Min", "", 1.23345f));
  params.insert(std::make_unique<Float32Parameter>(k_XMax_Key, "X Max", "", 1.23345f));
  params.insert(std::make_unique<Float32Parameter>(k_YMax_Key, "Y Max", "", 1.23345f));
  params.insert(std::make_unique<Float32Parameter>(k_ZMax_Key, "Z Max", "", 1.23345f));
  params.insert(std::make_unique<DataGroupCreationParameter>(k_CroppedDataContainerName_Key, "Cropped Data Container", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer CropVertexGeometry::clone() const
{
  return std::make_unique<CropVertexGeometry>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult CropVertexGeometry::preflightImpl(const DataStructure& dataStructure, const Arguments& filterArgs, const MessageHandler& messageHandler,
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
  auto pDataContainerNameValue = filterArgs.value<DataPath>(k_DataContainerName_Key);
  auto pXMinValue = filterArgs.value<float32>(k_XMin_Key);
  auto pYMinValue = filterArgs.value<float32>(k_YMin_Key);
  auto pZMinValue = filterArgs.value<float32>(k_ZMin_Key);
  auto pXMaxValue = filterArgs.value<float32>(k_XMax_Key);
  auto pYMaxValue = filterArgs.value<float32>(k_YMax_Key);
  auto pZMaxValue = filterArgs.value<float32>(k_ZMax_Key);
  auto pCroppedDataContainerNameValue = filterArgs.value<DataPath>(k_CroppedDataContainerName_Key);

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
  // These are some proposed Actions based on the FilterParameters used. Please check them for correctness.
  {
    auto createDataGroupAction = std::make_unique<CreateDataGroupAction>(pCroppedDataContainerNameValue);
    resultOutputActions.value().actions.push_back(std::move(createDataGroupAction));
  }

  // Store the preflight updated value(s) into the preflightUpdatedValues vector using
  // the appropriate methods.
  // None found based on the filter parameters

  // Return both the resultOutputActions and the preflightUpdatedValues via std::move()
  return {std::move(resultOutputActions), std::move(preflightUpdatedValues)};
}

//------------------------------------------------------------------------------
Result<> CropVertexGeometry::executeImpl(DataStructure& dataStructure, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler,
                                         const std::atomic_bool& shouldCancel) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pDataContainerNameValue = filterArgs.value<DataPath>(k_DataContainerName_Key);
  auto pXMinValue = filterArgs.value<float32>(k_XMin_Key);
  auto pYMinValue = filterArgs.value<float32>(k_YMin_Key);
  auto pZMinValue = filterArgs.value<float32>(k_ZMin_Key);
  auto pXMaxValue = filterArgs.value<float32>(k_XMax_Key);
  auto pYMaxValue = filterArgs.value<float32>(k_YMax_Key);
  auto pZMaxValue = filterArgs.value<float32>(k_ZMax_Key);
  auto pCroppedDataContainerNameValue = filterArgs.value<DataPath>(k_CroppedDataContainerName_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
