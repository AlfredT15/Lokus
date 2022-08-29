#ifndef VISITOR_H
#define VISITOR_H

#include "node.hpp"
#include "value.hpp"

// node.hpp
class NInteger;
class NDouble;
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

class Visitor
{
    public:
        virtual ~Visitor() {}
};

class VisitorType : public Visitor
{
    public:
        virtual ~VisitorType() {}
        virtual const Value* VisitNInteger(const NInteger *element) const = 0;
        virtual const Value* VisitNDouble(const NDouble *element) const = 0;
        virtual const Value* VisitNIdentifier(const NIdentifier *element) const = 0;
        virtual const Value* VisitNOperator(const NOperator *element) const = 0;
        virtual const Value* VisitNMethodCall(const NMethodCall *element) const = 0;
        virtual const Value* VisitNBinaryOperator(const NBinaryOperator *element) const = 0;
        virtual const Value* VisitNAssignment(const NAssignment *element) const = 0;
        virtual const Value* VisitNBlock(const NBlock *element) const = 0;
        virtual const Value* VisitNExpressionStatement(const NExpressionStatement *element) const = 0;
        virtual const Value* VisitNReturnStatement(const NReturnStatement *element) const = 0;
        virtual const Value* VisitNVariableDeclaration(const NVariableDeclaration *element) const = 0;
        virtual const Value* VisitNExternDeclaration(const NExternDeclaration *element) const = 0;
        virtual const Value* VisitNFunctionDeclaration(const NFunctionDeclaration *element) const = 0;
};

class VisitorVoid : public Visitor
{
    public:
        virtual ~VisitorVoid() {}
        virtual void VisitNInteger(const NInteger *element) const = 0;
        virtual void VisitNDouble(const NDouble *element) const = 0;
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
};

class PrintVisitor: public VisitorVoid
{
    public:
        void VisitNInteger(const NInteger *element) const override;
        void VisitNDouble(const NDouble *element) const override;
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
};

class InterpretVisitor: public VisitorType
{
    public:
        const Value* VisitNInteger(const NInteger *element) const override;
        const Value* VisitNDouble(const NDouble *element) const override;
        const Value* VisitNIdentifier(const NIdentifier *element) const override;
        const Value* VisitNOperator(const NOperator *element) const override;
        const Value* VisitNMethodCall(const NMethodCall *element) const override;
        const Value* VisitNBinaryOperator(const NBinaryOperator *element) const override;
        const Value* VisitNAssignment(const NAssignment *element) const override;
        const Value* VisitNBlock(const NBlock *element) const override;
        const Value* VisitNExpressionStatement(const NExpressionStatement *element) const override;
        const Value* VisitNReturnStatement(const NReturnStatement *element) const override;
        const Value* VisitNVariableDeclaration(const NVariableDeclaration *element) const override;
        const Value* VisitNExternDeclaration(const NExternDeclaration *element) const override;
        const Value* VisitNFunctionDeclaration(const NFunctionDeclaration *element) const override;
};


#endif