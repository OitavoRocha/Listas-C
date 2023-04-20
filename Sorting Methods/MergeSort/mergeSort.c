// code from: https://www.geeksforgeeks.org/merge-sort/
#include <stdio.h>
#include <stdlib.h>

void sort( int data[], int left, int right );
void merge( int data[], int left, int middle, int right );

int main() {
    int * array;
    int n;

    printf("Number of elements in the array: ");
    scanf("%d", &n);
    array = (int *)malloc( sizeof(int) * n );

    printf("Enter each element\n");
    for( int i = 0 ; i<n ; i++ ) {
        printf("Number %d: ", i+1);
        scanf("%d", &array[i]);
    }
    
    sort( array, 0, n-1 );

    printf("Printing sorted array...\n");
    for( int i = 0 ; i<n ; i++ )
        printf("%d ", array[i]);

    free(array);
    return 0;
}

void sort( int data[], int left, int right ) {
    if( left < right ){
        int middle = left + ( right - left ) / 2;

        sort( data, left, middle );
        sort( data, middle+1 , right);
        
        merge( data, left, middle, right );
    }   
}

void merge( int data[], int left, int middle, int right ) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftList[n1], rightList[n2];

    for( i = 0 ; i<n1 ; i++ )
        leftList[i] = data[left + i];
    for( j = 0 ; j<n2 ; j++ )
        rightList[j] = data[middle + 1 + j];
    
    i = j = 0;
    k = left;

    while( i<n1 && j<n2 ) {
        if( leftList[i] <= rightList[j]){
            data[k] = leftList[i];
            i++;
        } else {
            data[k] = rightList[j];
            j++;
        }
        k++;
    }

    while( i<n1 ) {
        data[k] = leftList[i];
        i++;
        k++;
    }

    while( j<n2 ) {
        data[k] = rightList[j];
        j++;
        k++;
    }
}