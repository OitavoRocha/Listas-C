/*
Link pro leetcode: https://leetcode.com/problems/string-compression/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char c;
    char* str;
    char* compressed;
    char n[10];
    int count=0;
    int count2;
    int j=0;

    str = (char *)malloc(sizeof(char));
    c = getchar();
    while ( c!='\n' ) {
        str[count] = c;
        count++;
        str = (char *)realloc(str, (count+1)*sizeof(char));
        c = getchar();
    }
    str[count] = '\0';

    compressed = (char *)malloc(sizeof(char));

    for ( int i=0 ; i<count ; i++ ) {
        count2 = 0;
        if ( str[i]==str[i+1] ) {
            count2++;
        } else {
            compressed = (char *)realloc(compressed, sizeof(compressed)+(2*sizeof(char)));
            compressed[j] = str[i];
            if ( count2!=0 ) {
                sprintf(n, "%d", count2);
                strcat(compressed, n);
            }
        }
    }

    printf("%s\n", str);    

    return 0;
}
