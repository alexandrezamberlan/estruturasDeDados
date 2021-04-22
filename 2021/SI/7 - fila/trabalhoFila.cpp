#include "fila.h"
#include "delay.h"

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;

    filaNormal = inicializar(filaNormal);
    filaPrioritaria = inicializar(filaPrioritaria);

    int senhaNormal = 100;
    int senhaPrioritaria = 500;
    int opcao;
    string senha;
    int quantidadeAtendimentos = 0;

    do {
        system("clear");
        cout << "Sistema de senhas de atendimento!!" << endl;
        cout << "1 - Senha normal" << endl;
        cout << "2 - Senha prioritária" << endl;
        cout << "3 - Atender: chamar uma senha" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: 
                    cout << "Você selecionou atendimento NORMAL - Senha: " << "N" << senhaNormal << endl;
                    filaNormal = inserir("N" + to_string(senhaNormal), filaNormal);
                    senhaNormal++;
                    break;
            case 2: 
                    cout << "Você selecionou atendimento PRIORITÁRIO - Senha: " << "P" << senhaPrioritaria << endl;
                    filaPrioritaria = inserir("P" + to_string(senhaPrioritaria), filaPrioritaria);
                    senhaPrioritaria++;
                    break;
            case 3:
                    if (quantidadeAtendimentos % 3 == 0) { //a cada 3 atendimentos no geral, um é prioritário
                        if (filaPrioritaria.inicio != NULL) {
                            filaPrioritaria = remover(filaPrioritaria, &senha);
                            cout << "Chamando senha " << senha << endl;
                        } else {
                            cout << "Atendimento prioritário sem senhas ou vazio!" << endl;
                        }
                    } else {
                        if (filaNormal.inicio != NULL) {
                            filaNormal = remover(filaNormal, &senha);
                            cout << "Chamando senha " << senha << endl;
                        } else {
                            cout << "Atendimento normal sem senhas ou vazio!" << endl;
                        }
                    }
                    quantidadeAtendimentos++;
                    break;
            case 4:
                    break;
            default: cout << "Opção inválida!" << endl;
        }
        delay(2000);
        
    } while (opcao != 4);

    return 1;
}

