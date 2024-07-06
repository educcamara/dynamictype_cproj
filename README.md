# Dynamic Type Project

The General Configuration Structure:
- **Field Template:** A template for a field containing its custom name and a type conforming to the basic types of C.
- **Dynamic Type Template:** A template for a dynamic type containing its custom name and a Singly Linked List for the fields templates.
- **Field:** A field containing a field template and a `void *` to store the data.
- **Dynamic Type:** A dynamic type containing a dynamic type schema and a Singly Linked List for the fields.