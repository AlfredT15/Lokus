#include <iostream>
#include "../include/node.hpp"
#include "../include/visitor.hpp"
#include "../include/context.hpp"

using namespace std;

extern int yyparse();
extern FILE *yyin;
extern NBlock* programBlock;

void print_output(const ListValue* output, Context* master_context)
{
    for (const Value* val : output->value)
    {
        if (dynamic_cast<const PrintValue*>(val))
        {
            const Value* valToPrint = (const Value*)val->get_value();
            if (dynamic_cast<const ErrorValue*>(valToPrint))
            {
                printf("%s\n", (*((std::string*)valToPrint->get_value())).c_str());
                return;
            }
            else if (dynamic_cast<const StringValue*>(valToPrint))
                printf("%s\n", ((std::string*)valToPrint->get_value())->c_str());
            else if (dynamic_cast<const IntValue*>(valToPrint))
                printf("%d\n", *((int*)valToPrint->get_value()));
            else if (dynamic_cast<const DoubleValue*>(valToPrint))
                printf("%f\n", *((double*)valToPrint->get_value()));
            else if (dynamic_cast<const BoolValue*>(valToPrint))
                printf("%d\n", *((int*)valToPrint->get_value()));
        }
        else if (dynamic_cast<const ListValue*>(val))
            print_output(dynamic_cast<const ListValue*>(val), master_context);
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
    print_output(output, master_context);
	return 0;
}