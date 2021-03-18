#include <iostream>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    //poderia ter outras variáveis
    struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *lista);
void exibir(Celula *lista);
int contarElementos(Celula *lista);
Celula *localizarValor(int valor, Celula *lista);
int somarElementos(Celula *lista);

int main() {
    Celula *lista = NULL;
    int valor;
    system("clear");
    do {
        cout << "Informe um valor inteiro para a lista (-1 sai do programa): ";
        cin >> valor;
        if (valor == -1) break;

        lista = inserir(valor,lista);
    } while (1);

    exibir(lista);

    cout << "A lista possui " << contarElementos(lista) << " elementos" << endl;

    cout << "Digite um valor para pesquisa: ";
    cin >> valor;

    Celula *enderecoValor = localizarValor(valor, lista);

    cout << "Valor encontrado no endereço " << enderecoValor << endl;

    cout << "A soma dos elementos é: " << somarElementos(lista) << endl;

    return 1;
}

Celula *inserir(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    Celula *p;

    for (p = lista; p->prox != NULL; p = p->prox) {
        if (valor == p->valor) {
            cout << "valor ja inserido na lista!\n";
            free(novo); //libera a alocação pq o valor ja está na lista
            return lista;
        }
    }
    //atencao... como o for pára no último elemento, o if do for não é executado, por isso, o if foi repetido fora do for
    if (valor == p->valor) {
        cout << "valor ja inserido na lista!\n";
        free(novo); //libera a alocação pq o valor ja está na lista
        return lista;
    }

    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado

    //retornar o primeiro elemento
    return lista;
}

void exibir(Celula *lista) {
    Celula *p;

    if (!lista) {
        cout << "Lista vazia!\n";
        return;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        cout << p->valor << "\t";
    }
    cout << endl;
}

int contarElementos(Celula *lista) {
   Celula *p;
   int contador = 0;

    if (!lista) {
        return contador;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        contador++;
    } 
    return contador;
}

int somarElementos(Celula *lista) {
   Celula *p;
   int soma = 0;

    if (!lista) {
        return soma;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        soma = soma + p->valor;
    } 
    return soma;
}

Celula *localizarValor(int valor, Celula *lista){
    Celula *p; //ponteiro para percorrer a lista

    if (!lista) {
        cout << "Lista vazia!\n";
        return lista;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        if (valor == p->valor) {
            return p;
        }
    }
    return NULL;//se chegou, eh pq não encontrou o valor
}