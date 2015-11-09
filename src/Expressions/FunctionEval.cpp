#include "Expressions/FunctionEval.hpp"

namespace ds
{

FunctionEval::FunctionEval(Identifier function, std::vector<std::unique_ptr<Expression>>&& arguments)
	:function(function)
	,arguments(std::move(arguments))
{
}

Value FunctionEval::evaluate(Context& context) const
{
	// @todo implement
	return Value();
}


} // ds
