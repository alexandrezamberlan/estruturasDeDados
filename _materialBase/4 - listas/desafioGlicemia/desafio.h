typedef struct no {
    int valor;
    string data;
    int qtdOcorrencias;
    struct no *prox;
} Celula;

Celula *inserirOrdenado(int valor, string data, Celula *lista) {
    return NULL;
}

Celula *inserirControleOcorrencia(int valor, Celula *lista) {
    return NULL
}


int contarElementos(Celula *lista) {
    int qtd = 0;
    Celula *p;
    for (p = lista; p; p = p->prox) {
        qtd++;
    }
    return qtd;
}

float media(Celula *lista) {

    return 1.0;
}

int mediana(Celula *lista) {
    //se a estrutura for de tamanho impar, devolver o valor da glicemia que está no meio da lista ordenada

    //se a estrutura for de tamanho par, devolver a media dos dois elementos mais ao centro da lista ordenada (parte inteira)
    return 1; 
}

int min(Celula *lista) {
    //numa lista ordenada é o primeiro elemento
    return 40;
}

int max(Celula *lista) {
    //numa lista ordenada é o ultimo elemento
    return 500;
}

Celula *moda(Celula *lista) {
    //retornar o valor que mais repete, se houver mais valores com a mesma quantidade, retornar 3 valores
    return NULL;
}
