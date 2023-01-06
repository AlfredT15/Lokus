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

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NExpressionStatement Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, expression_statement_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_expr = new NInteger(1);

    NExpressionStatement* node = new NExpressionStatement(*int_expr);

    ASSERT_THAT((int*)node->Accept(visitor, context)->get_value(), Pointee(Eq(1)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NReturnStatement Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, return_statement_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_expr = new NInteger(1);

    NReturnStatement* node = new NReturnStatement(int_expr);

    ASSERT_THAT((int*)((IntValue*)node->Accept(visitor, context)->get_value())->get_value(), Pointee(Eq(1)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NVariableDeclaration Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, variable_declaration_accept_null)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier id = NIdentifier("int", "test");

    NVariableDeclaration node = NVariableDeclaration(id);

    ASSERT_THAT((std::string*)node.Accept(visitor,context)->get_value(), Pointee(Eq("test")));
}

TEST(basic_node, variable_declaration_accept_null_and_reassignment)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NIdentifier id = NIdentifier("int","test");

    NVariableDeclaration node = NVariableDeclaration(id);

    ASSERT_THAT((std::string*)node.Accept(visitor,context)->get_value(), Pointee(Eq("test")));
    
    NExpression* rhs = new NInteger(1);
    NAssignment* assign = new NAssignment(id, *rhs);

    const IdentifierValue* result = dynamic_cast<const IdentifierValue*>(assign->Accept(visitor, context));

    ASSERT_THAT((int*)((IntValue*)context->find_value(result->value))->get_value(), Pointee(Eq(1)));
}

TEST(basic_node, variable_declaration_accept_expr)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    NExpression* int_expr = new NInteger(1);
    NIdentifier id = NIdentifier("int", "test");

    NVariableDeclaration node = NVariableDeclaration(id, int_expr);

    std::string iden = *((std::string*)node.Accept(visitor, context)->get_value());

    ASSERT_THAT((int*)((IntValue*)context->find_value(iden))->get_value(), Pointee(Eq(1)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NFunctionDeclatation Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, function_declaration_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    VariableList arg_values;
    NIdentifier id1 = NIdentifier("int", "test1");
    NExpression* val1 = new NInteger(1);
    NIdentifier id2 = NIdentifier("bool", "test2");
    NExpression* val2 = new NBool("true");
    NIdentifier id3 = NIdentifier("float", "test3");
    NExpression* val3 = new NDouble(1.5);

    arg_values.push_back(new NVariableDeclaration(id1, val1));
    arg_values.push_back(new NVariableDeclaration(id2, val2));
    arg_values.push_back(new NVariableDeclaration(id3, val3));


    Context* context = new Context();
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

    NIdentifier id = NIdentifier("int", "func_def");
    NFunctionDeclaration node = NFunctionDeclaration(id, arg_values, *body);

    const FunctionValue* func_val = dynamic_cast<const FunctionValue*>(node.Accept(visitor, context));

    ASSERT_THAT((int*)((IntValue*)func_val->block.Accept(visitor, context))->get_value(), Pointee(Eq(4)));

}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NIfStatement Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, if_statement_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();

    IdentifierValue* id = new IdentifierValue("int", "test1");
    IntValue* val = new IntValue(1);

    Context* context = new Context();
    context->set_value(id,val);
    NBlock body = NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NStatement* assign = new NVariableDeclaration(*var, binOp);

    NIdentifier* iden = new NIdentifier("int","test1");
    NExpression* binOp2 = new NBinaryOperator(*var, *op, *iden);
    NExpression* assign2 = new NAssignment(*iden, *binOp2);

    body.statements.push_back(assign);
    body.statements.push_back(new NExpressionStatement(*assign2));

    NExpression* rhs2 = new NInteger(1);
    NOperator* op2 = new NOperator("==");
    NExpression* binOp3 = new NBinaryOperator(*iden, *op2, *rhs2);

    NIfStatement node = NIfStatement(binOp3, body);

    // ASSERT_THAT(node.Accept(visitor, context)->get_type(), Eq(DataType::VOID_DTYPE));
    node.Accept(visitor, context);
    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(4)));
}

TEST(basic_node, if_with_else_if_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();

    IdentifierValue* id = new IdentifierValue("int", "test1");
    IntValue* val = new IntValue(1);

    Context* context = new Context();
    context->set_value(id,val);
    NBlock body = NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NStatement* assign = new NVariableDeclaration(*var, binOp);

    NIdentifier* iden = new NIdentifier("int","test1");
    NExpression* binOp2 = new NBinaryOperator(*var, *op, *iden);
    NExpression* assign2 = new NAssignment(*iden, *binOp2);

    body.statements.push_back(assign);
    body.statements.push_back(new NExpressionStatement(*assign2));

    NExpression* rhs2 = new NInteger(2);
    NOperator* op2 = new NOperator("==");
    NExpression* binOp3 = new NBinaryOperator(*iden, *op2, *rhs2);

    NBlock body2 = NBlock();
    NExpression* binOp4 = new NBinaryOperator(*iden, *op, *rhs);
    NExpression* assign3 = new NAssignment(*iden, *binOp4);
    body2.statements.push_back(new NExpressionStatement(*assign3));

    NExpression* rhs3 = new NInteger(1);
    NExpression* binOp5 = new NBinaryOperator(*iden, *op2, *rhs3);

    NIfStatement* elseIfNode = new NIfStatement(binOp5, body2);

    NIfStatement node = NIfStatement(binOp3, body, elseIfNode);

    // ASSERT_THAT(node.Accept(visitor, context)->get_type(), Eq(DataType::VOID_DTYPE));
    node.Accept(visitor, context);
    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(3)));
}

TEST(basic_node, if_with_else_if_with_else_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();

    IdentifierValue* id = new IdentifierValue("int", "test1");
    IntValue* val = new IntValue(1);

    Context* context = new Context();
    context->set_value(id,val);
    NBlock body = NBlock();

    NExpression* lhs = new NInteger(1);
    NOperator* op = new NOperator("+");
    NExpression* rhs = new NInteger(2);
    NExpression* binOp = new NBinaryOperator(*lhs, *op, *rhs);
    
    NIdentifier* var = new NIdentifier("int", "result");
    NStatement* assign = new NVariableDeclaration(*var, binOp);

    NIdentifier* iden = new NIdentifier("int","test1");
    NExpression* binOp2 = new NBinaryOperator(*var, *op, *iden);
    NExpression* assign2 = new NAssignment(*iden, *binOp2);

    body.statements.push_back(assign);
    body.statements.push_back(new NExpressionStatement(*assign2));

    NExpression* rhs2 = new NInteger(2);
    NOperator* op2 = new NOperator("==");
    NExpression* binOp3 = new NBinaryOperator(*iden, *op2, *rhs2);

    NBlock body2 = NBlock();
    NExpression* binOp4 = new NBinaryOperator(*iden, *op, *rhs);
    NExpression* assign3 = new NAssignment(*iden, *binOp4);
    body2.statements.push_back(new NExpressionStatement(*assign3));

    NExpression* rhs3 = new NInteger(-1);
    NExpression* binOp5 = new NBinaryOperator(*iden, *op2, *rhs3);

    NBlock body3 = NBlock();
    NOperator* op3 = new NOperator("-");
    NExpression* binOp6 = new NBinaryOperator(*iden, *op3, *rhs);
    NExpression* assign4 = new NAssignment(*iden, *binOp6);
    body3.statements.push_back(new NExpressionStatement(*assign4));

    NIfStatement* elseNode = new NIfStatement(body3);
    NIfStatement* elseIfNode = new NIfStatement(binOp5, body2, elseNode);
    NIfStatement node = NIfStatement(binOp3, body, elseIfNode);

    // ASSERT_THAT(node.Accept(visitor, context)->get_type(), Eq(DataType::VOID_DTYPE));
    node.Accept(visitor, context);
    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(-1)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NForStatement Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, for_statement_accept_positive_change)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();

    // Setup initial variable
    IdentifierValue id = IdentifierValue("int", "test1");
    IntValue val = IntValue(1);
    context->set_value(&id,&val);

    // Create the body of loop
    NBlock* body = new NBlock();

    NIdentifier* iden = new NIdentifier("int","test1");
    NOperator op = NOperator("+");
    NInteger* rhs = new NInteger(1);
    NBinaryOperator* binOp = new NBinaryOperator(*iden, op, *rhs);
    
    NAssignment* assign = new NAssignment(*iden, *binOp);

    NExpressionStatement expState = NExpressionStatement(*assign);

    body->statements.push_back(&expState);

    // Counter
    NExpression* int_expr = new NInteger(1);
    NIdentifier counter_id = NIdentifier("int", "counter");
    NVariableDeclaration counter = NVariableDeclaration(counter_id, int_expr);

    // Condition
    NOperator condition_op = NOperator("<=");
    NInteger condition_rhs = NInteger(5);
    NBinaryOperator condition = NBinaryOperator(counter_id, condition_op, condition_rhs);

    // Change
    NBinaryOperator* binOp2 = new NBinaryOperator(counter_id, op, *rhs);
    NAssignment change = NAssignment(counter_id, *binOp2);

    NForStatement node = NForStatement(&counter, &condition, &change, *body);

    node.Accept(visitor, context);

    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(6)));
}

TEST(basic_node, for_statement_accept_negative_change)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();

    // Setup initial variable
    IdentifierValue id = IdentifierValue("int", "test1");
    IntValue val = IntValue(1);
    context->set_value(&id,&val);

    // Create the body of loop
    NBlock* body = new NBlock();

    NIdentifier* iden = new NIdentifier("int","test1");
    NOperator op = NOperator("+");
    NInteger* rhs = new NInteger(1);
    NBinaryOperator* binOp = new NBinaryOperator(*iden, op, *rhs);
    
    NAssignment* assign = new NAssignment(*iden, *binOp);

    NExpressionStatement expState = NExpressionStatement(*assign);

    body->statements.push_back(&expState);

    // Counter
    NExpression* int_expr = new NInteger(5);
    NIdentifier counter_id = NIdentifier("int", "counter");
    NVariableDeclaration counter = NVariableDeclaration(counter_id, int_expr);

    // Condition
    NOperator condition_op = NOperator(">=");
    NInteger condition_rhs = NInteger(1);
    NBinaryOperator condition = NBinaryOperator(counter_id, condition_op, condition_rhs);

    // Change
    NOperator op2 = NOperator("-");
    NBinaryOperator* binOp2 = new NBinaryOperator(counter_id, op2, *rhs);
    NAssignment change = NAssignment(counter_id, *binOp2);

    NForStatement node = NForStatement(&counter, &condition, &change, *body);

    node.Accept(visitor, context);

    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(6)));
}

TEST(basic_node, for_statement_accept_double_loop)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();

    // Setup initial variable
    IdentifierValue id = IdentifierValue("int", "test1");
    IntValue val = IntValue(1);
    context->set_value(&id,&val);

    // Create body of loop1
    NBlock* body = new NBlock();
    
    // Loop One
    // Counter
    NExpression* int_expr = new NInteger(1);
    NIdentifier counter_id = NIdentifier("int", "counter");
    NVariableDeclaration counter = NVariableDeclaration(counter_id, int_expr);

    // Condition
    NOperator condition_op = NOperator("<=");
    NInteger condition_rhs = NInteger(5);
    NBinaryOperator condition = NBinaryOperator(counter_id, condition_op, condition_rhs);

    // Change
    NOperator op = NOperator("+");
    NInteger* rhs = new NInteger(1);
    NBinaryOperator* binOp2 = new NBinaryOperator(counter_id, op, *rhs);
    NAssignment change = NAssignment(counter_id, *binOp2);

    NForStatement loop1 = NForStatement(&counter, &condition, &change, *body);

    // Create the body of loop2
    NBlock* body2 = new NBlock();

    NIdentifier* iden = new NIdentifier("int","test1");
    NBinaryOperator* binOp = new NBinaryOperator(*iden, op, *rhs);
    
    NAssignment* assign = new NAssignment(*iden, *binOp);

    NExpressionStatement expState = NExpressionStatement(*assign);

    body2->statements.push_back(&expState);

    // Loop Two
    // Counter
    NExpression* int_expr2 = new NInteger(1);
    NIdentifier counter_id2 = NIdentifier("int", "counter2");
    NVariableDeclaration counter2 = NVariableDeclaration(counter_id2, int_expr2);

    // Condition
    NOperator condition_op2 = NOperator("<=");
    NInteger condition_rhs2 = NInteger(5);
    NBinaryOperator condition2 = NBinaryOperator(counter_id2, condition_op2, condition_rhs2);

    // Change
    NBinaryOperator* binOp3 = new NBinaryOperator(counter_id2, op, *rhs);
    NAssignment change2 = NAssignment(counter_id2, *binOp3);

    NForStatement loop2 = NForStatement(&counter2, &condition2, &change2, *body2);

    body->statements.push_back(&loop2);

    loop1.Accept(visitor, context);

    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(26)));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NWhileStatement Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, while_statement_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();

    // Setup initial variable
    IdentifierValue id = IdentifierValue("int", "test1");
    IntValue val = IntValue(1);
    context->set_value(&id,&val);

    // Create the body of loop
    NBlock* body = new NBlock();

    NIdentifier* iden = new NIdentifier("int","test1");
    NOperator op = NOperator("+");
    NInteger* rhs = new NInteger(1);
    NBinaryOperator* binOp = new NBinaryOperator(*iden, op, *rhs);
    
    NAssignment* assign = new NAssignment(*iden, *binOp);

    NExpressionStatement expState = NExpressionStatement(*assign);

    body->statements.push_back(&expState);

    // Condition
    NOperator condition_op = NOperator("<=");
    NInteger condition_rhs = NInteger(5);
    NBinaryOperator condition = NBinaryOperator(*iden, condition_op, condition_rhs);

    NWhileStatement node = NWhileStatement(&condition, *body);

    node.Accept(visitor, context);

    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(6)));
}

TEST(basic_node, while_statement_accept_double_loop)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();

    // Setup initial variable
    IdentifierValue id1 = IdentifierValue("int", "test1");
    IntValue val1 = IntValue(1);
    context->set_value(&id1,&val1);
    IdentifierValue id2 = IdentifierValue("int", "counter1");
    IntValue val2 = IntValue(1);
    context->set_value(&id2,&val2);
    IdentifierValue id3 = IdentifierValue("int", "counter2");
    IntValue val3 = IntValue(1);
    context->set_value(&id3,&val3);

    // Create body of loop1
    NBlock* body = new NBlock();
    
    // Loop One

    // Condition
    NIdentifier counter_id1 = NIdentifier("int", "counter1");
    NOperator condition_op = NOperator("<=");
    NInteger condition_rhs = NInteger(5);
    NBinaryOperator condition = NBinaryOperator(counter_id1, condition_op, condition_rhs);

    NWhileStatement loop1 = NWhileStatement(&condition, *body);

    // Create the body of loop2
    NBlock* body2 = new NBlock();

    NIdentifier* iden = new NIdentifier("int","test1");
    NOperator op = NOperator("+");
    NInteger* rhs = new NInteger(1);
    NBinaryOperator* binOp = new NBinaryOperator(*iden, op, *rhs);
    NAssignment* assign = new NAssignment(*iden, *binOp);
    NExpressionStatement expState = NExpressionStatement(*assign);

    NIdentifier counter_id2 = NIdentifier("int", "counter2");
    NBinaryOperator* binOp2 = new NBinaryOperator(counter_id2, op, *rhs);
    NAssignment* assign2 = new NAssignment(counter_id2, *binOp2);
    NExpressionStatement expState2 = NExpressionStatement(*assign2);

    body2->statements.push_back(&expState);
    body2->statements.push_back(&expState2);

    // Loop Two
    // Condition
    NOperator condition_op2 = NOperator("<=");
    NInteger condition_rhs2 = NInteger(5);
    NBinaryOperator condition2 = NBinaryOperator(counter_id2, condition_op2, condition_rhs2);

    NWhileStatement loop2 = NWhileStatement(&condition2, *body2);

    NInteger reset_node = NInteger(1);
    NAssignment* assign3 = new NAssignment(counter_id2, reset_node);
    NExpressionStatement expState3 = NExpressionStatement(*assign3);

    NBinaryOperator* binOp3 = new NBinaryOperator(counter_id1, op, *rhs);
    NAssignment* assign4 = new NAssignment(counter_id1, *binOp3);
    NExpressionStatement expState4 = NExpressionStatement(*assign4);

    body->statements.push_back(&loop2);
    body->statements.push_back(&expState3);
    body->statements.push_back(&expState4);

    loop1.Accept(visitor, context);

    ASSERT_THAT((int*)context->find_value("test1")->get_value(), Pointee(Eq(26)));
}

TEST(basic_node, print_statement)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();

    NInteger int_node = NInteger(1);
    NPrintStatement node = NPrintStatement(&int_node);

    ASSERT_THAT((int*)((IntValue*)((PrintValue*)node.Accept(visitor, context))->get_value())->get_value(), Pointee(Eq(1)));
}
