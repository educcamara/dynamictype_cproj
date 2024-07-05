# Tests for dynamictype.c
add_executable(dynamictype_tests dynamictype_tests.c
        ${CMAKE_SOURCE_DIR}/src/dynamictype.c)
target_link_libraries(dynamictype_tests ${HASH_LIB} ${ARVOREBINARIA_LIB})
add_test(NAME dynamictype_tests COMMAND dynamictype_tests)