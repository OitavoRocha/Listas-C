/*
Foi realizada um pesquisa de algumas caracterısticas fısicas de cinco habitantes de certa regiao. De cada habitante foram coletados os seguintes dados: sexo, cor dos olhos (A – Azuis ou C – Castanhos), cor dos cabelos (L – Louros, P – Pretos ou C – Castanhos) e idade.
• Faca uma funcao que leia esses dados em um vetor.
• Faca uma funcao que determine a media de idade das pessoas com olhos castanhos e cabelos pretos.
• Faca uma funcao que determine e devolva ao programa principal a maior idade entre os habitantes.
• Faca uma funcao que determine e devolva ao programa principal a quantidade de indivıduos do sexo feminino cuja idade esta entre 18 e 35 (inclusive) e que tenham olhos azuis e cabelos louros.
*/
#include<stdio.h>

#define NUM_HABITANTES 2

struct dados {
    char sexo;
    char corOlhos;
    char corCabelo;
    int idade;
}info[NUM_HABITANTES];

void lerDados(int n);
float calculaMedia();
int calculaIdadeMaior();
int contaFeminino();

int main() {
    int maiorIdade;
    int qtde;

    for (int i = 0; i < NUM_HABITANTES; i++) {
        printf("Informe as caracteristicas\n");
        lerDados(i);
        printf("+--------------------+\n");
    }

    printf("Media idade pessoas com olhos castanhos e cabelos pretos: %.2f\n", calculaMedia());
    
    

    return 0;
}

void lerDados(int n) {
    printf("Sexo: (F - Feminino | M - Masculino | O - Outro)\n");
    info[n].sexo = getchar();
    getchar();
    printf("Cor dos Olhos: (A - Azuis ou C - Castanhos)\n");
    info[n].corOlhos = getchar();
    getchar();
    printf("Cor dos Cabelos: (L - Louros, P - Pretos ou C - Castanhos)");
    info[n].corCabelo = getchar();
    getchar();
    printf("Idade: ");
    scanf("%d", &info[n].idade);
    getchar();
}

float calculaMedia() {
    int soma=0, qtd=0;
    float media;

    for (int i = 0; i < NUM_HABITANTES; i++) {
        if ( (info[i].corCabelo == 'C') && (info[i].corOlhos == 'P') ) {
            soma += info[i].idade;
            qtd++;
        }
    }
    printf("%d %d\n", soma, qtd);
    media = (float)soma / (float)qtd;
    return media;
}

int calculaIdadeMaior() {
    return 0;
}

int contaFeminino() {
    return 0;
}