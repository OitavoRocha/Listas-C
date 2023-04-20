#include <stdio.h>
#include <stdlib.h>

void insertionSort( int data[], int n ) {
    int buffer;
    int j;

    for( int i = 1 ; i < n ; i++ ) {
        j = i;
        while ( j>0 && data[j-1]>data[j] ){
            buffer = data[j-1];
            data[j-1] = data[j];
            data[j] = buffer;
            j--;
        }
    }
}

int main() {
    int * data;
    int n;

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    data = (int *)malloc( sizeof(int) * n );

    printf("Informe values for the array\n");
    for( int i = 0 ; i<n ; i++ ) {
        printf("Number %d: ", i+1 );
        scanf("%d", &data[i]);
    }

    insertionSort( data, n );

    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", data[i] );
    
    free( data );
    return 0;
}