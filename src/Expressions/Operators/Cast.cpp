#include "Expressions/Operators/Cast.hpp"

#include "Expressions/TypeCoercion.hpp"

#include "Errors/RuntimeTypeError.hpp"

namespace ds
{
namespace op
{

Cast::Cast(std::unique_ptr<Expression> expr, Value::Type type)
	:expr(std::move(expr))
	,type(type)
{
	if (type == Value::Type::Void || type == Value::Type::Array || type == Value::Type::Map || type == Value::Type::Function)
	{
		throw err::RuntimeTypeError("compile error actually lol - but no support for casts to " + Value::getTypeAsString(type));
	}
}

	
Value Cast::evaluate(const Context& context) const
{
	Value val(std::move(expr->evaluate(context)));
	Value ret;
	switch (type)
	{
	case Value::Type::Boolean:
		ret = Value(val.asBool());
		break;
	case Value::Type::Integer:
		ret = Value(val.asInt());
		break;
	case Value::Type::Float:
		ret = Value(val.asFloat());
		break;
	case Value::Type::String:
		ret = Value(val.asString());
		break;
	}
	return std::move(ret);
}
	
	
} // op
} // ds
