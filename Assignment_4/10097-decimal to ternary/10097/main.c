#include <stdio.h>
#include <stdlib.h>
void ter(int n,int m){
    if(m>1) ter(n/3,m-1);
    printf("%d",n%3);
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    ter(x,y);
    printf("\n");
    return 0;
}

