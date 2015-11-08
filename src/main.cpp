#include <iostream>
#include <memory>

#include "Context/Context.hpp"
#include "Expressions/Operators/Add.hpp"
#include "Expressions/Constant.hpp"

template <typename T>
std::unique_ptr<ds::Expression> constant(const T& val)
{
	return std::unique_ptr<ds::Expression>(new ds::Constant(ds::Value(val)));
}

int main()
{
	ds::Context context;
	std::unique_ptr<ds::Expression> root(new ds::op::Add(constant(5), constant(3)));
	std::cout << root->evaluate(context) << std::endl;
	return 0;
}