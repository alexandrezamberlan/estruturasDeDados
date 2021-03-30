#include <iostream>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    //poderia ter outras variáveis
    struct nodo *prox;
} Celula;

Celula *inserirC(int valor, Celula *lista);
void exibirC(Celula *lista);
int contarElementosC(Celula *lista);
int somarElementosC(Celula *lista);
Celula *localizarValorC(int valor, Celula *lista);

int main() {
    Celula *listaC = NULL;
    int valor;

    do {
        cout << "Informe um valor inteiro para a lista (-1 sai do programa): ";
        cin >> valor;
        if (valor == -1) break;

        listaC = inserirC(valor,listaC);
    } while (1);

    exibirC(listaC);

    cout << "A lista circular possui " << contarElementosC(listaC) << " elementos" << endl;
    
    cout << "Digite um valor para pesquisa: ";
    cin >> valor;

    Celula *enderecoValor = localizarValorC(valor, listaC);

    cout << "Valor encontrado no endereço " << enderecoValor << endl;

    cout << "A soma dos elementos é: " << somarElementosC(listaC) << endl;

    return 1;
}

Celula *inserirC(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;

    if (!lista) {
        novo->prox = novo; //o único elemento deve apontar pra si mesmo
        return novo; //se a lista for vazia, o novo será o primeiro e único elemento nela
    }

    //percorrer toda a lista e inserir na última posição
    Celula *p;
    for (p = lista; p->prox != lista; p = p->prox); //percurso para parar o p no último elemento

    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado
    novo->prox = lista; //o último elemento aponta para o primeiro elemento

    //retornar o primeiro elemento
    return lista;
}

void exibirC(Celula *lista) {
    Celula *p;

    if (!lista) {
        cout << "Lista vazia!\n";
        return;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        cout << p->valor << "\t";
    }
    cout << p->valor << "\n";
}

int contarElementosC(Celula *lista) { //lista contém o endereco do 1o elemento
   Celula *p;
   int contador = 0;

    if (!lista) {
        return contador;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        contador++;
    } 
    
    return ++contador;
}

int somarElementosC(Celula *lista) {
   Celula *p;
   int soma = 0;

    if (!lista) {
        return soma;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        soma = soma + p->valor;
    } 
    
    return soma + p->valor;
}

Celula *localizarValorC(int valor, Celula *lista){
    Celula *p; //ponteiro para percorrer a lista

    if (!lista) {
        cout << "Lista vazia!\n";
        return lista;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        if (valor == p->valor) {
            return p;
        }
    }
    if (valor == p->valor) {
        return p;
    }
    
    return NULL;//se chegou, eh pq não encontrou o valor
}