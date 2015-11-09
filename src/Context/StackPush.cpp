#include "Context/StackPush.hpp"

#include "Context/Context.hpp"

namespace ds
{

StackPush::StackPush(Context& context)
	:context(context)
{
	context.pushStack();
}

StackPush::~StackPush()
{
	context.popStack();
}

} // ds