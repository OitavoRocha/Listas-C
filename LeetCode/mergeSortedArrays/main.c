// https://leetcode.com/problems/merge-sorted-array/
#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int * temp = (int *)malloc( sizeof(int) * m );
    int i, j, k;

    for( i = 0 ; i<m ; i++ )
        temp[i] = nums1[i];

    i = j = k = 0;

    while( i<m && j<n ) {
        if( temp[i] <= nums2[j] ) {
            nums1[k] = temp[i];
            i++;
        } else {
            nums1[k] = nums2[j];
            j++;
        }
        k++;
    }

    while( i<m ) {
        nums1[k] = temp[i];
        i++;
        k++;
    }

    while( j<n ) {
        nums1[k] = nums2[j];
        j++;
        k++;
    }
    
}

int main() {
    int n;
    int m;
    int * nums1;
    int * nums2;

    printf("Informe os valores de m e n: ");
    scanf("%d%d", &m, &n);

    printf("Vetor 1\n");
    nums1 = (int *)calloc( ( m + n ), sizeof(int) );
    for( int i = 0 ; i<m ; i++ ) 
        scanf("%d", &nums1[i]);

    nums2 = (int *)malloc( sizeof(int) * n );
    printf("Vetor 2\n");
    for( int i = 0 ; i<n ; i++ ) 
        scanf("%d", &nums2[i]);

    merge( nums1, m+n, m, nums2, n, n );

    printf("\n");
    for( int i = 0 ; i<m+n ; i++ ) 
        printf("%d ", nums1[i]);

    return 0;
}