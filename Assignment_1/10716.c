#include<stdio.h>

int main()
{
	int a,n,d,sum=0;
	scanf("%d%d%d",&a,&n,&d);
	while(n-->1)
	{
		sum+=a;
		a+=d;
		printf("%d %d\n",a,sum);
	}
	sum+=a;
	printf("%d %d",a,sum);
	return 0;
}

