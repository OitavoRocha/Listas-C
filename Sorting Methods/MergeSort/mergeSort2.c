#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort( int nums[], int left, int right );
void merge( int nums[], int left, int mid, int right );

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

    sort( nums, 0, n-1 );

    printf("\nVetor Ordenado:\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", nums[i]);

    return 0;
}

void sort( int nums[], int left, int right ) {
    if( left < right ) {
        int mid = left + ( right - left )/2;

        sort( nums, left, mid );
        sort( nums, mid+1, right);

        merge( nums, left, mid, right);
    }
}

void merge( int nums[], int left, int mid, int right ) {
    int i, j, k;
    int n1 = mid - left + 1, n2 = right - mid;
    int leftList[n1], rightList[n2];

    for( i = 0 ; i<n1 ; i++ ) 
        leftList[i] = nums[left + i];
    for( j = 0 ; j<n2 ; j++ )
        rightList[j] = nums[mid + j + 1];
    
    i = j = 0;
    k = left;

    while( i<n1 && j<n2 ) {
        if( leftList[i] >= rightList[j] ) {
            nums[k] = rightList[j];
            j++;
            k++;
        } else {
            nums[k] = leftList[i];
            i++;
            k++;
        }
    }

    while( i<n1 ) {
        nums[k] = leftList[i];
        k++;
        i++;
    }

    while( j<n2 ) {
        nums[k] = rightList[j];
        j++;
        k++;
    }
}