#include <stdio.h>
#include <stdlib.h>
#include "11762.h"

int main() {
    Node *head = NULL;
    int n, data, i;

    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &data);
        head = Create_List( head, data );
    }

    head = Reverse_List( head );

    Print_List( head );
    Free_List( head );

    return 0;
}


