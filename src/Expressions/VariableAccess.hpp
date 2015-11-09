#ifndef DS_VARIABLEACCESS_HPP
#define DS_VARIABLEACCESS_HPP

#include <memory>

#include "Context/Identifier.hpp"
#include "Expressions/Expression.hpp"

namespace ds
{

class VariableAccess : public Expression
{
public:
	VariableAccess(Identifier id);
	
	Value evaluate(Context&) const override;
	
private:
	Identifier id;
};

} // ds

#endif // DS_VARIABLEACCESS_HPP