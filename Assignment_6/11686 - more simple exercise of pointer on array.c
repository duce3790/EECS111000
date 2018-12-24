// all accept
#include <stdio.h>
#include <stdlib.h>

void array_exchanger(int* array_a, int* array_b, int length) {
    int *temp;
	int i;
	for(i=0;i<length;++i){
		temp=array_b+i;
		array_b+i=array_a+i;
		array_a+i=temp;
	}
}

int main() {
    int length = 0,i;
    scanf("%d", &length);

    int *array_a, *array_b;

    array_a = (int*) malloc(length * sizeof(int));
    array_b = (int*) malloc(length * sizeof(int));

    for (i = 0; i < length; i++) {
        scanf("%d", &array_a[i]);
    }

    for (i = 0; i < length; i++) {
        scanf("%d", &array_b[i]);
    }

    array_exchanger(array_a, array_b, length);

    printf("%d", array_a[0]);
    for (i = 1; i < length; i++) {
        printf(" %d", array_a[i]);
    }

    printf("\n");

    printf("%d", array_b[0]);
    for (i = 1; i < length; i++) {
        printf(" %d", array_b[i]);
    }

}
