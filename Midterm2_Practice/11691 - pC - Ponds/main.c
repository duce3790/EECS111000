#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,ponds=0;
    scanf("%d%d",&m,&n);
    char maps[m+1][n+1];
    for(i=0;i<=n;++i) maps[0][i]='.';
    for(i=0;i<=m;++i) maps[i][0]='.';
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            scanf("%c",&maps[i][j]);
            if((maps[i-1][j]=='~')||(maps[i][j-1]=='~')) maps[i][j]='.';
        }
    }
    // Line 18~23 to show the changed maps
    for(i=0;i<=m;++i){
        for(j=0;j<=n;++j){
            printf("%c ",maps[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            if(maps[i][j]=='~') ponds++;
        }
    }
    printf("%d\n",ponds);
    return 0;
}
