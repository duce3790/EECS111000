#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {

    int n;
    int i, j, temp;
    int a[100010];
    int arr_k[20]; //to record each bit of the integer k
    int k = 0;
    long long SUM = 0;

    //input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    //start from LSB
    for (i = 0; i < 20; i++) {
        //to count how many times "1" appears in the same digit place over the array a
        temp = 0;
        /*
        for(j=0;j<n;++j){
            a[j]*=2;
        }
        for (j = 0; j < n; j++) {
            temp += a[j]% 2;
            a[j]/=2;
        }
        */
        // The following 33~41 codes is similar to 24~30 codes
        for(j=0;j<n;++j){
            temp += ( a[j] >> i) % 2;
        }
        if (n - temp >= temp) { //if 0 is more than 1
            arr_k[i] = 0; //than the same digit place of k should be 0.
        }
        else {
            arr_k[i] = 1; //otherwise it should be to 1
        }
    }

    //converting array k into a real integer k
    for (i = 0; i < 20; i++) {
        k += arr_k[i] * pow(2, i);
    }

    //calculate the SUM
    for (i = 0; i < n; i++) {
        SUM += k ^ a[i];
    }

    printf("%lld\n", SUM);

    return 0;
}
