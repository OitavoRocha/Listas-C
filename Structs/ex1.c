/*
Escreva um trecho de codigo para fazer a criacao dos novos tipos de dados conforme solicitado abaixo:
• Horario: composto de hora, minutos e segundos. 
• Data: composto de dia, mes e ano. 
• Compromisso: composto de uma data, horario e texto que descreve o compromisso.
*/
#include<stdio.h>

typedef struct Horario {
    int hora;
    int minutos;
    int segundos;
}horario;

typedef struct Data {
    int dia;
    int mes;
    int ano;
}date;

struct Compromisso {
    horario h;
    date d;
    char *texto;
};

int main() {

}