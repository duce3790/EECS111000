#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[2005];
    while(scanf("%s",s)!=EOF){
        int substr=0,i,j,k;
        //  奇數子字串
        for(i=1;i<strlen(s)-1;++i){
            for(j=i-1,k=i;j>=0,k<strlen(s);--j,++k){
                if(s[j]==s[k]) substr++;
                else break;      //中心字串不同時，擴展也不會正確
            }
        }
        //  偶數子字串
        for(i=1;i<strlen(s)-1;++i){
                for(j=i-1,k=i+1;j>=0,k<strlen(s);--j,++k){
                    if(s[j]==s[k]) substr++;
                    else break;     ////中心字串不同時，擴展也不會正確
                }
        }
        if(s[strlen(s)-1]==s[strlen(s)-2]) substr++;  //最後兩位相等不會檢查到
        printf("%d\n",substr);
    }
    return 0;
}
