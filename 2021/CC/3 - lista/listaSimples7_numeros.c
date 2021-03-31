#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
    int valor;
    //outros atrituos
    struct nodo *prox; //ponteiro para a próxima célula ou próximo elemento
} Celula;

void exibir(Celula *lista) {
    Celula *p;

    if (!lista) { //lista == NULL
        printf("Lista vazia.\n");
        return; //só sai do método
    } 

    //for(aponta p para o início da lista; enquanto p não chegar no final; p avança para o próximo)
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
    Celula *p, *pR; //pR sempre estará uma posição atrás do p
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) { 
        // if (valor == p->valor) {
        //     printf("Ja cadastrado!\n");
        //     free(novo);
        //     return lista;
        // }
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


int main() {
    Celula *lista = NULL;
    int valor;

    clock_t tempoInicio, tempoFim;

    system("clear");

    FILE *procuradorArquivo;
    char nomeArquivo[100];

    printf("Informe nome do arquivo com numeros: ");
    scanf("%s", nomeArquivo);

    //abri o arquivo
    procuradorArquivo = fopen(nomeArquivo,"r");
    if (!procuradorArquivo) {
        printf("Arquivo nao encontrado.\n");
        exit(0);
    }
    
    //percorrer o arquivo
    printf("iniciando a inserção\n");
    tempoInicio = clock();
    do {
        fscanf(procuradorArquivo,"%d",&valor);
        lista = inserir(valor, lista);
    } while (!feof(procuradorArquivo));

    tempoFim = clock();
    printf("inserção finalizada em %f segundos\n", (float)(tempoFim - tempoInicio)/CLOCKS_PER_SEC);

    exibir(lista);

    fclose(procuradorArquivo);
    return 1;
}

