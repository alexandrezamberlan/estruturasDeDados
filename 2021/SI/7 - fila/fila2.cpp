#include <iostream>
#include <string>
#include "delay.h"

using namespace std;

typedef struct no {
    string senha;
    struct no *prox;
} Celula;

typedef struct {
    Celula *inicio; //ponteiro utilizado para fazer as remoções - indica o elemento mais antigo na estrutura
    Celula *fim;    //ponteiro utilizado para fazer as inserções - indica o elemento mais recente na estrutura
} Fila;

Fila inicializar(Fila f);
Fila inserir(string senha, Fila f);
Fila remover(Fila f, string *resultado);

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;

    filaNormal = inicializar(filaNormal);
    filaPrioritaria = inicializar(filaPrioritaria);

    int senhaNormal = 100;
    int senhaPrioritaria = 500;

    int numero;
    srand(time(NULL));

    int opcao;
    do {
        system("clear");
        cout << "Escolha um tipo de atendimento!!!!" << endl;
        cout << "1 - senha normal; 2 - senha prioritária: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1 : //fila normal
                     cout << "Você selecionou atendimento NORMAL - Senha: " << "N" << senhaNormal << endl;
                     filaNormal = inserir("N" + to_string(senhaNormal), filaNormal);
                     senhaNormal++;
                     break;
            case 2 : //fila prioritária
                     cout << "Você selecionou atendimento PRIORITÁRIO - Senha: " << "P" << senhaPrioritaria << endl;
                     filaPrioritaria = inserir("P" + to_string(senhaPrioritaria), filaPrioritaria);
                     senhaPrioritaria++;
                     break;
            default : cout << "Opção inválida!" << endl;
        }
        delay(3000);
        system("clear");
        numero = rand() % 3;
        string resultado;
        switch (numero) {
            case 0 : //atendimento normal
                     filaNormal = remover(filaNormal, &resultado);
                     cout << "Atenção! Senha NORMAL " << resultado << " sendo chamada no guichê .... " << endl;
                     break;
            case 1 : //atendimento prioritário
                     filaPrioritaria = remover(filaPrioritaria, &resultado);
                     cout << "Atenção! Senha PRIORITÁRIA " << resultado << " sendo chamada no guichê .... " << endl;
                     break;
        }
        delay(3000);
    } while (true);

    return 1;
}

Fila inicializar(Fila f) {
    f.inicio = NULL;
    f.fim = NULL;

    return f;
}

Fila inserir(string senha, Fila f) {
    //alocar memória - como faziamos em pilha, listas 
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores dos parâmetros
    novo->senha = senha;
    novo->prox = NULL;

    //testa se é o primeiro
    if (!f.fim) { //fila está vazia, então o novo é o primeiro e o último ao mesmo tempo
        f.fim = novo;
        f.inicio = novo;
        return f;
    }

    //engata e atualiza onde está o último elemento
    f.fim->prox = novo;
    f.fim = novo;

    //retorna
    return f;
}

Fila remover(Fila f, string *resultado) {
    if (!f.inicio) {
        cout << "Fila vazia....." << endl;
        return f;
    }

    *resultado = f.inicio->senha; //guarda a senha a ser removida da lista
    Celula *lixo = f.inicio; //guardamos o elemento que será retirado da fila
    f.inicio = f.inicio->prox; //avança o início para o 2o elemento da fila
    free(lixo); //apagamos o primeiro elemento da fila

    if (!f.inicio) {
        f.fim = NULL;
    }

    return f;
}