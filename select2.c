#include "utils.h"
#include "quick sort.c"
#include "utils.c"
#include <malloc.h>
#include <time.h>

#define VAL 512*10000

int selection2 (int* array, int i, int size) {
    if (size == 0) return array[0];

    int q = partition(array, size);

    if(i < q){
        size = q - 1;
        return selection2(&array[0], i, size);
    } else if (i > q) {
        i -= (q+1);
        size -= q;
        return selection2(&array[q], i, size);
    } else {
        return array[q];
    }
}

int main () {
    int* array = (int*) malloc(sizeof(int)*(VAL));
    int i;

    for(i=0; i<VAL; i++) scanf("%d", &array[i]);

    clock_t start1 = clock();
    int r1 = selection2(array, 3000000, VAL);
    clock_t pause1 = clock();

    float time_spent1 = (float) (pause1 - start1) / CLOCKS_PER_SEC;
    printf("\nTempo decorrido: %.3f\n", time_spent1);

    printf("o iessimo menor elemento e: %d\n", r1);

    return 0;
}