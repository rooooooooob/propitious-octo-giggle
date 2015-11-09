#ifndef DS_STACKPUSH_HPP
#define DS_STACKPUSH_HPP

namespace ds
{

class Context;

class StackPush
{
public:
	StackPush(Context& context);

	~StackPush();

private:
	StackPush(const StackPush&);
	StackPush& operator=(const StackPush);

	Context& context;
};

} // ds

#endif // DS_STACKPUSH_HPP