//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#include "dynamictype.h"
#include <string.h>
#include <stdlib.h>

static int __compare_field_templates(void *a, void *b) {
    tFieldTemplate *field_a = (tFieldTemplate *) a;
    tFieldTemplate *field_b = (tFieldTemplate *) b;

    return strcmp(field_a->name, field_b->name);
}

tDinamicTypeTemplate *create_dynamic_type_template(const char *name) {
    tDinamicTypeTemplate *dynamictype = (tDinamicTypeTemplate *) malloc(sizeof(tDinamicTypeTemplate));

    strncpy(dynamictype->name, name, sizeof(char) * 20);
    dynamictype->fields = criar_lse(__compare_field_templates, NULL);

    return dynamictype;
}

tDynamicType *create_dynamic_type(const char *type_name) {
    tDynamicType *dynamictype = (tDynamicType *) malloc(sizeof(tDynamicType));

    strcpy(dynamictype->name, type_name);
    dynamictype->fields = criar_lse(__compare_fields, NULL);

    return dynamictype;
}

unsigned char add_field(tDynamicType *dynamictype, char *name, char *type, void *data) {
    tLSE *fields = dynamictype->fields;

    if (get_field(dynamictype, name) != NULL) {
        return 0;
    }

    tField *field = (tField *) malloc(sizeof(tField));
    strcpy(field->name, name);
    strcpy(field->type, type);
    field->data = data;

    inserir_final_lse(fields, field);
    return 1;
}

tField *get_field(tDynamicType *dynamictype, const char *name) {
    return (tField *) buscar_elem_lse(dynamictype->fields, (void *) name);
}
