#ifndef DS_CONTEXT_HPP
#define DS_CONTEXT_HPP

#include <vector>

#include "Context/Identifier.hpp"
#include "Context/Scope.hpp"

namespace ds
{

class Context
{
public:
	const Value& getVariable(Identifier id) const;

	void setVariable(Identifier id, Value&& val);

private:

	std::vector<Scope> stack;
	Scope globals;
};

} // ds

#endif // DS_CONTEXT_HPP