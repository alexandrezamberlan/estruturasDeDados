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

void mostrarPrimeiraMetadeC(Celula *lista) {
    Celula *p;
    int qtd = contarElementosC(lista);
    printf("PRIMEIRA METADE DA LISTA\n");
    
    if (qtd == 0 || qtd == 1) {
        printf("Lista Circular sem possibilidade de divisão\n");
        return;
    }

    int metade = qtd / 2;
    int i;
    for (p = lista, i = 0; i < metade; p = p->prox, i++) {
        printf("%d\t", p->valor);
    }
    printf("\n");
}

void mostrarSegundaMetadeC(Celula *lista) {
    Celula *p;
    int qtd = contarElementosC(lista);
    printf("SEGUNDA METADE DA LISTA\n");

    if (qtd == 0 || qtd == 1) {
        printf("Lista Circular sem possibilidade de divisão\n");
        return;
    }
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
    
    mostrarPrimeiraMetadeC(listaC);
    //mostrarSegundaMetade(listaC);
    return 1;
}