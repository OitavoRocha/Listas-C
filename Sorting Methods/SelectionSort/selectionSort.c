#include <stdio.h>

#define N 10

int main() {
    int array[N];
    int buffer;

    printf("Enter values to fill the array\n");
    for( int i = 0 ; i<N ; i++ ) {
        printf("Number %d: ", i+1);
        scanf("%d", &array[i]);
    }

    for( int i = 0 ; i<N ; i++ )
        for( int j = i + 1 ; j<N ; j++ ) 
            if ( array[i] > array[j] ) {
                buffer = array[j];
                array[j] = array[i];
                array[i] = buffer;
            }
    
    printf("Printing the sorted array...\n");
    for( int i = 0 ; i<N ; i++ ) 
        printf("%d ", array[i]);

    return 0;
}