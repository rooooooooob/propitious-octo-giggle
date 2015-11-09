#ifndef DS_RETURN_HPP
#define DS_RETURN_HPP

#include <memory>

#include "Expressions/Expression.hpp"
#include "Statements/Statement.hpp"

namespace ds
{

class Return : public Statement
{
public:
	Return(std::unique_ptr<Expression> val);
	
	bool execute(Context& context) const override;

private:

	std::unique_ptr<Expression> val;
};

} // ds

#endif // DS_RETURN_HPP