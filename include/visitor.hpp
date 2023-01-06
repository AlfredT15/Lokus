#ifndef VISITOR_H
#define VISITOR_H

#include "node.hpp"
#include "value.hpp"
#include "context.hpp"

// node.hpp
class NInteger;
class NDouble;
class NBool;
class NString;
class NIdentifier;
class NOperator;
class NMethodCall;
class NBinaryOperator;
class NAssignment;
class NBlock;
class NExpressionStatement;
class NReturnStatement;
class NVariableDeclaration;
class NExternDeclaration;
class NFunctionDeclaration;
class NIfStatement;
class NForStatement;
class NWhileStatement;
class NPrintStatement;

class Value;
class Context;

class Visitor
{
    public:
        virtual ~Visitor() {}
};

class VisitorType : public Visitor
{
    public:
        virtual ~VisitorType() {}
        virtual const Value* VisitNInteger(const NInteger *element, Context* context) const = 0;
        virtual const Value* VisitNDouble(const NDouble *element, Context* context) const = 0;
        virtual const Value* VisitNBool(const NBool *element, Context* context) const = 0;
        virtual const Value* VisitNString(const NString *element, Context* context) const = 0;
        virtual const Value* VisitNIdentifier(const NIdentifier *element, Context* context) const = 0;
        virtual const Value* VisitNOperator(const NOperator *element, Context* context) const = 0;
        virtual const Value* VisitNMethodCall(const NMethodCall *element, Context* context) const = 0;
        virtual const Value* VisitNBinaryOperator(const NBinaryOperator *element, Context* context) const = 0;
        virtual const Value* VisitNAssignment(const NAssignment *element, Context* context) const = 0;
        virtual const Value* VisitNBlock(const NBlock *element, Context* context) const = 0;
        virtual const Value* VisitNExpressionStatement(const NExpressionStatement *element, Context* context) const = 0;
        virtual const Value* VisitNReturnStatement(const NReturnStatement *element, Context* context) const = 0;
        virtual const Value* VisitNVariableDeclaration(const NVariableDeclaration *element, Context* context) const = 0;
        virtual const Value* VisitNExternDeclaration(const NExternDeclaration *element, Context* context) const = 0;
        virtual const Value* VisitNFunctionDeclaration(const NFunctionDeclaration *element, Context* context) const = 0;
        virtual const Value* VisitNIfStatement(const NIfStatement *element, Context* context) const = 0;
        virtual const Value* VisitNForStatement(const NForStatement *element, Context* context) const = 0;
        virtual const Value* VisitNWhileStatement(const NWhileStatement *element, Context* context) const = 0;
        virtual const Value* VisitNPrintStatement(const NPrintStatement *element, Context* context) const = 0;
};

class VisitorVoid : public Visitor
{
    public:
        virtual ~VisitorVoid() {}
        virtual void VisitNInteger(const NInteger *element) const = 0;
        virtual void VisitNDouble(const NDouble *element) const = 0;
        virtual void VisitNBool(const NBool *element) const = 0;
        virtual void VisitNString(const NString *element) const = 0;
        virtual void VisitNIdentifier(const NIdentifier *element) const = 0;
        virtual void VisitNOperator(const NOperator *element) const = 0;
        virtual void VisitNMethodCall(const NMethodCall *element) const = 0;
        virtual void VisitNBinaryOperator(const NBinaryOperator *element) const = 0;
        virtual void VisitNAssignment(const NAssignment *element) const = 0;
        virtual void VisitNBlock(const NBlock *element) const = 0;
        virtual void VisitNExpressionStatement(const NExpressionStatement *element) const = 0;
        virtual void VisitNReturnStatement(const NReturnStatement *element) const = 0;
        virtual void VisitNVariableDeclaration(const NVariableDeclaration *element) const = 0;
        virtual void VisitNExternDeclaration(const NExternDeclaration *element) const = 0;
        virtual void VisitNFunctionDeclaration(const NFunctionDeclaration *element) const = 0;
        virtual void VisitNIfStatement(const NIfStatement *element) const = 0;
        virtual void VisitNForStatement(const NForStatement *element) const = 0;
        virtual void VisitNWhileStatement(const NWhileStatement *element) const = 0;
        virtual void VisitNPrintStatement(const NPrintStatement *element) const = 0;
};

class PrintVisitor: public VisitorVoid
{
    public:
        void VisitNInteger(const NInteger *element) const override;
        void VisitNDouble(const NDouble *element) const override;
        void VisitNBool(const NBool *element) const override;
        void VisitNString(const NString *element) const override;
        void VisitNIdentifier(const NIdentifier *element) const override;
        void VisitNOperator(const NOperator *element) const override;
        void VisitNMethodCall(const NMethodCall *element) const override;
        void VisitNBinaryOperator(const NBinaryOperator *element) const override;
        void VisitNAssignment(const NAssignment *element) const override;
        void VisitNBlock(const NBlock *element) const override;
        void VisitNExpressionStatement(const NExpressionStatement *element) const override;
        void VisitNReturnStatement(const NReturnStatement *element) const override;
        void VisitNVariableDeclaration(const NVariableDeclaration *element) const override;
        void VisitNExternDeclaration(const NExternDeclaration *element) const override;
        void VisitNFunctionDeclaration(const NFunctionDeclaration *element) const override;
        void VisitNIfStatement(const NIfStatement *element) const override;
        void VisitNForStatement(const NForStatement *element) const override;
        void VisitNWhileStatement(const NWhileStatement *element) const override;
        void VisitNPrintStatement(const NPrintStatement *element) const override;
};

class InterpretVisitor: public VisitorType
{
    public:
        const Value* VisitNInteger(const NInteger *element, Context* context) const override;
        const Value* VisitNDouble(const NDouble *element, Context* context) const override;
        const Value* VisitNBool(const NBool *element, Context* context) const override;
        const Value* VisitNString(const NString *element, Context* context) const override;
        const Value* VisitNIdentifier(const NIdentifier *element, Context* context) const override;
        const Value* VisitNOperator(const NOperator *element, Context* context) const override;
        const Value* VisitNMethodCall(const NMethodCall *element, Context* context) const override;
        const Value* VisitNBinaryOperator(const NBinaryOperator *element, Context* context) const override;
        const Value* VisitNAssignment(const NAssignment *element, Context* context) const override;
        const Value* VisitNBlock(const NBlock *element, Context* context) const override;
        const Value* VisitNExpressionStatement(const NExpressionStatement *element, Context* context) const override;
        const Value* VisitNReturnStatement(const NReturnStatement *element, Context* context) const override;
        const Value* VisitNVariableDeclaration(const NVariableDeclaration *element, Context* context) const override;
        const Value* VisitNExternDeclaration(const NExternDeclaration *element, Context* context) const override;
        const Value* VisitNFunctionDeclaration(const NFunctionDeclaration *element, Context* context) const override;
        const Value* VisitNIfStatement(const NIfStatement *element, Context* context) const override;
        const Value* VisitNForStatement(const NForStatement *element, Context* context) const override;
        const Value* VisitNWhileStatement(const NWhileStatement *element, Context* context) const override;
        const Value* VisitNPrintStatement(const NPrintStatement *element, Context* context) const override;
};


#endif