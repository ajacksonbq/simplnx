#pragma once

#include "ComplexCore/ComplexCore_export.hpp"

#include "complex/Filter/FilterTraits.hpp"
#include "complex/Filter/IFilter.hpp"

namespace complex
{
/**
 * @class ComputeFeatureRectFilter
 * @brief This filter computes the XYZ minimum and maximum coordinates for each Feature in a segmentation.
 * This data can be important for finding the smallest encompassing volume. The values are given in pixel
 * coordinates.
 */
class COMPLEXCORE_EXPORT ComputeFeatureRectFilter : public IFilter
{
public:
  ComputeFeatureRectFilter() = default;
  ~ComputeFeatureRectFilter() noexcept override = default;

  ComputeFeatureRectFilter(const ComputeFeatureRectFilter&) = delete;
  ComputeFeatureRectFilter(ComputeFeatureRectFilter&&) noexcept = delete;

  ComputeFeatureRectFilter& operator=(const ComputeFeatureRectFilter&) = delete;
  ComputeFeatureRectFilter& operator=(ComputeFeatureRectFilter&&) noexcept = delete;

  // Parameter Keys
  static inline constexpr StringLiteral k_FeatureIdsArrayPath_Key = "feature_ids_array_path";
  static inline constexpr StringLiteral k_FeatureRectArrayPath_Key = "feature_rect_array_path";
  static inline constexpr StringLiteral k_FeatureDataAttributeMatrixPath_Key = "feature_data_attribute_matrix_path";

  /**
   * @brief Returns the name of the filter.
   * @return
   */
  std::string name() const override;

  /**
   * @brief Returns the C++ classname of this filter.
   * @return
   */
  std::string className() const override;

  /**
   * @brief Returns the uuid of the filter.
   * @return
   */
  Uuid uuid() const override;

  /**
   * @brief Returns the human readable name of the filter.
   * @return
   */
  std::string humanName() const override;

  /**
   * @brief Returns the default tags for this filter.
   * @return
   */
  std::vector<std::string> defaultTags() const override;

  /**
   * @brief Returns the parameters of the filter (i.e. its inputs)
   * @return
   */
  Parameters parameters() const override;

  /**
   * @brief Returns a copy of the filter.
   * @return
   */
  UniquePointer clone() const override;

protected:
  /**
   * @brief Takes in a DataStructure and checks that the filter can be run on it with the given arguments.
   * Returns any warnings/errors. Also returns the changes that would be applied to the DataStructure.
   * Some parts of the actions may not be completely filled out if all the required information is not available at preflight time.
   * @param ds The input DataStructure instance
   * @param filterArgs These are the input values for each parameter that is required for the filter
   * @param messageHandler The MessageHandler object
   * @return Returns a Result object with error or warning values if any of those occurred during execution of this function
   */
  PreflightResult preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler, const std::atomic_bool& shouldCancel) const override;

  /**
   * @brief Applies the filter's algorithm to the DataStructure with the given arguments. Returns any warnings/errors.
   * On failure, there is no guarantee that the DataStructure is in a correct state.
   * @param ds The input DataStructure instance
   * @param filterArgs These are the input values for each parameter that is required for the filter
   * @param messageHandler The MessageHandler object
   * @return Returns a Result object with error or warning values if any of those occurred during execution of this function
   */
  Result<> executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler, const std::atomic_bool& shouldCancel) const override;
};
} // namespace complex

COMPLEX_DEF_FILTER_TRAITS(complex, ComputeFeatureRectFilter, "bf947c45-8610-44c9-917a-405e88f73fe7");
/* LEGACY UUID FOR THIS FILTER 6eda8dbf-dbd8-562a-ae1a-f2904157c189 */
