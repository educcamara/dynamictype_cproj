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
tDynamicType *create_dynamic_type();

#endif //DYNAMICTYPE_H
