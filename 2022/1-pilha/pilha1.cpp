#include "pilha.h"

int main() {
    Celula *pilha = NULL;

    pilha = inserir(15, pilha); //push()
    pilha = inserir(20, pilha);
    pilha = inserir(50, pilha);
    pilha = inserir(100, pilha);

    pilha = remover(pilha);
    pilha = remover(pilha);
    
    //cout << pilha << endl;
    //cout << pilha->dado << endl;
    //cout << pilha->prox << endl;

    exibir(pilha);
    cout << "A pilha contem " << contar(pilha) << " elementos" << endl;

    int descobre = 150;
    cout << "O valor " << descobre << " esta no endereco: " << localiza(descobre, pilha) << endl;

    return 1;
}