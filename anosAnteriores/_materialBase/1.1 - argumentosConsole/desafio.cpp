#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool procurarPalavraNoAquivo(string palavra, char *nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    if (!procuradorArquivo) {
        cout << nomeArquivo << " eh um arquivo nao localizado." << endl;
        return false;
    }
    	
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		if (linha.find(palavra) != string::npos) {
            procuradorArquivo.close();
            return true;
        }
	}
	procuradorArquivo.close();
    return false;
}

int main(int quantidadeArgumentos, char** vetorArgumentos) {
    
    if (quantidadeArgumentos != 3) {
        cout << "Quantidade de argumentos invalida\n";
        exit(0);
    }

    cout << "Arquivo de busca: " << vetorArgumentos[1] << endl;
    cout << "Palavra de busca: " << vetorArgumentos[2] << endl;

    if (procurarPalavraNoAquivo(vetorArgumentos[2], vetorArgumentos[1])) {
        cout << "Palavra encontrada\n";
    } else {
        cout << "Palavra nao encontrada\n";
    }

    return 1;
}