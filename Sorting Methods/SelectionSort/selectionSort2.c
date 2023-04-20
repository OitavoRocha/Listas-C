#include <stdio.h>
#include <stdlib.h>

void selectSort( int data[], int n ) {
    int min, buffer, min_id;

    for( int i = 0 ; i<n ; i++ ) {
        min = data[i];
        for( int j = i+1 ; j<n ; j++ ) 
            if( data[j] < min ) {
                min = data[j];
                min_id = j;
            }
        buffer = data[i];
        data[i] = data[min_id];
        data[min_id] = buffer;
        min_id = i+1;
    }
}

int main() {
    int * array;
    int n;

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    array = (int *)malloc( sizeof(int) * n );

    printf("Enter values to fill the array\n");
    for( int i = 0 ; i<n ; i++ ) {
        printf("Number %d: ", i+1);
        scanf("%d", &array[i]);
    }

    selectSort( array, n );
    
    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<n ; i++ ) 
        printf("%d ", array[i]);

    return 0;
}