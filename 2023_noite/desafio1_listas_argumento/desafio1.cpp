#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "lista.h"

void mostraConteudoArquivo(char *nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    if (!procuradorArquivo) {
        cout << nomeArquivo << " eh um arquivo nao localizado." << endl;
        return;
    }
 
   	cout << "Exibindo o conteudo do arquivo : " << nomeArquivo << endl;
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		// procuradorArquivo >> frase; //lendo palavra por palavra da linha 
		cout << linha << endl;
		//tratar a linha e extrair dados dela
	}
	procuradorArquivo.close();
}


int main(int quantidadeArgumentos, char **vetorArgumentos) {
    Celula *listaAlunos = NULL;
    cout << "Quantidade de argumentos: " << quantidadeArgumentos << endl;

    for (int i = 1; i < quantidadeArgumentos; i++)
    {
        listaAlunos = inserirListaSimples(vetorArgumentos[i], listaAlunos);
    }
        
    exibirListaSimples(listaAlunos);

    return 1;
}
