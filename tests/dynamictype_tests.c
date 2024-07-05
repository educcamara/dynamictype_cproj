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
    assert(dynamictype->n_fields == 0);

    printf("- create_dynamic_type() tests passed\n");
}

void test_add_field() {
    tDynamicType *dynamictype = create_dynamic_type("Person");
    add_field(dynamictype, "name", "char*", "John Doe");

    assert(dynamictype->n_fields == 1);
    assert(strcmp(get_field(dynamictype, "name"), "John Doe") == 0);

    int num = 30;
    add_field(dynamictype, "age", "int", &num);

    assert(dynamictype->n_fields == 2);
    assert(*(int *) get_field(dynamictype, "age") == 30);

    printf("- add_field() tests passed\n");
}

void test_get_field() {
    tDynamicType *dynamictype = create_dynamic_type("Person");
    add_field(dynamictype, "name", "char*", "John Doe");

    assert(strcmp(get_field(dynamictype, "name"), "John Doe") == 0);
    assert(get_field(dynamictype, "age") == NULL);

    printf("- get_field() tests passed\n");
}
