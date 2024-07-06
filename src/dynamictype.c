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

static int __compare_fields(void *a, void *b) {
    tField *field_a = (tField *) a;
    tField *field_b = (tField *) b;

    return strcmp(field_a->template->name, field_b->template->name);
}

tDynamicTypeTemplate *create_dynamic_type_template(const char *name) {
    tDynamicTypeTemplate *dynamictype = (tDynamicTypeTemplate *) malloc(sizeof(tDynamicTypeTemplate));

    strncpy(dynamictype->name, name, sizeof(char) * 20);
    dynamictype->fields = criar_lse(__compare_field_templates, NULL);

    return dynamictype;
}

static tField *__create_field(tFieldTemplate *template, void *data) {
    tField *field = (tField *) malloc(sizeof(tField));

    field->template = template;
    field->data = data;

    return field;
}

tDynamicType *create_dynamic_type(tDynamicTypeTemplate *template) {
    tDynamicType *dynamictype = (tDynamicType *) malloc(sizeof(tDynamicType));
    if (dynamictype == NULL) { return NULL; }

    dynamictype->template = template;
    dynamictype->fields = criar_lse(__compare_fields, NULL);

    tElem_LSE *aux = template->fields->prim;
    while (aux != NULL) {
        tFieldTemplate *field_template = (tFieldTemplate *) aux->carga_util;
        tField *field = __create_field(field_template, NULL);

        inserir_final_lse(dynamictype->fields, field);

        aux = aux->prox;
    }

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
