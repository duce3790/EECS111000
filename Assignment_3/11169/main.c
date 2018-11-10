#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,x,y,i,j;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    int s=abs(y-x);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((i==x)&&(j==y)) printf("%c",'S');
            else if((i==x)||(j==y)) printf("%c",'+');
            else if((i+j==x+y)||(j-i==s)) printf("%c",'*');
            else printf("%c",'-');
        }
        printf("\n");
    }
    return 0;
}
