#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <fstream>

using namespace std;
int main() {
    char nomeArquivo[200];
    ofstream procurador;
    int qtdParticulas;
    int x,y;
    
    cout << "Nome do arquivo de saida contendo as particulas: ";
    cin >> nomeArquivo;
    procurador.open(nomeArquivo);
    cout << "Arquivo criado com sucesso!\n";
    cout << "Quantas particulas quer gerar? ";
    cin >> qtdParticulas;

    srand(time(NULL)); 
    for (; qtdParticulas > 0; qtdParticulas--) {
        x = 100 - rand() % 200; 
        y = 100 - rand() % 200;
        procurador << x << "," << y << endl;  //arquivo texto - plain text   
    }
    
    procurador.close();
    return 1;
}