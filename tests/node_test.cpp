#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <string>


#include "../include/value.hpp"
#include "../include/node.hpp"
#include "matchers.h"

using ::testing::Pointee;
using ::testing::Eq;
using ::testing::IsTrue;
using ::testing::IsFalse;
using ::testing::IsNull;


// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NInteger Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, int_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NInteger* node = new NInteger(1);

    ASSERT_THAT((int*)node->Accept(visitor, context)->get_value(), Pointee(Eq(1)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NDouble Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, double_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NDouble* node = new NDouble(1);

    ASSERT_THAT((double*)node->Accept(visitor, context)->get_value(), Pointee(Eq(1)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NBool Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, bool_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NBool* node = new NBool("true");

    ASSERT_THAT((bool*)node->Accept(visitor, context)->get_value(), Pointee(Eq(true)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NString Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, string_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NString* node = new NString("test");

    ASSERT_THAT((std::string*)node->Accept(visitor, context)->get_value(), Pointee(Eq("test")));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NIdentifier Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, identifier_accept_val)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* node = new NIdentifier("char", "test");

    ASSERT_THAT((std::string*)node->Accept(visitor, context)->get_value(), Pointee(Eq("test")));

}

TEST(basic_node, identifier_accept_type)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* node = new NIdentifier("char", "test");

    ASSERT_THAT(node->Accept(visitor, context)->get_type(), Eq(DataType::CHAR_DTYPE));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NOperator Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, operator_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NOperator* node = new NOperator("+");

    ASSERT_THAT((OperationType*)node->Accept(visitor, context)->get_value(), Pointee(Eq(OperationType::ADD_TYPE)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NMethodCall Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, method_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    ValueVec arg_values;
    IdentifierValue* arg1 = new IdentifierValue("int", "test1");
    IdentifierValue* arg2 = new IdentifierValue("bool", "test2");
    IdentifierValue* arg3 = new IdentifierValue("float", "test3");
    arg_values.push_back(arg1);
    arg_values.push_back(arg2);
    arg_values.push_back(arg3);

    Context* master_context = new Context();
    Context* function_context = new Context();
    NBlock* body = new NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NExpression* assign = new NAssignment(*var, *binOp);

    NExpression* iden = new NIdentifier("int","test1");
    NExpression* returnBinOp = new NBinaryOperator(*var, *op, *iden);
    NStatement* returnState = new NReturnStatement(returnBinOp);

    NStatement* expState = new NExpressionStatement(*assign);

    body->statements.push_back(expState);
    body->statements.push_back(returnState);
    FunctionValue* function_val = new FunctionValue(&arg_values, function_context, *body, DataType::INT_DTYPE);

    IdentifierValue* func_iden = new IdentifierValue("func_def");
    master_context->set_value(func_iden, function_val);
    master_context->set_value(arg1, new IntValue(1));
    master_context->set_value(arg2, new BoolValue(true));
    master_context->set_value(arg3, new DoubleValue(1.5));

    ExpressionList args;
    args.push_back(new NIdentifier("int","test1"));
    args.push_back(new NIdentifier("bool","test2"));
    args.push_back(new NIdentifier("float","test3"));

    NIdentifier iden_node = NIdentifier("func_def");

    NMethodCall* node = new NMethodCall(iden_node, args);

    ASSERT_THAT((int*)node->Accept(visitor, master_context)->get_value(), Pointee(Eq(4)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NBinaryOperator Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

// Int and Int
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
TEST(bin_op_node, int_plus_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_EQ(*((int*)bin_op_node->Accept(visitor, context)->get_value()), 1+2);
}

TEST(bin_op_node, int_minus_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("-");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_EQ(*((int*)bin_op_node->Accept(visitor, context)->get_value()), 1-2);
}

TEST(bin_op_node, int_multiply_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_EQ(*((int*)bin_op_node->Accept(visitor, context)->get_value()), 1*2);
}

TEST(bin_op_node, int_divide_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("/");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    // 1 divided by 2 = 1/2 = 0 
    ASSERT_EQ(*((int*)bin_op_node->Accept(visitor, context)->get_value()), 1/2);
}

TEST(bin_op_node, int_equal_to_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("==");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, int_not_equal_to_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("!=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, int_less_than_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("<");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, int_greater_than_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* int_node2 = (NExpression*) new NInteger(1);
    const NOperator* op_node = new NOperator(">");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, int_less_than_or_equal_to_int_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, int_less_than_or_equal_to_int_less)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, int_greater_than_or_equal_to_int_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* int_node2 = (NExpression*) new NInteger(2);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, int_greater_than_or_equal_to_int_greater)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* int_node2 = (NExpression*) new NInteger(1);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}


// Int and double
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
TEST(bin_op_node, int_plus_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 1+2.1);
}

TEST(bin_op_node, int_minus_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("-");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 1-2.1);
}

TEST(bin_op_node, int_multiply_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 1*2.1);
}

TEST(bin_op_node, int_divide_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("/");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 1/2.1);
}

TEST(bin_op_node, int_equal_to_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("==");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, int_not_equal_to_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("!=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, int_less_than_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("<");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, int_greater_than_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(1);
    const NOperator* op_node = new NOperator(">");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, int_less_than_or_equal_to_double_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, int_less_than_or_equal_to_double_less)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, int_greater_than_or_equal_to_double_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, int_greater_than_or_equal_to_double_greater)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(1);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *double_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

// double and int
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
TEST(bin_op_node, double_plus_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 + 1);
}

TEST(bin_op_node, double_minus_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("-");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 - 1);
}

TEST(bin_op_node, double_multiply_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 * 1);
}

TEST(bin_op_node, double_divide_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("/");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 / 1);
}

TEST(bin_op_node, double_equal_to_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("==");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, double_not_equal_to_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("!=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, double_less_than_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("<");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, double_greater_than_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(1);
    const NOperator* op_node = new NOperator(">");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, double_less_than_or_equal_to_int_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, double_less_than_or_equal_to_int_less)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(1);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

TEST(bin_op_node, double_greater_than_or_equal_to_int_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(2);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}


TEST(bin_op_node, double_greater_than_or_equal_to_int_greater)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NInteger(2);
    NExpression* double_node = (NExpression*) new NDouble(1);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *int_node);

    ASSERT_EQ(bin_op_node->Accept(visitor, context)->get_type(), DataType::ERROR_DTYPE);
}

// double and double
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
TEST(bin_op_node, double_plus_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* double_node2 = (NExpression*) new NDouble(1.7);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *double_node2);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 + 1.7);
}

TEST(bin_op_node, double_minus_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* double_node2 = (NExpression*) new NDouble(1.7);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("-");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *double_node2);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 - 1.7);
}

TEST(bin_op_node, double_multiply_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* double_node2 = (NExpression*) new NDouble(1.7);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *double_node2);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 * 1.7);
}

TEST(bin_op_node, double_divide_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* double_node2 = (NExpression*) new NDouble(1.7);
    NExpression* double_node = (NExpression*) new NDouble(2.1);
    const NOperator* op_node = new NOperator("/");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *double_node, *op_node, *double_node2);

    ASSERT_EQ(*((double*)bin_op_node->Accept(visitor, context)->get_value()), 2.1 / 1.7);
}

TEST(bin_op_node, double_equal_to_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(3.6);
    NExpression* int_node2 = (NExpression*) new NDouble(3.6);
    const NOperator* op_node = new NOperator("==");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, double_not_equal_to_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(1.6);
    NExpression* int_node2 = (NExpression*) new NDouble(2.6);
    const NOperator* op_node = new NOperator("!=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, double_less_than_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(1.6);
    NExpression* int_node2 = (NExpression*) new NDouble(2.6);
    const NOperator* op_node = new NOperator("<");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, double_greater_than_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(2.6);
    NExpression* int_node2 = (NExpression*) new NDouble(1.6);
    const NOperator* op_node = new NOperator(">");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, double_less_than_or_equal_to_double_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(2.6);
    NExpression* int_node2 = (NExpression*) new NDouble(2.6);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, double_less_than_or_equal_to_double_less)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(1.6);
    NExpression* int_node2 = (NExpression*) new NDouble(2.6);
    const NOperator* op_node = new NOperator("<=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, double_greater_than_or_equal_to_double_equal)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(2.6);
    NExpression* int_node2 = (NExpression*) new NDouble(2.6);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, double_greater_than_or_equal_to_double_greater)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_node = (NExpression*) new NDouble(2.6);
    NExpression* int_node2 = (NExpression*) new NDouble(1.6);
    const NOperator* op_node = new NOperator(">=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *int_node, *op_node, *int_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

// bool and bool
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(bin_op_node, bool_equal_to_bool)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* bool_node = (NExpression*) new NBool("true");
    NExpression* bool_node2 = (NExpression*) new NBool("true");
    const NOperator* op_node = new NOperator("==");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *bool_node, *op_node, *bool_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

TEST(bin_op_node, bool_not_equal_to_bool)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* bool_node = (NExpression*) new NBool("true");
    NExpression* bool_node2 = (NExpression*) new NBool("false");
    const NOperator* op_node = new NOperator("!=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *bool_node, *op_node, *bool_node2);

    ASSERT_TRUE(*((bool*)bin_op_node->Accept(visitor, context)->get_value()));
}

// string and string
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(bin_op_node, string_plus_string)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* string_node1 = new NIdentifier("string","test");
    NIdentifier* string_node2 = new NIdentifier("string", "test2");
    context->set_value((IdentifierValue*)string_node1->Accept(visitor,context), new StringValue("test"));
    context->set_value((IdentifierValue*)string_node2->Accept(visitor,context), new StringValue("ing string"));
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *string_node1, *op_node, *string_node2);

    ASSERT_THAT((std::string*)bin_op_node->Accept(visitor, context)->get_value(), Pointee(Eq("testing string")));
}

TEST(bin_op_node, string_multiplied_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* string_node = new NIdentifier("string","test");
    NExpression* int_node = new NInteger(3);
    context->set_value((IdentifierValue*)string_node->Accept(visitor,context), new StringValue("test "));
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *string_node, *op_node, *int_node);

    ASSERT_THAT((std::string*)bin_op_node->Accept(visitor, context)->get_value(), Pointee(Eq("test test test ")));
}

TEST(bin_op_node, string_equal_to_string)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* string_node1 = new NIdentifier("string","test");
    NIdentifier* string_node2 = new NIdentifier("string", "test2");
    context->set_value((IdentifierValue*)string_node1->Accept(visitor,context), new StringValue("test"));
    context->set_value((IdentifierValue*)string_node2->Accept(visitor,context), new StringValue("test"));
    const NOperator* op_node = new NOperator("==");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *string_node1, *op_node, *string_node2);

    ASSERT_THAT((bool*)bin_op_node->Accept(visitor, context)->get_value(), Pointee(IsTrue()));
}

TEST(bin_op_node, string_not_equal_to_string)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* string_node1 = new NIdentifier("string","test");
    NIdentifier* string_node2 = new NIdentifier("string", "test2");
    context->set_value((IdentifierValue*)string_node1->Accept(visitor,context), new StringValue("test"));
    context->set_value((IdentifierValue*)string_node2->Accept(visitor,context), new StringValue("test2"));
    const NOperator* op_node = new NOperator("!=");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *string_node1, *op_node, *string_node2);

    ASSERT_THAT((bool*)bin_op_node->Accept(visitor, context)->get_value(), Pointee(IsTrue()));
}

// list and list
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(bin_op_node, list_plus_list)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node1 = new NIdentifier("list","test");
    NIdentifier* list_node2 = new NIdentifier("list", "test2");
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    ValueVec valVec2 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node1->Accept(visitor,context), new ListValue(valVec1));
    context->set_value((IdentifierValue*)list_node2->Accept(visitor,context), new ListValue(valVec2));
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node1, *op_node, *list_node2);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(2), new IntValue(4), new IntValue(6)}));
}

TEST(bin_op_node, list_minus_list)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node1 = new NIdentifier("list","test");
    NIdentifier* list_node2 = new NIdentifier("list", "test2");
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    ValueVec valVec2 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node1->Accept(visitor,context), new ListValue(valVec1));
    context->set_value((IdentifierValue*)list_node2->Accept(visitor,context), new ListValue(valVec2));
    const NOperator* op_node = new NOperator("-");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node1, *op_node, *list_node2);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(0), new IntValue(0), new IntValue(0)}));
}

TEST(bin_op_node, list_multiply_list)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node1 = new NIdentifier("list","test");
    NIdentifier* list_node2 = new NIdentifier("list", "test2");
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    ValueVec valVec2 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node1->Accept(visitor,context), new ListValue(valVec1));
    context->set_value((IdentifierValue*)list_node2->Accept(visitor,context), new ListValue(valVec2));
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node1, *op_node, *list_node2);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(1), new IntValue(4), new IntValue(9)}));
}

TEST(bin_op_node, list_divide_list)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node1 = new NIdentifier("list","test");
    NIdentifier* list_node2 = new NIdentifier("list", "test2");
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    ValueVec valVec2 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node1->Accept(visitor,context), new ListValue(valVec1));
    context->set_value((IdentifierValue*)list_node2->Accept(visitor,context), new ListValue(valVec2));
    const NOperator* op_node = new NOperator("/");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node1, *op_node, *list_node2);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(1), new IntValue(1), new IntValue(1)}));
}

TEST(bin_op_node, list_plus_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NInteger* int_node = new NInteger(1);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *int_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(2), new IntValue(3), new IntValue(4)}));
}

TEST(bin_op_node, list_minus_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NInteger* int_node = new NInteger(1);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("-");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *int_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(0), new IntValue(1), new IntValue(2)}));
}

TEST(bin_op_node, list_multiply_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NInteger* int_node = new NInteger(2);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *int_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(2), new IntValue(4), new IntValue(6)}));
}

TEST(bin_op_node, list_divide_int)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NInteger* int_node = new NInteger(2);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("/");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *int_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), IntValueVecMatcher(ValueVec{new IntValue(0), new IntValue(1), new IntValue(1)}));
}

TEST(bin_op_node, list_plus_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NDouble* double_node = new NDouble(1.5);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *double_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), DoubleValueVecMatcher(ValueVec{new DoubleValue(2.5), new DoubleValue(3.5), new DoubleValue(4.5)}));
}

TEST(bin_op_node, list_minus_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NDouble* double_node = new NDouble(1.5);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("-");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *double_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), DoubleValueVecMatcher(ValueVec{new DoubleValue(-0.5), new DoubleValue(0.5), new DoubleValue(1.5)}));
}

TEST(bin_op_node, list_multiply_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NDouble* double_node = new NDouble(1.5);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("*");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *double_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), DoubleValueVecMatcher(ValueVec{new DoubleValue(1.5), new DoubleValue(2*1.5), new DoubleValue(3*1.5)}));
}

TEST(bin_op_node, list_divide_double)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NDouble* double_node = new NDouble(1.5);
    ValueVec valVec1 = {new IntValue(1), new IntValue(2), new IntValue(3)};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("/");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *double_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), DoubleValueVecMatcher(ValueVec{new DoubleValue(1/1.5), new DoubleValue(2/1.5), new DoubleValue(3/1.5)}));
}

TEST(bin_op_node, list_plus_string)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier* list_node = new NIdentifier("list","test");
    NString* string_node = new NString("-inator");
    ValueVec valVec1 = {new StringValue("zap"), new StringValue("bop"), new StringValue("thwak")};
    context->set_value((IdentifierValue*)list_node->Accept(visitor,context), new ListValue(valVec1));
    const NOperator* op_node = new NOperator("+");
    NBinaryOperator* bin_op_node = new NBinaryOperator( *list_node, *op_node, *string_node);

    ASSERT_THAT((ValueVec*)bin_op_node->Accept(visitor, context)->get_value(), StringValueVecMatcher(ValueVec{new StringValue("zap-inator"), new StringValue("bop-inator"), new StringValue("thwak-inator")}));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NAssignment Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, assignment_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier lhs = NIdentifier("test");
    NExpression* rhs = new NInteger(1);
    NAssignment* assign = new NAssignment(lhs, *rhs);

    const IdentifierValue* result = dynamic_cast<const IdentifierValue*>(assign->Accept(visitor, context));

    ASSERT_THAT((int*)((IntValue*)context->find_value(result->value))->get_value(), Pointee(Eq(1)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NBlock Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, block_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NBlock* body = new NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NExpression* assign = new NAssignment(*var, *binOp);

    NOperator* op2 = new NOperator("*");
    NExpression* binOp2 = new NBinaryOperator(*var, *op2, *rhs);
    NIdentifier* var2 = new NIdentifier("int", "result2");
    NExpression* assign2 = new NAssignment(*var2, *binOp2);

    NStatement* expState = new NExpressionStatement(*assign);
    NStatement* expState2 = new NExpressionStatement(*assign2);

    body->statements.push_back(expState);
    body->statements.push_back(expState2);

    ASSERT_THAT((ValueVec*)body->Accept(visitor, context)->get_value(), StringValueVecMatcher(ValueVec{new IdentifierValue("int","result"), new IdentifierValue("int","result2")}));
}

TEST(basic_node, block_with_return_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NBlock* body = new NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);

    NStatement* returnState = new NReturnStatement(binOp);

    body->statements.push_back(returnState);

    ASSERT_THAT((int*)body->Accept(visitor, context)->get_value(), Pointee(Eq(3)));
}

