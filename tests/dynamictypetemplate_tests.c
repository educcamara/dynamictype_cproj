//
// Created by Eduardo Cordeiro da Camara on 06/07/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "dynamictype.h"

void test_create_dynamic_type_template();

int main(void) {
    test_create_dynamic_type_template();

    printf("All tests passed on dynamictypetemplate_tests\n");
    return 0;
}

void test_create_dynamic_type_template() {
    tDynamicTypeTemplate *dynamictype = create_dynamic_type_template("Person");

    assert(dynamictype != NULL);
    assert(strcmp(dynamictype->name, "Person") == 0);
    assert(dynamictype->fields != NULL);
    assert(dynamictype->fields->tam == 0);

    printf("- create_dynamic_type_template() tests passed\n");
}