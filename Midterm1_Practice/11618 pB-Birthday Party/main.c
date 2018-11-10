// all accept
#include <stdio.h>
#include <stdlib.h>
long long int gcd(long long int a,long long int b){
    if(b>0)   return gcd(b,a%b);
    return a;
}
long long int lcm(long long int c,long long int d){
    return (c/gcd(c,d))*d;
}

int main()
{
    long long int t,x1,x2,x3,x4;
    scanf("%lld",&t);
    while(--t>=0){
        scanf("%lld%lld%lld%lld",&x1,&x2,&x3,&x4);
        long long int n,m,p,nm,final_step;
        n=gcd(x1,x2);
        m=gcd(x1,x3);
        p=gcd(x1,x4);
        nm=lcm(n,m);
        final_step=lcm(nm,p);
        printf("%lld\n",x1/final_step);
    }
    return 0;
}
