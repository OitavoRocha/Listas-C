/*
Faca um programa que:
(a) Peca para o usuario entrar com o nome e a posicao (coordenadas X e Y) de N cidades e as armazene em um vetor de estruturas (N e informado pelo usuario); -
(b) Crie uma matriz de distancias entre cidades de tamanho N x N; -
(c) Calcule as distancia entre cada duas cidades e armazene na matriz; -
(d) Exiba na tela a matriz de distancias obtida; -
(e) Quando o usuario digitar o numero de duas cidades o programa devera retornar a distancia entre elas. -
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char nome[30];
    int x;
    int y;
}Cidade;

float calculaDistancia(float x1, float x2, float y1, float y2);

int main() {
    int n;
    int count=0;
    Cidade* c;
    float** dist;
    float distanciaEntreDuas;
    char cidade1[30];
    char cidade2[30];

    printf("Informe o numero de cidades: ");
    scanf("%d", &n);

    c = (Cidade *)malloc(sizeof(Cidade)*n);
    for( int i=0 ; i < n ; i++ ) {
        getchar();
        printf("Informe os dados da cidade %d\n", i+1);
        printf("Nome: ");
        scanf("%[^\n]s", (c+i)->nome);
        getchar();
        printf("Localizacao (X Y): ");
        scanf("%d", &(c+i)->x);
        scanf("%d", &(c+i)->y);
    }
    getchar();

    dist = (float **)malloc(sizeof(int *) * n);
    for( int i=0 ; i < n ; i++ ) {
        dist[i] = (float *)malloc(n*sizeof(float));
    }

    for( int i=0 ; i < n ; i++ ) {
        for( int j=0 ; j<n ; j++ ) {
            dist[i][j] = calculaDistancia(c[i].x, c[j].x, (c+i)->y, (c+j)->y);
        }
    }

    for( int i=0 ; i < n ; i++ ) {
        for( int j=0 ; j<n ; j++ ) {
            printf("%.2f ", dist[i][j]);
        }
        printf("\n");
    }

    printf("Informe o nome de duas cidades: ");
    scanf("%[^\n]s", cidade1);
    getchar();
    scanf("%[^\n]s", cidade2);
    getchar();
    
    for( int i=0 ; i<n ; i++ ) {
        if( (strcmp((c+i)->nome, cidade1)) == 0 ) {
            for( int j=0 ; j<n ; j++ ) {
                if( (strcmp((c+j)->nome, cidade2)) == 0 ) {
                    distanciaEntreDuas = dist[i][j];
                    count++;
                    i = n;
                    j = n;
                }
            }
        }
    }

    if ( count==0 ) {
        printf("Distancia nao encontrada\n");
    } else {
        printf("A distancia entre ambas as cidades eh de %.2f\n", distanciaEntreDuas);
    }
    
    free(c);
    for( int i=0 ; i<n ; i++ ) {
        free(dist[i]);
    }
    free(dist);
    
    return 0;
}

float calculaDistancia(float x1, float x2, float y1, float y2) {
    float distancia;
    float a, b;

    a = x2 - x1;
    b = y2 -y1;
    distancia = pow(a, 2) + pow(b, 2);

    return sqrt(distancia);
}
