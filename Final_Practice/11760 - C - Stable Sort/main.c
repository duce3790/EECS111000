#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[25];
    int score;
} Student;

void sort(Student* arr, size_t len) {
    int i, j;
    Student temp;
    for (i = 0; i < len-1; i++) {
        for (j = 0; j < len - i -1; j++) {
            if ((arr[j].score < arr[j+1].score)) {
                memcpy(&temp, &arr[j], sizeof(Student));
                memcpy(&arr[j], &arr[j+1], sizeof(Student));
                memcpy(&arr[j+1], &temp, sizeof(Student));
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    int n,i;
    scanf("%d", &n);
    Student* list = malloc(sizeof(Student)*n);
    for (i = 0; i < n; i++)
        scanf("%s%d", list[i].name, &list[i].score);
    sort(list, n);
    for (i = 0; i < n; i++)
        printf("%s\n", list[i].name);
    return 0;
}
