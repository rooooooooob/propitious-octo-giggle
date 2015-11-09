#include "Expressions/FunctionEval.hpp"

#include "Context/Context.hpp"
#include "Context/Function.hpp"

namespace ds
{

FunctionEval::FunctionEval(Identifier id, std::vector<std::unique_ptr<Expression>>&& arguments)
	:id(id)
	,arguments(std::move(arguments))
{
}

Value FunctionEval::evaluate(Context& context) const
{
	const Function& f = context.getVariable(id).asFunction();
	f.call(context, arguments);
	return std::move(context.getReturnValue());
}


} // ds
