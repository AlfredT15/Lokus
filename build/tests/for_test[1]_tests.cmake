add_test( for_test.BasicAssertions /home/alfred/Code/Language/new_langauge/Lokus/build/tests/for_test [==[--gtest_filter=for_test.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( for_test.BasicAssertions PROPERTIES WORKING_DIRECTORY /home/alfred/Code/Language/new_langauge/Lokus/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( for_test_TESTS for_test.BasicAssertions)
