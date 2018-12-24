#include <stdio.h>

int main(void)
{

	int N, k, i, j, lim;
	int x, t, y, z;
	int num[16];

	scanf("%d%d", &N, &k);
	for (i=0; i<N; i++) {
		scanf("%d", &num[i]);
	}

	lim = 1<<N;

	x = 0;
	x = ~(~x << k);

	for (; x<lim; ) {
		for (j=N-1; j>=0; j--)  {
			if ( (x & (1<<j))!= 0 ) {
				printf("%d ", num[j]);
			}
		}
		t = x & -x;
		y =  t + x;
		z = y ^ x;
		z = (z>>2)/t;
		x = y | z;

		printf("\n");
	}

return 0;
}
