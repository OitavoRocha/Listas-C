// https://leetcode.com/problems/majority-element/
#include <stdio.h>
#include <stdlib.h>

int majorityElement(int* nums, int numsSize){
    int mat[numsSize][2];
    int key;
    int most = -1;
    int out;

    for( int i = 0 ; i<numsSize ; i++ )
        for( int j = 0 ; j<2 ; j++ )
            mat[i][j] = 0;
    
    for( int i = 0 ; i<numsSize ; i++ ) {
        mat[i][0] = nums[i];
        key = nums[i];
        for( int j = i + 1 ; j<numsSize ; j++ ) 
            if( key == nums[j] )
                mat[i][1]++;
    }

    for( int i = 0 ; i<numsSize ; i++ ) {
        if( most < mat[i][1] ) {
            most = mat[i][1];
            out = mat[i][0];
        }
    }
    
    return out;
}

int main() {
    int data[3] = { 3,3,4 };
    int n;

    n = majorityElement( data, 3 );

    printf("Elemento que mais aparece: %d\n", n);

    return 0;
}