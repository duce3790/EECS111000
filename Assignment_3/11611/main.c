#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    while(n-->0)
    {
        char a[1100],b[1100];
        long long int c,sum[1100]={0},quo[1100]={0};
        scanf("%s%s%lld",a,b,&c);
        for(i=strlen(a);i>=0;--i)
        {
            sum[strlen(a)-1-i]+=(a[i]-48)+(b[i]-48);
        }

        memset(quo,0,sizeof(quo));
        for(i=1097;i>=0;--i)                //devide
        {
            sum[i-1]+=(sum[i]%c)*10;
            quo[i]=sum[i]/c;
        }
        for(i=0;i<1007;++i)             //¶i¦ì
        {
            quo[i+1]+=quo[i]/10;
            quo[i]%=10;
        }
		int flag = 0;
        for(i = 1008; i >=0; i--) {
            if(quo[i] != 0){
                flag = 1;
            }
            if(flag) {
                printf("%lld",quo[i]);
            }
        }
        if(!flag) {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
