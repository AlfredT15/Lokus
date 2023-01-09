#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "visitor.hpp"
#include "value.hpp"
#include "context.hpp"
#include "enum.hpp"

class VisitorVoid;
class VisitorType;
class Value;
class NStatement;
class NExpression;
class NVariableDeclaration;
class NInteger;

class IntValue;
class DoubleValue;
class IdentifierValue;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;
typedef std::map<std::string, OperationType> TypeMap;



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
	NInteger(const int &value) : value(new IntValue(value)) { }

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

class NList : public NExpression {
public:
	ExpressionList value;
	NList(ExpressionList& value) : value(value) {}

	void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NBool : public NExpression {
public:
	BoolValue* value;
	NBool(const std::string &value) {
		if (value == "true")
		{
			this->value = new BoolValue(true);
		}
		else if (value == "false")
		{
			this->value = new BoolValue(false);
		}		
	 }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NString : public NExpression {
public:
	StringValue* value;
	NString(const std::string &value) : value(new StringValue(value)) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NIdentifier : public NExpression {
public:
	IdentifierValue* value;
	NIdentifier(const std::string &value) : value(new IdentifierValue(value)) { }
	NIdentifier(const std::string &type, const std::string &value) 
			: value(new IdentifierValue(type, value)) { }

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
	{"%", OperationType::MOD_TYPE},
	{"==", OperationType::EE_TYPE},
	{"!=", OperationType::NE_TYPE},
	{">", OperationType::GT_TYPE},
	{"<", OperationType::LT_TYPE},
	{">=", OperationType::GTE_TYPE},
	{"<=", OperationType::LTE_TYPE},
	{"and", OperationType::AND_TYPE},
	{"or", OperationType::OR_TYPE}
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

class NListAssignment : public NExpression {
public:
	NIdentifier& lhs;
	ExpressionList index;
	NExpression& rhs;
	NListAssignment(NIdentifier& lhs, ExpressionList& index, NExpression& rhs) : 
		lhs(lhs), index(index), rhs(rhs) { }

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

class NListAccess : public NExpression{
public:
	NIdentifier& id;
	ExpressionList index;
	NListAccess(NIdentifier& id, ExpressionList& index) : id(id), index(index) { }

	void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NLength : public NExpression{
public:
	NExpression* expr;
	NLength(NExpression* expr) : expr(expr) { }

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
	NExpression *expression;
	NReturnStatement(NExpression *expression) : 
		expression(expression) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NVariableDeclaration : public NStatement {
public:
	NIdentifier& id;
	NExpression *assignmentExpr;
	NVariableDeclaration(NIdentifier& id) :
		 id(id) { assignmentExpr = NULL; }
	NVariableDeclaration(NIdentifier& id, NExpression *assignmentExpr) :
		id(id), assignmentExpr(assignmentExpr) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NExternDeclaration : public NStatement {
public:
    const NIdentifier& id;
    VariableList arguments;
    NExternDeclaration(const NIdentifier& id, const VariableList& arguments) :
        id(id), arguments(arguments) {}

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NFunctionDeclaration : public NStatement {
public:
	const NIdentifier& id;
	VariableList arguments;
	NBlock& block;
	NFunctionDeclaration(const NIdentifier& id, const VariableList& arguments, NBlock& block) :
		id(id), arguments(arguments), block(block) { }

    void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NIfStatement : public NStatement {
public:
	NExpression *condition_expr;
	NBlock& block;
	NStatement* next_if; 
	NIfStatement(NExpression *condition_expr, NBlock& block)
			: condition_expr(condition_expr), block(block), next_if(nullptr) { }
	NIfStatement(NExpression *condition_expr, NBlock& block, NStatement* next_if)
			: condition_expr(condition_expr), block(block), next_if(next_if) { }
	NIfStatement(NBlock& block) : condition_expr(nullptr), block(block), next_if(nullptr) { }

	void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NForStatement : public NStatement{
public:
	NStatement *counter;
	NExpression *condition;
	NExpression *change;
	NBlock& block;

	NForStatement(NStatement *counter, NExpression *condition, NExpression *change, NBlock& block)
				: counter(counter), condition(condition), change(change), block(block) { }
	NForStatement(NExpression *counter, NExpression *condition, NExpression *change, NBlock& block)
				: counter(new NExpressionStatement(*counter)), condition(condition), change(change), block(block) { }

	void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NWhileStatement : public NStatement{
public:
	NExpression *condition;
	NBlock& block;

	NWhileStatement(NExpression *condition, NBlock& block)
				: condition(condition), block(block) { }

	void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

class NPrintStatement : public NStatement{
public:
	NExpression* expr;
	NExpression* ending_expr;
	bool ending = false;
	NPrintStatement(NExpression* expr) : expr(expr) { }
	NPrintStatement(NExpression* expr, NExpression* ending_expr) : expr(expr), ending(true), ending_expr(ending_expr)  { }

	void Accept(const VisitorVoid *visitor) const override;
	const Value* Accept(const VisitorType *visitor, Context *context) const override;
};

#endif