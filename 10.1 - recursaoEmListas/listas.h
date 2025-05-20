#include <cstdlib>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int dado, Celula *lista) {
    //alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));
    
    //depositar valores
    novo->dado = dado;
    novo->prox = NULL;

    //percorrer se existir lista
    if (lista == NULL) { //if (!lista)
        return novo;
    }
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox) {
        if (dado == p->dado) return lista; //controle de duplicados no método sem recursão
    }

    //encadear e retornar
    p->prox = novo;
    return lista;
}

Celula *inserirR(int dado, Celula *lista) {
    //testar a parada = há lista neste ponto
    if (lista && dado > lista->dado) {
        if (dado == lista->dado){
            return lista; //começa o desempilhamento sem a inserção
        }
        lista->prox = inserirR(dado, lista->prox); //ponto de recursão
        return lista;
    } else { //lista não existe mais, ou seja, empilhei até sair da lista
        //alocar memoria
        Celula *novo = (Celula*)malloc(sizeof(Celula));
    
        //depositar valores
        novo->dado = dado;

        if (lista && dado < lista->dado) {
            novo->prox = lista;
        }
        else {
            novo->prox = NULL;
        }
        return novo;
    }
}

void exibir(Celula *lista) {
    for (Celula *p = lista; p != NULL; p = p->prox) {
        cout << p->dado << "\n";
    }
    cout << endl;
}

void exibirR(Celula *lista) {
    if (lista) {
        cout << lista->dado << "\n";
        exibirR(lista->prox);        
    }
}

int contarR(Celula *lista) {
    if (lista) {
        return 1 + contarR(lista->prox);
    }
    return 0; //ao chegar no final do empilhamento, sai-se de lista, logo retorna 0 pq não há mais nodos
}

int somarR(Celula *lista) {
    if (lista) {
        return lista->dado + somarR(lista->prox);
    }
    return 0;
}

bool estaContidoR(int numero, Celula *lista) {
    if (lista) {
        if (numero == lista->dado) {
            return 1; //localizado e começo a desempilhar
        } else {
            return estaContidoR(numero, lista->prox); 
        }
    }
    return 0; //empilhou até o final da lista e não encontrou o numero, desempilha com 0
}

int minR(Celula *lista) {
    if (lista) {
        return lista->dado; //pq a lista está ordenada
    }
    return -27; //lista vazia, retorna erro -27
}

int maxR(Celula *lista) {
    if (lista->prox) {
        return maxR(lista->prox);
    }
    return lista->dado; //empilha-se até o ultimo no, em que está o maior elemento
}

Celula *removerR(int numero, Celula *lista) {
    if (lista) {
        if (numero == lista->dado) { //numero localizado... remover
            Celula *proximo = lista->prox;
            free(lista);
            return proximo;
        } else {
            lista->prox = removerR(numero, lista->prox); //avanço na recursão, mas preso na 'corda' do prox
            return lista;
        }
    } 
    return NULL; //se cheguei no final do empilhamento, nao encontrei o numero e retorno NULL
}
