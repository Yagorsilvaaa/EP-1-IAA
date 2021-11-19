#include "utils.h"
#include "quick sort.c"
#include "utils.c"

int selection1 (int* array, int i, int size) {
    quicksort(array, size);
    return array[i];
}

int selection2 (int* array, int i, int size) {
    if (size == 0) return array[0];

    int q = partition(array, size);

    if(i < q){
        size = q - 1;
        return selection2(&array, i, size);
    } else if (i > q) {
        i -= (q+1);
        size -= q;
        return selection2(&array[q], i, size);
    } else {
        return array[q];
    }
}