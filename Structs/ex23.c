/*
Escreva um programa que receba dois structs do tipo dma, cada um representando uma data valida, e calcule o numero de dias que decorreram entre as duas datas. 
*/
#include<stdio.h>

struct dma {
    int dia;
    int mes;
    int ano;
};

typedef struct dma dma;

int calculaDiferenca(dma maior, dma menor);

int main() {
    dma data1;
    dma data2;
    int dias;

//  LE AS VARIAVEIS
    printf("Informe a primeira data (dd/mm/aaaa)\n");
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    printf("Agora informe a segunda data\n");
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

//  CALCULA A DIFERENCA ENTRE DATAS
    if ( data1.ano > data2.ano ) {
        dias = calculaDiferenca(data1, data2);
    } else {
        dias = calculaDiferenca(data2, data1);
    }

    printf("As datas tem %d dias entre elas\n", dias);

    return 0;
}

int calculaDiferenca(dma maior, dma menor) {
    int anos, meses, dias;

    if ( maior.mes >= menor.mes ) {
        anos = (maior.ano - menor.ano) * 365;
    } else {
        anos = (maior.ano - menor.ano - 1) * 365;
    } 
    printf("anos %d\n", anos);

    if ( maior.mes > menor.mes ) {
        meses = (maior.mes - (maior.mes - menor.mes)) * 30;
    } else if ( maior.mes < menor.mes ) {
        meses = (menor.mes - (menor.mes - maior.mes)) * 30;
    } else { 
        meses = 0;
    }

    printf("meses %d\n", meses);

    if ( maior.dia > menor.dia ) {
        dias = (maior.dia - menor.dia);
    } else if ( maior.dia < menor.dia ) {
        dias = (menor.mes - maior.mes);
    } else { 
        dias = 0;
    }

    printf("dias %d\n", dias);

    return dias+meses+anos;
}