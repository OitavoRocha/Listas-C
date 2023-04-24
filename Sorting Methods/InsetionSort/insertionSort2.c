// this code comes from Cormen's book, chap 2, page 12
// in this example the array won't be changed in its first position 
#include <stdio.h>

void insertionSort ( int data[] ) {
    int key;
    int i;

    for( int j = 2 ; j<=6 ; j++ ) {
        key = data[j];
        i = j - 1;
        while( i>0 && data[i]>key ) {
            data[i+1] = data[i];
            i -= 1;
        }
        data[i+1] = key;
    }
}

int main() {
    int array[] = { 5, 2, 4, 6, 1, 3 };

    for( int i = 0 ; i<6 ; i++ )
        printf("%d ", array[i]);

    insertionSort( array );
    printf("\n");

    for( int i = 0 ; i<6 ; i++ )
        printf("%d ", array[i]);

    return 0;
}