#ifndef VALUE_H
#define VALUE_H

#include <string>
#include <vector>
#include <map>
#include "context.hpp"
#include "enum.hpp"

class Value;
class DoubleValue;
class BoolValue;
class NBlock;
class Context;

typedef std::vector<const Value*> ValueVec;
typedef std::map<std::string, DataType> DMap;

class Value {
public:
    virtual ~Value() {}

    // Arithmetic
    virtual const Value* added_to(const Value* other) const = 0;
    virtual const Value* subbed_by(const Value* other) const = 0;
    virtual const Value* multiplied_by(const Value* other) const = 0;
    virtual const Value* divided_by(const Value* other) const = 0;
    //Comparison
    virtual const Value* equal_to(const Value* other) const = 0;
    virtual const Value* not_equal_to(const Value* other) const = 0;
    virtual const Value* less_than(const Value* other) const = 0;
    virtual const Value* greater_than(const Value* other) const = 0;
    virtual const Value* less_than_or_equal_to(const Value* other) const = 0;
    virtual const Value* greater_than_or_equal_to(const Value* other) const = 0;
    // Internal
    virtual const void* get_value() const = 0;
    virtual const bool get_isError() const = 0;
    virtual const DataType& get_type() const = 0;
};

class ErrorValue : public Value
{
public:
    // Data
    std::string value;
    const bool isError = true;
    const DataType type = DataType::ERROR_DTYPE;

    ErrorValue(const std::string &value) : value(value) { }

    // Arithmetic
    const Value* added_to(const Value* other) const override
        {return new ErrorValue("Addition operator not implemented for errors");};
    const Value* subbed_by(const Value* other) const override
        {return new ErrorValue("Subtraction operator not implemented for errors");};
    const Value* multiplied_by(const Value* other) const override
        {return new ErrorValue("Multiplication operator not implemented for errors");};
    const Value* divided_by(const Value* other) const override
        {return new ErrorValue("Division operator not implemented for errors");};
    // Comparison
    const Value* equal_to(const Value* other) const override
        {return new ErrorValue("Equality operator not implemented for errors");};
    const Value* not_equal_to(const Value* other) const override
        {return new ErrorValue("Not Equal operator not implemented for errors");};
    const Value* less_than(const Value* other) const override
        {return new ErrorValue("Less than operator not implemented for errors");};
    const Value* greater_than(const Value* other) const override
        {return new ErrorValue("Greater than operator not implemented for errors");};
    const Value* less_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Less than or equal to operator not implemented for errors");};
    const Value* greater_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Greater than or equal to operator not implemented for errors");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};

class NumericValue : public Value
{};

class IntValue  : public NumericValue
{
public:
    // Data
    int value;
    const bool isError = false;
    const DataType type = DataType::INT_DTYPE;

    IntValue(const int &value) : value(value) { }

    // Arithmetic
    const Value* added_to(const Value* other) const override;
    const Value* subbed_by(const Value* other) const override;
    const Value* multiplied_by(const Value* other) const override;
    const Value* divided_by(const Value* other) const override;
    // Comparison
    const Value* equal_to(const Value* other) const override;
    const Value* not_equal_to(const Value* other) const override;
    const Value* less_than(const Value* other) const override;
    const Value* greater_than(const Value* other) const override;
    const Value* less_than_or_equal_to(const Value* other) const override;
    const Value* greater_than_or_equal_to(const Value* other) const override;
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};

class DoubleValue : public NumericValue
{
public:
    // Data
    double value;
    const bool isError = false;
    const DataType type = DataType::FLOAT_DTYPE;

    DoubleValue(const double &value) : value(value) { }

    // Arithmetic
    const Value* added_to(const Value* other) const override;
    const Value* subbed_by(const Value* other) const override;
    const Value* multiplied_by(const Value* other) const override;
    const Value* divided_by(const Value* other) const override;
    //Comparison
    const Value* equal_to(const Value* other) const override;
    const Value* not_equal_to(const Value* other) const override;
    const Value* less_than(const Value* other) const override;
    const Value* greater_than(const Value* other) const override;
    const Value* less_than_or_equal_to(const Value* other) const override;
    const Value* greater_than_or_equal_to(const Value* other) const override;
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};

class BoolValue : public Value
{
public:
    // Data
    bool value;
    const bool isError = false;
    const DataType type = DataType::BOOL_DTYPE;

    BoolValue(const bool &value) : value(value) { }

    // Arithmetic
    const Value* added_to(const Value* other) const override
        {return new ErrorValue("Addition operator not implemented for bools");};
    const Value* subbed_by(const Value* other) const override
        {return new ErrorValue("Subtraction operator not implemented for bools");};
    const Value* multiplied_by(const Value* other) const override
        {return new ErrorValue("Multiplication operator not implemented for bools");};
    const Value* divided_by(const Value* other) const override
        {return new ErrorValue("Division operator not implemented for bools");};
    //Comparison
    const Value* equal_to(const Value* other) const override;
    const Value* not_equal_to(const Value* other) const override;
    const Value* less_than(const Value* other) const override
        {return new ErrorValue("Less than operator not implmented for bools");};
    const Value* greater_than(const Value* other) const override
        {return new ErrorValue("Greater than operator not implmented for bools");};
    const Value* less_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Less than or equal to operator not implmented for bools");};
    const Value* greater_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Greater than or equal to operator not implmented for bools");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};

class StringValue : public Value
{
public:
    // Data
    std::string value;
    const bool isError = false;
    const DataType type = DataType::STRING_DTYPE;

    StringValue(const std::string &value) : value(value) { }

    // Arithmetic
    const Value* added_to(const Value* other) const override;
    const Value* subbed_by(const Value* other) const override
        {return new ErrorValue("Subtraction operator not implemented for strings");};
    const Value* multiplied_by(const Value* other) const override;
    const Value* divided_by(const Value* other) const override
        {return new ErrorValue("Division operator not implemented for strings");};
    //Comparison
    const Value* equal_to(const Value* other) const override;
    const Value* not_equal_to(const Value* other) const override;
    const Value* less_than(const Value* other) const override
        {return new ErrorValue("Less than operator not implemented for strings");};
    const Value* greater_than(const Value* other) const override
        {return new ErrorValue("Greater than operator not implemented for strings");};
    const Value* less_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Less than or equal to operator not implemented for strings");};
    const Value* greater_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Greater than or equal to operator not implemented for strings");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};

class IdentifierValue : public Value
{
private:
	DMap dTypeMap = {
	{"int", DataType::INT_DTYPE},
	{"float", DataType::FLOAT_DTYPE},
	{"string", DataType::STRING_DTYPE},
	{"char", DataType::CHAR_DTYPE},
	{"bool", DataType::BOOL_DTYPE},
	{"void", DataType::VOID_DTYPE},
	};
public:
    // Data
    std::string value;
    DataType type;
    const bool isError = false;

    IdentifierValue(const std::string &type, const std::string &value) 
                    : value(value), type(dTypeMap[type]) { }
    IdentifierValue(const std::string &value) : value(value), type(DataType::TNI) {}

    // Arithmetic
    const Value* added_to(const Value* other) const override
        {return new ErrorValue("Addition operator not implemented for Identifiers");};
    const Value* subbed_by(const Value* other) const override
        {return new ErrorValue("Subtraction operator not implemented for Identifiers");};
    const Value* multiplied_by(const Value* other) const override
        {return new ErrorValue("Multiplication operator not implemented for Identifiers");};
    const Value* divided_by(const Value* other) const override
        {return new ErrorValue("Division operator not implemented for Identifiers");};
    // Comparison
    const Value* equal_to(const Value* other) const override
        {return new ErrorValue("Equality operator not implemented for Identifiers");};
    const Value* not_equal_to(const Value* other) const override
        {return new ErrorValue("Not Equal operator not implemented for Identifiers");};
    const Value* less_than(const Value* other) const override
        {return new ErrorValue("Less than operator not implemented for Identifiers");};
    const Value* greater_than(const Value* other) const override
        {return new ErrorValue("Greater than operator not implemented for Identifiers");};
    const Value* less_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Less than or equal to operator not implemented for Identifiers");};
    const Value* greater_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Greater than or equal to operator not implemented for Identifiers");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};

class OperatorValue : public Value
{
public:
    // Data
    OperationType value;
    const bool isError = false;
    const DataType type = DataType::VOID_DTYPE;

    OperatorValue(const OperationType &value) : value(value) { }
    // Arithmetic
    const Value* added_to(const Value* other) const override
        {return new ErrorValue("Addition operator not implemented for Operators");};
    const Value* subbed_by(const Value* other) const override
        {return new ErrorValue("Subtraction operator not implemented for Operators");};
    const Value* multiplied_by(const Value* other) const override
        {return new ErrorValue("Multiplication operator not implemented for Operators");};
    const Value* divided_by(const Value* other) const override
        {return new ErrorValue("Division operator not implemented for Operators");};
    // Comparison
    const Value* equal_to(const Value* other) const override
        {return new ErrorValue("Equality operator not implemented for Operators");};
    const Value* not_equal_to(const Value* other) const override
        {return new ErrorValue("Not Equal operator not implemented for Operators");};
    const Value* less_than(const Value* other) const override
        {return new ErrorValue("Less than operator not implemented for Operators");};
    const Value* greater_than(const Value* other) const override
        {return new ErrorValue("Greater than operator not implemented for Operators");};
    const Value* less_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Less than or equal to operator not implemented for Operators");};
    const Value* greater_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Greater than or equal to operator not implemented for Operators");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};

class ListValue : public Value
{
public:
    //Data
    ValueVec value;
    const bool isError = false;
    const DataType type = DataType::LIST_DTYPE;

    ListValue(ValueVec &value) : value(value) { }
    // Arithmetic
    const Value* added_to(const Value* other) const override;
    const Value* subbed_by(const Value* other) const override;
    const Value* multiplied_by(const Value* other) const override;
    const Value* divided_by(const Value* other) const override;
    //Comparison
    const Value* equal_to(const Value* other) const override;
    const Value* not_equal_to(const Value* other) const override;
    const Value* less_than(const Value* other) const override
        {return new ErrorValue("Less than operator not implemented for Lists");};
    const Value* greater_than(const Value* other) const override
        {return new ErrorValue("Greater than operator not implemented for Lists");};
    const Value* less_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Less than or equal to operator not implemented for Lists");};
    const Value* greater_than_or_equal_to(const Value* other) const override
        {return new ErrorValue("Greater than or equal to operator not implemented for Lists");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
    const DataType& get_type() const override;
};


class FunctionValue : public Value
{
    public:
        const bool isError = false;
        const DataType type;
        ValueVec* arg_values;
        Context* function_context;
        NBlock &block;
        FunctionValue(ValueVec* arg_values, Context* function_context, NBlock &block, const DataType type)
                : arg_values(arg_values), function_context(function_context), block(block), type(type) {}

        // Arithmetic
        const Value* added_to(const Value* other) const override
            {return new ErrorValue("Addition operator not implemented for functions");};
        const Value* subbed_by(const Value* other) const override
            {return new ErrorValue("Subtraction operator not implemented for functions");};
        const Value* multiplied_by(const Value* other) const override
            {return new ErrorValue("Multiplication operator not implemented for functions");};
        const Value* divided_by(const Value* other) const override
            {return new ErrorValue("Division operator not implemented for functions");};
        // Comparison
        const Value* equal_to(const Value* other) const override
            {return new ErrorValue("Equality operator not implemented for functions");};
        const Value* not_equal_to(const Value* other) const override
            {return new ErrorValue("Not Equal operator not implemented for functions");};
        const Value* less_than(const Value* other) const override
            {return new ErrorValue("Less than operator not implemented for functions");};
        const Value* greater_than(const Value* other) const override
            {return new ErrorValue("Greater than operator not implemented for functions");};
        const Value* less_than_or_equal_to(const Value* other) const override
            {return new ErrorValue("Less than or equal to operator not implemented for functions");};
        const Value* greater_than_or_equal_to(const Value* other) const override
            {return new ErrorValue("Greater than or equal to operator not implemented for functions");};
        // Internal
        const void* get_value() const override
            {return this;};
        const bool get_isError() const override
            {return this->isError;};
        const DataType& get_type() const override
            {return this->type;};
};


class ReturnValue : public Value
{
    public:
        const bool isError = false;
        const Value* value;
        const DataType type;
        ReturnValue(const Value* value) : value(value), type(value->get_type()) {}

        // Arithmetic
        const Value* added_to(const Value* other) const override
            {return new ErrorValue("Addition operator not implemented for a return value");};
        const Value* subbed_by(const Value* other) const override
            {return new ErrorValue("Subtraction operator not implemented for a return value");};
        const Value* multiplied_by(const Value* other) const override
            {return new ErrorValue("Multiplication operator not implemented for a return value");};
        const Value* divided_by(const Value* other) const override
            {return new ErrorValue("Division operator not implemented for a return value");};
        // Comparison
        const Value* equal_to(const Value* other) const override
            {return new ErrorValue("Equality operator not implemented for a return value");};
        const Value* not_equal_to(const Value* other) const override
            {return new ErrorValue("Not Equal operator not implemented for a return value");};
        const Value* less_than(const Value* other) const override
            {return new ErrorValue("Less than operator not implemented for a return value");};
        const Value* greater_than(const Value* other) const override
            {return new ErrorValue("Greater than operator not implemented for a return value");};
        const Value* less_than_or_equal_to(const Value* other) const override
            {return new ErrorValue("Less than or equal to operator not implemented for a return value");};
        const Value* greater_than_or_equal_to(const Value* other) const override
            {return new ErrorValue("Greater than or equal to operator not implemented for a return value");};
        // Internal
        const void* get_value() const override
            {return this->value;};
        const bool get_isError() const override
            {return this->isError;};
        const DataType& get_type() const override
            {return this->type;};
};

#endif