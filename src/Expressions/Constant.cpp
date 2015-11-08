#include "Expressions/Constant.hpp"

namespace ds
{

Constant::Constant(const Value& value)
	:value(value)
{
}

Value Constant::evaluate(const Context&) const
{
	return value;
}


} // ds
