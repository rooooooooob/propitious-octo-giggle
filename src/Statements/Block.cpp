#include "Statements/Block.hpp"

namespace ds
{

Block::Block(std::vector<std::unique_ptr<Statement>>&& statements)
	:statements(std::move(statements))
{
}
	
bool Block::execute(Context& context) const
{
	for (const auto& statement : statements)
	{
		if (statement->execute(context))
		{
			return true;
		}
	}
	return false;
}

} // ds
