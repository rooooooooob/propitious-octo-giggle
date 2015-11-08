#ifndef SL_DS_ERR_RUNTIMETYPEERROR_HPP
#define SL_DS_ERR_RUNTIMETYPEERROR_HPP

#include <exception>
#include <string>

namespace ds
{
namespace err
{

class RuntimeTypeError : public std::exception
{
public:
	RuntimeTypeError(const std::string& info);
	
	virtual ~RuntimeTypeError() noexcept {}

	virtual const char* what() noexcept const;
	
private:
	std::string info;
};

} // err
} // ds

#endif // SL_DS_RUNTIMETYPEERROR_HPP