#include <iostream>
#include <string>
using namespace std;

void exibir(string lista[], int n) {
    for (int i = 0; i < n; i++) {
        cout << lista[i] << endl;
    }
}

void ordenar(string lista[], int n) {
    int i, houveTroca;
    string tmp;
    //algoritmo da bolha
    do {
        houveTroca = 0;
        for (i = 0; i < n-1; i++) {
            if (lista[i] > lista[i+1]) {
                houveTroca = 1;
                tmp = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = tmp;
            }
        }
    } while (houveTroca == 1);
}

int main() {
    string lista[5];
    lista[0] = "alexaNdre";
    lista[1] = "alexandre";
    lista[2] = "Igor";
    lista[3] = "lucca";
    lista[4] = "leuze";

    ordenar(lista, 5);
    exibir(lista, 5);


    return 1;
}