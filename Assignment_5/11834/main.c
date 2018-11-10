#include<stdio.h>
void hanoi(int x);
int main(void)
{
	int level;
	scanf("%d",&level);
	hanoi(level);
	return 0;
}
void hanoi(int x)
{
	if(x==0) return;
	hanoi(x-1);
	printf("%d\n",x);
	hanoi(x-1);
}
