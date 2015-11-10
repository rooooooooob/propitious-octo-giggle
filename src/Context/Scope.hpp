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
	Scope();

	Scope(Scope&& other);

	Scope& operator=(Scope&& rhs);

	const Value& getVariable(Identifier id) const;

	void setVariable(Identifier id, Value&& val);

	bool variableExists(Identifier id) const;

private:
	Scope(const Scope&);
	Scope& operator=(const Scope&);

	std::map<Identifier, Value> values;
};

} // ds

#endif // DS_SCOPE_HPP