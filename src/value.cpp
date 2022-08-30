#include <vector>
#include "../include/value.hpp"

typedef std::vector<const Value*> ValueVec;

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IntValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* IntValue::operator+(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value + *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value + *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator-(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value - *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value - *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator*(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value * *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value * *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator/(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value / *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value / *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Comparison
const Value* IntValue::operator==(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value == *((int*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator!=(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value != *((int*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator<(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value < *((int*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator>(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value > *((int*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator<=(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value <= *((int*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator>=(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value >= *((int*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Internal
const void* IntValue::get_value() const
{
    return &this->value;
}
const bool IntValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// DoubleValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* DoubleValue::operator+(const Value* other) const
{
    if (dynamic_cast<const NumericValue*>(other))
    {
        return new DoubleValue(this->value + *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator-(const Value* other) const
{
    if (dynamic_cast<const NumericValue*>(other))
    {
        return new DoubleValue(this->value - *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator*(const Value* other) const
{
    if (dynamic_cast<const NumericValue*>(other))
    {
        return new DoubleValue(this->value * *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator/(const Value* other) const
{
    if (dynamic_cast<const NumericValue*>(other))
    {
        return new DoubleValue(this->value / *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Comparison
const Value* DoubleValue::operator==(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
    {
        return new BoolValue(this->value == *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator!=(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
    {
        return new BoolValue(this->value != *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator<(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
    {
        return new BoolValue(this->value < *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator>(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
    {
        return new BoolValue(this->value > *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator<=(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
    {
        return new BoolValue(this->value <= *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* DoubleValue::operator>=(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
    {
        return new BoolValue(this->value >= *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Internal
const void* DoubleValue::get_value() const
{
    return &this->value;
}
const bool DoubleValue::get_isError() const
{
    return this->isError;
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// BoolValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

//Comparison
const Value* BoolValue::operator==(const Value* other) const
{
    if (dynamic_cast<const BoolValue*>(other))
    {
        return new BoolValue(this->value == any_cast<bool>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* BoolValue::operator!=(const Value* other) const
{
    if (dynamic_cast<const BoolValue*>(other))
    {
        return new BoolValue(this->value != any_cast<bool>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Internal
const void* BoolValue::get_value() const
{
    return &this->value;
}
const bool BoolValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// StringValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* StringValue::operator+(const Value* other) const
{
    if (dynamic_cast<const StringValue*>(other))
    {
        return new StringValue(this->value + any_cast<std::string>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* StringValue::operator*(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        std::string val = this->value;
        for (int i = 0; i < *((int*)other->get_value()); i++)
        {
            val += this->value;
        }
        return new StringValue(val);
    }
    return new ErrorValue("Operation not implemented");
}
// Comparison
const Value* StringValue::operator==(const Value* other) const
{
    if (dynamic_cast<const StringValue*>(other))
    {
        return new BoolValue(this->value == any_cast<std::string>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* StringValue::operator!=(const Value* other) const
{
    if (dynamic_cast<const StringValue*>(other))
    {
        return new BoolValue(this->value != any_cast<std::string>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Internal
const void* StringValue::get_value() const
{
    return &this->value;
}
const bool StringValue::get_isError() const
{
    return this->isError;
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IdentifierValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* IdentifierValue::operator+(const Value* other) const
{
    if (dynamic_cast<const IdentifierValue*>(other))
    {
        Value* temp = (Value*)other->get_value();
        return this->valuetemp;
    }
}
const Value* IntValue::operator-(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value - *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value - *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator*(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value * any_cast<int>(other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value * *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator/(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value / any_cast<int>(other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value / *((double*)other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Comparison
const Value* IntValue::operator==(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value == any_cast<int>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator!=(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value != any_cast<int>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator<(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value < any_cast<int>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator>(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value > any_cast<int>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator<=(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value <= any_cast<int>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
const Value* IntValue::operator>=(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new BoolValue(this->value >= any_cast<int>(other->get_value()));
    }
    return new ErrorValue("Operation not implemented");
}
// Internal
void IdentifierValue::set_value(Value* other)
{
    this->value = other;
}
const void* IdentifierValue::get_value() const
{
    return &this->value;
}
const bool IdentifierValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// OperatorValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Internal
const void* OperatorValue::get_value() const
{
    return &this->value;
}
const bool OperatorValue::get_isError() const
{
    return this->isError;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ListValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic

// Comparison

// Internal
const void* ListValue::get_value() const
{
    return &this->value;
}
const bool ListValue::get_isError() const
{
    return this->isError;
}
