/*
Faca um programa que possua uma funcao para:
• ler 2 notas e retorna-las por parametro (chamar uma funcao dedicada a ler 2 notas validas e que devolver os 2 numeros lidos); 
• calcular a media simples e a media ponderada e retorna-las por parametro, onde a segunda nota tem peso 2 media ponderada = (n1 + n2 ∗ 2)/3;
*/
#include <stdio.h>

void leNotas(int* a, int* b);
void calculaMedias(float* simples, float* ponderada, int* a, int* b);

int main() {
    int nota1;
    int nota2;
    float mediaSimples;
    float mediaPonderado;

    leNotas(&nota1, &nota2);
    calculaMedias(&mediaSimples, &mediaPonderado, &nota1, &nota2);
    printf("Nota Simples: %.2f\nMedia Ponderada: %.2f\n", mediaSimples, mediaPonderado);

    return 0;
}

void leNotas(int* a, int* b) {
    printf("Informe a primeira nota: ");
    scanf("%d", a);
    printf("Agora a segunda: ");
    scanf("%d", b);
}

void calculaMedias(float* simples, float* ponderada, int* a, int* b) {
    *simples = (*a + *b)/2.0;
    *ponderada = (*a + (*b*2))/3;
}