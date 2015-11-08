#ifndef DS_TYPECOERCION_HPP
#define DS_TYPECOERCION_HPP

#include "Expressions/Value.hpp"


namespace ds
{

bool canConvertTo(Value::Type source, Value::Type dest);

bool areConvertible(Value::Type a, Value::Type b);

Value::Type lowestCommonType(Value::Type a, Value::Type b);

} // ds

#endif //  DS_TYPECOERCION_HPP