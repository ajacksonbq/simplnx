#pragma once

#include "complex/Common/StringLiteral.hpp"
#include "complex/Filter/IParameter.hpp"

#include <type_traits>

namespace complex
{
/**
 * @brief Specializations of ParameterTraits provide name and uuid for T
 * @tparam T
 */
template <class T, class = std::enable_if_t<std::is_base_of_v<IParameter, T>>>
struct ParameterTraits
{
};
} // namespace complex

#define COMPLEX_DEF_PARAMETER_TRAITS_NAMED(type, nameString, uuidString)                                                                                                                               \
  template <>                                                                                                                                                                                          \
  struct complex::ParameterTraits<type>                                                                                                                                                                \
  {                                                                                                                                                                                                    \
    static inline constexpr complex::StringLiteral name = nameString;                                                                                                                                  \
    static inline constexpr complex::Uuid uuid = *complex::Uuid::FromString(uuidString);                                                                                                               \
  }

#define COMPLEX_DEF_PARAMETER_TRAITS(type, uuidString) COMPLEX_DEF_PARAMETER_TRAITS_NAMED(type, #type, uuidString)

#define COMPLEX_NAMESPACE_CONCAT(nameSpace, type) nameSpace::type

#define COMPLEX_DEF_PARAMETER_TRAITS_NAMEDSPACED(type, nameSpace, uuidString) COMPLEX_DEF_PARAMETER_TRAITS_NAMED(COMPLEX_NAMESPACE_CONCAT(nameSpace, type), #type, uuidString)
