# include_directories (${TEST_SOURCE_DIR}/src)
add_executable(
  tests
  for_test.cpp
  bin_op_test.cpp
  value_test.cpp
  node_test.cpp
)
target_link_libraries(
    tests
  GTest::gtest_main
  gmock
  LokusLib
)

include(GoogleTest)
gtest_discover_tests(tests)