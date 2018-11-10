#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a,b,c,d,e;
    scanf("%lld%lld%lld",&b,&c,&d);
    if((c-b)==(d-c)) printf("%lld %lld",2*b-c,d+c-b);
    else printf("%lld %lld",b*b/c,d*c/b);
    return 0;
}
