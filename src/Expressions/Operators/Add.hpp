#ifndef DS_OP_ADD_HPP
#define DS_OP_ADD_HPP

#include <memory>

#include "Expressions/Expression.hpp"

namespace ds
{
namespace op
{

class Add : public Expression
{
public:
	Add(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs);

	
	Value evaluate(const Context& context) const override;
	
	
private:
	std::unique_ptr<Expression> lhs;
	std::unique_ptr<Expression> rhs;
};

} // op
} // ds

#endif // DS_OP_ADD_HPP