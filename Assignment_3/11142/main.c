#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,p,i,j,k;
    while(scanf("%d%d%d",&n,&m,&p)!=EOF){
	    long long int a[105][105],b[105][105],c[105][105];
	    for(i=0;i<n;++i){
	        for(j=0;j<m;++j){
	            scanf("%lld",&a[i][j]);
	        }
	    } 
	    for(i=0;i<m;++i){
	        for(j=0;j<p;++j){
	            scanf("%lld",&b[i][j]);
	        }
	    }
	    for(i=0;i<n;++i){
	        for(j=0;j<p;++j){
	        	c[i][j]=0;
	                for(k=0;k<m;++k){
	                    c[i][j]+=(a[i][k]*b[k][j]);
	                }
	        }
	    }
	    for(i=0;i<n;++i){
	        for(j=0;j<p;++j){
	            printf("%lld",c[i][j]);
	            if(j!=p-1) printf(" ");
	        }
	        printf("\n");
	    }
	    printf("\n");
	}
	return 0;
}


