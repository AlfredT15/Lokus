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
    IntValue* int_val = new IntValue(1);
    NInteger* int_node = new NInteger(1);

    ASSERT_EQ(*((int*)int_node->Accept(visitor, context)->get_value()), *((int*)int_val->get_value()));
    // ASSERT_THAT((int*)int_node->Accept(visitor, context)->get_value(), Pointee(Eq(*((int*)int_val->get_value()))));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NDouble Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, double_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    DoubleValue* double_val = new DoubleValue(1);
    NDouble* double_node = new NDouble(1);

    ASSERT_EQ(*((double*)double_node->Accept(visitor, context)->get_value()), *((double*)double_val->get_value()));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NIdentifier Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, identifier_accept_val)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    IdentifierValue* identifier_val = new IdentifierValue("char", "test");
    NIdentifier* identifier_node = new NIdentifier("char", "test");

    ASSERT_EQ(*((std::string*)identifier_node->Accept(visitor, context)->get_value()), *((std::string*)identifier_val->get_value()));
}

TEST(basic_node, identifier_accept_type)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    IdentifierValue* identifier_val = new IdentifierValue("char", "test");
    NIdentifier* identifier_node = new NIdentifier("char", "test");

    ASSERT_EQ(identifier_node->Accept(visitor, context)->get_type(), identifier_val->get_type());
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NOperator Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, operator_accept)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* context = new Context();
    OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    NOperator* operator_node = new NOperator("+");

    ASSERT_EQ(*((OperationType*)operator_node->Accept(visitor, context)->get_value()), *((OperationType*)operator_val->get_value()));
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// NMethodCall Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(basic_node, method_accept)
{
    // const InterpretVisitor *visitor = new InterpretVisitor();
    // Context* context = new Context();
    // OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    // NOperator* operator_node = new NOperator("+");

    // ASSERT_EQ(*((OperationType*)operator_node->Accept(visitor, context)->get_value()), *((OperationType*)operator_val->get_value()));
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