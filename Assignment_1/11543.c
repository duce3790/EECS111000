#include<stdio.h>

int main()
{
	int n,i=0;
	scanf("%d",&n);
	float s=n,m=0,ave;
	for(;i<3;i++)
	{
		m+=n%10;
		n/=10;
		if(i<2) m*=10;
	} 
	ave=(s+m)/2;
	printf("%4.1f",ave);
	return 0;
}

