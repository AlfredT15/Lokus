#include "../include/node.hpp"

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// VisitorVoid Methods
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void NInteger::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNInteger(this);
};
void NDouble::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNDouble(this);
};
void NBool::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNBool(this);
};
void NString::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNString(this);
};
void NIdentifier::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNIdentifier(this);
};
void NOperator::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNOperator(this);
};
void NMethodCall::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNMethodCall(this);
};
void NBinaryOperator::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNBinaryOperator(this);
};
void NAssignment::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNAssignment(this);
};
void NBlock::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNBlock(this);
};
void NExpressionStatement::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNExpressionStatement(this);
};
void NReturnStatement::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNReturnStatement(this);
};
void NVariableDeclaration::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNVariableDeclaration(this);
};
void NExternDeclaration::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNExternDeclaration(this);
};
void NFunctionDeclaration::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNFunctionDeclaration(this);
};
void NIfStatement::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNIfStatement(this);
};
void NForStatement::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNForStatement(this);
};
void NWhileStatement::Accept(const VisitorVoid *visitor) const
{
    visitor->VisitNWhileStatement(this);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// VisitorType Methods
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
const Value* NInteger::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNInteger(this, context);
};
const Value* NDouble::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNDouble(this, context);
};
const Value* NBool::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNBool(this, context);
};
const Value* NString::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNString(this, context);
};
const Value* NIdentifier::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNIdentifier(this, context);
};
const Value* NOperator::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNOperator(this, context);
};
const Value* NMethodCall::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNMethodCall(this, context);
};
const Value* NBinaryOperator::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNBinaryOperator(this, context);
};
const Value* NAssignment::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNAssignment(this, context);
};
const Value* NBlock::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNBlock(this, context);
};
const Value* NExpressionStatement::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNExpressionStatement(this, context);
};
const Value* NReturnStatement::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNReturnStatement(this, context);
};
const Value* NVariableDeclaration::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNVariableDeclaration(this, context);
};
const Value* NExternDeclaration::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNExternDeclaration(this, context);
};
const Value* NFunctionDeclaration::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNFunctionDeclaration(this, context);
};
const Value* NIfStatement::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNIfStatement(this, context);
};
const Value* NForStatement::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNForStatement(this, context);
};
const Value* NWhileStatement::Accept(const VisitorType *visitor, Context *context) const
{
    return visitor->VisitNWhileStatement(this, context);
};