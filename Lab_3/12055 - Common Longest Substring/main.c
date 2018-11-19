// wa ac wa wa re re
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)

int main()
{
    char s[1005],t[1005];
    while((scanf("%s%s",s,t))!=EOF){
        int lens=strlen(s),lent=strlen(t),i,j;
        int lcs[lens+1][lent+1],lcs_max=-23433;
        memset(lcs,0,sizeof(lcs));
        for(i=0;i<lens;++i){
            if(s[i]==t[0]){
                lcs[0][i]=1;
                if(lcs[0][i]>lcs_max) lcs_max=lcs[0][i];
            }
        }
        for(i=0;i<lent;++i){
            if(s[0]==t[i]){
                lcs[i][0]=1;
                if(lcs[i][0]>lcs_max) lcs_max=lcs[i][0];
            }
        }
        for(i=1;i<lens;++i){
            for(j=1;j<lent;++j){
                if((lcs[i-1][j]==lcs[i][j-1])&&(s[i]==t[j])&&(s[i-1]==t[j-1])) lcs[i][j]=lcs[i-1][j-1]+1;
                else if((lcs[i-1][j]!=lcs[i][j-1])&&(s[i]==t[j])&&(s[i-1]==t[j-1])) lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1])+1;
                else if((s[i-1]!=t[j-1])&&(s[i]==t[j])) lcs[i][j]=1;
                if(lcs[i][j]>lcs_max) lcs_max=lcs[i][j];
            }
        }
        printf("%d\n",lcs_max);
    }
    return 0;
}
