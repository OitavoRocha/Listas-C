/*
Considerando a estrutura para representar um vetor no R3, implemente uma funcao que calcule a soma de dois vetores. Essa funcao deve obedecer ao prototipo: 
void soma (struct Vetor* v1, struct Vetor* v2, struct Vetor* res);
onde os parametros v1 e v2 sao ponteiros para os vetores a serem somados, e o parametro res e um ponteiro para uma estrutura vetor onde o resultado da operacao deve ser armazenado.
*/
#include<stdio.h>

struct Vetor{
float x;
float y;
float z;
};

typedef struct Vetor vetor;

void soma (struct Vetor* v1, struct Vetor* v2, struct Vetor* res);

int main() {
    vetor v1, v2, resposta;

    v1.x = 2;
    v1.y = 5;
    v1.z = -3;

    v2.x = 1;
    v2.y = 0;
    v2.z = 7;

    soma(&v1, &v2, &resposta);
    printf("%.2f\n", resposta.x);
    printf("%.2f\n", resposta.y);
    printf("%.2f\n", resposta.z);

    return 0;
}

void soma (struct Vetor* v1, struct Vetor* v2, struct Vetor* res) {
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
}