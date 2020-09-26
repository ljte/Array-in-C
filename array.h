#ifndef ARRAY
#define ARRAY


typedef struct _Array {
    int* arr;
    unsigned int size;
} Array;


Array* init_array(const unsigned int size);
void print_arr(Array* arr);
Array* append(Array* arr, int val);
Array* erase(Array* arr, int index);
Array* expand(Array* arr_to_be_expanded, Array* arr_to_expand_with);
int find(Array* arr, int val);
Array* fill_with(Array* arr, int val);
Array* clear(Array* arr);

#endif
