//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#include "dynamictype.h"
#include <string.h>
#include <stdlib.h>

static int __compare_fields(const void *a, const void *b) {
    tField *field_a = (tField *) a;
    tField *field_b = (tField *) b;

    return strcmp(field_a->name, field_b->name);
}

tDynamicType *create_dynamic_type(const char *type_name) {
    tDynamicType *dynamictype = (tDynamicType *) malloc(sizeof(tDynamicType));

    strcpy(dynamictype->name, type_name);
    dynamictype->fields = criar_lse(__compare_fields, NULL);

    return dynamictype;
}

void add_field(tDynamicType *dynamictype, char *name, char *type, void *data) {
    tLSE *fields = dynamictype->fields;

    tField *field = (tField *) malloc(sizeof(tField));
    strcpy(field->name, name);
    strcpy(field->type, type);
    field->data = data;

    inserir_final_lse(fields, field);
}

void *get_field(tDynamicType *dynamictype, const char *name) {
    tField *field = (tField *) buscar_elem_lse(dynamictype->fields, name);

    return field != NULL ? field->data : NULL;
}
