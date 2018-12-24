#include <stdio.h>
#include <stdlib.h>

#include "10904.h"

#define MAX_FLOOR_NUM 20000





int main() {
    int floorNum;
    int i;

    Floor floorArr[MAX_FLOOR_NUM];

    scanf("%d", &floorNum);

    for (i = 0; i < floorNum; i++) {
        scanf(" %c %d", &floorArr[i].color, &floorArr[i].size);
    }

    printf("%d", design(floorNum, floorArr));

    return 0;
}
