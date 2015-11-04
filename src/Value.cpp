#include "Expressions/Value.hpp"

#include "RuntimeInterpreterErrorException.hpp"


namespace ds
{

Value::Value()
	:type(Type::Void)
{
}

Value::Value(bool x)
	:type(Type::Boolean)
{
	data.boolean = x;
}

Value::Value(int x)
	:type(Type::Integer)
{
	data.integer = x;
}

Value::Value(float x)
	:type(Type::Float)
{
	data.decimal = x;
}

Value::Value(const std::string& x)
	:type(Type::String)
{
	data.string = new std::string(x);
}




bool Value::operator<(const Value& rhs) const
{
	if (type != rhs.type)
	{
		return type < rhs.type;
	}
	switch (type)
	{
	case Type::Void:
		return false; // so that Void == Void, since a < b && b < a means a == b
	case Type::Boolean:
		return !data.boolean && rhs.data.boolean;
	case Type::Integer:
		return data.integer < rhs.data.integer;
	case Type::Float:
		return data.decimal < rhs.data.decimal;
	case Type::String:
		return *data.string < *rhs.data.string;
	case Type::Array:
	case Type::Map:
	case Type::Function:
		throw RuntimeInterpreterErrorException("wtf are you doing?! (maybe do something better here later)");
	}
	return false; // get rid of warnings >:[
}


const Value& Value::operator[](int index) const
{
	// @todo implement
	return Value();
}

const Value& Value::operator[](const Type& key) const
{
	// @todo implement
	return Value();
}

bool Value::asBool() const
{
	switch (type)
	{
	case Type::Boolean:
		return data.boolean;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Boolean);
	}
}

int Value::asInt() const
{
	switch (type)
	{
	case Type::Integer:
		return data.integer;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Integer);
	}
}

float Value::asFloat() const
{
	switch (type)
	{
	case Type::Float:
		return data.decimal;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Float);
	}
}

const std::string& Value::asString() const
{
	switch (type)
	{
	case Type::String:
		return *data.string;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::String);
	}
}

const std::vector<Value::Type>& Value::asArray() const
{
	switch (type)
	{
	case Type::String:
		return *data.vector;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Array);
	}
}

const std::map<Value::Type, Value::Type>& Value::asMap() const
{
	switch (type)
	{
	case Type::Map:
		return *data.map;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Map);
	}
}

const std::string& Value::getTypeAsString() const
{
	return getTypeAsString(type);
}

Value::Type Value::getType() const
{
	return type;
}


/*static*/ const std::string& Value::getTypeAsString(Type type)
{
	static const std::string strings[8] = {
		"Void",
		"Boolean",
		"Integer",
		"Float",
		"String",
		"Array",
		"Map",
		"Function"
	};
	return strings[static_cast<int>(type)];
}


// private
void Value::throwTypeConversionError(Type typeToConvertTo) const
{
	throw RuntimeInterpreterErrorException("cannot convert from " + getTypeAsString() + " to " + getTypeAsString(typeToConvertTo));
}

} // ds