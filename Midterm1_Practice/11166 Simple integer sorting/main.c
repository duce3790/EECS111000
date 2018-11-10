// all accept
#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int a[],int b){
    int l,k,tmp;
    for(l=b-1;l>0;--l){
        for(k=0;k<l;++k){
            if(a[k]>a[k+1]){
                tmp=a[k];
                a[k]=a[k+1];
                a[k+1]=tmp;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0){
        int n;
        scanf("%d",&n);
        int v[n],i;
        for(i=0;i<n;++i) scanf("%d",&v[i]);
        bubble_sort(v,n);
        for(i=0;i<n;++i){
            if(i!=n-1) printf("%d ",v[i]);
            else printf("%d\n",v[i]);
        }
    }
    return 0;
}
