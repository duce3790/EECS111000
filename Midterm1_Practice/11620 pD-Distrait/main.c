// all accept
// i j k l 迴圈用   flag 用來偵錯是否有bingo t_pri用來印出正確答案
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,l,m,card[6][6],bingo[13],t,n,sel,flag=0,t_pri;
    for(i=1;i<6;++i){
        for(j=1;j<6;++j)
            scanf("%d",&card[i][j]);
    }
    scanf("%d",&t);
    t_pri=t;
    while(--t>=0){
        memset(bingo,0,sizeof(bingo));
        scanf("%d",&n);
        for(k=0;k<n;++k){
            scanf("%d",&sel);
            for(i=1;i<6;++i){
                for(j=1;j<6;++j){
                    if(card[i][j]==sel){
                        bingo[i]++;
                        bingo[j+5]++;
                        if(i==j){
                            bingo[11]++;
                        }
                        if((i+j)==6){
                            bingo[12]++;
                        }
                        for(l=1;l<13;++l){
                            if(bingo[l]==5){
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag) break;    //如果 bingo 就關掉雙層迴圈 節省時間
                }
                if(flag) break;
            }
            if(flag)     //如果已經bingo 就不用繼續輸入數字跑雙層回圈
            {
                int unsel[n-k];
                for(m=0;m<n-k-1;++m) scanf("%d",&unsel[m]);
                break;
            }
        }
        if(flag) printf("Case #%d: %d\n",t_pri-t,k+1);
        else printf("Case #%d: Not yet \\(^o^)/\n",t_pri-t);
        flag=0;
    }
    return 0;
}
