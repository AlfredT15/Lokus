#include <iostream>
#include "../include/node.hpp"
#include "../include/visitor.hpp"
#include "../include/context.hpp"

using namespace std;

extern int yyparse();
extern FILE *yyin;
extern NBlock* programBlock;


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
    for (const Value* val : output->value)
    {
        if (dynamic_cast<const ErrorValue*>(val))
        {
            printf("%s\n", (*((std::string*)val->get_value())).c_str());
            return 0;
        }
        else if (dynamic_cast<const IntValue*>(val))
            printf("%d\n", *((int*)val->get_value()));
        else if (dynamic_cast<const DoubleValue*>(val))
            printf("%f\n", *((double*)val->get_value()));
        else if (dynamic_cast<const BoolValue*>(val))
            printf("%d\n", *((int*)val->get_value()));
    }
	return 0;
}