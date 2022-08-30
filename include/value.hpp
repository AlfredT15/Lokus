#ifndef VALUE_H
#define VALUE_H

// #include <boost/any.hpp>
#include <string>

class Value;
class DoubleValue;
class BoolValue;

typedef std::vector<const Value*> ValueVec;

enum OperationType
{
    ADD_TYPE,
    SUB_TYPE,
    MUL_TYPE,
    DIV_TYPE,
    EE_TYPE,
    NE_TYPE,
    LT_TYPE,
    GT_TYPE,
    LTE_TYPE,
    GTE_TYPE
};

class Value {
public:
    virtual ~Value() {}

    // Arithmetic
    virtual const Value* operator+(const Value* other) const = 0;
    virtual const Value* operator-(const Value* other) const = 0;
    virtual const Value* operator*(const Value* other) const = 0;
    virtual const Value* operator/(const Value* other) const = 0;
    // Comparison
    virtual const Value* operator==(const Value* other) const = 0;
    virtual const Value* operator!=(const Value* other) const = 0;
    virtual const Value* operator<(const Value* other) const = 0;
    virtual const Value* operator>(const Value* other) const = 0;
    virtual const Value* operator<=(const Value* other) const = 0;
    virtual const Value* operator>=(const Value* other) const = 0;
    // Internal
    virtual const void* get_value() const = 0;
    virtual const bool get_isError() const = 0;
};

class ErrorValue : public Value
{
public:
    // Data
    std::string value;
    const bool isError = true;

    ErrorValue(const std::string &value) : value(value) { }

    // Arithmetic
    const ErrorValue* operator+(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator-(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator*(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator/(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Comparison
    const ErrorValue* operator==(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator!=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator<(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator<=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Internal
    const void* get_value() const override {return 0;};
    const bool get_isError() const override {return false;};
};

class NumericValue : public Value
{};

class IntValue  : public NumericValue
{
public:
    // Data
    int value;
    const bool isError = false;

    IntValue(const int &value) : value(value) { }

    // Arithmetic
    const Value* operator+(const Value* other) const override;
    const Value* operator-(const Value* other) const override;
    const Value* operator*(const Value* other) const override;
    const Value* operator/(const Value* other) const override;
    // Comparison
    const Value* operator==(const Value* other) const override;
    const Value* operator!=(const Value* other) const override;
    const Value* operator<(const Value* other) const override;
    const Value* operator>(const Value* other) const override;
    const Value* operator<=(const Value* other) const override;
    const Value* operator>=(const Value* other) const override;
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
};

class DoubleValue : public NumericValue
{
public:
    // Data
    double value;
    const bool isError = false;

    DoubleValue(const double &value) : value(value) { }

    // Arithmetic
    const Value* operator+(const Value* other) const override;
    const Value* operator-(const Value* other) const override;
    const Value* operator*(const Value* other) const override;
    const Value* operator/(const Value* other) const override;
    // Comparison
    const Value* operator==(const Value* other) const override;
    const Value* operator!=(const Value* other) const override;
    const Value* operator<(const Value* other) const override;
    const Value* operator>(const Value* other) const override;
    const Value* operator<=(const Value* other) const override;
    const Value* operator>=(const Value* other) const override;
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
};

class BoolValue : public Value
{
public:
    // Data
    bool value;
    const bool isError = false;

    BoolValue(const bool &value) : value(value) { }

    // Arithmetic
    const ErrorValue* operator+(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator-(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator*(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator/(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Comparison
    const Value* operator==(const Value* other) const override;
    const Value* operator!=(const Value* other) const override;
    const ErrorValue* operator<(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator<=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
};

class StringValue : public Value
{
public:
    // Data
    std::string value;
    const bool isError = false;

    StringValue(const std::string &value) : value(value) { }

    // Arithmetic
    const Value* operator+(const Value* other) const override;
    const ErrorValue* operator-(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const Value* operator*(const Value* other) const override;
    const ErrorValue* operator/(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Comparison
    const Value* operator==(const Value* other) const override;
    const Value* operator!=(const Value* other) const override;
    const ErrorValue* operator<(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator<=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
};

class IdentifierValue : public Value
{
public:
    // Data
    std::string name;
    Value* value;
    const bool isError = false;

    IdentifierValue(const std::string &name) : name(name) { }

    // Arithmetic
    const Value* operator+(const Value* other) const override;
    const Value* operator-(const Value* other) const override;
    const Value* operator*(const Value* other) const override;
    const Value* operator/(const Value* other) const override;
    // Comparison
    const Value* operator==(const Value* other) const override;
    const Value* operator!=(const Value* other) const override;
    const Value* operator<(const Value* other) const override;
    const Value* operator>(const Value* other) const override;
    const Value* operator<=(const Value* other) const override;
    const Value* operator>=(const Value* other) const override;
    // Internal
    void set_value(Value* other);
    const void* get_value() const override;
    const bool get_isError() const override;
};

class OperatorValue : public Value
{
public:
    // Data
    OperationType value;
    const bool isError = false;

    OperatorValue(const OperationType &value) : value(value) { }
    // Arithmetic
    const ErrorValue* operator+(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator-(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator*(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator/(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Comparison
    const ErrorValue* operator==(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator!=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator<(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator<=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator>=(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
};

class ListValue : public Value
{
public:
    //Data
    ValueVec value;
    const bool isError = false;

    ListValue(ValueVec &value) : value(value) { }
    // Arithmetic
    const Value* operator+(const Value* other) const override;
    const ErrorValue* operator-(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator*(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    const ErrorValue* operator/(const Value* other) const override
        {return new ErrorValue("Operator not implemented");};
    // Comparison
    const Value* operator==(const Value* other) const override;
    const Value* operator!=(const Value* other) const override;
    const Value* operator<(const Value* other) const override;
    const Value* operator>(const Value* other) const override;
    const Value* operator<=(const Value* other) const override;
    const Value* operator>=(const Value* other) const override;
    // Internal
    const void* get_value() const override;
    const bool get_isError() const override;
};

#endif