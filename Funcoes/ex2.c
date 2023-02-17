/*
Faca uma funcao que receba a data atual (dia, mes e ano em inteiro) e exiba-a na tela no formato textual por extenso. 
Exemplo: Data: 01/01/2000, Imprimir: 1 de janeiro de 2000.
*/
#include<stdio.h>
#include<string.h>

struct dma {
    int dia;
    int mes;
    int ano;
};

typedef struct dma data;

void converteData(data d1);

int main() {
    data d1;

    printf("Informe a data deseja: (dd/mm/aaaa)\n");
    scanf("%d/%d/%d", &d1.dia, &d1.mes, &d1.ano);

    converteData(d1);

    return 0;
}

void converteData(data d1) {
    char mes[10]; //POR QUE O STRCPY NAO ESTA ESCREVENDO CORRETAMENTE DENTRO DA VARIAVEL QUANDO EU CRIO ELA COMO "char *mes;" ?

    //EH POSSIVEL TRANSFORMAR UMA ENUMARATION EM UMA STRING?
    switch (d1.mes) {
        case 1:
            strcpy(mes, "Janeiro");
            break;
        case 2:
            strcpy(mes, "Fevereiro");
            break;
        case 3:
            strcpy(mes, "Marco");
            break;
        case 4:
            strcpy(mes, "Abril");
            break;
        case 5:
            strcpy(mes, "Maio");
            break;
        case 6:
            strcpy(mes, "Junho");
            break;
        case 7:
            strcpy(mes, "Julho");
            break;
        case 8:
            strcpy(mes, "Agosto");
            break;
        case 9:
            strcpy(mes, "Setembro");
            break;
        case 10:
            strcpy(mes, "Outubro");
            break;
        case 11:
            strcpy(mes, "Novembro");
            break;
        case 12:
            strcpy(mes, "Dezembro");
            break;
    }

    printf("%d de %s de %d\n", d1.dia, mes, d1.ano);
}
