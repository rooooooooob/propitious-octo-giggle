#include <iostream>
#include <memory>

#include "Context/Context.hpp"
#include "Expressions/Operators/Add.hpp"
#include "Expressions/Operators/Cast.hpp"
#include "Expressions/Constant.hpp"

template <typename T>
std::unique_ptr<ds::Expression> constant(const T& val)
{
	return std::unique_ptr<ds::Expression>(new ds::Constant(ds::Value(val)));
}

int main()
{
	try
	{
		ds::Context context;
		std::unique_ptr<ds::Expression> root(new ds::op::Add(std::unique_ptr<ds::Expression>(new ds::op::Cast(constant(5), ds::Value::Type::String)), constant(3)));
		std::cout << root->evaluate(context) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Uh oh... " << e.what() << std::endl;
	}
	return 0;
}