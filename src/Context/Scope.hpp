#ifndef DS_SCOPE_HPP
#define DS_SCOPE_HPP

// @todo figure out what lookup structure to use - sorted vector maybe? (if using hoisting like JS does)
#include <map>

#include "Context/Identifier.hpp"
#include "Expressions/Value.hpp"

namespace ds
{

class Scope
{
public:
	const Value& getVariable(Identifier id) const;

	void setVariable(Identifier id, Value&& val);

	bool variableExists(Identifier id) const;

private:
	std::map<Identifier, Value> values;
};

} // ds

#endif // DS_SCOPE_HPP