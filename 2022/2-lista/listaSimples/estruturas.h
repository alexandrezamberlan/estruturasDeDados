#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


//struct utilizado tanto pra pilha quanto pra lista
typedef struct no {
  int dado;
  struct no *prox;
} Celula;


//mostra os valores glicemicos do mais recente (topo) ao mais antigo
void exibirPilha(Celula *topo) {
  Celula *p;
  for (p = topo; p; p = p->prox) {
    cout << p->dado << endl;
  }
}

Celula *inserirPilha(int valor, Celula *topo) {
  //alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  //depositar valores
  novo->dado = valor;

  //engatar o ultimo no topo
  novo->prox = topo;
  
  //retornar o novo topo
  return novo;
}

//mostra os valores ordenados, do menor ao maior
void exibirLista(Celula *lista) {
  Celula *p;
  for (p = lista; p; p = p->prox) {
    cout << p->dado << endl;
  }
}


//inserir na lista de forma ordenada tendo como chave o valorGlicemia
Celula *inserirLista(int valor, Celula *lista) {
  //alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  //depositar valores
  novo->dado = valor;
  novo->prox = NULL;

  //percorrer para encontrar o local adequado na lista
  //testar se é a primeira vez
  if (!lista) return novo;

  Celula *p, *pR;
  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor < p->dado) break;
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

//metodo que receba um valor, o localiza na lista e o remove da estrutura
Celula *excluirLista(int valor, Celula *lista) {
  Celula *p, *pR;

  if (!lista) {
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor == p->dado) {
      //eh o primeiro
      if (p == lista) {
        lista = lista->prox;
      } else if (!p->prox) { //eh o ultimo
        pR->prox = NULL;
      } else { //esta entre celulas
        pR->prox = p->prox;
      }
      free(p);
      return lista;
    }
  }
  cout << "Valor não localizado para exclusão!" << endl;
  return lista;
}

Celula *excluirOcorrenciasLista(int valor, Celula *lista) {
  Celula *p, *pR;

  if (!lista) {
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  bool houveExclusao;
  do {
    houveExclusao = false;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
      if (valor == p->dado) {
        //eh o primeiro
        if (p == lista) {
          lista = lista->prox;
        } else if (!p->prox) { //eh o ultimo
          pR->prox = NULL;
        } else { //esta entre celulas
          pR->prox = p->prox;
        }
        free(p);
        houveExclusao = true;
        break;
      }
    }   
  } while (houveExclusao);
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
    soma+= p->dado;
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

  
  if (!ehPar) return p->dado;
  
  return (p->dado + p->prox->dado)/2;
}
