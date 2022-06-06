#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


//struct utilizado tanto pra pilha quanto pra lista
typedef struct no {
  int valorGlicemia;
  string data;
  string hora;
  struct no *prox;
} Celula;


//mostra os valores glicemicos do mais recente (topo) ao mais antigo
void exibirPilha(Celula *topo) {
  Celula *p;
  for (p = topo; p; p = p->prox) {
    cout << p->valorGlicemia << endl;
  }
}

Celula *inserirPilha(int valor, Celula *topo) {
  //alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  //depositar valores
  novo->valorGlicemia = valor;

  //engatar o ultimo no topo
  novo->prox = topo;
  
  //retornar o novo topo
  return novo;
}

//mostra os valores ordenados, do menor ao maior
void exibirLista(Celula *lista) {
  Celula *p;
  for (p = lista; p; p = p->prox) {
    cout << p->valorGlicemia << endl;
  }
}


//inserir na lista de forma ordenada tendo como chave o valorGlicemia
Celula *inserirLista(int valor, Celula *lista) {
  //alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  //depositar valores
  novo->valorGlicemia = valor;
  novo->prox = NULL;

  //percorrer para encontrar o local adequado na lista
  //testar se é a primeira vez
  if (!lista) return novo;

  Celula *p, *pR;
  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor < p->valorGlicemia) break;
  }

  //é o primeiro
  if (p == lista) {
    novo->prox = lista;
    return novo;
  }
  //é o último
  if (!p) {
    pR->prox = novo;
  } else { //está no meio de duas celulas
    pR->prox = novo;
    novo->prox = p;
  }
  //retorna o inicio da lista
  return lista;  
}

//metodo que recebe uma lista e retorna a quantidade de elementos
int contarElementos(Celula *lista) {
  int contador = 0;
  Celula *p;
  for (p = lista; p ; p = p->prox) {
    contador++;
  }
  return contador;
}

float media(Celula *lista) {
  int soma = 0;

  Celula *p;
  for (p = lista; p ; p = p->prox) {
    soma+= p->valorGlicemia;
  }
  return soma/contarElementos(lista);
}

float mediana(Celula *lista) {
  int quantidadeElementos = contarElementos(lista);
  bool ehPar;

  if (quantidadeElementos % 2 == 0) {
    ehPar = true;
  } else {
    ehPar = false;
  }

  int i;
  int metade;
  Celula *p;
  if (!ehPar) {
    metade = (int)quantidadeElementos/2;
  } else {
    metade = (int)quantidadeElementos/2 - 1;
  }
  for (i = 0, p = lista; i < metade; i++, p = p->prox);

  
  if (!ehPar) return p->valorGlicemia;
  
  return (p->valorGlicemia + p->prox->valorGlicemia)/2;
}