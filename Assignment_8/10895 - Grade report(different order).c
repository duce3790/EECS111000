#include <stdio.h>
#include <stdlib.h>
#include "10895 - Grade report(different order).h"
int main(){
    int n, i;
    char order[20];
    Grade gradeList[1000];
    scanf("%d%s", &n, order);
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
    sortGrade(gradeList, n, order);
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,gradeList[i].Chinese, gradeList[i].English,gradeList[i].math, gradeList[i].science);
    return 0;
}
