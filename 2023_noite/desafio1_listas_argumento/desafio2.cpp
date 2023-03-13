#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "lista.h"

Celula *popularListaConteudoArquivo(char *nomeArquivo, Celula *lista) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    if (!procuradorArquivo) {
        cout << nomeArquivo << " Nao eh um arquivo valido." << endl;
        return lista;
    }
 
   	cout << "Populando o conteudo do arquivo : " << nomeArquivo << endl;
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		lista = inserirListaSimples(linha, lista);
	}
	procuradorArquivo.close();
    return lista;
}


int main(int quantidadeArgumentos, char **vetorArgumentos) {
    Celula *listaAlunos = NULL;
    cout << "Quantidade de argumentos: " << quantidadeArgumentos << endl;

    for (int i = 1; i < quantidadeArgumentos; i++)
    {
        listaAlunos = popularListaConteudoArquivo(vetorArgumentos[i], listaAlunos);
    }
        
    exibirListaSimples(listaAlunos);

    return 1;
}
