#include <stdio.h>
#include <stdlib.h>
#include "11766.h"

int main(void)
{
	int n;

	// Read inputs
	scanf("%d",&n);
	Letter *letters=(Letter*)malloc(sizeof(Letter)*n);

	int i;
	for(i=0; i!=n; ++i)
		scanf("%d %s",&(letters[i].zipcode),letters[i].name);

	// Sort the data
	qsort(letters,n,sizeof(Letter),compare);

	// Output result
	for(i=0; i!=n; ++i)
		printf("%d %s\n",letters[i].zipcode,letters[i].name);

	free(letters);
}
