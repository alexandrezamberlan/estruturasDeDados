#include <iostream>
#include <ctime>
#include "estruturas.h"

using namespace std;

Celula *popular(Celula *lista, int n) {
  srand(time(NULL));
  
  for (int i = 0; i < n; i++) {
    lista = inserirLista(rand() % 100, lista);
  }
  return lista;
}

int main() {
  int qtdNumerosLista = 30;
  Celula *lista = NULL;

  lista = popular(lista, qtdNumerosLista);
  cout << "Lista inicial" << endl;
  exibirLista(lista);

  int numero;
  cout << "Qual o número que você deseja apagar da lista? ";
  cin >> numero;

  lista = excluirLista(numero, lista);
  cout << "Lista após exclusão" << endl;
  exibirLista(lista);
  return 1;
}