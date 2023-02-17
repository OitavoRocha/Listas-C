/*
Faca um programa para ler uma tabela contendo os nomes dos alunos de uma turma de
5 alunos. O programa deve solicitar ao usuario os nomes do aluno, sempre perguntando se ele deseja inserir mais um nome na lista. Uma vez lidos todos os alunos, o usuario ira indicar um nome que ele deseja verificar se esta presente na lista, onde o programa deve procurar pelo nome (ou parte deste nome) e se encontrar deve exibir na tela o nome completo e o ındice do vetor onde esta guardado este nome
*/
#include<stdio.h>
#include<string.h>

#define TAMANHO_NOME 100
#define NUMERO_ALUNOS 5

int main() {
    char alunos[TAMANHO_NOME][NUMERO_ALUNOS];
    char *busca;
    char *token;
    int acerto = 0;
    int flag;
    int i;

    printf("Informe o nome dos alunos: \n");
    for( i=0 ; i<NUMERO_ALUNOS ; i++ ) {
        printf("Aluno %d: ", i+1);
        scanf("%[^\n]s", alunos[i]);
        getchar();
    }

    printf("-----------------------------\nInsira o nome que você gostaria de buscar: ");
    scanf("%[^\n]s", busca);
    getchar();

    for( i=0 ; i<NUMERO_ALUNOS ; i++ ) {
        //POR QUE TA DANDO ERRO COM O USO DO TOKEN? COMO USAR CORRETAMENTE O COMANDO STRTOK
        token = strtok(alunos[i], " ");
        flag = strcmp(busca, token);
        if ( flag == 0 ) 
            acerto = i;
        }
    
    printf("O aluno %s esta na posicao %d\n", alunos[acerto], acerto);

    return 0;
}
