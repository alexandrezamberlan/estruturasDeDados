
typedef struct no {
    int valor;
    struct no *prox;
} Celula;


Celula *inserirR(int valor, Celula *lista) {
    //if (lista && lista->valor == valor) return lista; //codigo para controlar duplicados

    if (lista && valor > lista->valor) {
        lista->prox = inserirR(valor, lista->prox);  //teoria de joão e maria -> rastro
        return lista;
    } 
    Celula *novo;
    //chegamos neste ponto, quando atingimos o final da lista ou a posição de inserção correta do valor
    novo = (Celula *)malloc(sizeof(Celula));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

void exibirR(Celula *lista) {
    if (lista) {
        printf("%d\n", lista->valor);
        exibirR(lista->prox);
        //..
    }
}

int contarElementosR(Celula *lista) {
    if (lista) {
        return 1 + contarElementosR(lista->prox);
    } 
    return 0;
}

int somarElementosR(Celula *lista) {
    if (lista) {
        return lista->valor + somarElementosR(lista->prox);
    }
    return 0;
}

Celula *excluirR(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->valor) {
            //encontramos e vamos apagar
            Celula *backup = lista->prox;
            free(lista);
            return backup;
        } else {
            lista->prox = excluirR(valor, lista->prox); //teoria do joão e maria -> rastro
            return lista;
        }
    } else {
        return NULL; //ao se chegar aqui, é pq o valor não foi localizado
    }
}

Celula  *localizarElementoR(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->valor) {
            return lista;
        } else {
            return localizarElementoR(valor, lista->prox);
        }
    } else {
        return NULL; //valor não encontrado
    }
}

int localizarPosicaoLogicaElementoR(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->valor) {
            return 0;
        } else {
            int respostaDeCima = localizarPosicaoLogicaElementoR(valor, lista->prox);
            if (respostaDeCima != -27) {
                return 1 + respostaDeCima;
            } else {
                return respostaDeCima;
            }            
        }
    } else {
        return -27; //valor não encontrado
    }
}

void exibirParesR(Celula *lista) {
    if (lista) {
        if (lista->valor % 2 == 0) {
            printf("%d\n", lista->valor);
        }
        exibirParesR(lista->prox);
    }
}

int contarParesR(Celula *lista) {
    if (lista) {
        if (lista->valor % 2 == 0) {
            return 1 + contarParesR(lista->prox);
        }
        return 0 + contarParesR(lista->prox);
    }
    return 0;
}