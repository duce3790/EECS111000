#include <stdio.h>
#include <stdlib.h>

int main()
{   char a[5];
    scanf("%s",a);
    int i,j,n,occ=0,occ_max=0,len1=strlen(a),flag=1;
    scanf("%d",&n);
    while(--n>=0){
        char b[10];
        scanf("%s",b);
        int len2=strlen(b);
        for(i=0;i<=len2-len1+1;++i){
            for(j=0;j<len1;++j){
                if(a[j]!=b[i+j]){
                    flag=0;
                    break;
                }
            }
            if(flag) occ++;
            else flag=1;
        }
        if(occ>=occ_max) occ_max=occ;
        occ=0;
    }
    printf("%d",occ_max);
    return 0;
}
