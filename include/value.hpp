#ifndef VALUE_H
#define VALUE_H

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
    const Value* added_to(const Value* other) const;
    const Value* subbed_by(const Value* other) const;
    const Value* multiplied_by(const Value* other) const;
    const Value* divided_by(const Value* other) const;
    //Comparison
    const Value* equal_to(const Value* other) const;
    const Value* not_equal_to(const Value* other) const;
    const Value* less_than(const Value* other) const;
    const Value* greater_than(const Value* other) const;
    const Value* less_than_or_equal_to(const Value* other) const;
    const Value* greater_than_or_equal_to(const Value* other) const;
    // Internal
    int get_value() const {return 0;}
    bool get_isError() const {return false;}
};

class ErrorValue : public Value
{
public:
    // Data
    std::string value;
    const bool isError = true;

    ErrorValue(const std::string &value) : value(value) { }

    // Internal
    const std::string& get_value() const;
    const bool& get_isError() const;
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
    // Ints
    const IntValue* added_to(const IntValue* other) const;
    const IntValue* subbed_by(const IntValue* other) const;
    const IntValue* multiplied_by(const IntValue* other) const;
    const IntValue* divided_by(const IntValue* other) const;
    // Doubles
    const DoubleValue* added_to(const DoubleValue* other) const;
    const DoubleValue* subbed_by(const DoubleValue* other) const;
    const DoubleValue* multiplied_by(const DoubleValue* other) const;
    const DoubleValue* divided_by(const DoubleValue* other) const;
    //Comparison
    const BoolValue* equal_to(const IntValue* other) const;
    const BoolValue* not_equal_to(const IntValue* other) const;
    const BoolValue* less_than(const IntValue* other) const;
    const BoolValue* greater_than(const IntValue* other) const;
    const BoolValue* less_than_or_equal_to(const IntValue* other) const;
    const BoolValue* greater_than_or_equal_to(const IntValue* other) const;
    // Internal
    const int& get_value() const;
    const bool& get_isError() const;
};

class DoubleValue : public NumericValue
{
public:
    // Data
    double value;
    const bool isError = false;

    DoubleValue(const double &value) : value(value) { }

    // Arithmetic
    // Doubles
    const DoubleValue* added_to(const DoubleValue* other) const;
    const DoubleValue* subbed_by(const DoubleValue* other) const;
    const DoubleValue* multiplied_by(const DoubleValue* other) const;
    const DoubleValue* divided_by(const DoubleValue* other) const;
    // Ints
    const DoubleValue* added_to(const IntValue* other) const;
    const DoubleValue* subbed_by(const IntValue* other) const;
    const DoubleValue* multiplied_by(const IntValue* other) const;
    const DoubleValue* divided_by(const IntValue* other) const;
    //Comparison
    const BoolValue* equal_to(const DoubleValue* other) const;
    const BoolValue* not_equal_to(const DoubleValue* other) const;
    const BoolValue* less_than(const DoubleValue* other) const;
    const BoolValue* greater_than(const DoubleValue* other) const;
    const BoolValue* less_than_or_equal_to(const DoubleValue* other) const;
    const BoolValue* greater_than_or_equal_to(const DoubleValue* other) const;
    // Internal
    const double& get_value() const;
    const bool& get_isError() const;
};

class BoolValue : public Value
{
public:
    // Data
    bool value;
    const bool isError = false;

    BoolValue(const bool &value) : value(value) { }

    //Comparison
    const BoolValue* equal_to(const BoolValue* other) const;
    const BoolValue* not_equal_to(const BoolValue* other) const;
    // Internal
    const bool& get_value() const;
    const bool& get_isError() const;
};

class StringValue : public Value
{
public:
    // Data
    std::string value;
    const bool isError = false;

    StringValue(const std::string &value) : value(value) { }

    // Arithmetic
    const StringValue* added_to(const StringValue* other) const;
    const Value* multiplied_by(const IntValue* other) const;
    //Comparison
    const BoolValue* equal_to(const StringValue* other) const;
    const BoolValue* not_equal_to(const StringValue* other) const;
    // Internal
    const std::string& get_value() const;
    const bool& get_isError() const;
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
    // String
    const Value* added_to(const StringValue* other) const;
    const Value* multiplied_by(const IntValue* other) const;
    // Int
    const Value* added_to(const NumericValue* other) const;
    const Value* subbed_by(const NumericValue* other) const;
    const Value* multiplied_by(const NumericValue* other) const;
    const Value* divided_by(const NumericValue* other) const;
    //Comparison
    const Value* equal_to(const Value* other) const;
    const Value* not_equal_to(const Value* other) const;
    const Value* less_than(const Value* other) const;
    const Value* greater_than(const Value* other) const;
    const Value* less_than_or_equal_to(const Value* other) const;
    const Value* greater_than_or_equal_to(const Value* other) const;
    // Internal
    void set_value(Value* other);
    const Value* get_value() const;
    const bool& get_isError() const;
};

class OperatorValue : public Value
{
public:
    // Data
    OperationType value;
    const bool isError = false;

    OperatorValue(const OperationType &value) : value(value) { }
    // Internal
    const OperationType& get_value() const;
    const bool& get_isError() const;
};

class ListValue : public Value
{
public:
    //Data
    ValueVec value;
    const bool isError = false;

    ListValue(ValueVec &value) : value(value) { }
    // Arithmetic
    const Value* added_to(const ListValue* other) const;
    const Value* subbed_by(const ListValue* other) const;
    const Value* multiplied_by(const ListValue* other) const;
    const Value* divided_by(const ListValue* other) const;
    // Comparison
    const Value* equal_to(const ListValue* other) const;
    const Value* not_equal_to(const ListValue* other) const;
    // Internal
    const ValueVec& get_value() const;
    const bool& get_isError() const;
};

#endif