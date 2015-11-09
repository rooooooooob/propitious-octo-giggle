#ifndef DS_OP_CAST_HPP
#define DS_OP_CAST_HPP

#include <memory>

#include "Expressions/Expression.hpp"

namespace ds
{
namespace op
{

class Cast : public Expression
{
public:
	Cast(std::unique_ptr<Expression> expr, Value::Type type);

	
	Value evaluate(const Context& context) const override;
	
	
private:
	std::unique_ptr<Expression> expr;
	Value::Type type;
};

} // op
} // ds

#endif // DS_OP_CAST_HPP