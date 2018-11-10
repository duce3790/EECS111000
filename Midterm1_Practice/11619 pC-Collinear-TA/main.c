#include <stdio.h>
#include <string.h>

int main() {
    int t,n;
    int i,j,k;
    int tmp,col_num;
    int count[110];
    long long x[110],y[110];
    scanf("%d", &t);
    while (t-->=0) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld%lld", &x[i], &y[i]);
        }
        memset(count, 0, sizeof(count));
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                tmp = 2;
                for (k = 0; k < n; k++) {
                    if (k != i && k != j && (x[j] - x[i]) * (y[k] - y[j]) == (x[k] - x[j]) * (y[j] - y[i])) {
                        tmp++;
                    }
                }
                count[tmp]++;
            }
        }
        col_num = 0;
        for (i = 3; i <= n; i++) {
            count[i] = (count[i] * 2) / (i * (i - 1));
            col_num += count[i];
        }
        printf("%d\n", col_num);
    }
    return 0;
}
