#include "Expressions/Operators/Add.hpp"

#include "Errors/RuntimeTypeError.hpp"

namespace ds
{
namespace op
{

Add::Add(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
	:lhs(std::move(lhs))
	,rhs(std::move(rhs))
{
}


Value Add::evaluate(const Context& context) const
{
	const Value left = lhs->evaluate(context);
	const Value right = rhs->evaluate(context);
	// @todo figure out which implicit conversiosn to actually support
	if (left.getType() != right.getType())
	{
		throw err::RuntimeTypeError("operator+ works only on homogenious types");
	}
	Value result;
	switch (left.getType())
	{
	case Value::Type::Integer:
		result = Value(lhs->evaluate(context).asInt() + rhs->evaluate(context).asInt());
		break;
	case Value::Type::Float:
		result = Value(lhs->evaluate(context).asFloat() + rhs->evaluate(context).asFloat());
		break;
	case Value::Type::String:
		result = Value(lhs->evaluate(context).asString() + rhs->evaluate(context).asString());
		break;
	default:
		throw err::RuntimeTypeError("operator+ not defined for: " + left.getTypeAsString() + " + " + right.getTypeAsString());
	}
	return std::move(result);
}


} // op
} // ds
