//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#include "dynamictype.h"
#include <string.h>
#include <stdlib.h>

#define MAX_FIELDS 16
#define MAX_DATA 256

struct Field {
    char name[20]; /** Name of the field */
    char type[20]; /** Type of the field */
    void *data; /** Data of the field */
};

struct DynamicType {
    char name[20]; /** Name of the dynamic type */
    tField fields[MAX_FIELDS]; /** Fields of the dynamic type */
    unsigned n_fields; /** Number of fields */
};

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
