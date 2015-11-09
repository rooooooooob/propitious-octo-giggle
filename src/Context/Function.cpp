#include "Context/Function.hpp"

#include "Context/Context.hpp"
#include "Context/StackPush.hpp"

namespace ds
{

Function::Function(std::vector<Identifier>&& params, std::unique_ptr<Statement> block)
	:info(std::make_shared<Info>())
{
	info->params = std::move(params);
	info->block = std::move(block);
}


void Function::call(Context& context, const std::vector<std::unique_ptr<Expression>>& arguments) const
{
	// @assert arguments.size() == params.size() here later
	// evaluate before registering locals in case name conflits happen
	std::vector<Value> argValues;
	argValues.reserve(arguments.size());
	for (int i = 0; i < arguments.size(); ++i)
	{
		argValues[i] = std::move(arguments[i]->evaluate(context));
	}
	StackPush stack(context);
	for (int i = 0; i < arguments.size(); ++i)
	{
		context.getLocalScope()->setVariable(info->params[i], std::move(argValues[i]));
	}
	if (!info->block->execute(context))
	{
		context.setReturnValue(Value());
	}
}

} // ds
