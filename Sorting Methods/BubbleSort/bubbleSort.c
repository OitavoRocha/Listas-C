#include <stdio.h>
#include <stdlib.h>

void bubbleSort( int data[], int size ) {
    int buffer;

    for( int i = 0 ; i < size - 1 ; i++ ) 
        for( int j = 0 ; j < size - 1 ; j++ ) // j do not go up to the last element of array
            if( data[j] > data[j+1] ) {
                // swap
                buffer = data[j];
                data[j] = data[j+1];
                data[j+1] = buffer;
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

    bubbleSort( data, n );

    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", data[i] );
    
    free( data );
    return 0;
}