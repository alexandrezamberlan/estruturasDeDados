#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

typedef struct no {
    int valor;
    struct no *prox;
} Celula;


//lista de protótipos, ou seja, os métodos que deverão ser implementados no código
Celula *inserirOrdenado(int valor, Celula *lista);
Celula *inserirDesordenado(int valor, Celula *lista);
void exibir(Celula *lista, string frase);


int main() {
    Celula *listaOriginalGlicemia = NULL;
    Celula *listaOriginalInsulina = NULL;
    Celula *listaOriginalCalorias = NULL;
    Celula *listaOriginalCarboidrato = NULL;

    Celula *listaOrdenadaGlicemia = NULL;
    Celula *listaOrdenadaInsulina = NULL;
    Celula *listaOrdenadaCalorias = NULL;
    Celula *listaOrdenadaCarboidrato = NULL;
    
    FILE *procuradorEntrada;
    FILE *procuradorSaida;
    char nomeArquivo[100];

    system("clear"); //system("cls");

    //tratar o arquivo de entrada: abrir 
    cout << "Digite caminho e nome do arquivo fonte com dados glicêmicos: ";
    
    //em c
    gets(nomeArquivo);
    procuradorEntrada = fopen(nomeArquivo, "r");
    
    if (!procuradorEntrada) {
        cout << "Arquivo não encontrado. Programa será encerrado." << endl;
        exit(0);
    }
    cout << "Arquivo localizado e sendo tratado." << endl;

    //passar pelo arquivo de entrada e extrair seus dados nas diferentes listas
    int glicemia, insulina, calorias, carboidrato;
    do {    
        fscanf(procuradorEntrada, "%d %d %d %d", &glicemia, &insulina, &calorias, &carboidrato);
        listaOriginalGlicemia = inserirDesordenado(glicemia, listaOriginalGlicemia);
        listaOrdenadaGlicemia = inserirOrdenado(glicemia, listaOrdenadaGlicemia);

        listaOriginalInsulina = inserirDesordenado(insulina, listaOriginalInsulina);
        listaOrdenadaInsulina = inserirOrdenado(insulina, listaOrdenadaInsulina);

        listaOriginalCalorias = inserirDesordenado(calorias, listaOriginalCalorias);
        listaOrdenadaCalorias = inserirOrdenado(calorias, listaOrdenadaCalorias);

        listaOriginalCarboidrato = inserirDesordenado(carboidrato, listaOriginalCarboidrato);
        listaOrdenadaCarboidrato = inserirOrdenado(carboidrato, listaOrdenadaCarboidrato);

    } while (!feof(procuradorEntrada));

    //exibir(listaOriginalGlicemia, "Lista original de glicemia");
    //exibir(listaOrdenadaGlicemia, "Lista ordenada da glicemia");


    //abrir o arquivo de saida
    //em c
    procuradorSaida = fopen("saida.dat", "w");
    //capturar data e hora para armazenar no arquivo e exibir na tela
    struct tm data;
    time_t t = time(NULL);
    data = *localtime(&t);
    //printf("Data: %02d/%02d/%d. Hora: %02d:%02d\n", data.tm_mday, data.tm_mon + 1, data.tm_year + 1900,
    //        data.tm_hour, data.tm_min);
    
    fprintf(procuradorSaida, "Data: %02d/%02d/%d. Hora: %02d:%02d\n", data.tm_mday, data.tm_mon + 1, data.tm_year + 1900,
            data.tm_hour, data.tm_min);
    
    

    //calcular média de cada valor glicêmico e 'jogar' na tela e arquivo de saida


    //calcular mediana de cada valor glicêmico e 'jogar' na tela e arquivo de saida

    //calcular moda de cada valor glicêmico e 'jogar' na tela e arquivo de saida

    //analisar os dados glicêmicos glicemia e carboidrato e dar um parecer

    //fechar arquivos
    fclose(procuradorEntrada);
    fclose(procuradorSaida);
    return 1;
}

void exibir(Celula *lista, string frase) {
    if (!lista) {
        return;
    }
    cout << frase << endl;
    Celula *p;
    for (p = lista; p ; p = p->prox) {
        cout << p->valor << endl;
    }

}

Celula *inserirDesordenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox);

    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado

    //retornar o primeiro elemento
    return lista;
}

Celula *inserirOrdenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    Celula *p, *pR;
    for (pR = NULL, p = lista; p != NULL; pR = p, p = p->prox) {
        if (valor <= p->valor) { //encontramos a posição do valor
            break;  //sai do for      
        }
    }
    //existem 2 motivos para sair do for:
    //1o pq o p chegou no final da lista - sabe-se então que o valor será o último elemento
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //2o pq o break executou - ou o valor pode ser o primeiro ou pode estar no meio
    if (p == lista) {
        novo->prox = lista; //novo->prox = p;
        return novo;
    }
    //não é o primeiro e nem o último, ou seja, está no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}