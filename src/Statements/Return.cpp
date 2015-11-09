#include "Statements/Return.hpp"

#include "Context/Context.hpp"

namespace ds
{

Return::Return(std::unique_ptr<Expression> val)
	:val(std::move(val))
{
}
	
bool Return::execute(Context& context) const
{
	context.setReturnValue(std::move(val->evaluate(context)));
	return true;
}

} // ds
