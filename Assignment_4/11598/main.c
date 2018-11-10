// 回文 輸入一字串 abc
// 輸出            bca
//                 cba
//                 abc
// AC
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1005],tmp;
    while((scanf("%s",str))!=EOF)
    {
        int time=strlen(str),i;
        while(time-->0){
            tmp=str[0];
            for(i=0;i<strlen(str)-1;++i){
                str[i]=str[i+1];
            }
            str[strlen(str)-1]=tmp;
            printf("%s\n",str);
        }
    }
    return 0;
}
