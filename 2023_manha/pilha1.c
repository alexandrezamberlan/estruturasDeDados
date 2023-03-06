//Pilha (Stack) é uma ED Abstrata com duas operações somente
    //LIFO - Last In, First Out
    //inserir (push)   -> topo - ponteiro (variável dinâmica que guarda o endereço do ultimo elemento inserido)
        //há um valor para inserir
    //remover (pop)   -> topo
        //sempre sai o valor que está no topo

//Pilha é linear
    //vetor -> alocação estática -> tempo de programação
    //struct + ponteiro -> alocação dinâmica -> tempo de execução        
        //malloc
        //free

#include <stdio.h>
#include <stdlib.h>

//criar ou definir artificialmente um struct
//exemplo uma estrutura ou tipo para dados cartesianos
typedef struct no {
    int x;
    int y;
    struct no *prox;
} PontoCartesiano;        


PontoCartesiano *inserir(int x, int y, PontoCartesiano *topo) {
    //alocar memoria
    PontoCartesiano *novo = (PontoCartesiano *)malloc(sizeof(PontoCartesiano));
    
    //depositar valores
    novo->x = x;
    novo->y = y;

    //encadear e retornar
    novo->prox = topo;

    return novo;
}

PontoCartesiano *remover(PontoCartesiano *topo) {
    if (!topo) return topo;
    
    //guardar o topo em lixo
    PontoCartesiano *lixo = topo;

    //avancar o topo para o proximo elemento
    topo = topo->prox;

    //liberar memoria
    free(lixo);

    //retornar o novo topo
    return topo;
}


int contarPilha(PontoCartesiano *topo) {
    int qtd = 0;
    for (PontoCartesiano *p = topo; p ; p = p->prox) {
        qtd++;
    }
    return qtd;
}


void exibir(PontoCartesiano *topo) {

    for (PontoCartesiano *p = topo; p ; p = p->prox) {
        printf("(%d,%d)\n", p->x, p->y);
    }
    
}
int main() {
    PontoCartesiano *pilha = NULL;

    pilha = inserir(-3,1,pilha);
    pilha = inserir(0,7,pilha);
    pilha = inserir(0,0,pilha);

    printf("Esta estrutura tem %d elementos\n", contarPilha(pilha));
    exibir(pilha);


    // printf("Endereco do topo: %p\n", pilha);
    // printf("Valores do topo: %d,%d\n", pilha->x, pilha->y);

    // pilha = remover(pilha);
    // pilha = remover(pilha);

    // printf("Endereco do topo: %p\n", pilha);
    // printf("Valores do topo: %d,%d\n", pilha->x, pilha->y);
    return 1;
}

















