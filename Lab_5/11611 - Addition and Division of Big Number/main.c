#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x,y) (x,y)?x:y

int main()
{
    int n;
    scanf("%d",&n);
    while(--n>=0){
        char s[1010],t[1010];
        long long div,add[1010]={0};
        scanf("%s%s%lld",s,t,&div);
        int i,lens=strlen(s),lent=strlen(t),flag=0;
        lens=max(lens,lent);
        // �j�ƥ[�k
        for(i=0;i<lens;++i){
            add[i]+=((s[lens-i-1]-'0')+(t[lens-i-1]-'0'))%10;
            add[i+1]+=((s[lens-i-1]-'0')+(t[lens-i-1]-'0'))/10;
        }
        // �j�ư��k
        for(i=lens;i>0;--i){
            add[i-1]+=(add[i]%div)*10;
            add[i]/=div;
        }
        add[0]/=div;
        for(i=lens+1;i>=0;--i){
            if(add[i]!=0) flag=1; //flag�ΨӦY��0
            if(add[i]!=0||flag==1) printf("%lld",add[i]);
        }
        if(flag==0) printf("%lld",add[i]); // 0+0 �~�|�Ψ�o��
        printf("\n");
    }
    return 0;
}
