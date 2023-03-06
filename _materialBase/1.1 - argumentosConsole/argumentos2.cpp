#include <iostream>
#include <string>
using namespace std;

int main(int quantidadeArgumentos, char** vetorArgumentos) {
    cout << "Quantidade de argumentos: " << quantidadeArgumentos << endl;

    for (size_t i = 1; i < quantidadeArgumentos; i++)
    {
        cout << "Argumento " << i << ": " << vetorArgumentos[i] << endl;
    }
    

    return 1;
}