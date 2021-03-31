#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    //poderia ter outras variáveis
    struct nodo *prox;
} Celula;

Celula *inserirC(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;

    if (!lista) {
        novo->prox = novo; //o único elemento deve apontar pra si mesmo
        return novo; //se a lista for vazia, o novo será o primeiro e único elemento nela
    }

    //percorrer toda a lista e inserir na última posição
    Celula *p;
    for (p = lista; p->prox != lista; p = p->prox); //percurso para parar o p no último elemento

    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado
    novo->prox = lista; //o último elemento aponta para o primeiro elemento

    //retornar o primeiro elemento
    return lista;
}

void exibirC(Celula *lista) {
    Celula *p;

    if (!lista) {
        printf("Lista vazia!\n");
        return;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        printf("%d\t", p->valor);
    }
    printf("%d\n", p->valor);
}

int contarElementosC(Celula *lista) { //lista contém o endereco do 1o elemento
   Celula *p;
   int contador = 0;

    if (!lista) {
        return contador;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        contador++;
    } 
    
    return ++contador;
}

Celula *podarC(Celula *lista) {
    int qtd = contarElementosC(lista);
    if (qtd >= 0 && qtd <= 2) {
        printf("A quantidade não permite a poda\n");
        return lista;
    }

    Celula *p, *novaLista;
    p = lista;
    novaLista = lista->prox; //reposicionei o controle da lista no segundo elemento
    free(p); //liberamos o endereço do primeiro elemento, ou seja, podamos o primeiro

    //leva o p até o penúltimo elemento, pois o último elemento sera liberado
    for (p = novaLista; p->prox->prox != lista; p = p->prox);

    free(p->prox);
    p->prox = novaLista;


    return novaLista;
}

int main() {
    Celula *listaC = NULL;
    int valor;
    system("clear"); //system("cls");
    do {
        printf("Informe um valor inteiro para a lista (-1 sai do programa): ");
        scanf("%d", &valor);
        if (valor == -1) break;

        listaC = inserirC(valor,listaC);
    } while (1);

    exibirC(listaC);

    printf("A lista circular possui %d elementos\n", contarElementosC(listaC));
    
    listaC = podarC(listaC);
    printf("Lista após a poda\n");
    exibirC(listaC);
    return 1;
}
