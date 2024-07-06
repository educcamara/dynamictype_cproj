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
} tDynamicTypeTemplate;

/**
 * @brief Struct that represents a field of a dynamic type
 */
typedef struct Field {
    tFieldTemplate *template; /** Template of the field */
    void *data; /** Data of the field */
} tField;

/**
 * @brief Struct that represents a dynamic type
 */
typedef struct DynamicType {
    tDynamicTypeTemplate *template; /** Template of the dynamic type */
    tLSE *fields; /** Fields of the dynamic type */
} tDynamicType;

/**
 * @brief Creates a dynamic type template
 *
 * @param name The name of the dynamic type template
 *
 * @return A pointer to the created dynamic type template
 */
tDynamicTypeTemplate *create_dynamic_type_template(const char *name);

/**
 * @brief Creates a dynamic type
 *
 * @return A pointer to the created dynamic type
 */
tDynamicType *create_dynamic_type(tDynamicTypeTemplate *template);

/**
 * @brief Adds a field template to a dynamic type template
 *
 * @param dynamictemplate The dynamic type template to add the field template
 * @param name The name of the field template
 * @param type The type of the field template
 *
 * @return a boolean indicating if the field template was added successfully
 */
unsigned char add_field_template(tDynamicTypeTemplate *dynamictemplate, const char *name, const char *type);

/**
 * @brief Gets a field from a dynamic type
 *
 * @param dynamictype The dynamic type to get the field
 * @param name The name of the field
 *
 * @return A pointer to the field itself or NULL if the field is not found
 *
 */
tField *get_field_dynamic_type(tDynamicType *dynamictype, const char *name);

/**
 * @brief Adds data to a field of a dynamic type
 *
 * @param dynamictype The dynamic type to add the data
 * @param name The name of the field
 * @param data The data to be added
 *
 * @return a boolean indicating if the data was added successfully
 */
unsigned char add_field_data_dynamic_type(tDynamicType *dynamictype, const char *name, void *data);

#endif //DYNAMICTYPE_H
