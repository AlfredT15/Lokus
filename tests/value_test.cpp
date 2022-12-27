#include <gtest/gtest.h>
#include <math.h>
#include <string>

#include "gmock/gmock.h"
#include "../include/value.hpp"
#include "../include/enum.hpp"

using ::testing::ElementsAre;

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ErrorValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, error_check)
{
    ErrorValue* error_val = new ErrorValue("Error");
    ASSERT_EQ(*((std::string*)error_val->get_value()), "Error");
};

TEST(value_construction, error_isError_check)
{
    ErrorValue* error_val = new ErrorValue("Error");
    ASSERT_TRUE(error_val->get_isError());
};

TEST(value_construction, error_type_check)
{
    ErrorValue* error_val = new ErrorValue("Error");
    ASSERT_EQ(error_val->get_type(), DataType::ERROR_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// VoidValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, void_check)
{
    VoidValue* void_val = new VoidValue();
    ASSERT_EQ((void_val->get_value()), nullptr);
};

TEST(value_construction, void_isError_check)
{
    VoidValue* void_val = new VoidValue();
    ASSERT_FALSE(void_val->get_isError());
};

TEST(value_construction, void_type_check)
{
    VoidValue* void_val = new VoidValue();
    ASSERT_EQ(void_val->get_type(), DataType::VOID_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IntValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, int_check)
{
    IntValue* int_val = new IntValue(5);
    ASSERT_EQ(*((int*)int_val->get_value()), 5);
};

TEST(value_construction, int_isError_check)
{
    IntValue* int_val = new IntValue(0);
    ASSERT_FALSE(int_val->get_isError());
};

TEST(value_construction, int_type_check)
{
    IntValue* int_val = new IntValue(0);
    ASSERT_EQ(int_val->get_type(), DataType::INT_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// DoubleValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, double_check_int)
{
    DoubleValue* double_val = new DoubleValue(5);
    ASSERT_EQ(*((double*)double_val->get_value()), 5);
};

TEST(value_construction, double_check_double)
{
    DoubleValue* double_val = new DoubleValue(5.67);
    ASSERT_EQ(*((double*)double_val->get_value()), 5.67);
};

TEST(value_construction, double_check_pi)
{
    DoubleValue* double_val = new DoubleValue(M_PI);
    ASSERT_EQ(*((double*)double_val->get_value()), M_PI);
};

TEST(value_construction, double_isError_check)
{
    DoubleValue* double_val = new DoubleValue(0);
    ASSERT_FALSE(double_val->get_isError());
};

TEST(value_construction, double_type_check)
{
    DoubleValue* double_val = new DoubleValue(0);
    ASSERT_EQ(double_val->get_type(), DataType::FLOAT_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// BoolValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, bool_check)
{
    BoolValue* bool_val = new BoolValue(true);
    ASSERT_TRUE(*((bool*)bool_val->get_value()));
};

TEST(value_construction, bool_isError_check)
{
    BoolValue* bool_val = new BoolValue(true);
    ASSERT_FALSE(bool_val->get_isError());
};

TEST(value_construction, bool_type_check)
{
    BoolValue* bool_val = new BoolValue(true);
    ASSERT_EQ(bool_val->get_type(), DataType::BOOL_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// IdentifierValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, identifier_check)
{
    IdentifierValue* identifier_val = new IdentifierValue("test");
    ASSERT_EQ(*((std::string*)identifier_val->get_value()), "test");
};

TEST(value_construction, identifier_isError_check)
{
    IdentifierValue* identifier_val = new IdentifierValue("test");
    ASSERT_FALSE(identifier_val->get_isError());
};

TEST(value_construction, identifier_type_check)
{
    IdentifierValue* identifier_val = new IdentifierValue("int", "test");
    ASSERT_EQ(identifier_val->get_type(), DataType::INT_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// OperatorValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, operator_check)
{
    OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    ASSERT_EQ(*((OperationType*)operator_val->get_value()), OperationType::ADD_TYPE);
};

TEST(value_construction, operator_isError_check)
{
    OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    ASSERT_FALSE(operator_val->get_isError());
};

TEST(value_construction, operator_type_check)
{
    OperatorValue* operator_val = new OperatorValue(OperationType::ADD_TYPE);
    ASSERT_EQ(operator_val->get_type(), DataType::VOID_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// ListValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, list_check)
{
    ValueVec val_vec = {new IntValue(1), new IntValue(2), new IntValue(3)};
    ListValue* list_val = new ListValue(val_vec);
    std::vector<int> test_vec = {1,2,3};
    ASSERT_EQ(test_vec.size(), ((ValueVec*)list_val->get_value())->size());
    for (int i = 0; i < test_vec.size(); i++)
    {
        ASSERT_EQ(*((int*)((ValueVec*)list_val->get_value())->at(i)->get_value()), test_vec[i]);
    }
};

TEST(value_construction, list_isError_check)
{
    ValueVec val_vec;
    ListValue* list_val = new ListValue(val_vec);
    ASSERT_FALSE(list_val->get_isError());
};

TEST(value_construction, list_type_check)
{
    ValueVec val_vec;
    ListValue* list_val = new ListValue(val_vec);
    ASSERT_EQ(list_val->get_type(), DataType::LIST_DTYPE);
};

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// FunctionValue Tests
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TEST(value_construction, function_check)
{
    // ValueVec arg_values = {new IdentifierValue("int", "test1"), new IdentifierValue("bool", "test2"), new IdentifierValue("float", "test3")};
    // Context context = new Context();
    // FunctionValue* function_val = new FunctionValue("test");
    // ASSERT_EQ(*((std::string*)function_val->get_value()), "test");
};

TEST(value_construction, function_isError_check)
{
    // FunctionValue* function_val = new FunctionValue("test");
    // ASSERT_FALSE(function_val->get_isError());
};

TEST(value_construction, function_type_check)
{
    // FunctionValue* function_val = new FunctionValue("int", "test");
    // ASSERT_EQ(function_val->get_type(), DataType::INT_DTYPE);
};