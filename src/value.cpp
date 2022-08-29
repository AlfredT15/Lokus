#include <vector>
#include "../include/value.hpp"

typedef std::vector<const Value*> ValueVec;

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Value
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* Value::added_to(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::subbed_by(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::multiplied_by(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::divided_by(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
// Comparison
const Value* Value::equal_to(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::not_equal_to(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::less_than(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::greater_than(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::less_than_or_equal_to(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
const Value* Value::greater_than_or_equal_to(const Value* other) const
{
    return new ErrorValue("Illegal operation");
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IntValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
// Ints
const IntValue* IntValue::added_to(const IntValue* other) const
{
    return new IntValue(this->value + other->value);
}
const IntValue* IntValue::subbed_by(const IntValue* other) const
{
    return new IntValue(this->value - other->value);
}
const IntValue* IntValue::multiplied_by(const IntValue* other) const
{
    return new IntValue(this->value * other->value);
}
const IntValue* IntValue::divided_by(const IntValue* other) const
{
    return new IntValue(this->value / other->value);
}
// Doubles
const DoubleValue* IntValue::added_to(const DoubleValue* other) const
{
    return new DoubleValue(this->value + other->value);
}
const DoubleValue* IntValue::subbed_by(const DoubleValue* other) const
{
    return new DoubleValue(this->value - other->value);
}
const DoubleValue* IntValue::multiplied_by(const DoubleValue* other) const
{
    return new DoubleValue(this->value * other->value);
}
const DoubleValue* IntValue::divided_by(const DoubleValue* other) const
{
    return new DoubleValue(this->value / other->value);
}
// Comparison
const BoolValue* IntValue::equal_to(const IntValue* other) const
{
    return new BoolValue(this->value == other->value);
}
const BoolValue* IntValue::not_equal_to(const IntValue* other) const
{
    return new BoolValue(this->value != other->value);
}
const BoolValue* IntValue::less_than(const IntValue* other) const
{
    return new BoolValue(this->value < other->value);
}
const BoolValue* IntValue::greater_than(const IntValue* other) const
{
    return new BoolValue(this->value > other->value);
}
const BoolValue* IntValue::less_than_or_equal_to(const IntValue* other) const
{
    return new BoolValue(this->value <= other->value);
}
const BoolValue* IntValue::greater_than_or_equal_to(const IntValue* other) const
{
    return new BoolValue(this->value >= other->value);
}
// Internal
const int& IntValue::get_value() const
{
    return this->value;
}
const bool& IntValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// DoubleValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
// Doubles
const DoubleValue* DoubleValue::added_to(const DoubleValue* other) const
{
    return new DoubleValue(this->value + other->value);
}
const DoubleValue* DoubleValue::subbed_by(const DoubleValue* other) const
{
    return new DoubleValue(this->value - other->value);
}
const DoubleValue* DoubleValue::multiplied_by(const DoubleValue* other) const
{
    return new DoubleValue(this->value * other->value);
}
const DoubleValue* DoubleValue::divided_by(const DoubleValue* other) const
{
    return new DoubleValue(this->value / other->value);
}
// Ints
const DoubleValue* DoubleValue::added_to(const IntValue* other) const
{
    return new DoubleValue(this->value + other->value);
}
const DoubleValue* DoubleValue::subbed_by(const IntValue* other) const
{
    return new DoubleValue(this->value - other->value);
}
const DoubleValue* DoubleValue::multiplied_by(const IntValue* other) const
{
    return new DoubleValue(this->value * other->value);
}
const DoubleValue* DoubleValue::divided_by(const IntValue* other) const
{
    return new DoubleValue(this->value / other->value);
}
// Comparison
const BoolValue* DoubleValue::equal_to(const DoubleValue* other) const
{
    return new BoolValue(this->value == other->value);
}
const BoolValue* DoubleValue::not_equal_to(const DoubleValue* other) const
{
    return new BoolValue(this->value != other->value);
}
const BoolValue* DoubleValue::less_than(const DoubleValue* other) const
{
    return new BoolValue(this->value < other->value);
}
const BoolValue* DoubleValue::greater_than(const DoubleValue* other) const
{
    return new BoolValue(this->value > other->value);
}
const BoolValue* DoubleValue::less_than_or_equal_to(const DoubleValue* other) const
{
    return new BoolValue(this->value <= other->value);
}
const BoolValue* DoubleValue::greater_than_or_equal_to(const DoubleValue* other) const
{
    return new BoolValue(this->value >= other->value);
}
// Internal
const double& DoubleValue::get_value() const
{
    return this->value;
}
const bool& DoubleValue::get_isError() const
{
    return this->isError;
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// BoolValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

//Comparison
const BoolValue* BoolValue::equal_to(const BoolValue* other) const
{
    return new BoolValue(this->value == other->value);
}
const BoolValue* BoolValue::not_equal_to(const BoolValue* other) const
{
    return new BoolValue(this->value != other->value);
}
// Internal
const bool& BoolValue::get_value() const
{
    return this->value;
}
const bool& BoolValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// StringValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const StringValue* StringValue::added_to(const StringValue* other) const
{
    return new StringValue(this->value + other->value);
}
const Value* StringValue::multiplied_by(const IntValue* other) const
{
    if (other->value < 1)
    {
        return new ErrorValue("String multiplication must be done by positive integers");
    }

    std::string temp_val = this->value;
    for (int i = 1; i < other->value; i++)
    {
        temp_val += this->value;
    }
    return new StringValue(temp_val);
}
// Comparison
const BoolValue* StringValue::equal_to(const StringValue* other) const
{
    return new BoolValue(this->value == other->value);
}
const BoolValue* StringValue::not_equal_to(const StringValue* other) const
{
    return new BoolValue(this->value != other->value);
}
// Internal
const std::string& StringValue::get_value() const
{
    return this->value;
}
const bool& StringValue::get_isError() const
{
    return this->isError;
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IdentifierValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
// String
const Value* IdentifierValue::added_to(const StringValue* other) const
{
    return this->value->added_to(other);
}
const Value* IdentifierValue::multiplied_by(const IntValue* other) const
{
    return this->value->multiplied_by(other);
}
// Numeric
const Value* IdentifierValue::added_to(const NumericValue* other) const
{
    return this->value->added_to(other);
}
const Value* IdentifierValue::subbed_by(const NumericValue* other) const
{
    return this->value->subbed_by(other);
}
const Value* IdentifierValue::multiplied_by(const NumericValue* other) const
{
    return this->value->multiplied_by(other);
}
const Value* IdentifierValue::divided_by(const NumericValue* other) const
{
    return this->value->divided_by(other);
}
// Comparison
const Value* IdentifierValue::equal_to(const Value* other) const
{
    return this->value->equal_to(other);
}
const Value* IdentifierValue::not_equal_to(const Value* other) const
{
    return this->value->not_equal_to(other);
}
const Value* IdentifierValue::less_than(const Value* other) const
{
    return this->value->less_than(other);
}
const Value* IdentifierValue::greater_than(const Value* other) const
{
    return this->value->greater_than(other);
}
const Value* IdentifierValue::less_than_or_equal_to(const Value* other) const
{
    return this->value->less_than_or_equal_to(other);
}
const Value* IdentifierValue::greater_than_or_equal_to(const Value* other) const
{
    return this->value->greater_than_or_equal_to(other);
}
// Internal
void IdentifierValue::set_value(Value* other)
{
    this->value = other;
}
const Value* IdentifierValue::get_value() const
{
    return this->value;
}
const bool& IdentifierValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// OperatorValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Internal
const OperationType& OperatorValue::get_value() const
{
    return this->value;
}
const bool& OperatorValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ListValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* ListValue::added_to(const ListValue* other) const
{
    ValueVec output;
    if (this->value.size() != other->value.size())
    {
        return new ErrorValue("Dimension of lists must match for addition");
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->subbed_by(other->value[i]);
        if (temp->get_isError())
            return temp;
        output.push_back(temp);
    }
    return new ListValue(output);
}
const Value* ListValue::subbed_by(const ListValue* other) const
{
    ValueVec output;
    if (this->value.size() != other->value.size())
    {
        return new ErrorValue("Dimension of lists must match for subtraction");
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->subbed_by(other->value[i]);
        if (temp->get_isError())
            return temp;
        output.push_back(temp);
    }
    return new ListValue(output);
}
const Value* ListValue::multiplied_by(const ListValue* other) const
{
    ValueVec output;
    if (this->value.size() != other->value.size())
    {
        return new ErrorValue("Dimension of lists must match for multiplication");
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->subbed_by(other->value[i]);
        if (temp->get_isError())
            return temp;
        output.push_back(temp);
    }
    return new ListValue(output);
}
const Value* ListValue::divided_by(const ListValue* other) const
{
    ValueVec output;
    if (this->value.size() != other->value.size())
    {
        return new ErrorValue("Dimension of lists must match for division");
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->subbed_by(other->value[i]);
        if (temp->get_isError())
            return temp;
        output.push_back(temp);
    }
    return new ListValue(output);
}
// Comparison
const Value* ListValue::equal_to(const ListValue* other) const
{
    ValueVec output;
    if (this->value.size() != other->value.size())
    {
        return new BoolValue(false);
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->not_equal_to(other->value[i]);
        if (temp->get_isError())
            return temp;
        if (temp->get_value())
        {
            return new BoolValue(false);
        }
    }
    return new BoolValue(true);
}
const Value* ListValue::not_equal_to(const ListValue* other) const
{
    ValueVec output;
    if (this->value.size() != other->value.size())
    {
        return new BoolValue(true);
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->equal_to(other->value[i]);
        if (temp->get_isError())
            return temp;
        if (!temp->get_value())
        {
            return new BoolValue(true);
        }
    }
    return new BoolValue(false);
}
// Internal
const ValueVec& ListValue::get_value() const
{
    return this->value;
}
const bool& ListValue::get_isError() const
{
    return this->isError;
}
