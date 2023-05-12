#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void insertionSort( int nums[], int size ) {
    int buffer;
    int j;

    for( int i = 0 ; i<size ; i++ ) {
        j = i;

        while( j>0 && nums[j-1]>nums[j] ) {
            buffer = nums[j-1];
            nums[j-1] = nums[j];
            nums[j] = buffer;
            j--;
        }
    }
}

int main() {
    int n;
    int * nums;

/*
    srand(time(NULL));

    printf("Informe n: ");
    scanf("%d", &n);
    nums = (int *)malloc( sizeof(int) * n );

    printf("Vetor:\n");
    for( int i = 0 ; i<n ; i++ ) {
        nums[i] = rand() % 100;
        printf("%d ", nums[i]);
    }

    insertionSort( nums, n );

    printf("\nVetor Ordenado:\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", nums[i]);
*/
    clock_t t;
    srand(time(NULL) ^ (intptr_t)&main);

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    nums = (int *)malloc( sizeof(int) * n );

    //printf("Informe values for the array\n");
    for( int i = 0 ; i<n ; i++ ) {
        //printf("Number %d: ", i+1 );
        //scanf("%d", &data[i]);
        nums[i] = rand() % 500;
    }

    t = clock();
    insertionSort( nums, n );
    t = clock() - t;

/*
    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", data[i] );
*/
    printf("Execution Time: %.5fs\n", ((double)t)/CLOCKS_PER_SEC);
    free( nums );
    return 0;
}