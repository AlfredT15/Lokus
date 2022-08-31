#ifndef CONTEXT_H
#define CONTEXT_H

#include <map>
#include "value.hpp"

typedef std::map<const std::string, const Value*> SymbolTable;

class Context
{
    public:
        Context* parent;
        SymbolTable sym_table;
        Context() : parent(nullptr) {}
        Context(Context* parent) : parent(parent) {}

        const Value* find_value(const std::string& name);
        bool set_value(const IdentifierValue* ident_val, const Value* val);
};

#endif