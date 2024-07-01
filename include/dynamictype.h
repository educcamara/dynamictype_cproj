//
// Created by Eduardo Cordeiro da Camara on 30/06/24.
//

#ifndef DYNAMICTYPE_H
#define DYNAMICTYPE_H

/**
 * @brief Struct that represents a field of a dynamic type
 */
typedef struct Field tField;

/**
 * @brief Struct that represents a dynamic type
 */
typedef struct DynamicType tDynamicType;

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

#endif //DYNAMICTYPE_H
