#pragma once

#include "ComplexCore/ComplexCore_export.hpp"

#include "complex/DataStructure/DataArray.hpp"
#include "complex/DataStructure/DataPath.hpp"
#include "complex/DataStructure/DataStructure.hpp"
#include "complex/DataStructure/NeighborList.hpp"
#include "complex/Filter/IFilter.hpp"

#include <mutex>

namespace complex
{

struct COMPLEXCORE_EXPORT FindNeighborhoodsInputValues
{
  float32 MultiplesOfAverage;
  DataPath EquivalentDiametersArrayPath;
  DataPath FeaturePhasesArrayPath;
  DataPath CentroidsArrayPath;
  DataPath NeighborhoodsArrayName;
  DataPath NeighborhoodListArrayName;
  DataPath InputImageGeometry;
};

/**
 * @class ConditionalSetValue
 * @brief This filter replaces values in the target array with a user specified value
 * where a bool mask array specifies.
 */

class COMPLEXCORE_EXPORT FindNeighborhoods
{
public:
  FindNeighborhoods(DataStructure& dataStructure, const IFilter::MessageHandler& mesgHandler, const std::atomic_bool& shouldCancel, FindNeighborhoodsInputValues* inputValues);
  ~FindNeighborhoods() noexcept;

  FindNeighborhoods(const FindNeighborhoods&) = delete;
  FindNeighborhoods(FindNeighborhoods&&) noexcept = delete;
  FindNeighborhoods& operator=(const FindNeighborhoods&) = delete;
  FindNeighborhoods& operator=(FindNeighborhoods&&) noexcept = delete;

  Result<> operator()();

  const std::atomic_bool& getCancel();

  void updateNeighborHood(usize sourceIndex, usize targetIndex);
  void updateProgress(float64 counter, const std::chrono::steady_clock::time_point& now = std::chrono::steady_clock::now());

private:
  DataStructure& m_DataStructure;
  const FindNeighborhoodsInputValues* m_InputValues = nullptr;
  const std::atomic_bool& m_ShouldCancel;
  const IFilter::MessageHandler& m_MessageHandler;

  std::mutex m_Mutex;
  std::chrono::steady_clock::time_point m_InitialTime = std::chrono::steady_clock::now();
  float64 m_TotalFeatures = 0;
  float64 m_ProgressCounter = 0;

  Int32Array* m_Neighborhoods = nullptr;
  std::vector<std::vector<int32_t>> m_LocalNeighborhoodList;
};

} // namespace complex
