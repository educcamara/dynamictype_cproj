//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#include "dynamictype.h"
#include <string.h>
#include <stdlib.h>

tDynamicType *create_dynamic_type(const char *type_name) {
    tDynamicType *dynamictype = (tDynamicType *) malloc(sizeof(tDynamicType));

    strcpy(dynamictype->name, type_name);
    dynamictype->fields = criar_lse(NULL, NULL);

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
