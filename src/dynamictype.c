//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#include "dynamictype.h"
#include <string.h>
#include <stdlib.h>

tDynamicType *create_dynamic_type(const char *type_name) {
    tDynamicType *dynamictype = (tDynamicType *) malloc(sizeof(tDynamicType));

    strcpy(dynamictype->name, type_name);
    dynamictype->fields = criar_Hash(NULL);
    dynamictype->n_fields = 0;

    return dynamictype;
}

void add_field(tDynamicType *dynamictype, char *name, char *type, void *data) {
    tTabelaHash *fields = dynamictype->fields;

    tField *field = (tField *) malloc(sizeof(tField));
    strcpy(field->name, name);
    strcpy(field->type, type);
    field->data = data;

    inserir_Hash(fields, name, field);

    dynamictype->n_fields++;
}
