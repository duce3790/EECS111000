#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[25];
    int a, b;
    int diff;
} Factory;

Factory* list;
Factory* factory_a;
Factory* factory_b;
int n, x, y, cur;

int compare_Factory_byA_descend(const void* a, const void* b) {
    const Factory* pa = (const Factory*) a;
    const Factory* pb = (const Factory*) b;
    return pb->a - pa->a;
}

int compare_Factory_byB_descand(const void* a, const void* b) {
    const Factory* pa = (const Factory*) a;
    const Factory* pb = (const Factory*) b;
    return pb->b - pa->b;
}

int compare_Factory_byDiff_descend(const void* a, const void* b) {
    const Factory* pa = (const Factory*) a;
    const Factory* pb = (const Factory*) b;
    return pb->diff - pa->diff;
}

int compare_Factory_byName(const void* a, const void* b) {
    const Factory* pa = (const Factory*) a;
    const Factory* pb = (const Factory*) b;
    return strcmp(pa->name, pb->name);
}

int calculateProfit() {
    int i;
    int profit = 0;
    for (i = 0; i < x; i++) {
        profit += factory_a[i].a;
    }
    for (i = 0; i < y; i++) {
        profit += factory_b[i].b;
    }
    return profit;
}

int main(int argc, const char * argv[]) {

    int i;
    int maxProfit, maxCur;
    int temp;

    scanf("%d%d%d", &n, &x, &y);
    list = (Factory*) malloc(sizeof(Factory)*n);
    factory_a = (Factory*) malloc(sizeof(Factory)*n);
    factory_b = (Factory*) malloc(sizeof(Factory)*n);

    for (i = 0; i < n; i++) {
        scanf("%s%d%d", list[i].name, &list[i].a, &list[i].b);
        list[i].diff = list[i].a - list[i].b;
    }

    maxProfit = 0;
    maxCur = x - 1;
    cur = x - 1;
    while (cur < n - y) {
        qsort(list, n, sizeof(Factory), compare_Factory_byDiff_descend);
        memcpy(factory_a, list, sizeof(Factory) * (cur + 1));
        memcpy(factory_b, &(list[cur+1]), sizeof(Factory) * (n-cur-1));
        qsort(factory_a, cur+1, sizeof(Factory), compare_Factory_byA_descend);
        qsort(factory_b, n-cur-1, sizeof(Factory), compare_Factory_byB_descand);
        temp = calculateProfit();
        if (temp > maxProfit) {
            maxProfit = temp;
            maxCur = cur;
        }
        cur++;
    }

    qsort(list, n, sizeof(Factory), compare_Factory_byDiff_descend);
    memcpy(factory_a, list, sizeof(Factory) * (maxCur + 1));
    qsort(factory_a, maxCur+1, sizeof(Factory), compare_Factory_byA_descend);

    qsort(factory_a, x, sizeof(Factory), compare_Factory_byName);
    for (i = 0; i < x; i++) {
        printf("%s\n", factory_a[i].name);
    }

    return 0;
}
