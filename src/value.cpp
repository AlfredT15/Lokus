#include <vector>
#include "../include/value.hpp"

typedef std::vector<const Value*> ValueVec;
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ErrorValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

const void* ErrorValue::get_value() const
{
    return &this->value;
}
const bool ErrorValue::get_isError() const
{
    return this->isError;
}
const DataType& ErrorValue::get_type() const
{
    return this->type;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IntValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* IntValue::added_to(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value + *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value + *((double*)other->get_value()));
    }
    return new ErrorValue("'+' is not defined between the two types");
}
const Value* IntValue::subbed_by(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value - *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value - *((double*)other->get_value()));
    }
    return new ErrorValue("'-' is not defined between the two types");
}
const Value* IntValue::multiplied_by(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value * *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value * *((double*)other->get_value()));
    }
    return new ErrorValue("'*' is not defined between the two types");
}
const Value* IntValue::divided_by(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
    {
        return new IntValue(this->value / *((int*)other->get_value()));
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        return new DoubleValue(this->value / *((double*)other->get_value()));
    }
    return new ErrorValue("'/' is not defined between the two types");
}
// Comparison
const Value* IntValue::equal_to(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
        return new BoolValue(this->value == *((int*)other->get_value()));
    return new ErrorValue("'==' is not defined between the two types");
}
const Value* IntValue::not_equal_to(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
        return new BoolValue(this->value != *((int*)other->get_value()));
    return new ErrorValue("'!=' is not defined between the two types");
}
const Value* IntValue::less_than(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
        return new BoolValue(this->value < *((int*)other->get_value()));
    return new ErrorValue("'<' is not defined between the two types");
}
const Value* IntValue::greater_than(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
        return new BoolValue(this->value > *((int*)other->get_value()));
    return new ErrorValue("'>' is not defined between the two types");
}
const Value* IntValue::less_than_or_equal_to(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
        return new BoolValue(this->value <= *((int*)other->get_value()));
    return new ErrorValue("'<=' is not defined between the two types");
}
const Value* IntValue::greater_than_or_equal_to(const Value* other) const
{
    if (dynamic_cast<const IntValue*>(other))
        return new BoolValue(this->value >= *((int*)other->get_value()));
    return new ErrorValue("'>=' is not defined between the two types");
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
const DataType& IntValue::get_type() const
{
    return this->type;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// DoubleValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* DoubleValue::added_to(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new DoubleValue(this->value + *((double*)other->get_value()));
    return new ErrorValue("'+' is not defined between the two types");
}
const Value* DoubleValue::subbed_by(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new DoubleValue(this->value - *((double*)other->get_value()));
    return new ErrorValue("'-' is not defined between the two types");
}
const Value* DoubleValue::multiplied_by(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new DoubleValue(this->value * *((double*)other->get_value()));
    return new ErrorValue("'*' is not defined between the two types");
}
const Value* DoubleValue::divided_by(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new DoubleValue(this->value / *((double*)other->get_value()));
    return new ErrorValue("'/' is not defined between the two types");
}
// Comparison
const Value* DoubleValue::equal_to(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new BoolValue(this->value == *((double*)other->get_value()));
    return new ErrorValue("'==' is not defined between the two types");
}
const Value* DoubleValue::not_equal_to(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new BoolValue(this->value != *((double*)other->get_value()));
    return new ErrorValue("'!=' is not defined between the two types");
}
const Value* DoubleValue::less_than(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new BoolValue(this->value < *((double*)other->get_value()));
    return new ErrorValue("'<' is not defined between the two types");
}
const Value* DoubleValue::greater_than(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new BoolValue(this->value > *((double*)other->get_value()));
    return new ErrorValue("'>' is not defined between the two types");
}
const Value* DoubleValue::less_than_or_equal_to(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new BoolValue(this->value <= *((double*)other->get_value()));
    return new ErrorValue("'<=' is not defined between the two types");
}
const Value* DoubleValue::greater_than_or_equal_to(const Value* other) const
{
    if (dynamic_cast<const DoubleValue*>(other))
        return new BoolValue(this->value >= *((double*)other->get_value()));
    return new ErrorValue("'>=' is not defined between the two types");
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
const DataType& DoubleValue::get_type() const
{
    return this->type;
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// BoolValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

//Comparison
const Value* BoolValue::equal_to(const Value* other) const
{
    if (dynamic_cast<const BoolValue*>(other))
        return new BoolValue(this->value == *((bool*)other->get_value()));
    return new ErrorValue("'==' is not defined between the two types");
}
const Value* BoolValue::not_equal_to(const Value* other) const
{
    if (dynamic_cast<const BoolValue*>(other))
        return new BoolValue(this->value != *((bool*)other->get_value()));
    return new ErrorValue("'!=' is not defined between the two types");
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
const DataType& BoolValue::get_type() const
{
    return this->type;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// StringValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* StringValue::added_to(const Value* other) const
{
    if (dynamic_cast<const StringValue*>(other))
        return new StringValue(this->value + *((std::string*)other->get_value()));
    return new ErrorValue("'+' is not defined between the two types");
}
const Value* StringValue::multiplied_by(const Value* other) const
{
    if (!dynamic_cast<const IntValue*>(other))
        return new ErrorValue("'*' is not defined between the two types");
    if (*((int*)other->get_value()) < 1)
    {
        return new ErrorValue("String multiplication must be done by positive integers");
    }

    std::string temp_val = this->value;
    for (int i = 1; i < *((int*)other->get_value()); i++)
    {
        temp_val += this->value;
    }
    return new StringValue(temp_val);
}
// Comparison
const Value* StringValue::equal_to(const Value* other) const
{
    if (dynamic_cast<const StringValue*>(other))
        return new BoolValue(this->value == *((std::string*)other->get_value()));
    return new ErrorValue("'==' is not defined between the two types");
}
const Value* StringValue::not_equal_to(const Value* other) const
{
    if (dynamic_cast<const StringValue*>(other))
        return new BoolValue(this->value != *((std::string*)other->get_value()));
    return new ErrorValue("'!=' is not defined between the two types");
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
const DataType& StringValue::get_type() const
{
    return this->type;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IdentifierValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Internal
const void* IdentifierValue::get_value() const
{
    return &this->value;
}
const bool IdentifierValue::get_isError() const
{
    return this->isError;
}
const DataType& IdentifierValue::get_type() const
{
    return this->type;
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
const DataType& OperatorValue::get_type() const
{
    return this->type;
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ListValue
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Arithmetic
const Value* ListValue::added_to(const Value* other) const
{
    ValueVec output;
    if (dynamic_cast<const IntValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->added_to(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->added_to(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    else if (dynamic_cast<const StringValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->added_to(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    if (dynamic_cast<const ListValue*>(other))
    {
        if (this->value.size() != (*((ValueVec*)other->get_value())).size())
        {
            return new ErrorValue("Dimension of lists must match for addition");
        }
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->subbed_by((*((ValueVec*)other->get_value()))[i]);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    return new ErrorValue("'+' is not defined between the two types");
}
const Value* ListValue::subbed_by(const Value* other) const
{
    ValueVec output;
    if (dynamic_cast<const IntValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->subbed_by(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->subbed_by(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    if (dynamic_cast<const ListValue*>(other))
    {
        if (this->value.size() != (*((ValueVec*)other->get_value())).size())
        {
            return new ErrorValue("Dimension of lists must match for addition");
        }
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->subbed_by((*((ValueVec*)other->get_value()))[i]);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    return new ErrorValue("'+' is not defined between the two types");
}
const Value* ListValue::multiplied_by(const Value* other) const
{
    ValueVec output;
    if (dynamic_cast<const IntValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->multiplied_by(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->multiplied_by(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    else if (dynamic_cast<const StringValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->multiplied_by(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    if (dynamic_cast<const ListValue*>(other))
    {
        if (this->value.size() != (*((ValueVec*)other->get_value())).size())
        {
            return new ErrorValue("Dimension of lists must match for addition");
        }
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->multiplied_by((*((ValueVec*)other->get_value()))[i]);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    return new ErrorValue("'+' is not defined between the two types");
}
const Value* ListValue::divided_by(const Value* other) const
{
   ValueVec output;
    if (dynamic_cast<const IntValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->divided_by(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    else if (dynamic_cast<const DoubleValue*>(other))
    {
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->divided_by(other);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    if (dynamic_cast<const ListValue*>(other))
    {
        if (this->value.size() != (*((ValueVec*)other->get_value())).size())
        {
            return new ErrorValue("Dimension of lists must match for addition");
        }
        for (int i = 0; i < this->value.size(); i++)
        {
            const Value* temp = this->value[i]->divided_by((*((ValueVec*)other->get_value()))[i]);
            if (temp->get_isError())
                return temp;
            output.push_back(temp);
        }
        return new ListValue(output);
    }
    return new ErrorValue("'+' is not defined between the two types");
}
// Comparison
const Value* ListValue::equal_to(const Value* other) const
{
    ValueVec output;
    if (this->value.size() != (*((ValueVec*)other->get_value())).size())
    {
        return new BoolValue(false);
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->not_equal_to((*((ValueVec*)other->get_value()))[i]);
        if (temp->get_isError())
            return temp;
        if (*((bool*)temp->get_value()))
        {
            return new BoolValue(false);
        }
    }
    return new BoolValue(true);
}
const Value* ListValue::not_equal_to(const Value* other) const
{
    ValueVec output;
    if (this->value.size() != (*((ValueVec*)other->get_value())).size())
    {
        return new BoolValue(true);
    }
    for (int i = 0; i < this->value.size(); i++)
    {
        const Value* temp = this->value[i]->equal_to((*((ValueVec*)other->get_value()))[i]);
        if (temp->get_isError())
            return temp;
        if (!*((bool*)temp->get_value()))
        {
            return new BoolValue(true);
        }
    }
    return new BoolValue(false);
}
// Internal
const void* ListValue::get_value() const
{
    return &this->value;
}
const bool ListValue::get_isError() const
{
    return this->isError;
}
const DataType& ListValue::get_type() const
{
    return this->type;
}