#include <stdio.h>
#include <stdlib.h>

int spe_num,n,time;

int markov_matrix(double tra[n][n],double ans[n]){
    time++;
    int i,j;
    double ans_pre=ans[0];
    double next[n];
    memset(next,0.0,n * sizeof(double));
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            next[i]+=tra[i][j]*ans[j];
        }
    }
    //for(i=0;i<n;i++) printf("%.10lf ",next[i]);
    //printf("\n");
    if(time==100){
        if((int)next[0]<=spe_num)
            return 1;
        return 0;
    }
    else if(next[0]<=spe_num) return 1;
    return markov_matrix(tra,next);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(--t>=0){
        time=0;
        int i,j,result;
        scanf("%d",&n);
        double a[n][n],pop[n];
        for(i=0;i<n;++i){
            for(j=0;j<n;++j)
                scanf("%lf",&a[i][j]);
        }
        for(i=0;i<n;++i) scanf("%lf",&pop[i]);
        scanf("%d",&spe_num);
        if(spe_num >= pop[0]) result=-1;
        else result=markov_matrix(a,pop);
        if(result==0) printf("Never\n");
        else if(result==-1) printf("0\n");
        else printf("%d\n",time);
    }
    return 0;
}
