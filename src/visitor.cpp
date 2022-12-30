#include <cstdio>
#include "../include/visitor.hpp"
#include "../include/value.hpp"

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// PrintVisitor
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void PrintVisitor::VisitNInteger(const NInteger *element) const
{
    printf("int: %d \n", element->value->value);
}
void PrintVisitor::VisitNDouble(const NDouble *element) const
{
    printf("float: %f \n", element->value->value);
}
void PrintVisitor::VisitNBool(const NBool *element) const
{
    printf("bool: %d \n", element->value->value);
}
void PrintVisitor::VisitNString(const NString *element) const
{
    printf("string: %s \n", element->value->value.c_str());
}
void PrintVisitor::VisitNIdentifier(const NIdentifier *element) const
{
    printf("identifier: %s \n", element->value->value.c_str());
}
void PrintVisitor::VisitNOperator(const NOperator *element) const
{
    printf("operation: %d \n", element->value->value);
}
void PrintVisitor::VisitNMethodCall(const NMethodCall *element) const
{
    element->id.Accept(this);
    for (NExpression* expr : element->arguments)
    {
        expr->Accept(this);
    }
}
void PrintVisitor::VisitNBinaryOperator(const NBinaryOperator *element) const
{
    element->lhs.Accept(this);
    element->op.Accept(this);
    element->rhs.Accept(this);   
}
void PrintVisitor::VisitNAssignment(const NAssignment *element) const
{
    element->lhs.Accept(this);
    printf(" = ");
    element->rhs.Accept(this); 
}
void PrintVisitor::VisitNBlock(const NBlock *element) const
{
    for (NStatement* stmnt : element->statements)
    {
        stmnt->Accept(this);
    }
}
void PrintVisitor::VisitNExpressionStatement(const NExpressionStatement *element) const
{
    element->expression.Accept(this);
}
void PrintVisitor::VisitNReturnStatement(const NReturnStatement *element) const
{
    element->expression->Accept(this);
}
void PrintVisitor::VisitNVariableDeclaration(const NVariableDeclaration *element) const
{
    element->id.Accept(this);
    element->assignmentExpr->Accept(this);
}
void PrintVisitor::VisitNExternDeclaration(const NExternDeclaration *element) const
{
    element->id.Accept(this);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this);
    }
}
void PrintVisitor::VisitNFunctionDeclaration(const NFunctionDeclaration *element) const
{
    element->id.Accept(this);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this);
    }
    element->block.Accept(this);
}
void PrintVisitor::VisitNIfStatement(const NIfStatement *element) const
{
    element->condition_expr->Accept(this);
    element->block.Accept(this);
    element->next_if->Accept(this);
}
void PrintVisitor::VisitNForStatement(const NForStatement *element) const
{
    element->counter->Accept(this);
    element->condition->Accept(this);
    element->change->Accept(this);
    element->block.Accept(this);
}
void PrintVisitor::VisitNWhileStatement(const NWhileStatement *element) const
{
    element->condition->Accept(this);
    element->block.Accept(this);
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// InterpretVisitor
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

const Value* InterpretVisitor::VisitNInteger(const NInteger *element, Context* context) const
{
    // Returns an IntValue object
    return element->value;
}
const Value* InterpretVisitor::VisitNDouble(const NDouble *element, Context* context) const
{
    // Returns an DoubleValue object
    return element->value;
}
const Value* InterpretVisitor::VisitNBool(const NBool *element, Context* context) const
{
    // Returns an BoolValue object
    return element->value;
}
const Value* InterpretVisitor::VisitNString(const NString *element, Context* context) const
{
    // Returns an StringValue object
    return element->value;
}
const Value* InterpretVisitor::VisitNIdentifier(const NIdentifier *element, Context* context) const
{
    // Returns an IdentifierValue object
    return element->value;
}
const Value* InterpretVisitor::VisitNOperator(const NOperator *element, Context* context) const
{
    // Returns an OperatorValue object
    return element->value;
}
const Value* InterpretVisitor::VisitNMethodCall(const NMethodCall *element, Context* context) const
{
    // Gets the identfier associated with the method call and collects its value
    const IdentifierValue* id = dynamic_cast<const IdentifierValue*>(element->id.Accept(this, context));
    const Value* val = context->find_value(id->value);
    if (val->get_isError())
        return val;
    
    // Tries to convert the value into a function value
    const FunctionValue* func_val = dynamic_cast<const FunctionValue*>(val);
    if (!func_val)
        return new ErrorValue(id->value + " is not a callable function.");

    // Creates a vector to store the argument values provided to the method call
    ValueVec arg_vals;
    for (NExpression* expr : element->arguments)
    {
        arg_vals.push_back(expr->Accept(this, context));
    }

    // Checks the number of argument values provided compared to the amount expected
    if (func_val->arg_values->size() != arg_vals.size())
    {
        return new ErrorValue(id->value + " expects " + std::to_string(func_val->arg_values->size()) 
                        + "arguments. " + std::to_string(arg_vals.size()) + " were provided");
    }

    // Checks the types of the agrument values provided against what is expected
    for (int i = 0; i < func_val->arg_values->size(); i++)
    {
        if (func_val->arg_values->at(i)->get_type() != arg_vals[i]->get_type())
            return new ErrorValue("Parameter number " + std::to_string(i+1) + " expects a different type");
    }

    // Assigns the arguments passed through to the method to the context within the method and to the associated identifiers
    for (int i = 0; i < func_val->arg_values->size(); i++)
    {
        const IdentifierValue* id2 = dynamic_cast<const IdentifierValue*>(func_val->arg_values->at(i));
        if (!id2)
            return new ErrorValue("Something is wrong");
        bool var_set = func_val->function_context->set_value(id2, arg_vals.at(i));
        if (!var_set)
            return new ErrorValue("Expected a different type in arguments passed");
    }

    // Now evaluate the function with the context appropriately preset
    return func_val->block.Accept(this, func_val->function_context);
}
const Value* InterpretVisitor::VisitNBinaryOperator(const NBinaryOperator *element, Context* context) const
{
    // Evaluate the left hand side and right hand side of the binary operation
    const Value* lhs_val = element->lhs.Accept(this, context);
    const Value* rhs_val = element->rhs.Accept(this, context);
    const OperatorValue* op_val = dynamic_cast<const OperatorValue*>(element->op.Accept(this, context));

    // Check if either of the sides are identifiers and need to be converted to their appropriate value
    const IdentifierValue* lhs_id = dynamic_cast<const IdentifierValue*>(lhs_val);
    const IdentifierValue* rhs_id = dynamic_cast<const IdentifierValue*>(rhs_val);
    if (lhs_id)
    {
        lhs_val = context->find_value(lhs_id->value);
        if (lhs_val->get_isError())
            return lhs_val;
    }
    if (rhs_id)
    {
        rhs_val = context->find_value(rhs_id->value);
        if (rhs_val->get_isError())
            return rhs_val;
    }

    // Perform the associated operation
    switch (op_val->value)
    {
    case OperationType::ADD_TYPE:
        return lhs_val->added_to(rhs_val);
    case OperationType::SUB_TYPE:
        return lhs_val->subbed_by(rhs_val);
    case OperationType::MUL_TYPE:
        return lhs_val->multiplied_by(rhs_val);
    case OperationType::DIV_TYPE:
        return lhs_val->divided_by(rhs_val);
    case OperationType::EE_TYPE:
        return lhs_val->equal_to(rhs_val);
    case OperationType::NE_TYPE:
        return lhs_val->not_equal_to(rhs_val);
    case OperationType::LT_TYPE:
        return lhs_val->less_than(rhs_val);
    case OperationType::GT_TYPE:
        return lhs_val->greater_than(rhs_val);
    case OperationType::LTE_TYPE:
        return lhs_val->less_than_or_equal_to(rhs_val);
    case OperationType::GTE_TYPE:
        return lhs_val->greater_than_or_equal_to(rhs_val);
    }   
}
const Value* InterpretVisitor::VisitNAssignment(const NAssignment *element, Context* context) const
{
    // Get the identifier for the left hand side
    const IdentifierValue* lhs_id = dynamic_cast<const IdentifierValue*>(element->lhs.Accept(this, context));

    // Get the value for the right hand side and check errors
    const Value* rhs_val = element->rhs.Accept(this, context);
    if (rhs_val->get_isError())
        return rhs_val;

    // Check to see if the rhs is an identifier and get it's value
    const IdentifierValue* rhs_id = dynamic_cast<const IdentifierValue*>(rhs_val);
    if (rhs_id)
    {
        rhs_val = context->find_value(rhs_id->value);
        if (rhs_val->get_isError())
            return rhs_val;
    }

    // Set the value to the identifier in the current context
    const bool variable_set = context->set_value(lhs_id, rhs_val);
    if (!variable_set)
        return new ErrorValue(lhs_id->value + " does not exist in this scope");
    
    // return the variable assigned?
    return lhs_id;
}
const Value* InterpretVisitor::VisitNBlock(const NBlock *element, Context* context) const
{
    ValueVec value;
    // Context* new_context = new Context(context);

    // For each statement in the block evaluate it
    for (NStatement* stmnt : element->statements)
    {
        // evaluate the statement
        const Value* val = stmnt->Accept(this, context);
        // If statement is to return then return the value
        const ReturnValue* ret = dynamic_cast<const ReturnValue*>(val);
        if (ret)
            return ret->value;
        value.push_back(val);
    }
    return new ListValue(value);
}
const Value* InterpretVisitor::VisitNExpressionStatement(const NExpressionStatement *element, Context* context) const
{
    return element->expression.Accept(this, context);
}
const Value* InterpretVisitor::VisitNReturnStatement(const NReturnStatement *element, Context* context) const
{
    // Get the value to return
    const Value* value = element->expression->Accept(this, context);

    // If value is an identifier get the value associated with it
    const IdentifierValue* id = dynamic_cast<const IdentifierValue*>(value);
    if (id)
    {
        value = context->find_value(id->value);
    }
    return new ReturnValue(value);
}
const Value* InterpretVisitor::VisitNVariableDeclaration(const NVariableDeclaration *element, Context* context) const
{
    // Get the Identifier from the Variable Declaration
    const IdentifierValue* id = dynamic_cast<const IdentifierValue*>(element->id.Accept(this, context));

    // Declare a Value
    const Value* val;

    // If the declaration included a value to be assigned to the identifier
    if (element->assignmentExpr)
    {
        // Retrieve the value to be assigned and check if it returns an error
        val = element->assignmentExpr->Accept(this, context);
        if (val->get_isError())
            return val;
        // Check if the value to be assigned is an identifier and needs to be converted to a value
        const IdentifierValue* id2 = dynamic_cast<const IdentifierValue*>(val);
        if (id2)
        {
            val = context->find_value(id2->value);
            if (val->get_isError())
                return val;
        }
        // If the variable type is not equal to the value type
        if (id->type != val->get_type())
            return new ErrorValue("Incompatible types");
    }

    // In the current context assign the value to the identifier
    const bool variable_set = context->set_value(id, val);
    if (!variable_set)
        return new ErrorValue("Error initializing " + id->value);
    return id;
}
const Value* InterpretVisitor::VisitNExternDeclaration(const NExternDeclaration *element, Context* context) const
{
    element->id.Accept(this, context);
    for (NVariableDeclaration* dec : element->arguments)
    {
        dec->Accept(this, context);
    }
    return new ErrorValue("NOT IMPLEMENTED");
}
const Value* InterpretVisitor::VisitNFunctionDeclaration(const NFunctionDeclaration *element, Context* context) const
{
    // Get the idenfitier associated with the function declaration
    const IdentifierValue* id = dynamic_cast<const IdentifierValue*>(element->id.Accept(this, context));

    // Create the expected parameters for the function
    ValueVec* arg_values = new ValueVec;
    for (NVariableDeclaration* dec : element->arguments)
    {
        arg_values->push_back(dec->Accept(this, context));
    }

    // Create a new context for the function
    Context* new_context = new Context(context);
    const FunctionValue* func_val = new FunctionValue(arg_values, new_context, element->block, id->type);

    // Assign the function value to the identifier in the current context
    context->set_value(id, func_val);

    return func_val;
}
const Value* InterpretVisitor::VisitNIfStatement(const NIfStatement *element, Context* context) const
{
    // If this is an else statement
    if (!element->condition_expr)
    {
        // Create a new context for else statement
        Context* new_context = new Context(context);
        return element->block.Accept(this, new_context);
    }

    // Evaluate the condition, check for errors and make sure its a bool
    const Value* condition_val = element->condition_expr->Accept(this, context);
    if (condition_val->get_isError())
        return condition_val;
    const BoolValue* condition = dynamic_cast<const BoolValue*>(condition_val);
    if (!condition)
        return new ErrorValue("The condition in the if statement must evaulate to a bool");

    // Check validity of condition
    if (condition->value)
    {
        // if true create a new context and evaluate the block
        Context* new_context = new Context(context);
        return element->block.Accept(this, new_context);
    }

    // If there is another if statement to check
    if (element->next_if)
        return element->next_if->Accept(this, context);
    return new VoidValue();
}
const Value* InterpretVisitor::VisitNForStatement(const NForStatement *element, Context* context) const
{
    // Ensure the counter evaluates to an identifier
    const IdentifierValue* counter = dynamic_cast<const IdentifierValue*>(element->counter->Accept(this, context));
    if (!counter)
        return new ErrorValue("The first argument of a for loop must be an assignment or declaration");

    // Ensure the condition evaluates to a bool
    const BoolValue* condition = dynamic_cast<const BoolValue*>(element->condition->Accept(this, context));
    if (!condition)
        return new ErrorValue("The second argument of a for loop must return a bool");

    ValueVec result;
    while(true)
    {
        // If the condition is false then end the loop
        if (!condition->value)
        {
            break;
        }
        // Append the results of the for loop
        result.push_back(element->block.Accept(this, context));
        // Increment the counter
        element->change->Accept(this,context);
        // Compute the condition again
        condition = dynamic_cast<const BoolValue*>(element->condition->Accept(this, context));
    }
    return new ListValue(result);
}
const Value* InterpretVisitor::VisitNWhileStatement(const NWhileStatement *element, Context* context) const
{
    // Ensure the condition evaluates to a bool
    const BoolValue* condition = dynamic_cast<const BoolValue*>(element->condition->Accept(this, context));
    if (!condition)
        return new ErrorValue("The argument for a while loop must return a bool");
    
    ValueVec result;
    while(true)
    {
        // If the condition is false then end the loop
        if (!condition->value)
        {
            break;
        }
        
        // Append the results of the while loop
        result.push_back(element->block.Accept(this, context));
        // Compute the condition again
        condition = dynamic_cast<const BoolValue*>(element->condition->Accept(this, context));
    }
    return new ListValue(result);
}