#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(int quantidadeArgumentos, char** vetorArgumentos) {
    if (quantidadeArgumentos != 2) {
        cout << "Problema nos parametros!" << endl;
        exit(0);
    }

    
    cout << "Valor vindo do outro programa: " << vetorArgumentos[1] << endl;
    

    return 1;
}