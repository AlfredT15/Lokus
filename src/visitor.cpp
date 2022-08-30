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
    printf("identifier: %s \n", element->value->name.c_str());
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
    element->type.Accept(this);
    element->id.Accept(this);
    element->assignmentExpr->Accept(this);
}
void PrintVisitor::VisitNExternDeclaration(const NExternDeclaration *element) const
{
    element->type.Accept(this);
    element->id.Accept(this);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this);
    }
}
void PrintVisitor::VisitNFunctionDeclaration(const NFunctionDeclaration *element) const
{
    element->type.Accept(this);
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

const Value* InterpretVisitor::VisitNInteger(const NInteger *element) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNDouble(const NDouble *element) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNIdentifier(const NIdentifier *element) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNOperator(const NOperator *element) const
{
    return element->value;
}
const Value* InterpretVisitor::VisitNMethodCall(const NMethodCall *element) const
{
    element->id.Accept(this);
    for (NExpression* expr : element->arguments)
    {
        expr->Accept(this);
    }
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNBinaryOperator(const NBinaryOperator *element) const
{
    const Value* lhs_val = element->lhs.Accept(this);
    int temp = any_cast<int>(lhs_val->get_value());
    const Value* rhs_val = element->rhs.Accept(this);
    const OperatorValue* op_val = dynamic_cast<const OperatorValue*>(element->op.Accept(this));
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
const Value* InterpretVisitor::VisitNAssignment(const NAssignment *element) const
{
    element->lhs.Accept(this);
    printf(" = ");
    element->rhs.Accept(this); 
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNBlock(const NBlock *element) const
{
    ValueVec value;
    for (NStatement* stmnt : element->statements)
    {
        value.push_back(stmnt->Accept(this));
    }
    return new ListValue(value);
}
const Value* InterpretVisitor::VisitNExpressionStatement(const NExpressionStatement *element) const
{
    return element->expression.Accept(this);
}
const Value* InterpretVisitor::VisitNReturnStatement(const NReturnStatement *element) const
{
    element->expression.Accept(this);
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNVariableDeclaration(const NVariableDeclaration *element) const
{
    element->type.Accept(this);
    element->id.Accept(this);
    element->assignmentExpr->Accept(this);
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNExternDeclaration(const NExternDeclaration *element) const
{
    element->type.Accept(this);
    element->id.Accept(this);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this);
    }
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNFunctionDeclaration(const NFunctionDeclaration *element) const
{
    element->type.Accept(this);
    element->id.Accept(this);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this);
    }
    element->block.Accept(this);
    return new ErrorValue("NOT IMPLEMENTED");
}