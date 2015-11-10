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

	void createVariable(Identifier id, Value&& val);

	void createGlobalVariable(Identifier id, Value&& val);

	Scope* getLocalScope();

	const Value& getReturnValue() const;

	void setReturnValue(Value&& val);

	void pushStack();

	void popStack();

private:

	std::vector<Scope> stack;
	Scope globals;
	Value returnVal;
};

} // ds

#endif // DS_CONTEXT_HPP