#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream procurador;
    ofstream procuradorEscrita;

    char nomeArquivo[200];
    int qtdParticulas = 0, conta1q = 0, conta2q = 0, conta3q = 0, conta4q = 0, contaOrigem = 0;
    int x, y;

    cout << "Informe nome do arquivo de entrada com dados de particulas: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);
    if (!procurador) {
        cout << "Arquivo digitado nao localizado!";
        return 0;
    }

    string linha;
    string varX, varY;
    int posicaoVirgula = 0;
    while (getline(procurador,linha)){ //"1,-9"
        posicaoVirgula = linha.find(",");

        //extrair o x da linha
        varX = linha.substr(0,posicaoVirgula);
        stringstream xx(varX);
        xx >> x;

        //extrair o y da linha
        varY = linha.substr(posicaoVirgula+1, linha.length());
        stringstream yy(varY);
        yy >> y;

        qtdParticulas++;
        //if (feof(procurador)) break;

        if (x > 0 && y > 0) {
            conta1q++;
        } else if (x < 0 && y > 0) {
            conta2q++;
        } else if (x < 0 && y < 0) {
            conta3q++;
        } else if (x > 0 && y < 0) {
            conta4q++;
        } else {
            contaOrigem++;
        }
    } 
    procurador.close();

    procuradorEscrita.open("log.txt");
    procuradorEscrita << "Foram localizadas " << qtdParticulas << " particulas\n";
    procuradorEscrita << "1º Quadrante: " <<  conta1q << endl;
    procuradorEscrita << "2º Quadrante: " << conta2q << endl;
    procuradorEscrita << "3º Quadrante: " << conta3q << endl;
    procuradorEscrita << "4º Quadrante: " << conta4q << endl;
    procuradorEscrita << "Origem " << contaOrigem << endl;

    procuradorEscrita.close();
    return 1;
}

