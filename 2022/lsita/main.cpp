#include <iostream>
#include <fstream>
#include <iomanip>

#include "estruturas.h"

using namespace std;

void popularDoArquivo(Celula **topo, Celula **lista) {
  char nomeArquivo[200];
  ifstream procurador;
  
  cout << "Informe caminho e nome do arquivo com dados glicemicos: ";
  cin >> nomeArquivo;

  procurador.open(nomeArquivo);
  if (!procurador) {
      cout << "Arquivo digitado nao localizado!";
      return;
  }

  string linha;
  string glicemia;
  
  int posicaoEspaco = 0;
  while (getline(procurador,linha)){ //"1,-9"
    posicaoEspaco = linha.find(" ");
    //extrair glicemia
    glicemia = linha.substr(0,posicaoEspaco);
    *topo = inserirPilha(stoi(glicemia), *topo);
    *lista = inserirLista(stoi(glicemia), *lista);
  } 
  procurador.close();
}


int main() {
  Celula *pilha = NULL;
  Celula *lista = NULL;

  popularDoArquivo(&pilha, &lista);
  
  cout << "Valores originais de glicemia do mais recente ao mais antigo" << endl;
  exibirPilha(pilha);

  cout << "Valores ordenados de glicemia do mais baixo ao mais alto" << endl;
  exibirLista(lista);

  cout << "Foram carregados " << contarElementos(lista) << " dados glicêmicos" << endl;

  cout << "Média glicêmica é " << media(lista) << endl;

  cout << "A Mediana da lista é " << mediana(lista) << endl;
}