//
// Created by Eduardo Cordeiro da Camara on 06/07/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "dynamictype.h"

void test_create_and_free_dynamic_type_template();
void test_add_field_template();

int main(void) {
    test_create_and_free_dynamic_type_template();
    test_add_field_template();

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

void test_add_field_template() {
    tDynamicTypeTemplate *dynamictemplate = create_dynamic_type_template("Person");
    add_field_template(dynamictemplate, "name", "char*");

    assert(dynamictemplate->fields->tam == 1);
    assert(strcmp(((tFieldTemplate *) dynamictemplate->fields->prim->carga_util)->name, "name") == 0);
    assert(strcmp(((tFieldTemplate *) dynamictemplate->fields->prim->carga_util)->type, "char*") == 0);

    add_field_template(dynamictemplate, "age", "int");

    assert(dynamictemplate->fields->tam == 2);
    assert(strcmp(((tFieldTemplate *) dynamictemplate->fields->prim->carga_util)->name, "name") == 0);
    assert(strcmp(((tFieldTemplate *) dynamictemplate->fields->prim->carga_util)->type, "char*") == 0);
    assert(strcmp(((tFieldTemplate *) dynamictemplate->fields->ult->carga_util)->name, "age") == 0);
    assert(strcmp(((tFieldTemplate *) dynamictemplate->fields->ult->carga_util)->type, "int") == 0);

    free_dynamic_type_template(dynamictemplate);

    printf("- add_field_template() tests passed\n");
}