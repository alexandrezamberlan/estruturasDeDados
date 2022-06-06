#include "pilha.h"
#include <fstream>
using namespace std;
int main() {
    ifstream procurador;

    char nomeArquivo[200];
    cout << "Nome do arquivo fonte com os numeros: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);
    if (!procurador) {
        cout << "Arquivo nao localizado!\n";
        exit(0);
    }

    //daqui pra baixo
    int valor;
    Celula *pilha = NULL;
    do {
        procurador >> valor;
        pilha = inserir(valor,pilha);
    } while(!procurador.eof());
    procurador.close();

    exibir(pilha);
    cout << "A pilha contem " << contar(pilha) << " elementos" << endl;
    

    return 1;
}