// this code takes a value in the middle of each array and subarray as the pivot for each call of quickSort() function
#include <stdio.h>

#define MAX 10

void quickSort( int data[], int left, int right ) {
    int mid, buffer, i = left, j = right;

    mid = data[(left + right)/2];

    do {
        while( data[i] < mid )
            i++;
        while( mid < data[j] )
            j--;
        
        if( i <= j ) {
            buffer = data[i];
            data[i] = data[j];
            data[j] = buffer;
            i++;
            j--; 
        }
    } while( i<=j );

    if( left < j )
        quickSort( data , left, j );
    if( i < right )
        quickSort( data, i, right );
}

int main(){
    int data[MAX];
    
    printf("Informe values for the array\n");
    for( int i = 0 ; i<MAX ; i++ ) {
        printf("Number %d: ", i+1 );
        scanf("%d", &data[i]);
    }

    quickSort( data, 0, MAX-1 );

    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<MAX ; i++ )
        printf("%d ", data[i] );

    return 0;
}