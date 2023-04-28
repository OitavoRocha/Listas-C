#include <stdio.h>
#include <stdlib.h>
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
    srand(time(NULL));

    printf("Informe n: ");
    scanf("%d", &n);
    nums = (int *)malloc( sizeof(int) * n );

    printf("Vetor:\n");
    for( int i = 0 ; i<n ; i++ ) {
        nums[i] = rand() % 100;
        printf("%d ", nums[i]);
    }

    quickSort( nums, 0, n-1 );

    printf("\nVetor Ordenado:\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", nums[i]);

    return 0;
}