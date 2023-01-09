# Lokus

Lokus is a custom language written in C++. It uses Flex and Bison for the parser and lexer. The language is interpreted and it's syntax is similar to python and C++. As of now basically functionality 
has been implemented into the language, allowing you to create functions, if statements, for and while loops, and basic types 
(int, float, bool, string, list). 

The language uses cmake as it's build system and it is fully unit tested using gtest.

The work on the language could continue almost indefinetly but I decided to call it complete for now when I was able to implement
a suduko solver in the language.

## How to build

To build the project enter into the root directory of the project and run

`cmake --build build`

This will rebuild the project for you. Once it has successfully built you can run the language through the executable located at

`Lokus/build/src/Lokus`

There are example files located in `Lokus/examples` with the .lk file extension. The file extension is just convention and is not neccessary.
The most interesting file is `sudoku_solver.lk` where I have implemented a suduko solver in the language. To run it type

`./build/src/Lokus examples/sudoku_solver.lk`

and you should see the following output

```
Board inputed: 
7  8  0   |  4  0  0   |  1  2  0
6  0  0   |  0  7  5   |  0  0  9
0  0  0   |  6  0  1   |  0  7  8
- - - - - - - - - - - - - - - - -
0  0  7   |  0  4  0   |  2  6  0
0  0  1   |  0  5  0   |  9  3  0
9  0  4   |  0  6  0   |  0  0  5
- - - - - - - - - - - - - - - - -
0  7  0   |  3  0  0   |  0  1  2
1  2  0   |  0  0  7   |  4  0  0
0  4  9   |  2  0  6   |  0  0  7
__________________________________
Solved:
7  8  5   |  4  3  9   |  1  2  6
6  1  2   |  8  7  5   |  3  4  9
4  9  3   |  6  2  1   |  5  7  8
- - - - - - - - - - - - - - - - -
8  5  7   |  9  4  3   |  2  6  1
2  6  1   |  7  5  8   |  9  3  4
9  3  4   |  1  6  2   |  7  8  5
- - - - - - - - - - - - - - - - -
5  7  8   |  3  9  4   |  6  1  2
1  2  6   |  5  8  7   |  4  9  3
3  4  9   |  2  1  6   |  8  5  7
```

## Language Syntax

### Basic language structure

There is no semi colons used to signify the end of a statement. Typically every line has on it only one statement. However if you wanted to include more
statements on one line you can, they just have to be seperated by at least one space.

### Types

- Integer
  - Syntax of 'int'
- Float
  - Syntax of 'float'
- Bool
  - Syntax of 'bool'
- String
  - Syntax of 'string'
- List
  - Syntax of 'list'
- Void
  - Syntax of 'void'
  
 ### Creating a variable
 
 A variable is declared like
 `TYPE NAME = VALUE` or `TYPE NAME`. An example is `int test = 1`
 
 #### Creating a list
 
 A list is an array in this language. You can create a list like so `list test = [1,2,3,4]`. A list can store a mix of data types or it can be multi
 dimensional.
 
 ### Declaring a function
 
A function is declared like `TYPE FUNC_NAME(TYPE PARAM_NAME, ... )`. An example is `void print_board(list board)`

### Operations

The following operations have been implemented

Operation      | Implementation
-------------  | -------------
Addition | +
Subtraction | -
Multiplication | *
Division | /
Modulus | %
Not equal | !=
Greater than | >
Less than | <
Greater than or equal to | >=
Less than or equal to | <=
And | and
Or | or

### Loops

You can create for loops and while loops

#### For loops

Can create a for loop as follows `for (DECLARATION, CONDITION, CHANGE) { BODY }`. An example is

```
for (int i = 0, i < 10 i = i + 1)
{
  print(i)
}
```

#### While loops

Can create a while loop as follows `while EXPRESSION { BODY }`. An example is

```
int i = 0
while i < 10
{
  print(i)
  i = i + 1
}
```

### Conditionals

#### If Statements

Can create an if statment as follows `if EXPRESSION { BODY }`. An example is
```
int i = 0
if i == 0
{
  print("i is 0")
}
```

#### Else If Statements

Can create an else if statment as follows `elif EXPRESSION { BODY }`. An example is
```
int i = 1
if i == 0
{
  print("i is 0")
}
elif i == 1
{
  print("i is 1") 
}
```

#### Else Statements

Can create an else statment as follows `else { BODY }`. An example is
```
int i = 2
if i == 0
{
  print("i is 0")
}
elif i == 1
{
  print("i is 1") 
}
else
{
  print("i is neither 0 or 1")
}
```

### Special Functions

- print
  - You can print to the console with `print(EXPRESION)`
  - the print expression automatically prints your expression with a new line as well
  - you can print a line with your own ending through `print(EXPRESSION, ENDING_EXPRESSION)`
- len
  - Can find the length of a list or string

