#include <stdio.h>
#include <stdlib.h>
#include "11752 - My Insertion Sort.h"

int main(int argc, char *argv[])
{
    int* data;
    int i;
    int size = 0;

    scanf("%d", &size);

    data = (int*) malloc(size * sizeof(int));

    for (i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }
//    printf("ok\n");

    mysort(data, size, sizeof(int), compare);
//    printf("ok\n");

    for (i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}