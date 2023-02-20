/*
Considere um cadastro de produtos de um estoque, com as seguintes informacoes para cada produto:
• Codigo de identificacao do produto: representado por um valor inteiro
• Nome do produto: com ate 50 caracteres
• Quantidade disponıvel no estoque: representado por um numero inteiro 
• Preco de venda: representado por um valor real

(a) Defina uma estrutura, denominada produto, que tenha os campos apropriados para guardar as informacoes de um produto
(b) Crie um conjunto de N produtos (N e um valor fornecido pelo usuario) e peca ao 
usuario para entrar com as informacoes de cada produto
(c) Encontre o produto com o maior preco de venda
(d) Encontre o produto com a maior quantidade disponıvel no estoque
*/
#include <stdio.h>
#include <stdlib.h>

struct produto {
    int id;
    int qtd;
    float preco;
    char nome[50];
};

typedef struct produto product;


int main() {
    product* produtos;
    product* maior;
    product* mais;
    int n;

    scanf("%d", &n);
    produtos = (product *)malloc(n*sizeof(product));
    for( int i=0 ; i<n ; i++ ) {
        printf("Informe os dados do produto %d\n", i+1);
        printf("Nome: ");
        scanf("%s", (produtos+i)->nome);
        getchar();
        printf("Id: ");
        scanf("%d", &(produtos+i)->id);
        printf("Quantidade disponivel: ");
        scanf("%d", &(produtos+i)->qtd);
        printf("Preco: ");
        scanf("%f", &(produtos+i)->preco);
    }

    for( int i=0 ; i<n ; i++ ) {
        if ( i==0 ) {
            maior = produtos;
            mais = produtos;
        } else {
            if ( maior->preco < (produtos+i)->preco ) {
                maior = (produtos+i);
            }
            if ( mais->qtd < (produtos+i)->qtd ) {
                mais = (produtos+i);
            }
        }
    }
    printf("Produto com maior preco: %s\nCom maior quantidade: %s\n", (maior)->nome, (mais)->nome);

    return 0;
}
