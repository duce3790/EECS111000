#include <stdio.h>
#include <stdlib.h>

int h,w,time=0,k;

int route(int row, int col, int dir){
    if(row==1||col==1||row==h||col==w){
        if(time==k-1){
        printf("(%d,%d)",row,col);
        return 0;
    }
    if(dir==0){
        if(row==1) dir=1;
        else dir=3;
    }
    else if(dir==1){
        if(col==w) dir=2;
        else dir=0;
    }
    else if(dir==2){
        if(row==h) dir=3;
        else dir=1;
    }
    else if(dir==3){
        if(col==1) dir=0;
        else dir=2;
    }
    time++;
    }
    if((row==1&&col==1)||(row==1&&col==w)||
       (row==h&&col==w)||(row==h&&col==1)){
           printf("(%d,%d)",row,col);
           return 0;
       }
    else if(dir==-1) return route(row-1,col+1,dir+1);
    else if(dir==0) return route(row-1,col+1,dir);
    else if(dir==1) return route(row+1,col+1,dir);
    else if(dir==2) return route(row+1,col-1,dir);
    else if(dir==3) return route(row-1,col-1,dir);
}

int main()
{
    int row_init,col_init;
    scanf("%d%d",&h,&w);
    scanf("%d%d",&row_init,&col_init);
    scanf("%d",&k);
    route(row_init,1,-1);
    return 0;
}
