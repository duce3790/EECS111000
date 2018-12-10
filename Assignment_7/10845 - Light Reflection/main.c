#include <stdio.h>
#include <stdlib.h>

int poi_row[100000]={0};  // 第K點的row
int poi_col[100000]={0};  // 第K點的col
int h,w,time=1,k;

int route(int row, int col, int i, int dir){
    if((i!=0)&&(row==1||col==1||row==h||col==w)){
        poi_row[time]=row;
        poi_col[time]=col;
        dir=(dir+1)%4; //dir 0=up-right 1=down-right 2=down-left 3=up-left
        if(time==k-1){
            printf("(%d,%d)",poi_row[time],poi_col[time]);
            return 0;
        }
        time++;
    }
    if((row==1&&col==1)||(row==1&&col==w)||
            (row==h&&col==w)||(row==h&&col==1)) return 0;
    else if(dir==0) return route(row-1,col+1,i+1,0);
    else if(dir==1) return route(row+1,col+1,i+1,1);
    else if(dir==2) return route(row+1,col-1,i+1,2);
    else if(dir==3) return route(row-1,col-1,i+1,3);
}

int main()
{
    int row_init,col_init;
    scanf("%d%d",&h,&w);
    scanf("%d%d",&row_init,&col_init);
    scanf("%d",&k);
    poi_row[0]=row_init;
    poi_col[0]=col_init;
    route(row_init,col_init,0,0);
    return 0;
}
