#ifndef FUNCTION_H
#define FUNCTION_H

#define RED 0
#define BLUE 1

typedef struct {
    char color;
    unsigned int size;
} Floor;

int compare(const void *a, const void *b){
    const Floor* fa = (Floor*) a;
    const Floor* fb = (Floor*) b;
    return fb->size - fa->size;
}

int design(int floorNum, Floor floorArr[]){
    int height, color;
    int idx;

    qsort(floorArr, floorNum, sizeof(Floor), compare);

    height = 1;
    color = (floorArr[0].color == 'B') ? BLUE : RED;
    // 表示前一位的color
    int idx_pre=0; // the previous picked index

    for (idx = 1; idx < floorNum; idx++) {
        if (color == BLUE && floorArr[idx].color == 'R' && (floorArr[idx_pre].size+floorArr[idx].size)%2 ) {
            height++;
            idx_pre=idx;
            color = RED;
        }
        else if (color == RED && floorArr[idx].color == 'B' && (floorArr[idx_pre].size+floorArr[idx].size)%2 ) {
            height++;
            idx_pre=idx;
            color = BLUE;
            }
    }
    return height;
}


#endif
