#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "dynamictype.h"

tDynamicTypeTemplate *custom_dynamic_template();

void test_create_and_free_dynamic_type();
void test_add_field();
void test_get_field();

int main(void) {
    test_create_and_free_dynamic_type();
    test_add_field();
    test_get_field();

    printf("All tests passed\n");

    return 0;
}

tDynamicTypeTemplate *custom_dynamic_template() {
    tDynamicTypeTemplate *dynamictemplate = create_dynamic_type_template("Person");
    add_field_template(dynamictemplate, "name", "char*");
    add_field_template(dynamictemplate, "age", "int");

    return dynamictemplate;
}

void test_create_and_free_dynamic_type() {

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

    tField *field = get_field_dynamic_type(dynamictype, "name");
    assert(field != NULL);
    assert(strcmp(field->name, "name") == 0);
    assert(strcmp(field->type, "char*") == 0);
    assert(strcmp(field->data, "John Doe") == 0);

    assert(get_field_dynamic_type(dynamictype, "age") == NULL);

    printf("- get_field() tests passed\n");
}
