#include <stdio.h>

char map[1007][1007];

void flag(int row,int col,int row_max,int col_max){
    if(map[row][col]=='~'&&row>=0&&row<row_max&&col>=0&&col<col_max){
        map[row][col]='.'; // 把相連的水域都轉成陸地
        flag(row-1,col,row_max,col_max);
        flag(row+1,col,row_max,col_max);
        flag(row,col-1,row_max,col_max);
        flag(row,col+1,row_max,col_max);
    }
}

int main(){
    int m,n,i,j,count=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;++i)    scanf("%s",map[i]);
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            if(map[i][j]=='~'){
                count++;
                flag(i,j,m,n);
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
