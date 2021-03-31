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

int somarElementosC(Celula *lista) { //lista contém o endereco do 1o elemento
   Celula *p;
   int soma = 0;

    if (!lista) {
        return soma;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        soma = soma + p->valor;
    } 
    soma = soma + p->valor;

    return soma;
}

char *regiaoValorC(int valor, Celula *lista) {
    if (!lista) return "Lista vazia"; 

    Celula *p;
    
    for (p = lista; p  ; p = p->prox) { //percurso clássico: exibir, contar, localizar, excluir, ....
        if (valor == p->valor) {
            //verificar se é o primeiro
           
            //verificar se é o último
           
            //se não é o primeiro e nem o último, só pode estar em alguma posição do meio
           
        }
    }
    //???
    return "não encontrado";
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
    printf("Soma dos elementos da lista: %d\n", somarElementosC(listaC));

    printf("Informe um valor de pesquisa: ");
    scanf("%d", &valor);

    printf("O valor está: %s\n", regiaoValorC(valor, listaC));

    return 1;
}