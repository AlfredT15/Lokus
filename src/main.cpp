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
        printf("%s\n", (*((std::string*)out->get_value())).c_str());
    }
	return 0;
}