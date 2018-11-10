#include<stdio.h>

int main()
{
	int n,i=3;
	scanf("%d",&n);
	char str[4];
	while(--i>=0)
	{
		str[i]=(n%10+64);
		n/=10;
	}
	printf("%s",str);
	return 0;
}


