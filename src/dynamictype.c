//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#include "dynamictype.h"
#include <string.h>
#include <stdlib.h>

tDynamicType *create_dynamic_type(const char *type_name) {
    tDynamicType *dynamictype = (tDynamicType *) malloc(sizeof(tDynamicType));

    strcpy(dynamictype->name, type_name);
    dynamictype->n_fields = 0;

    return dynamictype;
}

void add_field(tDynamicType *dynamictype, char *name, char *type, void *data) {
    if (dynamictype->n_fields >= MAX_FIELDS) {
        return;
    }
    tField *field = &dynamictype->fields[dynamictype->n_fields];
    strcpy(field->name, name);
    strcpy(field->type, type);
    field->data = data;

    dynamictype->n_fields++;
}
