#include <stdio.h>
#include <stdlib.h>

int n;
int edge[1005][1005];

void dfs(int vertex, int depth){
    int i;
    if(edge[vertex][0]==0){
        edge[vertex][0] = depth;
        for(i=1;i<=n;++i){
            if(edge[vertex][i])
                dfs(i,depth+1);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(--t >= 0){
        int m, i, j, flag = 0, index_1, index_2;
        scanf("%d%d",&n,&m);
        memset(edge,0,sizeof(edge));
        for(i=0; i < m; ++i){
            scanf("%d%d",&index_1,&index_2);
            edge[index_1][index_2]=1;
            edge[index_2][index_1]=1;
        }
        for(i=1; i<n;++i){
            if(!edge[i][0])
                dfs(i,1);
        }
        for(i=1;i<=n;++i){
            for(j=i+1;j<=n;++j){
                if(edge[i][j]){
                    if((edge[i][0] + edge[j][0]) % 2 == 0){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
