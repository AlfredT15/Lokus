#include <gtest/gtest.h>
#include <string>

#include "../include/value.hpp"
#include "../include/enum.hpp"
#include "../include/visitor.hpp"

// Loop construciton tests:
// 1. Test the counter
// 2. Test the condition
// 3. Test the change
// 4. Test the block execution

// Testing counter construction with a non IdentifierValue
TEST(Loop_Construction, counter)
{
    const InterpretVisitor *visitor = new InterpretVisitor();
    // Context* context = new Context();
    // IdentifierValue* counter = new IdentifierValue("bool", "counter");
    // const bool variable_set = context->set_value(counter, int_val);
    IntValue* int_val = new IntValue(5);
}