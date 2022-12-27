add_library(LokusLib context.cpp node.cpp semantics.cpp syntax.cpp value.cpp visitor.cpp)
add_executable(Lokus main.cpp)
target_link_libraries(Lokus LokusLib)
target_include_directories(Lokus PUBLIC ../include)