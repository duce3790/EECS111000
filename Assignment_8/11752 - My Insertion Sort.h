//
// Created by 贾松昊 on 2017/12/21.
//

#ifndef TEST_FOR_C_FUNCTION_H
#define TEST_FOR_C_FUNCTION_H

#include <stdio.h>

int compare(const void* a, const void* b){
    const int *x=(int*) a;
    const int *y=(int*) b;
    return *x-*y;
}

void assign(char* x, char* y, size_t size){
    int len=strlen(x),i,j;
    char *tmp;
    for(i=0;i<len*size;i+=size){
        for(j=0;j<size;++j){
            *(tmp+i+j)=*(x+i+j);
            *(x+i+j)=*(y+i+j);
            *(y+i+j)=*(x+i+j);
        }
    }
}

void mysort(void* arr, size_t count, size_t size, int (*cmp) (const void*, const void*)){
    int i,j;
    for(i=0;i<count;++i){
        for(j=0;j<count-i;++j){
            if(cmp(arr,arr+j)){
                assign(arr,arr+j,size);
            }
        }
    }
}

#endif //TEST_FOR_C_FUNCTION_H
