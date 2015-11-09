#include <iostream>
#include <memory>

#include "Context/Context.hpp"
#include "Context/Identifier.hpp"
#include "Context/Function.hpp"
#include "Expressions/Operators/Add.hpp"
#include "Expressions/Operators/Cast.hpp"
#include "Expressions/Constant.hpp"
#include "Expressions/FunctionEval.hpp"
#include "Expressions/VariableAccess.hpp"
#include "Statements/Return.hpp"

namespace ds
{

template <typename T>
std::unique_ptr<Expression> constant(const T& val)
{
	return std::unique_ptr<Expression>(new Constant(Value(val)));
}

std::unique_ptr<Expression> var(const std::string& name)
{
	return std::unique_ptr<Expression>(new VariableAccess(getIdentifier(name)));
}

void test()
{
	ds::Context context;
	context.createVariable(getIdentifier("a"), Value(3));
	std::unique_ptr<Expression> fBody(new op::Add(std::unique_ptr<Expression>(new op::Cast(var("c"), Value::Type::String)), var("d")));
	std::vector<Identifier> params(2);
	params[0] = getIdentifier("c");
	params[1] = getIdentifier("d");
	std::unique_ptr<Function> f(new Function(
		std::move(params),
		std::unique_ptr<Statement>(
			new Return(std::move(fBody))
		)
	));
	context.createVariable(getIdentifier("foo"), Value(std::move(f)));


	std::vector<std::unique_ptr<Expression>> args;
	args.push_back(constant(5));
	args.push_back(var("a"));
	std::unique_ptr<Expression> root(new FunctionEval(getIdentifier("foo"), std::move(args)));

	std::cout << root->evaluate(context) << std::endl;
}

} // ds

int main()
{
	try
	{
		ds::test();
		std::cin.get();
	}
	catch (std::exception& e)
	{
		std::cout << "Uh oh... " << e.what() << std::endl;
	}
	return 0;
}