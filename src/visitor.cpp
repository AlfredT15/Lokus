#include <cstdio>
#include "../include/visitor.hpp"
#include "../include/value.hpp"

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// PrintVisitor
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void PrintVisitor::VisitNInteger(const NInteger *element) const
{
    printf("int: %d \n", element->value->value);
}
void PrintVisitor::VisitNDouble(const NDouble *element) const
{
    printf("float: %f \n", element->value->value);
}
void PrintVisitor::VisitNIdentifier(const NIdentifier *element) const
{
    printf("identifier: %s \n", element->value->value.c_str());
}
void PrintVisitor::VisitNOperator(const NOperator *element) const
{
    printf("operation: %d \n", element->value->value);
}
void PrintVisitor::VisitNMethodCall(const NMethodCall *element) const
{
    element->id.Accept(this);
    for (NExpression* expr : element->arguments)
    {
        expr->Accept(this);
    }
}
void PrintVisitor::VisitNBinaryOperator(const NBinaryOperator *element) const
{
    element->lhs.Accept(this);
    element->op.Accept(this);
    element->rhs.Accept(this);   
}
void PrintVisitor::VisitNAssignment(const NAssignment *element) const
{
    element->lhs.Accept(this);
    printf(" = ");
    element->rhs.Accept(this); 
}
void PrintVisitor::VisitNBlock(const NBlock *element) const
{
    for (NStatement* stmnt : element->statements)
    {
        stmnt->Accept(this);
    }
}
void PrintVisitor::VisitNExpressionStatement(const NExpressionStatement *element) const
{
    element->expression.Accept(this);
}
void PrintVisitor::VisitNReturnStatement(const NReturnStatement *element) const
{
    element->expression.Accept(this);
}
void PrintVisitor::VisitNVariableDeclaration(const NVariableDeclaration *element) const
{
    element->id.Accept(this);
    element->assignmentExpr->Accept(this);
}
void PrintVisitor::VisitNExternDeclaration(const NExternDeclaration *element) const
{
    element->id.Accept(this);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this);
    }
}
void PrintVisitor::VisitNFunctionDeclaration(const NFunctionDeclaration *element) const
{
    element->id.Accept(this);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this);
    }
    element->block.Accept(this);
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// InterpretVisitor
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

const Value* InterpretVisitor::VisitNInteger(const NInteger *element, Context* context) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNDouble(const NDouble *element, Context* context) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNIdentifier(const NIdentifier *element, Context* context) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNOperator(const NOperator *element, Context* context) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNMethodCall(const NMethodCall *element, Context* context) const
{
    element->id.Accept(this, context);
    for (NExpression* expr : element->arguments)
    {
        expr->Accept(this, context);
    }
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNBinaryOperator(const NBinaryOperator *element, Context* context) const
{
    const Value* lhs_val = element->lhs.Accept(this, context);
    const Value* rhs_val = element->rhs.Accept(this, context);
    const OperatorValue* op_val = dynamic_cast<const OperatorValue*>(element->op.Accept(this, context));

    const IdentifierValue* lhs_id = dynamic_cast<const IdentifierValue*>(lhs_val);
    const IdentifierValue* rhs_id = dynamic_cast<const IdentifierValue*>(rhs_val);
    if (lhs_id)
        lhs_val = context->find_value(lhs_id->value);
    if (rhs_id)
        rhs_val = context->find_value(rhs_id->value);

    switch (op_val->value)
    {
    case OperationType::ADD_TYPE:
        return lhs_val->added_to(rhs_val);
    case OperationType::SUB_TYPE:
        return lhs_val->subbed_by(rhs_val);
    case OperationType::MUL_TYPE:
        return lhs_val->multiplied_by(rhs_val);
    case OperationType::DIV_TYPE:
        return lhs_val->divided_by(rhs_val);
    case OperationType::EE_TYPE:
        return lhs_val->equal_to(rhs_val);
    case OperationType::NE_TYPE:
        return lhs_val->not_equal_to(rhs_val);
    case OperationType::LT_TYPE:
        return lhs_val->less_than(rhs_val);
    case OperationType::GT_TYPE:
        return lhs_val->greater_than(rhs_val);
    case OperationType::LTE_TYPE:
        return lhs_val->less_than_or_equal_to(rhs_val);
    case OperationType::GTE_TYPE:
        return lhs_val->greater_than_or_equal_to(rhs_val);
    }   
}
const Value* InterpretVisitor::VisitNAssignment(const NAssignment *element, Context* context) const
{
    const IdentifierValue* lhs_val = dynamic_cast<const IdentifierValue*>
                                        (element->lhs.Accept(this, context));
    const Value* rhs_val = element->rhs.Accept(this, context);
    if (rhs_val->get_isError())
        return rhs_val;
    const bool variable_set = context->set_value(lhs_val, rhs_val);
    if (!variable_set)
        return new ErrorValue(lhs_val->value + " does not exist in this scope");
    return lhs_val;
}
const Value* InterpretVisitor::VisitNBlock(const NBlock *element, Context* context) const
{
    ValueVec value;
    Context* new_context = new Context(context);
    for (NStatement* stmnt : element->statements)
    {
        value.push_back(stmnt->Accept(this, new_context));
    }
    return new ListValue(value);
}
const Value* InterpretVisitor::VisitNExpressionStatement(const NExpressionStatement *element, Context* context) const
{
    return element->expression.Accept(this, context);
}
const Value* InterpretVisitor::VisitNReturnStatement(const NReturnStatement *element, Context* context) const
{
    element->expression.Accept(this, context);
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNVariableDeclaration(const NVariableDeclaration *element, Context* context) const
{
    const IdentifierValue* id = dynamic_cast<const IdentifierValue*>(element->id.Accept(this, context));
    const Value* val;
    if (element->assignmentExpr)
    {
        val = element->assignmentExpr->Accept(this, context);
        const IdentifierValue* id2 = dynamic_cast<const IdentifierValue*>(val);
        if (id2)
        {
            val = context->find_value(id2->value);
            if (val->get_isError())
                return val;
        }
        if (!(element->type == val->get_type()))
            return new ErrorValue("Incompatible types");
    }
    const bool variable_set = context->set_value(id, val);
    if (!variable_set)
        return new ErrorValue("Error initializing " + id->value);
    return id;
}
const Value* InterpretVisitor::VisitNExternDeclaration(const NExternDeclaration *element, Context* context) const
{
    element->id.Accept(this, context);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this, context);
    }
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNFunctionDeclaration(const NFunctionDeclaration *element, Context* context) const
{
    const IdentifierValue* id = dynamic_cast<const IdentifierValue*>(element->id.Accept(this, context));
    ValueVec arg_values;
    for (NVariableDeclaration* dec : element->arguments)
    {
        arg_values.push_back(dec->Accept(this, context));
    }
    element->block.Accept(this, context);
    return new ErrorValue("NOT IMPLEMENTED");
}