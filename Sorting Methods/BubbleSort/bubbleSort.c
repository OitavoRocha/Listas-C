#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

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
    clock_t t;
    srand(time(NULL) ^ (intptr_t)&main);

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    data = (int *)malloc( sizeof(int) * n );

    //printf("Informe values for the array\n");
    for( int i = 0 ; i<n ; i++ ) {
        //printf("Number %d: ", i+1 );
        //scanf("%d", &data[i]);
        data[i] = rand() % 500;
    }

    t = clock();
    bubbleSort( data, n );
    t = clock() - t;

/*
    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", data[i] );
*/
    printf("Execution Time: %.5fs\n", ((double)t)/CLOCKS_PER_SEC);
    free( data );
    return 0;
}