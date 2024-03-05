#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

typedef struct no {
  string valor;
  struct no *prox;
} Lista;

Lista *inserir(string valor, Lista *lista) {
  // alocar memoria
  Lista *novo = (Lista *)malloc(sizeof(Lista));

  // depositar conteudos do parametro
  novo->valor = valor;
  novo->prox = NULL;

  // localizar posicao na estrutura
  Lista *pR, *p;
  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {

    if (novo->valor < p->valor) {
      break;
    }
  }
  // eh o primeiro
  if (p == lista) {
    novo->prox = lista;
    return novo;
  }
  // eh o ultimo
  if (!p) {
    pR->prox = novo;
    return lista;
  }
  // esta em algum lugar do meio
  pR->prox = novo;
  novo->prox = p;

  // retornar o inicio da lista
  return lista;
}

bool contido(string valor, Lista *lista) {
  if (!lista) {
    return false;
  }

  Lista *p;
  for (p = lista; p; p = p->prox) {
    if (valor == p->valor) {
      return true;
    }
  }
  return false;
}

void exibir(Lista *lista) {
  if (!lista) {
    return;
  }

  Lista *p;
  for (p = lista; p; p = p->prox) {
    cout << p->valor << endl;
  }
}

Lista *conectarBanco(Lista *lista) {
  ifstream leitor;
  leitor.open("numeros.txt");
  if (!leitor) {
    cout << "Erro ao abrir o arquivo" << endl;
    return NULL;
  }
  string linha;
  while (!leitor.eof()) {
    getline(leitor, linha);
    lista = inserir(linha, lista);
  }
  leitor.close();
  return lista;
}

void gravarBanco(Lista *lista) {
  ofstream escritor;
  escritor.open("numeros.txt");

  Lista *p;
  for (p = lista; p; p = p->prox) {
    escritor << p->valor << endl;
  }

  escritor.close();
}
int main() {
  Lista *listaNumeros = NULL;
  string valor;
  listaNumeros = conectarBanco(listaNumeros);
  //exibir(listaNumeros);
  while (true) {
    cout << "Digite um valor ou 0 para finalizar: ";
    getline(cin, valor);
    if (valor == "0") {
      break;
    }
    // testar se já cadastrado
    if (!contido(valor, listaNumeros)) {
      // inserir o nome na lista
      listaNumeros = inserir(valor, listaNumeros); // insercao com ordenação
      gravarBanco(listaNumeros);
    } else {
      cout << "Numero ja cadastrado" << endl;
    }
  }
  exibir(listaNumeros);

  return 1;
}