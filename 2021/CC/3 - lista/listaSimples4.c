#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    //outros atrituos
    struct no *prox;
} Celula;

void exibir(Celula *lista) {
    Celula *p;

    if (!lista) { //lista == NULL
        printf("Lista vazia.\n");
        return;
    } 

    for (p = lista; p ; p = p->prox) { //percurso clássico: usado para exibir, contar, localizar, ...
        printf("%d\t", p->valor);
    }

    printf("\n");
    
}

Celula *inserir(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valores que vem dos parametros
    novo->valor = valor;
    novo->prox = NULL; //como não sabemos onde o novo será inserido (inicio, meio, fim)

    if (!lista) { //caso a lista esteja vazia, na primeira inserção, a lista começa pelo novo
        return novo;
    }

    //percorrer com controle de duplicidade
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox) { //percurso que pára no último elemento
        if (valor == p->valor) {
            printf("Ja cadastrado!\n");
            free(novo);
            return lista;
        }
    }
    //como o ultimo elemento nao foi testado, o código de teste sai do for
    if (valor == p->valor) {
        printf("Ja cadastrado!\n");
        free(novo);
        return lista;
    }
    // 4    6   1   7 
    
    //engatar
    p->prox = novo;

    //retornar
    return lista;
}

int contarElementos(Celula *lista) {
    if (!lista) return 0;

    Celula *p;
    
    int contador = 0;
    for (p = lista; p  ; p = p->prox) {
        contador++;
    }

    // for (contador = 0, p = lista; p  ; p = p->prox, contatdor++);

    return contador;
}

Celula *localizarValor(int valor, Celula *lista) {
    if (!lista) return NULL; //lista é vazia e estamos retornando NULL

    Celula *p;
    
    for (p = lista; p  ; p = p->prox) { //percurso clássico: exibir, contar, localizar, excluir, ....
        if (valor == p->valor) {
            return p;
        }
    }

    //se saimos do for, logo não encontramos o valor
    return NULL;
}

int main() {
    Celula *lista = NULL;
    system("clear");

    
    int valor;
    do {
        printf("Digite um numero inteiro (-1 para sair): ");
        scanf("%d", &valor);
        if (valor == -1)
            break;

        lista = inserir(valor, lista); //vamos inserir no final da lista //percorrendo e parando no último

    } while (1);

    exibir(lista); //percorrer passando por todos elementos

    int quantidadeElementos = contarElementos(lista); //percorrer passando por todos elementos
    printf("A lista possui %d elementos\n", quantidadeElementos);

    printf("Digite um valor para pesquisar na lista: ");
    scanf("%d", &valor);

    Celula *enderecoElemento = localizarValor(valor, lista); //percorrer passando por todos elementos
    printf("Valor localizado no endereço: %p\n", enderecoElemento);

    return 1;
}



/**
 * numeros a serem inseridos: 30 7 12 5 90 1 3
 * 
 * pilha -> 3 1 90 5 12 7 30
 * 
 * lista -> 30 7 12 5 90 1 3
 * 
 * listaOrdenada -> 1 3 5 7 12 30 90
 */ 
