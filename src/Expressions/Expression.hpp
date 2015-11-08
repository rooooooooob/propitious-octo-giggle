#ifndef DS_EXPRESSION_HPP
#define DS_EXPRESSION_HPP

#include "Expressions/Value.hpp"

namespace ds
{

class Context;

class Expression
{
public:
	virtual ~Expression() {}
	
	virtual Value evaluate(const Context& context) const = 0;

protected:
	Expression() {}

private:
	// deleted
	Expression(const Expression&);
	// deleted
	Expression& operator=(const Expression&);
};

} // ds

#endif // DS_EXPRESSION_HPP
