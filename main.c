#include "array.h"
#include "stdlib.h"
#include "string.h"


int main(int argc, char** argv) {
    Array* arr = init_array(10);
    Array* arr2 = init_array(10);
    for (int i = 0; i < 10; i++) {
        arr->arr[i] = i;
    }

    print_arr(arr);
    print_arr(arr2);
    arr = expand(arr, arr2);
    print_arr(arr);

    free(arr);
    free(arr2);
}
