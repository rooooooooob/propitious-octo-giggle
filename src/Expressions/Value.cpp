#include "Expressions/Value.hpp"

#include <sstream>
#include <utility>

#include "Context/Function.hpp"
#include "Errors/RuntimeTypeError.hpp"


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

Value::Value(const char *x)
	:type(Type::String)
{
	data.string = new std::string(x);
}

Value::Value(std::unique_ptr<Function> f)
	:type(Type::Function)
{
	data.func = f.release();
}

Value::Value(Value&& other)
	:type(Type::Void)
{
	swap(*this, other);
}

Value::Value(const Value& other)
	:type(other.type)
{
	switch(other.type)
	{
	case Type::Void:
		break;
	case Type::Boolean:
		data.boolean = other.data.boolean;
		break;
	case Type::Integer:
		data.integer = other.data.integer;
		break;
	case Type::Float:
		data.decimal = other.data.decimal;
		break;
	case Type::String:
		data.string = new std::string(*other.data.string);
		break;
	case Type::Array:
		data.vector = new std::vector<Type>(*other.data.vector);
		break;
	case Type::Map:
		data.map = new std::map<Type, Type>(*other.data.map);
		break;
	case Type::Function:
		data.func = new Function(*other.data.func);
		break;
	}
}

Value::~Value()
{
	free();
}


Value& Value::operator=(Value&& rhs)
{
	if (this != &rhs)
	{
		free();
		swap(*this, rhs);
	}
	return *this;
}

Value& Value::operator=(const Value& rhs)
{
	// MSVC++ says it's ambiguous between Value vs Value&& so had to change
	// the copy-swap idiom to pass by const ref and construct a temporary...
	Value temp(rhs);
	swap(*this, temp);
	return *this;
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
		throw err::RuntimeTypeError("wtf are you doing?! (maybe do something better here later)");
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
	case Type::Boolean:
		return data.boolean ? 1 : 0;
	case Type::Integer:
		return data.integer;
	case Type::Float:
		return static_cast<int>(data.decimal);
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Integer);
	}
}

float Value::asFloat() const
{
	switch (type)
	{
	case Type::Boolean:
	case Type::Integer:
		return static_cast<float>(asInt());
		break;
	case Type::Float:
		return data.decimal;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Float);
	}
}

const std::string Value::asString() const
{
	switch (type)
	{
	case Type::String:
		return *data.string;
	default:
		{
			std::stringstream ss;
			ss << *this;
			return ss.str();
		}
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

const Function& Value::asFunction() const
{
	switch (type)
	{
	case Type::Function:
		return *data.func;
	default:
		// maybe allow conversions here?
		throwTypeConversionError(Type::Function);
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

/*static*/ void Value::swap(Value& lhs, Value& rhs)
{
	std::swap(lhs.type, rhs.type);
	std::swap(lhs.data, rhs.data);
}


// private
void Value::free()
{
	switch(type)
	{
	case Type::Void:
	case Type::Boolean:
	case Type::Integer:
	case Type::Float:
		// do nothing
		break;
	case Type::String:
		delete data.string;
		break;
	case Type::Array:
		delete data.vector;
		break;
	case Type::Map:
		delete data.vector;
		break;
	case Type::Function:
		delete data.func;
		break;
	}
	type = Type::Void;
}

void Value::throwTypeConversionError(Type typeToConvertTo) const
{
	throw err::RuntimeTypeError("cannot convert from " + getTypeAsString() + " to " + getTypeAsString(typeToConvertTo));
}



// non-member
std::ostream& operator<<(std::ostream& os, const Value& value)
{
	switch (value.getType())
	{
	case Value::Type::Void:
		break;
	case Value::Type::Boolean:
		os << (value.asBool() ? "true" : "false");
		break;
	case Value::Type::Integer:
		os << value.asInt();
		break;
	case Value::Type::Float:
		os << value.asFloat();
		break;
	case Value::Type::String:
		os << value.asString();
		break;
	case Value::Type::Array:
		os << "[";
		for (auto it = value.asArray().cbegin(), end = value.asArray().cend(); it != end; ++it)
		{
			if (it != value.asArray().cbegin())
			{
				os << ", ";
			}
			//os << *it;
		}
		os << "]";
		break;
	case Value::Type::Map:
		os << "{";
		for (auto it = value.asMap().cbegin(), end = value.asMap().cend(); it != end; ++it)
		{
			if (it != value.asMap().cbegin())
			{
				os << ", ";
			}
			//os << "(" << it->first << " : " << it->second << ")";
		}
		os << "}";
		break;
	case Value::Type::Function:
		/* not implemented */
		throw "implement functions goddammit";
		break;
	}
	return os;
}

} // ds