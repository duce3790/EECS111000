// all accept
#include <stdio.h>
#include <stdlib.h>

int main(){

	int n,m,i,j,pos;
	int e[100010];
	int seq[200010];
	int e_flag[200010]; //e_flag 因為request的數沒規定不能一樣，所以要避免輸出相同的數

	//input
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d", &e[i]);
	}

	memset(seq,1,sizeof(seq));
	memset(e_flag,0,sizeof(e_flag));

	//progress
	for(i = 0; i < m; i++) {
		seq[e[i]] = 0;
	}

	//output
	for(i = m - 1; i >= 0; i--) {
		if(e_flag[e[i]] == 0){
			printf("%d\n", e[i]);
			e_flag[e[i]] = 1;
		}
	}
	for(i = 1; i <= n; i++) {
		if(seq[i]){
			printf("%d\n", i);
		}
	}
	return 0;
}
