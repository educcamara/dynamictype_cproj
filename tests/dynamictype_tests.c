#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "dynamictype.h"

tDynamicTypeTemplate *custom_dynamic_template();

void test_create_and_free_dynamic_type();
void teste_get_field();
void test_add_field_data();

int main(void) {
    test_create_and_free_dynamic_type();
    teste_get_field();
    test_add_field_data();

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
    tDynamicTypeTemplate *dynamictemplate = custom_dynamic_template();
    tDynamicType *dynamictype = create_dynamic_type(dynamictemplate);

    assert(dynamictype != NULL);
    assert(strcmp(dynamictype->template->name, "Person") == 0);
    assert(dynamictype->fields->tam == 2);
    assert(dynamictype->fields->prim != NULL);
    assert(dynamictype->fields->prim->carga_util != NULL);
    assert(((tField*) dynamictype->fields->prim->carga_util)->template != NULL);
    assert(((tField*) dynamictype->fields->prim->carga_util)->data == NULL);

    free_dynamic_type(dynamictype);
    free_dynamic_type_template(dynamictemplate);

    printf("- create_dynamic_type() and free_dynamic_type() tests passed\n");
}

void teste_get_field() {
    tDynamicTypeTemplate *dynamictemplate = custom_dynamic_template();
    tDynamicType *dynamictype = create_dynamic_type(dynamictemplate);

    tField *field = get_field_dynamic_type(dynamictype, "name");
    assert(field != NULL);
    assert(strcmp(field->template->name, "name") == 0);
    assert(field->data == NULL);

    field = get_field_dynamic_type(dynamictype, "age");
    assert(field != NULL);
    assert(strcmp(field->template->name, "age") == 0);
    assert(field->data == NULL);

    field = get_field_dynamic_type(dynamictype, "not_found");
    assert(field == NULL);

    free_dynamic_type(dynamictype);
    free_dynamic_type_template(dynamictemplate);

    printf("- get_field_dynamic_type() tests passed\n");
}

void test_add_field_data() {
    tDynamicTypeTemplate *dynamictemplate = custom_dynamic_template();
    tDynamicType *dynamictype = create_dynamic_type(dynamictemplate);

    char str[20] = "Eduardo";
    unsigned char res = add_field_data_dynamic_type(dynamictype, "name", str);

    assert(res == 1);
    tField *field = get_field_dynamic_type(dynamictype, "name");
    assert(strcmp((char*) field->data, str) == 0);

    int age = 24;
    res = add_field_data_dynamic_type(dynamictype, "age", &age);

    assert(res == 1);
    field = get_field_dynamic_type(dynamictype, "age");
    assert(*(int*) field->data == age);

    res = add_field_data_dynamic_type(dynamictype, "not_found", NULL);
    assert(res == 0);

    free_dynamic_type(dynamictype);
    free_dynamic_type_template(dynamictemplate);

    printf("- add_field_data_dynamic_type() tests passed\n");
}

