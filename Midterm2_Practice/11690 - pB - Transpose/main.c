// complier error don't know why
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int input[m][n],output[n][m],i,j;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            scanf("%d",&input[i][j]);
            output[j][i]=input[i][j];
        }
    }
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            if(j!=m-1) printf("%d ",output[i][j]);
            else printf("%d\n",output[i][j]);
        }
    }
    return 0;
}
