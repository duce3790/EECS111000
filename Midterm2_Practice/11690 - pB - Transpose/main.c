#include <stdio.h>
#include <stdint.h>
//#include "function.h"

void Print(int m, int n, int matrix[][500] ) {
    int i , j;
    for ( i = 0; i < m; i++ ) {
        for ( j = 0; j < n; j++ ) {
            printf("%d%c", matrix[i][j], " \n"[j==n-1] );
        }
    }
}
void Transpose(int *row, int *col, int matrix[][500]){
    int i,j,tmp[500][500];
    for(i=0;i<*row;++i){
        for(j=0;j<*col;++j){
            tmp[j][i]=matrix[i][j];
        }
    }
    i=*row;
    *row=*col;
    *col=i;
    for(i=0;i<*row;++i){
        for(j=0;j<*col;++j){
            matrix[i][j]=tmp[i][j];
        }
    }
}

int32_t main(){
    int matrix[500][500];
    int row, col,i,j;
    scanf("%d %d", &row, &col);
    for ( i = 0; i < row; i++ ) {
        for (  j = 0; j < col; j++ ) {
            scanf("%d", &matrix[i][j]);
        }
    }
    Transpose( &row, &col, matrix);
    Print( row, col, matrix );
    return 0;
}
