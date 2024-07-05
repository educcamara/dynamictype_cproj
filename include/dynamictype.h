//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#ifndef DYNAMICTYPE_H
#define DYNAMICTYPE_H

#include <hash.h>

/**
 * @brief Struct that represents a field of a dynamic type
 */
typedef struct Field {
    char name[20]; /** Name of the field */
    char type[20]; /** Type of the field */
    void *data; /** Data of the field */
} tField;

/**
 * @brief Struct that represents a dynamic type
 */
typedef struct DynamicType {
    char name[20]; /** Name of the dynamic type */
    tTabelaHash *fields; /** Fields of the dynamic type */
    unsigned n_fields; /** Number of fields */
} tDynamicType;

/**
 * @brief Creates a dynamic type
 *
 * @return A pointer to the created dynamic type
 */
tDynamicType *create_dynamic_type(const char *type_name);

/**
 * @brief Adds a field to a dynamic type
 *
 * @param dynamictype The dynamic type to add the field
 * @param name The name of the field
 * @param type The type of the field
 * @param data The data of the field
 */
void add_field(tDynamicType *dynamictype, char *name, char *type, void *data);

/**
 * @brief Gets a field from a dynamic type
 *
 * @param dynamictype The dynamic type to get the field
 * @param name The name of the field
 *
 * @return The data of the field or NULL if the field is not found
 */
void *get_field(tDynamicType *dynamictype, const char *name);

#endif //DYNAMICTYPE_H
