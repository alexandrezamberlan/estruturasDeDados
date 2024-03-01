#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string paraMaiusculo(string frase) { //para C++ como passagem de parametro por valor
    int i;
    for (i = 0; i < frase.length(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

void split(string vetor[], string str, string deli = " ") {        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}

int main() {
    string nomeArquivo;
    ifstream procurador; //leitura

    system("cls");
    
    cout << "Informe caminho e nome do arquivo: ";
    cin >> nomeArquivo;
    
    procurador.open(nomeArquivo);
    if (!procurador) {
        cout << "Arquivo nao localizado" << endl;
        exit(0);
    }

    cout << "Arquivo localizado com sucesso" << endl;

    string linha;
    int qtdLinhas = 0;
    string vetor[3];
    while (!procurador.eof()) {
        getline(procurador, linha);
        split(vetor,linha,";");
        cout << "Nome: " << vetor[0] << ". Idade: " << vetor[2] << endl;
        qtdLinhas++;
    }

    cout << "\n\nTotal de linhas: " << qtdLinhas << endl;

    procurador.close();
    return 1;
}
