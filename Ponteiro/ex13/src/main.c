/*
Elabore uma funcao que receba duas strings como parametros e verifique se a segunda string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres das strings.
*/
#include <stdio.h>
#include <string.h>

void strCMP(char *str1, char *str2) {
    int flag = 0;
    int count = 0;

    for( int i=0 ; i<strlen(str1) ; i++ ) {
        if ( *(str1) == *(str2) ) {
            for( int j=0 ; j<strlen(str2) ; j++ ) {
                if ( *(str1) != *(str2) ) {
                    flag++;
                }
                count++;
                str1++;
                str2++;
            }
            if (flag==0) i += count;
            else i = strlen(str1);
        }
        str1++;
    }

    if ( flag==0 ) {
        printf("A segunda string ocorre dentro da primeira\n");
    }
}

int main() {
    char *str1 = "SDUSFAHGUANSDHUAFASD";
    char *str2 = "GUAN";

    strCMP(str1, str2);

    return 0;
}
