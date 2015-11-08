#include "Expressions/TypeCoercion.hpp"

namespace ds
{

bool canConvertTo(Value::Type source, Value::Type dest)
{
	if (source == dest)
	{
		return true;
	}
	if (source < dest && source >= Value::Type::Boolean && dest <= Value::Type::String)
	{
		return true;
	}
	return false;
}

bool areConvertible(Value::Type a, Value::Type b)
{
	return canConvertTo(a, b) || canConvertTo(b, a);
}

Value::Type lowestCommonType(Value::Type a, Value::Type b)
{
	if (a == b || canConvertTo(a, b))
	{
		return b;
	}
	else if (canConvertTo(b, a))
	{
		return a;
	}
	return Value::Type::Void;
}

} // ds
