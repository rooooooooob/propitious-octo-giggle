#ifndef DS_FUNCTIONEVAL_HPP
#define DS_FUNCTIONEVAL_HPP

#include <memory>
#include <vector>

#include "Context/Identifier.hpp"
#include "Expressions/Expression.hpp"

namespace ds
{

class FunctionEval : public Expression
{
public:
	FunctionEval(Identifier id, std::vector<std::unique_ptr<Expression>>&& arguments);

	Value evaluate(Context& context) const;

private:
	Identifier id;
	std::vector<std::unique_ptr<Expression>> arguments;
};

} // ds

#endif // DS_FUNCTIONEVAL_HPP