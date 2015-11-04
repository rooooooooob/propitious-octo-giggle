#ifndef DS_VALUE_HPP
#define DS_VALUE_HPP

#include <map>
#include <string>
#include <vector>

namespace ds
{

class Value
{
public:
	enum class Type
	{
		Void = 0,
		Boolean,
		Integer,
		Float,
		String,
		Array,
		Map,
		Function
	};


	Value();

	explicit Value(bool x);

	explicit Value(int x);

	explicit Value(float x);

	explicit Value(const std::string& x);




	bool operator<(const Value& rhs) const;



	const Value& operator[](int index) const;

	const Value& operator[](const Type& key) const;

	bool asBool() const;

	int asInt() const;

	float asFloat() const;

	const std::string& asString() const;

	const std::vector<Type>& asArray() const;

	const std::map<Type, Type>& asMap() const;



	const std::string& getTypeAsString() const;

	Type getType() const;

	









	static const std::string& getTypeAsString(Type type);
private:

	void throwTypeConversionError(Type typeToConvertTo) const;
	

	Type type;
	union Data
	{
		bool boolean;
		int integer;
		float decimal;
		std::string *string;
		std::vector<Type> *vector; 
		std::map<Type, Type> *map;
	};
	Data data;
};

} // ds

#endif // DS_VALUE_HPP