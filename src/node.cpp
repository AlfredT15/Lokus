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

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// VisitorType Methods
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
const 
Value* NInteger::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNInteger(this);
};
const Value* NDouble::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNDouble(this);
};
const Value* NIdentifier::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNIdentifier(this);
};
const Value* NOperator::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNOperator(this);
};
const Value* NMethodCall::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNMethodCall(this);
};
const Value* NBinaryOperator::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNBinaryOperator(this);
};
const Value* NAssignment::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNAssignment(this);
};
const Value* NBlock::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNBlock(this);
};
const Value* NExpressionStatement::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNExpressionStatement(this);
};
const Value* NReturnStatement::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNReturnStatement(this);
};
const Value* NVariableDeclaration::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNVariableDeclaration(this);
};
const Value* NExternDeclaration::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNExternDeclaration(this);
};
const Value* NFunctionDeclaration::Accept(const VisitorType *visitor) const
{
    return visitor->VisitNFunctionDeclaration(this);
};