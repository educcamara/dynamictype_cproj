//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#include "dynamictype.h"

#define MAX_FIELDS 16
#define MAX_DATA 256

struct Field {
    char name[20]; /** Name of the field */
    char type[20]; /** Type of the field */
    void *data; /** Data of the field */
};

struct DynamicType{
    tField fields[MAX_FIELDS]; /** Fields of the dynamic type */
    unsigned n_fields; /** Number of fields */
};
