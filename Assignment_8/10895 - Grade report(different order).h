#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;

int ascsort(const void *x,const void *y){
    const Grade* a = (Grade*) x;
    const Grade* b = (Grade*) y;
    if((*a).total!=(*b).total) return (*a).total-(*b).total;
    else if( (*a).Chinese!= (*b).Chinese) return (*a).Chinese- (*b).Chinese;
    else if( (*a).English!= (*b).English) return (*a).English- (*b).English;
    else if((*a).math!= (*b).math) return (*a).math- (*b).math;
    else if((*a).science!= (*b).science) return (*a).science- (*b).science;
    else return  a->ID- b->ID;

}

int dessort(const void *x,const void *y){
    const Grade* a = (const Grade*) x;
    const Grade* b = (const Grade*) y;
    if((*a).total!=(*b).total) return (*b).total-(*a).total;
    else if((*a).Chinese!=(*b).Chinese) return (*b).Chinese-(*a).Chinese;
    else if((*a).English!=(*b).English) return (*b).English-(*a).English;
    else if((*a).math!=(*b).math) return (*b).math-(*a).math;
    else if((*a).science!=(*b).science) return (*b).science-(*a).science;
    else return  a->ID-b->ID;
}

void sortGrade(Grade *gList, int n, char *order){
    int i;
    for(i=0;i<n;++i)
        gList[i].total=gList[i].Chinese+gList[i].English+gList[i].math+gList[i].science;
    if(order[0]=='d') qsort(gList,n,sizeof(Grade),dessort);
    else qsort(gList,n,sizeof(Grade),ascsort);

}
#endif
