bison -d -o src/syntax.cpp src/syntax.y
# clang++ -c -o syntax.o syntax.cpp
flex -o src/semantics.cpp src/semantics.l
# clang++ -c -o semantics.o semantics.cpp
# g++ main.cpp visitor.cpp node.cpp syntax.cpp semantics.cpp -lfl -o lokus
clang++ -I include/ src/main.cpp src/context.cpp src/value.cpp src/visitor.cpp src/node.cpp src/syntax.cpp src/semantics.cpp -o lokus
# clang++ main.cpp visitor.cpp node.cpp semantics.o syntax.o -lfl -o lokus