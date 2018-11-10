#include <stdio.h>
int way(int floor) {
    if (floor == 1)
        return 1;
    else if (floor == 2)
        return 2;
    else
        return way(floor - 1) + way(floor - 2);
}

int main() {
    int test_case, floor,i;
    scanf("%d", &test_case);
    for (i = 0; i < test_case; ++i) {
        scanf("%d", &floor);
        printf("%d\n", way(floor));
    }

    return 0;
}
