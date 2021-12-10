#include "CreateNeighborListAction.hpp"

#include <fmt/core.h>

#include "complex/Utilities/DataArrayUtilities.hpp"

using namespace complex;

namespace complex
{
CreateNeighborListAction::CreateNeighborListAction(DataType type, usize tupleCount, const DataPath& path)
: m_Type(type)
, m_TupleCount(tupleCount)
, m_Path(path)
{
}

CreateNeighborListAction::~CreateNeighborListAction() noexcept = default;

Result<> CreateNeighborListAction::apply(DataStructure& dataStructure, Mode mode) const
{
  // Validate the Numeric Type
  switch(m_Type)
  {
  case DataType::int8: {
    return CreateNeighbors<int8>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::uint8: {
    return CreateNeighbors<uint8>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::int16: {
    return CreateNeighbors<int16>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::uint16: {
    return CreateNeighbors<uint16>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::int32: {
    return CreateNeighbors<int32>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::uint32: {
    return CreateNeighbors<uint32>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::int64: {
    return CreateNeighbors<int64>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::uint64: {
    return CreateNeighbors<uint64>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::float32: {
    return CreateNeighbors<float32>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::float64: {
    return CreateNeighbors<float64>(dataStructure, m_TupleCount, m_Path, mode);
  }
  case DataType::boolean: {
    return CreateNeighbors<bool>(dataStructure, m_TupleCount, m_Path, mode);
  }
  default:
    throw std::runtime_error(fmt::format("CreateNeighborListAction: Invalid Numeric Type '{}'", m_Type));
  }
}

DataType CreateNeighborListAction::type() const
{
  return m_Type;
}

usize CreateNeighborListAction::tupleCount() const
{
  return m_TupleCount;
}

DataPath CreateNeighborListAction::path() const
{
  return m_Path;
}
} // namespace complex
