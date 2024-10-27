#ifndef H_DARRAY
#define H_DARRAY

#include <stdlib.h>

/* opaque type -- the struct should be implemented in a .c file  */
typedef struct darray{
    int *data;
    size_t size;
    size_t capacity;
} darray;


/*
 * Create an empty darray object of size 0 and return a pointer to it. If the
 * creation should fail, return NULL.
 */
darray *da_create(){
    int *array = malloc(0);
    if (array == NULL){
        return NULL;
    }
    else{
    return array;
    }
}
/*
 * Access the element stored at index idx within the darray and return a
 * pointer to it. If the idx is out of range for the darray, return NULL
 * instead. If the provided array pointer is NULL, return NULL.
 */
int *da_get(darray *array, size_t idx){
    if (idx > sizeof(array) || idx==NULL){
        return NULL;
    }
    else{
        return &array->data[idx];
    }
}

/*
 * Increase the length of array by 1 and place value within the newly created
 * spot. If the append operation fails, return 0. Otherwise return 1. Return 0
 * also if the provided array pointer is null.
 */
int da_append(darray *array, int value){
    if (array == NULL || value == NULL){
        return 0;
    }
    else{
        array->data[array->size] = value;
        array->size++;
        return 1;
    }
}

/*
 * Returns the size of the array. Note that this size should be the accessible
 * size (using get, for example), not the physical size of the allocation,
 * which may be larger. If array is NULL, return 0.
 */
size_t da_size(darray *array){
    if (array == NULL){
        return 0;
    }
    else{
        return sizeof(array);
    }
}


/*
 * Free all the allocated memory associated with array. If array is NULL, do
 * nothing.
 */
void da_delete(darray *array){
if (array == NULL){
    return 0;
} 
else {
    free(array);
    return 1;
}
}

#endif
