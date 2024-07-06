//
// Created by Eduardo Cordeiro da Camara on 06/07/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "dynamictype.h"

void test_create_and_free_dynamic_type_template();

int main(void) {
    test_create_and_free_dynamic_type_template();

    printf("All tests passed on dynamictypetemplate_tests\n");
    return 0;
}

void test_create_and_free_dynamic_type_template() {
    tDynamicTypeTemplate *dynamictype = create_dynamic_type_template("Person");

    assert(dynamictype != NULL);
    assert(strcmp(dynamictype->name, "Person") == 0);
    assert(dynamictype->fields != NULL);
    assert(dynamictype->fields->tam == 0);

    free_dynamic_type_template(dynamictype);

    tDynamicTypeTemplate *dynamictype2 = create_dynamic_type_template("String bigger than 20 characters");
    assert(dynamictype2 != NULL);
    assert(strcmp(dynamictype2->name, "String bigger than ") == 0);
    assert(dynamictype2->fields != NULL);
    assert(dynamictype2->fields->tam == 0);
    assert(dynamictype2->fields->tam == 0);

    free_dynamic_type_template(dynamictype2);

    printf("- create_dynamic_type_template() tests passed\n");
}