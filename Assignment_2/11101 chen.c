#include <stdio.h>
#include <stdlib.h>

int first4(int x){
   return x/10000;
}
int last4(int x){
   return x%10000;
}
int main(void){
  int x;
  int a,b;
  int c1,c2,c3;
  scanf("%d%d",&x);
  a = first4(x);
  b = last4(x);
  if ((a*a%10000)*10000+2*a*b+b*b/10000>=100000000){
    c1=a*a/10000+1;
    c2=(a*a%10000)*10000+2*a*b+b*b/10000-100000000;
  }
  else {
    c1=a*a/10000;
    c2=(a*a%10000)*10000+2*a*b+b*b/10000;
    }
    c3=b*b%10000;
  printf("%4d%08d%04d", c1,c2,c3);
  return 0;
}
