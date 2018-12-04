// all accept
#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (x>y?x:y)
char map[23][100];
int c,f,h,rou=0;

int draw(int row,int col, char dir){
    map[row][col]='*';
    rou++;
    if(dir=='u'){
        if((map[row-1][col]=='-')) draw(row+1,col+1,'d');
        else if(row>0) draw(row-1,col+1,'u');
        else return 0;
    }
    else{
        if((map[row+1][col]=='-')) draw(row-1,col+1,'u');
        else if(row<=h) draw(row+1,col+1,'d');
        else return 0;
    }
}

int main()
{
    int s,i,j;
    char dir;
    memset(map,' ',sizeof(map));
    scanf("%d%d%d%d%c",&c,&f,&h,&s,&dir);
    for (i = 0; i < c; ++i) map[0][i] = '-';
    for(i = 0; i < f; ++i) map[h+1][i] = '-';
    if(dir=='u')    draw(s,0,'u');
    else    draw(s,0,'d');
    c=max(c,f);
    c=max(c,rou);
    for(i=0;i<h+2;++i){
        for(j=0;j<c;++j)
            printf("%c",map[i][j]);
        printf("\n");
    }
    return 0;
}
