#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>  

using namespace std;

int main() {
    string linha = "-12,-7";
    int x, y;
    string varX, varY;
    int posicaoVirgula = linha.find(",");

    varX = linha.substr(0,posicaoVirgula);
    varY = linha.substr(posicaoVirgula+1, linha.length());

    stringstream xx(varX);
    xx >> x;

    stringstream yy(varY);
    yy >> y;
    
    cout << x << "," << y << endl;
    return 1;
}