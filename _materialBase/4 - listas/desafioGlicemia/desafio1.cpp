#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "desafio.h"


Celula *popularListaOrdenadaArquivo(Celula *lista) {
    ifstream procurador;
    string linha;
    string data;
    int valor; 

    //o ideal seria o usuario informar o nome do arquivo com os dados de glicemia
    cout << "Populando a lista...... \n";
    procurador.open("dadosGlicose.txt");
    do {
        getline(procurador, linha);    
        data = linha.substr(0, linha.find(" "));
        valor = stoi(linha.substr(linha.find(" "), 100));
        lista = inserirOrdenado(valor, data, lista);     
    } while (!procurador.eof());


    procurador.close();
    return lista;
}

int main() {
    Celula *listaOrdenada = NULL; //nao precisa guardar a ocorrencia (0)
    Celula *listaControleOcorrencia = NULL; //nao precisa guardar a data (NULL)


    listaOrdenada = popularListaOrdenadaArquivo(listaOrdenada);
    cout << "Exibindo a lista com os valores glicemicos ordenados por valor\n";
    exibir(listaOrdenada);
    cout << "O total de amostras eh: " << contarElementos(listaOrdenada) << endl;

    cout << "A media glicemica eh: " << media(listaOrdenada) << endl;
    cout << "A mediana glicemica eh: " << mediana(listaOrdenada) << endl;


    listaControleOcorrencia = copiaListaControleDuplicidade(listaOrdenada);
    listaControleOcorrencia = ordenarPelasOcorrencias(listaControleOcorrencia);
    cout << "Exibindo a lista sem valores duplicados\n";
    exibirOcorrencias(listaControleOcorrencia);
    
    //menu
    return 1;
}