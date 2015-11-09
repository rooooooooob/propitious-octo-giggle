#ifndef DS_BLOCK_HPP
#define DS_BLOCK_HPP

#include <memory>
#include <vector>

#include "Statements/Statement.hpp"

namespace ds
{

class Block : public Statement
{
public:
	Block(std::vector<std::unique_ptr<Statement>>&& statements);
	
	bool execute(Context& context) const override;

private:

	std::vector<std::unique_ptr<Statement>> statements;
};

} // ds

#endif // DS_BLOCK_HPP