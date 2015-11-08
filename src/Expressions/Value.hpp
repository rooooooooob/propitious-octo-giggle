#ifndef DS_VALUE_HPP
#define DS_VALUE_HPP

#include <map>
#include <ostream>
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
	
	Value(Value&& other);
	
	Value(const Value& other);
	
	~Value();
	
	
	Value& operator=(Value&& rhs);
	
	Value& operator=(const Value& rhs);




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
	
	static void swap(Value& lhs, Value& rhs);
	
private:

	void free();

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



	friend std::ostream& operator<<(std::ostream& os, const Value& value);
};

std::ostream& operator<<(std::ostream& os, const Value& value);

} // ds

#endif // DS_VALUE_HPP