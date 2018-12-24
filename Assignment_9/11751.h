#ifndef _FUNCTION_H
#define _FUNCTION_H

typedef struct {
	int value;
	char str[30];
	float x;
} MyData;

int compare_function(const void* a, const void* b){
    const MyData** ma = (MyData**) a;
    const MyData** mb = (MyData**) b;
    if( (*ma)->value != (*mb)->value ) return (*mb)->value < (*ma)->value;
    else if(strcmp((*ma)->str, (*mb)->str)!=0) return strcmp((*ma)->str, (*mb)->str);
    else return (*mb)->x < (*ma)->x;
}

#endif
