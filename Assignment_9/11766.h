#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct {
	int zipcode;
	char name[15];
} Letter;

int compare(const void *a,const void *b){
    const Letter* la = (Letter*) a;
    const Letter* lb = (Letter*) b;
    int len_a = strlen(la->name) , len_b = strlen(lb->name) , i;
    int a_wgt = (la->name[0] - 95) , b_wgt = (lb->name[0] - 95);
    for(i=1;i<len_a;++i) a_wgt+=(la->name[i]-64);
    for(i=1;i<len_b;++i) b_wgt+=(lb->name[i]-64);
    if(la->zipcode != lb->zipcode) return la->zipcode - lb->zipcode;
    else if(a_wgt != b_wgt) return a_wgt - b_wgt;
    else return strcmp(la->name,lb->name);
}

#endif
