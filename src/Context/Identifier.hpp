#ifndef DS_IDENTIFIER_HPP
#define DS_IDENTIFIER_HPP

#include <string>

namespace ds
{

typedef int Identifier;

Identifier getIdentifier(const std::string& name);

} // ds

#endif // DS_IDENTIFIER_HPP