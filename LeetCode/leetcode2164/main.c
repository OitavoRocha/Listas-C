// https://leetcode.com/problems/sort-even-and-odd-indices-independently/
// odd - decreasing order && even - increasing order
#include <stdio.h>
#include <stdlib.h>

int* sortEvenOdd(int* nums, int numsSize, int* returnSize){
    int min, max;
    int min_id = 0 , max_id = 1;
    int buffer;

    for( int i = 0 ; i<numsSize ; i += 2 ) {
        min = nums[i];
        for( int j = i+2 ; j<numsSize ; j+=2 ) {
            if( nums[j]<min ) {
                min = nums[j];
                min_id = j;
            }
        }
        buffer = nums[i];
        nums[i] = nums[min_id];
        nums[min_id] = buffer;
        min_id = i+2;
    }

    for( int i = 1 ; i<numsSize ; i += 2 ) {
        max = nums[i];
        for( int j = i+2 ; j<numsSize ; j+=2 ) {
            if( nums[j]>=max ) {
                max = nums[j];
                max_id = j;
            }
        }
        buffer = nums[i];
        nums[i] = nums[max_id];
        nums[max_id] = buffer;
        max_id = i+2;
    }

    *returnSize = numsSize;
    return nums;
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

    data = sortEvenOdd( data, n, &n );

    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", data[i] );
    
    free( data );
    return 0;
}