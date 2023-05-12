#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void selectionSort( int * nums, int size ) {
    int key;
    int min_id;
    int buffer;

    for( int i = 0 ; i<size ; i++ ) {
        key = nums[i];

        for( int j = i + 1 ; j<size ; j++ ) 
            if( key > nums[j] ) {
                key = nums[j];
                min_id = j;
            }
        
        buffer = nums[i];
        nums[i] = nums[min_id];
        nums[min_id] = buffer;

        min_id = i + 1;
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
    for( int i = 0 ; i<n ; i++ )
        nums[i] = rand() % 100;

    selectionSort( nums, n );

    printf("Vetor Ordenado:\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", nums[i]);

    return 0;*/

    
    clock_t t;
    srand(time(NULL) ^ (intptr_t)&main);

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    nums = (int *)malloc( sizeof(int) * n );

    for( int i = 0 ; i<n ; i++ ) {
        nums[i] = rand() % 500;
    }

    t = clock();
    selectionSort( nums, n );
    t = clock() - t;

    printf("Execution Time: %.5fs\n", ((double)t)/CLOCKS_PER_SEC);
    free( nums );
    return 0;
}