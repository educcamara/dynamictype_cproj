#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "dynamictype.h"

void test_create_dynamic_type();
void test_add_field();
void test_get_field();

int main(void) {
    test_create_dynamic_type();
    test_add_field();
    test_get_field();

    printf("All tests passed\n");

    return 0;
}

void test_create_dynamic_type() {
    tDynamicType *dynamictype = create_dynamic_type("Person");

    assert(dynamictype != NULL);
    assert(strcmp(dynamictype->name, "Person") == 0);
    assert(dynamictype->fields != NULL);
    assert(dynamictype->fields->tam == 0);

    printf("- create_dynamic_type() tests passed\n");
}

void test_add_field() {
    tDynamicType *dynamictype = create_dynamic_type("Person");
    add_field(dynamictype, "name", "char*", "John Doe");

    assert(dynamictype->fields->tam == 1);
    tField *field = (tField *) dynamictype->fields->prim->carga_util;
    assert(strcmp(field->name, "name") == 0);
    assert(strcmp(field->type, "char*") == 0);
    assert(strcmp(field->data, "John Doe") == 0);

    int num = 30;
    add_field(dynamictype, "age", "int", &num);

    assert(dynamictype->fields->tam == 2);
    field = (tField *) dynamictype->fields->ult->carga_util;
    assert(strcmp(field->name, "age") == 0);
    assert(strcmp(field->type, "int") == 0);
    assert(*(int *) field->data == 30);

    printf("- add_field() tests passed\n");
}

void test_get_field() {
    tDynamicType *dynamictype = create_dynamic_type("Person");
    add_field(dynamictype, "name", "char*", "John Doe");

    tField *field = get_field(dynamictype, "name");
    assert(field != NULL);
    assert(strcmp(field->name, "name") == 0);
    assert(strcmp(field->type, "char*") == 0);
    assert(strcmp(field->data, "John Doe") == 0);

    assert(get_field(dynamictype, "age") == NULL);

    printf("- get_field() tests passed\n");
}
