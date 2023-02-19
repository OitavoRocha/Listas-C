/*
Crie uma funcao para somar dois arrays. Esta funcao deve receber dois arrays e retornara soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja diferente entao a funcao retornara ZERO (0). Caso a funcao seja concluıda com sucesso a mesma deve retornar o valor UM (1). Utilize aritmetica de ponteiros para manipulacao do array
*/
#include <stdio.h>

int somaArray(int* a, int* b, int* res);

int main() {
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {9, 8, 7, 6, 5};
    int resultado[5] = {0, 0, 0, 0, 0};
    int flag;

    flag = somaArray(array1, array2, resultado);
    if ( flag==0 ) {
        printf("IMPOSSIVEL REALIZAR A OPERACAO\n");
    } else {
        for ( int i=0 ; i<(int)(sizeof(resultado)/sizeof(int)) ; i++ ) {
            printf("%d ", *resultado);
        }
        printf("\n");
    }
    return 0;
}

int somaArray(int* a, int* b, int* res) {
    int tamanho = (int)(sizeof(res)/sizeof(res[0]));
    if ( sizeof(a)!=sizeof(b) ) {
        return 0;
    }
    for ( int i=0 ; i<tamanho ; i++ ) {
        *res = *a + *b;        
    }
    return 1;
}