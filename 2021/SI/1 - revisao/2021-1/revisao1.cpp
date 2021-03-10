// uso do compilador g++

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Bem vindos a turma de Estruturas de Dados\n";
    string frase;

    cout << "Digite algo: ";
    getline (cin,frase);
    cout << "A frase digitada foi " << frase << "\n";

    return 1;
}