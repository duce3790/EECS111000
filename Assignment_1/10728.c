#include<stdio.h>

int main()
{
	int n,x,y,z;
	scanf("%d%d%d%d",&n,&x,&y,&z);
	printf("%d %d",x+y+z-n,n-y-z);
	return 0;
}

