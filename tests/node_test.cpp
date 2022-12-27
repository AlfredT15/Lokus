#include <gtest/gtest.h>
#include <string>

#include "../include/value.hpp"
#include "../include/node.hpp"


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