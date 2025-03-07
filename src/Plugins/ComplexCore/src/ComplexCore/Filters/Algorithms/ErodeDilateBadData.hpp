#pragma once

#include "ComplexCore/ComplexCore_export.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/DataStructure/DataStructure.hpp"
#include "complex/Filter/IFilter.hpp"
#include "complex/Parameters/ChoicesParameter.hpp"
#include "complex/Parameters/MultiArraySelectionParameter.hpp"

namespace
{
const std::string k_DilateString("Dilate");
const std::string k_ErodeString("Erode");
const complex::ChoicesParameter::Choices k_OperationChoices = {
    k_DilateString,
    k_ErodeString,
};

const complex::ChoicesParameter::ValueType k_DilateIndex = 0ULL;
const complex::ChoicesParameter::ValueType k_ErodeIndex = 1ULL;

} // namespace

namespace complex
{

struct COMPLEXCORE_EXPORT ErodeDilateBadDataInputValues
{
  ChoicesParameter::ValueType Operation;
  int32 NumIterations;
  bool XDirOn;
  bool YDirOn;
  bool ZDirOn;
  DataPath FeatureIdsArrayPath;
  MultiArraySelectionParameter::ValueType IgnoredDataArrayPaths;
  DataPath InputImageGeometry;
};

/**
 * @class ConditionalSetValue
 * @brief This filter replaces values in the target array with a user specified value
 * where a bool mask array specifies.
 */
class COMPLEXCORE_EXPORT ErodeDilateBadData
{
public:
  ErodeDilateBadData(DataStructure& dataStructure, const IFilter::MessageHandler& mesgHandler, const std::atomic_bool& shouldCancel, ErodeDilateBadDataInputValues* inputValues);
  ~ErodeDilateBadData() noexcept;

  ErodeDilateBadData(const ErodeDilateBadData&) = delete;
  ErodeDilateBadData(ErodeDilateBadData&&) noexcept = delete;
  ErodeDilateBadData& operator=(const ErodeDilateBadData&) = delete;
  ErodeDilateBadData& operator=(ErodeDilateBadData&&) noexcept = delete;

  Result<> operator()();

  const std::atomic_bool& getCancel();
  void updateProgress(const std::string& progMessage);

private:
  DataStructure& m_DataStructure;
  const ErodeDilateBadDataInputValues* m_InputValues = nullptr;
  const std::atomic_bool& m_ShouldCancel;
  const IFilter::MessageHandler& m_MessageHandler;
};

} // namespace complex
