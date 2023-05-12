#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void quickSort( int nums[], int left, int right ) {
    int pivot;
    int buffer;
    int i = left, j = right;

    if( i == j-1 )
        pivot = nums[i];
    else
        pivot = nums[(rand() % (left - right + 1)) + left];

    do {
        while( nums[i] < pivot )
            i++;
        while( nums[j] > pivot )
            j--;
        
        if( i<=j ) {
            buffer = nums[i];
            nums[i] = nums[j];
            nums[j] = buffer;
            i++;
            j--;
        }
    } while( i <= j );
    
    if( left<j )
        quickSort( nums, left, j );
    if( right>i )
        quickSort( nums, i, right );
}

int main() {
    int n;
    int * nums;
    clock_t t;
    srand(time(NULL) ^ (intptr_t)&main);

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    nums = (int *)malloc( sizeof(int) * n );

    for( int i = 0 ; i<n ; i++ ) {
        nums[i] = rand() % 500;
    }

    t = clock();
    quickSort( nums, 0, n-1 );
    t = clock() - t;

    printf("Execution Time: %.5fs\n", ((double)t)/CLOCKS_PER_SEC);
    free( nums );
    return 0;
}