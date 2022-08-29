#include <iostream>
#include "../include/node.hpp"
#include "../include/visitor.hpp"

using namespace std;

extern int yyparse();
extern FILE *yyin;
extern NBlock* programBlock;


int main(int argc, char **argv)
{
    // open a file handle to a particular file:
    FILE *myfile = fopen("test.lk", "r");
    // make sure it is valid:
    if (!myfile) {
        cout << "I can't open test.lk!" << endl;
        return -1;
    }
    // Set flex to read from it instead of defaulting to STDIN:
    yyin = myfile;
	yyparse();
    // const PrintVisitor *visitor = new PrintVisitor();
    const InterpretVisitor *visitor = new InterpretVisitor();
	const ListValue* output = dynamic_cast<const ListValue*>(programBlock->Accept(visitor));	
    for (const Value* val : output->value)
    {
        printf("%d", val->get_value());
    }
	return 0;
}