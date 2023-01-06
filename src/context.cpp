#include "../include/context.hpp"

const Value* Context::find_value(const std::string& name)
{
    if (this->sym_table.find(name) == this->sym_table.end())
    {
        if (this->parent)
            return this->parent->find_value(name);
        else
            return new ErrorValue(name + " was not declared in this scope");
    }
    return this->sym_table[name];
}

bool Context::set_value(const IdentifierValue* ident_val, const Value* val)
{
    if (this->parent)
    {
        bool result = this->parent->set_value(ident_val, val);
        if (result)
            return result;
    }
    else if (this->sym_table.find(ident_val->value) == this->sym_table.end())
    {
        this->sym_table[ident_val->value] = val;
        return true;
    }
    else if (this->sym_table[ident_val->value]->get_type() == val->get_type())
    {
        this->sym_table[ident_val->value] = val;
        return true;
    }
    return false;
}