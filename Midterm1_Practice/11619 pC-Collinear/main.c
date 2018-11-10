// collinear
#include <stdio.h>

int main() {
    int test_case,i;
    scanf("%d", &test_case);
    for ( i = 0; i < test_case; ++i) {
        int number, left, middle, right, j, k, v = 0, o = 0, collinear = 0, vertical[161700];
        float x[100], y[100], slope[161700], intercept[161700];
        scanf("%d", &number);
        for (j = 0; j < number; ++j)
            scanf("%f %f", &x[j], &y[j]);
        for (left = 0; left < number - 2; ++left) {
            for (middle = left + 1; middle < number - 1; ++middle) {
                for (right = middle + 1; right < number; ++right) {
                    if (x[left] == x[middle] && x[left] == x[right])
                        vertical[v++] = x[left];
                    else if (x[left] != x[middle] && x[left] != x[right]) {
                        if ((y[left] - y[middle]) / (x[left] - x[middle]) == (y[left] - y[right]) / (x[left] - x[right])) {
                            slope[o] = (y[left] - y[middle]) / (x[left] - x[middle]);
                            intercept[o++] = (x[left] * y[middle] - x[middle] * y[left]) / (x[left] - x[middle]);
                        }
                    }
                }
            }
        }
        if (v > 1) {
            for (j = 0; j < v; ++j) {
                for (k = j + 1; k < v; ++k) {
                    if (vertical[j] == vertical[k]) {
                        --collinear;
                        break;
                    }
                }
                ++collinear;
            }
        } else if (v == 1)
            ++collinear;
        if (o > 1) {
            for (j = 0; j < o; ++j) {
                for (k = j + 1; k < o; ++k) {
                    if (slope[j] == slope[k] && intercept[j] == intercept[k]) {
                        --collinear;
                        break;
                    }
                }
                ++collinear;
            }
        } else if (o == 1)
            ++collinear;
        printf("%d\n", collinear);
    }

    return 0;
}
