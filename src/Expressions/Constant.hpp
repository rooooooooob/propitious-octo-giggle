#ifndef DS_CONSTANT_HPP
#define DS_CONSTANT_HPP

#include <memory>

#include "Expressions/Expression.hpp"

namespace ds
{

class Constant : public Expression
{
public:
	Constant(const Value& value);
	
	Value evaluate(const Context&) const override;
	
private:
	Value value;
};

} // ds

#endif // DS_CONSTANT_HPP