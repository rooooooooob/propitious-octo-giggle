#include "Expressions/VariableAccess.hpp"

#include "Context/Context.hpp"

namespace ds
{
VariableAccess::VariableAccess(Identifier id)
	:id(id)
{
}
	
Value VariableAccess::evaluate(Context& context) const
{
	return std::move(context.getVariable(id));
}

} // ds
