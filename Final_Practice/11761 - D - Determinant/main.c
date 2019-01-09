#include <stdio.h>

long long det(int a[][10], int n) {

    if (n == 2) {
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }
    else {
        int b[10][10]; //create a new array b
        int i, j, k, bx, flag = 1;
        long long val = 0;
        for (i = 0; i < n; i++) {
            bx=0;
            for(j = 0; j < n ; ++j){
                if(i != j){
                    for(k = 1; k < n ; ++k){
                        b[bx][k-1] = a[j][k];
                    }
                    bx++;
                }
            }
            val += a[i][0] * det(b, n - 1) * flag;
            flag *= -1;
        }
        return val;
    }
}


int main(int argc, const char * argv[]) {

    int n;
    int a[10][10];
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("%lld\n", det(a, n));

    return 0;
}
