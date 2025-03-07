#pragma once

#include "ComplexCore/ComplexCore_export.hpp"

#include "complex/Filter/FilterTraits.hpp"
#include "complex/Filter/IFilter.hpp"

namespace complex
{
/**
 * @class QuickSurfaceMeshFilter
 * @brief This filter will ....
 */
class COMPLEXCORE_EXPORT QuickSurfaceMeshFilter : public IFilter
{
public:
  QuickSurfaceMeshFilter() = default;
  ~QuickSurfaceMeshFilter() noexcept override = default;

  QuickSurfaceMeshFilter(const QuickSurfaceMeshFilter&) = delete;
  QuickSurfaceMeshFilter(QuickSurfaceMeshFilter&&) noexcept = delete;

  QuickSurfaceMeshFilter& operator=(const QuickSurfaceMeshFilter&) = delete;
  QuickSurfaceMeshFilter& operator=(QuickSurfaceMeshFilter&&) noexcept = delete;

  // Parameter Keys

  static inline constexpr StringLiteral k_GenerateTripleLines_Key = "generate_triple_lines";
  static inline constexpr StringLiteral k_FixProblemVoxels_Key = "fix_problem_voxels";
  static inline constexpr StringLiteral k_GridGeometryDataPath_Key = "grid_geometry_data_path";
  static inline constexpr StringLiteral k_CellFeatureIdsArrayPath_Key = "feature_ids_path";
  static inline constexpr StringLiteral k_SelectedDataArrayPaths_Key = "selected_data_array_paths";

  static inline constexpr StringLiteral k_TriangleGeometryName_Key = "triangle_geometry_name";

  static inline constexpr StringLiteral k_VertexDataGroupName_Key = "vertex_data_group_name";
  static inline constexpr StringLiteral k_NodeTypesArrayName_Key = "node_types_array_name";

  static inline constexpr StringLiteral k_FaceDataGroupName_Key = "face_data_group_name";
  static inline constexpr StringLiteral k_FaceLabelsArrayName_Key = "face_labels_array_name";
  static inline constexpr StringLiteral k_FaceFeatureAttributeMatrixName_Key = "face_feature_attribute_matrix_name";

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
   * @param dataStructure The input DataStructure instance
   * @param filterArgs These are the input values for each parameter that is required for the filter
   * @param messageHandler The MessageHandler object
   * @return Returns a Result object with error or warning values if any of those occurred during execution of this function
   */
  PreflightResult preflightImpl(const DataStructure& dataStructure, const Arguments& filterArgs, const MessageHandler& messageHandler, const std::atomic_bool& shouldCancel) const override;

  /**
   * @brief Applies the filter's algorithm to the DataStructure with the given arguments. Returns any warnings/errors.
   * On failure, there is no guarantee that the DataStructure is in a correct state.
   * @param dataStructure The input DataStructure instance
   * @param filterArgs These are the input values for each parameter that is required for the filter
   * @param messageHandler The MessageHandler object
   * @return Returns a Result object with error or warning values if any of those occurred during execution of this function
   */
  Result<> executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler, const std::atomic_bool& shouldCancel) const override;
};
} // namespace complex

COMPLEX_DEF_FILTER_TRAITS(complex, QuickSurfaceMeshFilter, "13dd00bd-ad49-4e04-95eb-3267952fd6e5");
