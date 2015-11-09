#include "Expressions/Operators/Add.hpp"

#include "Errors/RuntimeTypeError.hpp"
#include "Expressions/TypeCoercion.hpp"

namespace ds
{
namespace op
{

Add::Add(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs)
	:Expression()
	,lhs(std::move(lhs))
	,rhs(std::move(rhs))
{
}


Value Add::evaluate(Context& context) const
{
	const Value left = lhs->evaluate(context);
	const Value right = rhs->evaluate(context);
	if (!areConvertible(left.getType(), right.getType()))
	{
		throw err::RuntimeTypeError("operator+ not defined for: " + left.getTypeAsString() + " + " + right.getTypeAsString());
	}
	Value result;
	switch (lowestCommonType(left.getType(), right.getType()))
	{
	case Value::Type::Integer:
		result = std::move(Value(left.asInt() + right.asInt()));
		break;
	case Value::Type::Float:
		result = std::move(Value(left.asFloat() + right.asFloat()));
		break;
	case Value::Type::String:
		result = std::move(Value(left.asString() + right.asString()));
		break;
	default:
		throw err::RuntimeTypeError("operator+ not defined for: " + left.getTypeAsString() + " + " + right.getTypeAsString());
	}
	return std::move(result);
}


} // op
} // ds
