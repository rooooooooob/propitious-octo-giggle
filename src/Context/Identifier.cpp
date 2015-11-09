#include "Context/Identifier.hpp"

#include <unordered_map>

namespace ds
{

Identifier getIdentifier(const std::string& name)
{
	static std::unordered_map<std::string, Identifier> identifiers;
	auto it = identifiers.find(name);
	if (it == identifiers.end())
	{
		const Identifier newID = static_cast<Identifier>(identifiers.size());
		it = identifiers.insert(std::make_pair(name, newID)).first;
	}
	return it->second;
}

} // ds