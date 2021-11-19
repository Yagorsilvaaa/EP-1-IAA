#include "utils.h"
#include "quick sort.c"
#include "utils.c"
#include <malloc.h>
#include <time.h>

#define VAL 512*10000

int selection1 (int* array, int i, int size) {
    quicksort(array, size);
    return array[i];
}

int main () {
    int* array = (int*) malloc(sizeof(int)*(VAL));
    int i;

    for(i=0; i<VAL; i++) scanf("%d", &array[i]);

    clock_t start1 = clock();
    int r1 = selection1(array, 3000000, VAL);
    clock_t pause1 = clock();

    float time_spent1 = (float) (pause1 - start1) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido: %.3f\n", time_spent1);

    printf("o iessimo menor elemento e: %d\n", r1);

    return 0;
}