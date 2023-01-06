#include <gtest/gtest.h>
#include <math.h>
#include <string>
#include <tuple>
#include <vector>

#include "gmock/gmock.h"
#include "../include/value.hpp"
#include "../include/enum.hpp"
#include "../include/node.hpp"
#include "matchers.h"

using ::testing::ElementsAre;
using ::testing::Pointee;
using ::testing::Eq;
using ::testing::IsTrue;
using ::testing::IsFalse;
using ::testing::IsNull;
using ::testing::ContainerEq;
using ::testing::ElementsAre;


// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ErrorValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, error_check)
{
    auto error_val = new ErrorValue("Error");
    ASSERT_THAT((std::string*)error_val->get_value(), Pointee(Eq(std::string("Error"))));
};

TEST(value_construction, error_isError_check)
{
    auto error_val = new ErrorValue("Error");
    ASSERT_THAT(error_val->get_isError(), IsTrue());
};

TEST(value_construction, error_type_check)
{
    ErrorValue* error_val = new ErrorValue("Error");
    ASSERT_THAT(error_val->get_type(), Eq(DataType::ERROR_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// VoidValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, void_check)
{
    VoidValue* void_val = new VoidValue();
    ASSERT_THAT(void_val->get_value(), IsNull());
};

TEST(value_construction, void_isError_check)
{
    VoidValue* void_val = new VoidValue();
    ASSERT_THAT(void_val->get_isError(), IsFalse());
};

TEST(value_construction, void_type_check)
{
    VoidValue* void_val = new VoidValue();
    ASSERT_THAT(void_val->get_type(), Eq(DataType::VOID_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IntValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, int_check)
{
    IntValue* int_val = new IntValue(5);
    ASSERT_THAT((int*)int_val->get_value(), Pointee(Eq(5)));
};

TEST(value_construction, int_isError_check)
{
    IntValue* int_val = new IntValue(0);
    ASSERT_THAT(int_val->get_isError(), IsFalse());
};

TEST(value_construction, int_type_check)
{
    IntValue* int_val = new IntValue(0);
    ASSERT_THAT(int_val->get_type(), Eq(DataType::INT_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// DoubleValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, double_check_int)
{
    DoubleValue* double_val = new DoubleValue(5);
    ASSERT_THAT((double*)double_val->get_value(), Pointee(Eq(5)));
};

TEST(value_construction, double_check_double)
{
    DoubleValue* double_val = new DoubleValue(5.67);
    ASSERT_THAT((double*)double_val->get_value(), Pointee(Eq(5.67)));
};

TEST(value_construction, double_check_pi)
{
    DoubleValue* double_val = new DoubleValue(M_PI);
    ASSERT_THAT((double*)double_val->get_value(), Pointee(Eq(M_PI)));
};

TEST(value_construction, double_isError_check)
{
    DoubleValue* double_val = new DoubleValue(0);
    ASSERT_THAT(double_val->get_isError(), IsFalse());
};

TEST(value_construction, double_type_check)
{
    DoubleValue* double_val = new DoubleValue(0);
    ASSERT_THAT(double_val->get_type(), Eq(DataType::FLOAT_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// BoolValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, bool_check)
{
    BoolValue* bool_val = new BoolValue(true);
    ASSERT_THAT((bool*)bool_val->get_value(), Pointee(Eq(true)));
};

TEST(value_construction, bool_isError_check)
{
    BoolValue* bool_val = new BoolValue(true);
     ASSERT_THAT(bool_val->get_isError(), IsFalse());
};

TEST(value_construction, bool_type_check)
{
    BoolValue* bool_val = new BoolValue(true);
    ASSERT_THAT(bool_val->get_type(), Eq(DataType::BOOL_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// StringValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, string_check)
{
    StringValue* str_val = new StringValue("test");
    ASSERT_THAT((std::string*)str_val->get_value(), Pointee(Eq("test")));
};

TEST(value_construction, string_isError_check)
{
    StringValue* str_val = new StringValue("test");
    ASSERT_THAT(str_val->get_isError(), IsFalse());
};

TEST(value_construction, string_type_check)
{
    StringValue* str_val = new StringValue("test");
    ASSERT_THAT(str_val->get_type(), Eq(DataType::STRING_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IdentifierValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, identifier_check)
{
    IdentifierValue* identifier_val = new IdentifierValue("test");
    ASSERT_THAT((std::string*)identifier_val->get_value(), Pointee(Eq("test")));
    ASSERT_THAT(identifier_val->get_type(), Eq(DataType::TNI));
};

TEST(value_construction, identifier_isError_check)
{
    IdentifierValue* identifier_val = new IdentifierValue("test");
    ASSERT_THAT(identifier_val->get_isError(), IsFalse());
};

TEST(value_construction, identifier_type_check)
{
    IdentifierValue* identifier_val = new IdentifierValue("int", "test");
    ASSERT_THAT(identifier_val->get_type(), Eq(DataType::INT_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// OperatorValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, operator_check)
{
    OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    ASSERT_THAT((OperationType*)operator_val->get_value(), Pointee(Eq(OperationType::ADD_TYPE)));
};

TEST(value_construction, operator_isError_check)
{
    OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    ASSERT_THAT(operator_val->get_isError(), IsFalse());
};

TEST(value_construction, operator_type_check)
{
    OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    ASSERT_THAT(operator_val->get_type(), Eq(DataType::VOID_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ListValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, list_check)
{
    ValueVec val_vec = {new IntValue(1), new IntValue(2), new IntValue(3)};
    ListValue* list_val = new ListValue(val_vec);
    ASSERT_THAT(((ValueVec*)list_val->get_value())->size(), Eq(3));
    ASSERT_THAT((ValueVec*)list_val->get_value(), IntValueVecMatcher(ValueVec{new IntValue(1), new IntValue(2), new IntValue(3)}));
};

TEST(value_construction, list_isError_check)
{
    ValueVec val_vec;
    ListValue* list_val = new ListValue(val_vec);
    ASSERT_THAT(list_val->get_isError(), IsFalse());
};

TEST(value_construction, list_type_check)
{
    ValueVec val_vec;
    ListValue* list_val = new ListValue(val_vec);
    ASSERT_THAT(list_val->get_type(), Eq(DataType::LIST_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// FunctionValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, function_construction)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    ValueVec arg_values;
    IdentifierValue* arg1 = new IdentifierValue("int", "test1");
    IdentifierValue* arg2 = new IdentifierValue("bool", "test2");
    IdentifierValue* arg3 = new IdentifierValue("float", "test3");
    arg_values.push_back(arg1);
    arg_values.push_back(arg2);
    arg_values.push_back(arg3);

    Context* context = new Context();
    NBlock* body = new NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NExpression* assign = new NAssignment(*var, *binOp);

    NExpression* iden = new NIdentifier("test1");
    NExpression* returnBinOp = new NBinaryOperator(*var, *op, *iden);
    NStatement* returnState = new NReturnStatement(returnBinOp);

    NStatement* expState = new NExpressionStatement(*assign);

    body->statements.push_back(expState);
    body->statements.push_back(returnState);

    context->set_value(arg1, new IntValue(1));
    context->set_value(arg2, new BoolValue(true));
    context->set_value(arg3, new DoubleValue(1.5));

    Context* func_context = new Context(context);

    FunctionValue* function_val = new FunctionValue(&arg_values, func_context, *body, DataType::INT_DTYPE);
    ASSERT_THAT((int*)((IntValue*)function_val->block.Accept(visitor, function_val->function_context))->get_value(), Pointee(Eq(4)));
};

TEST(value_construction, function_isError_check)
{
    ValueVec arg_values;
    arg_values.push_back(new IdentifierValue("int", "test1"));
    arg_values.push_back(new IdentifierValue("bool", "test2"));
    arg_values.push_back(new IdentifierValue("float", "test3"));

    Context* context = new Context();
    NBlock* body = new NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NExpression* assign = new NAssignment(*var, *binOp);

    NExpression* iden = new NIdentifier("test1");
    NExpression* returnBinOp = new NBinaryOperator(*var, *op, *iden);
    NStatement* returnState = new NReturnStatement(returnBinOp);

    NStatement* expState = new NExpressionStatement(*assign);

    body->statements.push_back(expState);
    body->statements.push_back(returnState);
    FunctionValue* function_val = new FunctionValue(&arg_values, context, *body, DataType::INT_DTYPE);
    ASSERT_THAT(function_val->get_isError(), IsFalse());
};

TEST(value_construction, function_type_check)
{
    ValueVec arg_values;
    arg_values.push_back(new IdentifierValue("int", "test1"));
    arg_values.push_back(new IdentifierValue("bool", "test2"));
    arg_values.push_back(new IdentifierValue("float", "test3"));

    Context* context = new Context();
    NBlock* body = new NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NExpression* assign = new NAssignment(*var, *binOp);

    NExpression* iden = new NIdentifier("test1");
    NExpression* returnBinOp = new NBinaryOperator(*var, *op, *iden);
    NStatement* returnState = new NReturnStatement(returnBinOp);

    NStatement* expState = new NExpressionStatement(*assign);

    body->statements.push_back(expState);
    body->statements.push_back(returnState);
    FunctionValue* function_val = new FunctionValue(&arg_values, context, *body, DataType::INT_DTYPE);
    ASSERT_THAT(function_val->get_type(), Eq(DataType::INT_DTYPE));
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ReturnValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, return_check)
{
    ReturnValue* retValue = new ReturnValue(new IntValue(1));
    Value* val = (Value*)retValue->get_value();
    ASSERT_THAT((int*)val->get_value(), Pointee(Eq(1)));
};

TEST(value_construction, return_isError_check)
{
    ReturnValue* retValue = new ReturnValue(new IntValue(1));
    ASSERT_THAT(retValue->get_isError(), IsFalse());
};

TEST(value_construction, return_type_check)
{
    ReturnValue* retValue = new ReturnValue(new IntValue(1));
    ASSERT_THAT(retValue->get_type(), Eq(DataType::INT_DTYPE));
};