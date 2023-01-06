#include <iostream>
#include "../include/node.hpp"
#include "../include/visitor.hpp"
#include "../include/context.hpp"

using namespace std;

extern int yyparse();
extern FILE *yyin;
extern NBlock* programBlock;

void print_output(const Value* val)
{
    if (dynamic_cast<const ErrorValue*>(val))
    {
        printf("%s\n", (*((std::string*)val->get_value())).c_str());
        return;
    }
    else if (dynamic_cast<const StringValue*>(val))
        printf("%s\n", ((std::string*)val->get_value())->c_str());
    else if (dynamic_cast<const IntValue*>(val))
        printf("%d\n", *((int*)val->get_value()));
    else if (dynamic_cast<const DoubleValue*>(val))
        printf("%f\n", *((double*)val->get_value()));
    else if (dynamic_cast<const BoolValue*>(val))
        printf("%d\n", *((int*)val->get_value()));
    else if (dynamic_cast<const ListValue*>(val))
    {
        const ListValue* val2 = dynamic_cast<const ListValue*>(val);
        for (const Value* element_val : val2->value)
        {
            print_output(element_val);
        }
    }
}

void print_output_list(const ListValue* output)
{
    for (const Value* val : output->value)
    {
        if (dynamic_cast<const ErrorValue*>(val))
        {
            printf("%s\n", (*((std::string*)val->get_value())).c_str());
            return;
        }
        else if (dynamic_cast<const PrintValue*>(val))
        {
            print_output((const Value*)val->get_value());
        }
        else if (dynamic_cast<const ListValue*>(val))
            print_output_list(dynamic_cast<const ListValue*>(val));
    }
}

int main(int argc, char **argv)
{
    // open a file handle to a particular file:
    FILE *myfile = fopen(argv[1], "r");
    // make sure it is valid:
    if (!myfile) {
        cout << "I can't open " << argv[1] << "!" << endl;
        return -1;
    }
    // Set flex to read from it instead of defaulting to STDIN:
    yyin = myfile;
	yyparse();
    // const PrintVisitor *visitor = new PrintVisitor();
    const InterpretVisitor *visitor = new InterpretVisitor();
    Context* master_context = new Context();
    const Value* out = programBlock->Accept(visitor, master_context);
    if (out->get_isError())
    {
        printf("%s", (*((std::string*)out->get_value())).c_str());
        return 0;
    }
	const ListValue* output = dynamic_cast<const ListValue*>(out);	
    print_output_list(output);
	return 0;
}