#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <map>
#include "visitor.hpp"
#include "value.hpp"
#include "context.hpp"

class VisitorVoid;
class VisitorType;
class Value;
class NStatement;
class NExpression;
class NVariableDeclaration;

enum DataType;
enum OperationType;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;
typedef std::map<std::string, OperationType> TypeMap;
typedef std::map<std::string, DataType> DMap;


class Node {
public:
	virtual ~Node() {}
    virtual void Accept(const VisitorVoid *visitor) const = 0;
	virtual const Value* Accept(const VisitorType *visitor, Context *context) const = 0;
};

class NExpression : public Node {
};

class NStatement : public Node {   
};

class NInteger : public NExpression {
public:
	IntValue* value;
	NInteger(const int &value) : value(new IntValue(value)) {}

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NDouble : public NExpression {
public:
	DoubleValue* value;
	NDouble(const double &value) : value(new DoubleValue(value)) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NIdentifier : public NExpression {
public:
	IdentifierValue* value;
	NIdentifier(const std::string& value) : value(new IdentifierValue(value)) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NOperator : public NExpression {
private:
	TypeMap opType = {
	{"+", OperationType::ADD_TYPE},
	{"-", OperationType::SUB_TYPE},
	{"*", OperationType::MUL_TYPE},
	{"/", OperationType::DIV_TYPE},
	{"==", OperationType::EE_TYPE},
	{"!=", OperationType::NE_TYPE},
	{">", OperationType::GT_TYPE},
	{"<", OperationType::LT_TYPE},
	{">=", OperationType::GTE_TYPE},
	{"<=", OperationType::LTE_TYPE}
	};
public:
	OperatorValue* value;
	NOperator(const std::string& value) : value(new OperatorValue(opType[value])) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NMethodCall : public NExpression {
public:
	const NIdentifier& id;
	ExpressionList arguments;
	NMethodCall(const NIdentifier& id, ExpressionList& arguments) :
		id(id), arguments(arguments) { }
	NMethodCall(const NIdentifier& id) : id(id) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NBinaryOperator : public NExpression {
public:
	const NOperator& op;
	NExpression& lhs;
	NExpression& rhs;
	NBinaryOperator(NExpression& lhs, const NOperator& op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NAssignment : public NExpression {
public:
	NIdentifier& lhs;
	NExpression& rhs;
	NAssignment(NIdentifier& lhs, NExpression& rhs) : 
		lhs(lhs), rhs(rhs) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NBlock : public NExpression {
public:
	StatementList statements;
	NBlock() { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NExpressionStatement : public NStatement {
public:
	NExpression& expression;
	NExpressionStatement(NExpression& expression) : 
		expression(expression) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NReturnStatement : public NStatement {
public:
	NExpression& expression;
	NReturnStatement(NExpression& expression) : 
		expression(expression) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NVariableDeclaration : public NStatement {
private:
	DMap dTypeMap = {
	{"int", DataType::INT_DTYPE},
	{"float", DataType::FLOAT_DTYPE},
	{"string", DataType::STRING_DTYPE},
	{"char", DataType::CHAR_DTYPE},
	{"bool", DataType::BOOL_DTYPE},
	{"void", DataType::VOID_DTYPE},
	};
public:
	DataType type;
	NIdentifier& id;
	NExpression *assignmentExpr;
	NVariableDeclaration(const std::string& type, NIdentifier& id) :
		type(dTypeMap[type]), id(id) { assignmentExpr = NULL; }
	NVariableDeclaration(const std::string& type, NIdentifier& id, NExpression *assignmentExpr) :
		type(dTypeMap[type]), id(id), assignmentExpr(assignmentExpr) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NExternDeclaration : public NStatement {
private:
	DMap dTypeMap = {
	{"int", DataType::INT_DTYPE},
	{"float", DataType::FLOAT_DTYPE},
	{"string", DataType::STRING_DTYPE},
	{"char", DataType::CHAR_DTYPE},
	{"bool", DataType::BOOL_DTYPE},
	{"void", DataType::VOID_DTYPE},
	};
public:
    const DataType type;
    const NIdentifier& id;
    VariableList arguments;
    NExternDeclaration(const std::string& type, const NIdentifier& id,
            const VariableList& arguments) :
        type(dTypeMap[type]), id(id), arguments(arguments) {}

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NFunctionDeclaration : public NStatement {
private:
	DMap dTypeMap = {
	{"int", DataType::INT_DTYPE},
	{"float", DataType::FLOAT_DTYPE},
	{"string", DataType::STRING_DTYPE},
	{"char", DataType::CHAR_DTYPE},
	{"bool", DataType::BOOL_DTYPE},
	{"void", DataType::VOID_DTYPE},
	};
public:
	const DataType type;
	const NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDeclaration(const std::string& type, const NIdentifier& id, 
			const VariableList& arguments, NBlock& block) :
		type(dTypeMap[type]), id(id), arguments(arguments), block(block) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

#endif