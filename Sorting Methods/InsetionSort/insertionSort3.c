#include <stdio.h>
#include <stdlib.h>
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

    return 0;
}