///


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,pt;
    while((scanf("%d",&n))!=EOF){
        for(i=0;i<=2*n-2;i++){
            if(i>=n) pt=2*abs(i-(2*n-2))+1;
            else pt=2*i+1;
            for(j=0;j<=2*n-2;j++){
                if(i>=n){
                    if(abs(n-1-j)<=abs(2*n-2-i)){
                        if(pt>abs(2*n-2-i+1)) {
                            printf("%c",abs(pt-(2*abs(i-(2*n-2))+1))+65);
                            pt--;
                        }
                        else {
                            printf("%c",pt+64);
                            pt--;
                        }
                    }
                    else{
                        if(j!=2*n-2){
                                if(pt!=0) printf(" ");
                        }
                    }
                }
                else{
                    if(abs(n-1-j)<=i){
                        if(pt>i+1) {
                            printf("%c",abs(pt-(2*i+1))+65);
                            pt--;
                        }
                        else {
                            printf("%c",pt+64);
                            pt--;
                        }
                    }
                    else{
                        if(j!=2*n-2)printf(" ");
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
