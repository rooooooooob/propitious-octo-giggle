#include "Context/Context.hpp"

namespace ds
{

const Value& Context::getVariable(Identifier id) const
{
	if (!stack.empty() && stack.back().variableExists(id))
	{
		return stack.back().getVariable(id);
	}
	else if (globals.variableExists(id))
	{
		return globals.getVariable(id);
	}
	throw "replace this with a real exception or handle it during parsing";
	return Value(); // go away warnings
}

void Context::setVariable(Identifier id, Value&& val)
{
	if (!stack.empty() && stack.back().variableExists(id))
	{
		stack.back().setVariable(id, std::move(val));
	}
	else if (globals.variableExists(id))
	{
		globals.setVariable(id, std::move(val));
	}
	else
	{
		throw "replace this with a real variable doesn't exist error or handle it during syntax tree construction";
	}
}

Scope* Context::getLocalScope()
{
	return &stack.back();
}

const Value& Context::getReturnValue() const
{
	return returnVal;
}

void Context::setReturnValue(Value&& val)
{
	returnVal = std::move(val);
}

} // ds
