
#include<stdio.h>

int main()
{
	int n,i=0,c=1,ct=0,str1[1000],str2[1000]={0};  
	scanf("%d",&n);   //c=進位的值 初始直射1因為題目限制要加1 ct=進位次數
		while(n>0)
		{
			str2[i]+=c;
			str1[i]=n%2;
			n/=2;
			str2[i]+=str1[i];
			if(str2[i]>1)
			{
				c=str2[i]/2;
				str2[i]%=2;
				ct++;
			}
			else c=0;
			i++;
		}
		if(c==0)
		{
			for(i--;i>=0;i--)
				printf("%d",str2[i]);
		}
		else
		{
			str2[i]+=c;
			for(;i>=0;i--)
			printf("%d",str2[i]);
		}
		printf(" %d",ct);
	return 0;
}


