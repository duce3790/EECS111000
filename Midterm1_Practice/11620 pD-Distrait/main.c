// all accept
// i j k l �j���   flag �ΨӰ����O�_��bingo t_pri�ΨӦL�X���T����
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
                    if(flag) break;    //�p�G bingo �N�������h�j�� �`�ٮɶ�
                }
                if(flag) break;
            }
            if(flag)     //�p�G�w�gbingo �N�����~���J�Ʀr�]���h�^��
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
