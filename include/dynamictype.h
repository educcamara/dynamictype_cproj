//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#ifndef DYNAMICTYPE_H
#define DYNAMICTYPE_H

#include <lista_se.h>

/**
 * @brief Struct that represents a field template
 */
typedef struct FieldTemplate {
    char name[20]; /** Name of the field template */
    char type[20]; /** Type of the field template */
} tFieldTemplate;

/**
 * @brief Struct that represents a dynamic type template
 */
typedef struct DynamicTypeTemplate {
    char name[20]; /** Name of the dynamic type template */
    tLSE *fields; /** Template fields of the dynamic type template */
} tDinamicTypeTemplate;

/**
 * @brief Struct that represents a field of a dynamic type
 */
typedef struct Field {
    tLSE *template; /** Template of the field */
    void *data; /** Data of the field */
} tField;

/**
 * @brief Struct that represents a dynamic type
 */
typedef struct DynamicType {
    tDinamicTypeTemplate *template; /** Template of the dynamic type */
    tLSE *fields; /** Fields of the dynamic type */
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
 *
 * @return a boolean indicating if the field was added successfully
 */
unsigned char add_field(tDynamicType *dynamictype, char *name, char *type, void *data);

/**
 * @brief Gets a field from a dynamic type
 *
 * @param dynamictype The dynamic type to get the field
 * @param name The name of the field
 *
 * @return A pointer to the field itself or NULL if the field is not found
 *
 */
tField *get_field(tDynamicType *dynamictype, const char *name);

#endif //DYNAMICTYPE_H
