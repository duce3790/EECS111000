#include <stdio.h>

char map[1007][1007];
int m ,n , life=0;

void flag(int row,int col){
    if(map[row][col]=='~') life=1;
    else if(map[row][col]!='^'&& row>= 0 && col>= 0 && row< m && col< n+1){
        map[row][col]='^';
        flag(row-1,col);
        flag(row+1,col);
        flag(row,col-1);
        flag(row,col+1);
    }
}

int main()
{
    scanf("%d%d",&m,&n);
    int i,j,ex,ey;
    // 測資裡每一行都有換行字元 所以 j domain =n+1
    for(i=0;i<m;++i){
        for(j=0;j<n+1;++j){
            if((map[i][j]=getchar())=='e'){
                ex=i;
                ey=j;
            }
        }
    }
    flag(ex,ey);
    if(life) printf("Alive!\n");
    else printf("Dead!\n");
    return 0;
}

/*
test data
5 5
^^^^~
...^.
.^.^.
.^.^.
e^...
*/
