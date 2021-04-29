#include "fila.h"
#include "lista.h"
#include "delay.h"

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;
    CelulaS *listaSenhas = NULL;

    filaNormal = inicializar(filaNormal);
    filaPrioritaria = inicializar(filaPrioritaria);

    //abrir o arquivo de senhas e popular na lista
    int senhaNormal = 100; //atualizar qual foi a última senha normal chamada
    int senhaPrioritaria = 500; //atualizar qual foi a última senha prioritária chamada
    int opcao;
    string senha;
    int quantidadeAtendimentos = 0; //atualizar a quantidade de atendimentos

    do {
        system("clear");
        cout << "Sistema de senhas de atendimento!!" << endl;
        cout << "Senhas já chamadas: ";
        exibir(listaSenhas);
        cout << endl;
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
                    delay(2000);
                    break;
            case 2: 
                    cout << "Você selecionou atendimento PRIORITÁRIO - Senha: " << "P" << senhaPrioritaria << endl;
                    filaPrioritaria = inserir("P" + to_string(senhaPrioritaria), filaPrioritaria);
                    senhaPrioritaria++;
                    delay(2000);
                    break;
            case 3:
                    if (quantidadeAtendimentos % 3 == 0) { //a cada 3 atendimentos no geral, um é prioritário
                        if (filaPrioritaria.inicio != NULL) {
                            filaPrioritaria = remover(filaPrioritaria, &senha);
                            cout << "Chamando senha " << senha << endl;
                            listaSenhas = inserir(senha,listaSenhas);
                        } else {
                            cout << "Atendimento prioritário sem senhas ou vazio!" << endl;
                        }
                    } else {
                        if (filaNormal.inicio != NULL) {
                            filaNormal = remover(filaNormal, &senha);
                            cout << "Chamando senha " << senha << endl;
                            listaSenhas = inserir(senha,listaSenhas);
                        } else {
                            cout << "Atendimento normal sem senhas ou vazio!" << endl;
                        }
                    }
                    quantidadeAtendimentos++;
                    delay(2000);
                    break;
            case 4: //gravar a lista em um arquivo texto
                    break;
            default: cout << "Opção inválida!" << endl;
        }
    } while (opcao != 4);

    return 1;
}

