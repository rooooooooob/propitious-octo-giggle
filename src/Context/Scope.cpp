#include "Context/Scope.hpp"

namespace ds
{

const Value& Scope::getVariable(Identifier id) const
{
	auto it = values.find(id);
	if (it == values.end())
	{
		throw "put a real error here or detect it at syntax tree construction time";
	}
	return it->second;
}

void Scope::setVariable(Identifier id, Value&& val)
{
	values[id] = std::move(val);
}

bool Scope::variableExists(Identifier id) const
{
	return values.count(id) != 0;
}

} // ds
