#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int valor;
    struct no *prox;
} Celula;

void exibir(Celula *lista) {
    Celula *p;

    if (!lista) { //lista == NULL
        printf("Lista vazia.\n");
        return;
    } 

    for (p = lista; p != NULL; p = p->prox) { //percurso clássico: usado para exibir, contar, localizar, ...
        printf("%d\t", p->valor);
    }

    printf("\n");
    
}

Celula *inserirDesordenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valores que vem dos parametros
    novo->valor = valor;
    novo->prox = NULL; //como não sabemos onde o novo será inserido (inicio, meio, fim)

    if (!lista) { //caso a lista esteja vazia, na primeira inserção, a lista começa pelo novo
        return novo;
    }

    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox);
    
    //engatar
    p->prox = novo;

    //retornar
    return lista;
}

Celula *inserirOrdenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valores que vem dos parametros
    novo->valor = valor;
    novo->prox = NULL; //como não sabemos onde o novo será inserido (inicio, meio, fim)

    if (!lista) { //caso a lista esteja vazia, na primeira inserção, a lista começa pelo novo
        return novo;
    }

    Celula *p, *pR; //pR sempre estará uma posição atrás do p
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) { 
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

FILE *abreArquivoLeitura() {
    char nomeArquivo[100];
    printf("Digite o arquivo que deseja processar: ");
    scanf("%s", nomeArquivo);
    FILE *procurador = fopen(nomeArquivo, "r");
    if (!procurador) {
        printf("Arquivo não localizado!!\n");
        exit(0);
    }
    printf("Arquivo localizado e sendo processado!!\n");
    return procurador;
}


int main() {
    Celula *listaOriginalGlicemia = NULL;
    Celula *listaOrdenadaGlicemia = NULL;
    Celula *listaOriginalCarboidratos = NULL;
    Celula *listaOrdenadaCarboidratos = NULL;

    FILE *procuradorEntrada;
    FILE *procuradorSaida;

    system("clear"); //system("cls");

    //abertura de arquivo de entrada, ou seja, dados de glicemia
    procuradorEntrada = abreArquivoLeitura();

    //percorrer o arquivo e popular as 4 listas:
    int glicemia, insulina, calorias, carboidratos;
    do {
        fscanf(procuradorEntrada,"%d %d %d %d", &glicemia, &insulina, &calorias, &carboidratos);
        listaOriginalGlicemia = inserirDesordenado(glicemia, listaOriginalGlicemia);
        listaOrdenadaGlicemia = inserirOrdenado(glicemia, listaOrdenadaGlicemia);

        listaOriginalCarboidratos = inserirDesordenado(carboidratos, listaOriginalCarboidratos);
        listaOrdenadaCarboidratos = inserirOrdenado(carboidratos, listaOrdenadaCarboidratos);

    } while (!feof(procuradorEntrada));

    // exibir(listaOriginalGlicemia);
    // exibir(listaOrdenadaGlicemia);

    //abertura de arquivo de saida
    procuradorSaida = fopen("saida.dat", "w");

    //na primeira linha do arquivo saida.dat, gravar data e hora
    struct tm dataHora;
    time_t t = time(NULL);
    dataHora = *localtime(&t);
    
    fprintf(procuradorSaida, "Data: %02d/%02d/%d. Hora: %02d:%02d\n", dataHora.tm_mday, dataHora.tm_mon + 1, dataHora.tm_year + 1900,
            dataHora.tm_hour, dataHora.tm_min);

    //calcular e gravar a media glicemia
    calcularMedia(listaOrdenadaGlicemia, procuradorSaida);

    //calcular e gravar a mediana glicemia

    //calcular e gravar moda glicemia

    //calcular e gravar a media carboidratos

    //calcular e gravar a mediana carboidratos

    //calcular e gravar moda carboidratos

    //fechar arquivo entrada
    fclose(procuradorEntrada);

    //fechar arquivo saida
    fclose(procuradorSaida);

    return 1;
}