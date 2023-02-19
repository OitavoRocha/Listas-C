/*
Implemente uma funcao que calcule as raızes de uma equacao do segundo grau do tipo 
Ax2 + Bx + C = 0. Lembrando que:
X =(−B ±√∆) / 2A
Onde
    ∆ = B^2 − 4AC

A variavel A tem que ser diferente de zero.

    • Se ∆ < 0 nao existe real.
    • Se ∆ = 0 existe uma raiz real.
    • Se ∆ ≥ 0 existem duas raızes reais.

Essa funcao deve ter como valor de retorno o numero de raızes reais e distintas da equacao. Se existirem raızes reais, seus valores devem ser armazenados nas variaveis apontadas por X1 e X2.
*/
#include <stdio.h>
#include <math.h>

int raizes(float A,float B,float C,float * X1,float * X2);
int delta(float A, float B, float C);

int main() {
    float a = 1;
    float b = 3;
    float c = -4;
    float x1, x2;
    int numeroRaizes;

    numeroRaizes = raizes(a, b, c, &x1, &x2);
    if ( numeroRaizes==0 ) {
        printf("NAO EXISTEM RAIZES REAIS\n");
    } else {
        printf("x1: %.2f    x2: %.2f\n", x1, x2);
    }

    return 0;
}

int raizes(float A,float B,float C,float * X1,float * X2){
    int D = delta(A, B, C);
    if ( D == 0 ) {
        *X1 = (-(B)+(sqrt(D)))/(2*A);
        *X2 = *X1;
        return 1;
    } else if ( D<0 ) {
        return 0;
    } else {
        *X1 = (-(B)+(sqrt(D)))/(2*A);
        *X2 = (-(B)-(sqrt(D)))/(2*A);
        return 2;
    }
}

int delta(float A, float B, float C) {
    return pow(B,2)+((-4)*A*C);
}