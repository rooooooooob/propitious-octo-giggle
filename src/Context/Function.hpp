#ifndef DS_FUNCTION_HPP
#define DS_FUNCTION_HPP

#include <memory>
#include <vector>

#include "Context/Identifier.hpp"
#include "Expressions/Expression.hpp"
#include "Statements/Statement.hpp"

namespace ds
{

class Context;

class Function
{
public:
	Function(std::vector<Identifier>&& params, std::unique_ptr<Statement> block);


	void call(Context& context, const std::vector<std::unique_ptr<Expression>>& arguments) const;

private:
	struct Info
	{
		std::vector<Identifier> params;
		std::unique_ptr<Statement> block;
	};
	std::shared_ptr<Info> info;
};

} // ds

#endif // DS_FUNCTION_HPP