// this code takes a random value in the array as the pivot, wich may be better in bigger arrays
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void quickSort( int data[], int left, int right ) {
    int pivot, buffer, i = left, j = right, n;

    // this condition is needed when we are with really close limits, to avoid 'rand()%0'
    if( i == j-1 )
        n = i;
    else
        n = (rand() % (left - right + 1)) + left;

    pivot = data[n];

    do {
        while( data[i] < pivot )
            i++;
        while( pivot < data[j] )
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
    srand(time(NULL));
    
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