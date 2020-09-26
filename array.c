#include "array.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"


Array* init_array(const unsigned int size) {
   // create new array of size elems and initialise it with zeros
   Array* new_arr = (Array*)malloc(sizeof(new_arr));
   new_arr->arr = (int*)malloc(sizeof(int) * size);
   new_arr->size = size;
   new_arr = fill_with(new_arr, 0);

   return new_arr;
}

Array* append(Array* arr, int val) {
    // append a val to the Array
    Array* new_arr = init_array(arr->size + 1); // create new array
    new_arr->size = arr->size + 1;
    memcpy(new_arr->arr, arr->arr, sizeof(int) * arr->size); // copy elements from the old array to the new one
    new_arr->arr[new_arr->size - 1] = val; // set the last elem to the appended value

    free(arr->arr);
    free(arr); // free old array;

    return new_arr;
}

Array* erase(Array* arr, int index) {
    // remove element at index from arr
    Array* new_arr = init_array(arr->size - 1); // create new array
    memcpy(new_arr->arr, arr->arr, sizeof(int) * index);
    for (int i = index; i < arr->size - 1; i++){
        new_arr->arr[i] = arr->arr[i + 1];
    }

    free(arr->arr);
    free(arr);

    return new_arr;
}

Array* fill_with(Array* arr, int val) {
    // fill array with vals
    memset(arr->arr, val, sizeof(int) * arr->size);

    return arr;
}

int find(Array* arr, int val) {
    // return the index of the element that equals to val
    for (int i = 0; i < arr->size; i++) {
        if (arr->arr[i] == val)
            return i;
    }
    return -1;
}

Array* clear(Array* arr) {
    free(arr->arr);
    arr->size = 0;
    return arr;
}

Array* expand(Array* arr_to_be_expanded, Array* arr_to_expand_with) {
    // expand one array with the values of the second e.g expand({1, 2, 3}, {4, 5, 6}) - > {1, 2, 3, 4, 5, 6}
    int total_size = arr_to_be_expanded->size + arr_to_expand_with->size;
    Array* new_arr = init_array(total_size);
    memcpy(new_arr->arr, arr_to_be_expanded->arr, sizeof(int) * arr_to_be_expanded->size);
    for (int i = 0; i < arr_to_expand_with->size; i++) {
        new_arr->arr[i + arr_to_expand_with->size] = arr_to_expand_with->arr[i];
    }

    free(arr_to_be_expanded->arr);
    free(arr_to_be_expanded);

    return new_arr;
}

void print_arr(Array* arr) {
    // print all the elements of the given array to the console
    if (arr->size == 0) {
        printf("{}\n");
    }
    else {
        printf("{%d", arr->arr[0]);
        for (unsigned i = 1; i < arr->size; i++) {
            printf(", %d", arr->arr[i]);
        }
        printf("}\n");
    }
}
