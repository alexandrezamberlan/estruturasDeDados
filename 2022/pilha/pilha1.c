#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox; //ponteiro para o proximo elemento dessa estrutura
} Celula;

Celula *inserir(int valor, Celula *topo) {
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));
        
    //depositar valor
    novo->dado = valor;

    //engatar o novo no ultimo
    novo->prox = topo;

    //retornar o novo top
    return novo;
}

Celula *remover(Celula *topo) {
    //testar se pilha vazia
    if (!topo) {
        printf("Pilha vazia. Operacao nao realizada\n");
        return topo;
    }

    //ponteiro lixo apontar para o topo/ultimo
    Celula *lixo = topo;

    //topo avanca 
    topo = topo->prox;

    //liberar lixo
    free(lixo);

    //retornar novo topo
    return topo;
}

int contarNos(Celula *topo) {
    int qtd = 0;
    Celula *p;
    for (p = topo; p ; p = p->prox){
        qtd++;
    }
    return qtd;
}

void exibir(Celula *topo) {
    if (!topo) {
        printf("Pilha vazia\n");
        return;
    }
    Celula *p;
    for (p = topo; p ; p = p->prox){
        printf("%d\t", p->dado);
    } 

}

int localizado(int valor, Celula *topo){
    Celula *p;
    if (!topo) return 0; //pilha vazia, logo valor nao encontrado

    for (p = topo; p ; p = p->prox){
        if (valor == p->dado) return 1
    }
    return 0; //passou por toda a pilha e nao encontrou o valor
}

int main() {
    Celula *pilha1 = NULL;          //pilha1 é um ponteiro de Celula que vai apontar para o ultimo elemento inserido

    pilha1 = inserir(15, pilha1);
    pilha1 = inserir(10, pilha1);
    pilha1 = inserir(5, pilha1);
    pilha1 = inserir(25, pilha1);
    pilha1 = inserir(100, pilha1);

    pilha1 = remover(pilha1);

    printf("Endereco do ultimo elemento: %p\n",pilha1);
    printf("Valor do ultimo elemenbto  : %d\n",pilha1->dado);  

    printf("O tamanho da pilha1 eh: %d\n", contarNos(pilha1));  
    exibir(pilha1);

    printf("O numero 12 esta ou nao na pilha? %d", localizado(12, pilha1));
    

    return 1;
}