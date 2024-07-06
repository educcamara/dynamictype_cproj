# Tests for dynamictype.c
add_executable(dynamictypetemplate_tests dynamictypetemplate_tests.c
        ${CMAKE_SOURCE_DIR}/src/dynamictype.c)
target_link_libraries(dynamictypetemplate_tests ${LISTAENCADEADA_LIB})
add_test(NAME dynamictypetemplate_tests COMMAND dynamictypetemplate_tests)

add_executable(dynamictype_tests dynamictype_tests.c
        ${CMAKE_SOURCE_DIR}/src/dynamictype.c)
target_link_libraries(dynamictype_tests ${LISTAENCADEADA_LIB})
add_test(NAME dynamictype_tests COMMAND dynamictype_tests)

