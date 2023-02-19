#include <stdio.h>

int main() {
    int array[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int* pointer;

    pointer = array;

    for ( int i=0 ; i<10 ; i++ ) {
        *pointer = 2;
        printf("%d ", *pointer);
        pointer++;
    }
    printf("\n");
 
    return 0;
}
