#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    //outros atrituos
    struct nodo *prox; //ponteiro para a próxima célula ou próximo elemento
} Celula;

void exibirR(Celula *lista) { //variável de controle é lista e está inicializando no parâmetro
    if (lista) { //teste de parada
        //codigo de empilhamento
        printf("%d\t", lista->valor);
        exibirR(lista->prox); //ponto de recursão com a transformação da variável de controle
        //codigo de desempilhamento   
    }
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
    Celula *p, *pR; //pR sempre estará uma posição atrás do p
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) { 
        if (valor == p->valor) {
            printf("Ja cadastrado!\n");
            free(novo);
            return lista;
        }
       if (valor < p->valor) {
           break;
       }
    }
    //2 situações que saimos do for
    //1o porque chegamos no final (p é null). Isso significa que o valor a ser inserido será o último
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //2o porque saimos com o break. Isso significa que o valor vai ser inserido na primeira posição
    if (p == lista) {
        novo->prox = lista;
        return novo; //novo se torna o primeiro elemento da lista
    }
    //se não for o último e nem o primeiro, só pode estar no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

int contarElementos(Celula *lista) {
    if (!lista) return 0;

    Celula *p;
    
    int contador = 0;
    //for(aponta p para o início da lista; enquanto p não chegar no final; p avança para o próximo)
    for (p = lista; p  ; p = p->prox) {
        contador++;
    }

    // for (contador = 0, p = lista; p  ; p = p->prox, contatdor++);

    return contador;
}

void exibirEnderecoValorR(Celula *lista, int valor) {
    if (lista) {
        if (lista->valor == valor) {
            printf("O endereço do valor é: %p\n", lista);
            return;
        }
        exibirEnderecoValorR(lista->prox, valor);
    }
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

    exibirR(lista); 
    printf("\n");

    int quantidadeElementos = contarElementos(lista); //percorrer passando por todos elementos
    printf("A lista possui %d elementos\n", quantidadeElementos);

    printf("Digite valor para pesquisa: ");
    scanf("%d", &valor);

    //metodo que recebe uma lista e um valor qualquer. O método tentar localizar o valor e exibir o endereco do valor
    exibirEnderecoValorR(lista, valor);

    return 1;
}
