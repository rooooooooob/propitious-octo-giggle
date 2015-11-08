#include "Errors/RuntimeTypeError.hpp"

namespace ds
{
namespace err
{

RuntimeTypeError::RuntimeTypeError(const std::string& info)
	:info("RuntimeTypeError: ")
{
	this->info += info;
}

const char * RuntimeTypeError::what() const noexcept
{
	return info.c_str();
}

} // err
} // ds