#include "array.h"


int main(int argc, char** argv) {
    Array* arr = init_array(10);
    Array* arr2 = init_array(10);
    for (int i = 0; i < arr->size; i++) {
        arr->arr[i] = i;
    }

    print_arr(arr);
    print_arr(arr2);
    arr = expand(arr, arr2);
    print_arr(arr);

    free(arr);
    free(arr2);
}
