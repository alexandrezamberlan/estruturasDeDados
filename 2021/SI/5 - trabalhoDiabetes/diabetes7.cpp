#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

typedef struct no {
    int valor;
    struct no *prox;
} Celula;


//lista de protótipos, ou seja, os métodos que deverão ser implementados no código
Celula *inserirOrdenado(int valor, Celula *lista);
Celula *inserirDesordenado(int valor, Celula *lista);
Celula *inserirControleDuplicidade(int valor, Celula *lista);
Celula *destruir(Celula *lista);

void exibir(Celula *lista, string frase);
int contarElementos(Celula *lista);
int somarElementos(Celula *lista);

void calcularMediaGlicemia(Celula *lista, FILE *procuradorSaida);
void calcularMediaInsulina(Celula *lista, FILE *procuradorSaida);
void calcularMediaCalorias(Celula *lista, FILE *procuradorSaida);
void calcularMediaCarboidrato(Celula *lista, FILE *procuradorSaida);

void calcularMedianaGlicemia(Celula *lista, FILE *procuradorSaida);
void calcularMedianaInsulina(Celula *lista, FILE *procuradorSaida);
void calcularMedianaCalorias(Celula *lista, FILE *procuradorSaida);
void calcularMedianaCarboidrato(Celula *lista, FILE *procuradorSaida);

void calcularModaGlicemia(Celula *lista, FILE *procuradorSaida);
void calcularModaInsulina(Celula *lista, FILE *procuradorSaida);
void calcularModaCalorias(Celula *lista, FILE *procuradorSaida);
void calcularModaCarboidrato(Celula *lista, FILE *procuradorSaida);

int main() {
    Celula *listaOriginalGlicemia = NULL;
    Celula *listaOriginalInsulina = NULL;
    Celula *listaOriginalCalorias = NULL;
    Celula *listaOriginalCarboidrato = NULL;

    Celula *listaOrdenadaGlicemia = NULL;
    Celula *listaOrdenadaInsulina = NULL;
    Celula *listaOrdenadaCalorias = NULL;
    Celula *listaOrdenadaCarboidrato = NULL;
    
    FILE *procuradorEntrada;
    FILE *procuradorSaida;
    char nomeArquivo[100];

    system("clear"); //system("cls");

    //tratar o arquivo de entrada: abrir 
    cout << "Digite caminho e nome do arquivo fonte com dados glicêmicos: ";
    
    //em c
    gets(nomeArquivo);
    procuradorEntrada = fopen(nomeArquivo, "r");
    
    if (!procuradorEntrada) {
        cout << "Arquivo não encontrado. Programa será encerrado." << endl;
        exit(0);
    }
    cout << "Arquivo localizado e sendo tratado." << endl;

    //passar pelo arquivo de entrada e extrair seus dados nas diferentes listas
    int glicemia, insulina, calorias, carboidrato;
    do {    
        fscanf(procuradorEntrada, "%d %d %d %d", &glicemia, &insulina, &calorias, &carboidrato);
        listaOriginalGlicemia = inserirDesordenado(glicemia, listaOriginalGlicemia);
        listaOrdenadaGlicemia = inserirOrdenado(glicemia, listaOrdenadaGlicemia);

        listaOriginalInsulina = inserirDesordenado(insulina, listaOriginalInsulina);
        listaOrdenadaInsulina = inserirOrdenado(insulina, listaOrdenadaInsulina);

        listaOriginalCalorias = inserirDesordenado(calorias, listaOriginalCalorias);
        listaOrdenadaCalorias = inserirOrdenado(calorias, listaOrdenadaCalorias);

        listaOriginalCarboidrato = inserirDesordenado(carboidrato, listaOriginalCarboidrato);
        listaOrdenadaCarboidrato = inserirOrdenado(carboidrato, listaOrdenadaCarboidrato);

    } while (!feof(procuradorEntrada));

    //exibir(listaOriginalGlicemia, "Lista original de glicemia");
    //exibir(listaOrdenadaGlicemia, "Lista ordenada da glicemia");

    //abrir o arquivo de saida
    //em c
    procuradorSaida = fopen("saida.dat", "w");
    //capturar data e hora para armazenar no arquivo e exibir na tela
    struct tm data;
    time_t t = time(NULL);
    data = *localtime(&t);
    //printf("Data: %02d/%02d/%d. Hora: %02d:%02d\n", data.tm_mday, data.tm_mon + 1, data.tm_year + 1900,
    //        data.tm_hour, data.tm_min);
    
    fprintf(procuradorSaida, "Data: %02d/%02d/%d. Hora: %02d:%02d\n", data.tm_mday, data.tm_mon + 1, data.tm_year + 1900,
            data.tm_hour, data.tm_min);

    //calcular média de cada valor glicêmico e 'jogar' na tela e arquivo de saida
    calcularMediaGlicemia(listaOriginalGlicemia, procuradorSaida);
    calcularMediaInsulina(listaOriginalInsulina, procuradorSaida);
    calcularMediaCalorias(listaOriginalCalorias, procuradorSaida);
    calcularMediaCarboidrato(listaOriginalCarboidrato, procuradorSaida);

    cout << endl;
    fprintf(procuradorSaida, "\n");

    //calcular mediana de cada valor glicêmico e 'jogar' na tela e arquivo de saida
    calcularMedianaGlicemia(listaOrdenadaGlicemia, procuradorSaida);
    calcularMedianaInsulina(listaOrdenadaInsulina, procuradorSaida);
    calcularMedianaCalorias(listaOrdenadaCalorias, procuradorSaida);
    calcularMedianaCarboidrato(listaOrdenadaCarboidrato, procuradorSaida);

    cout << endl;
    fprintf(procuradorSaida, "\n");

    //calcular moda de cada valor glicêmico e 'jogar' na tela e arquivo de saida
    calcularModaGlicemia(listaOrdenadaGlicemia, procuradorSaida);
    calcularModaInsulina(listaOrdenadaInsulina, procuradorSaida);
    calcularModaCalorias(listaOrdenadaCalorias, procuradorSaida);
    calcularModaCarboidrato(listaOrdenadaCarboidrato, procuradorSaida);

    cout << endl;
    fprintf(procuradorSaida, "\n");

    //analisar os dados glicêmicos glicemia e carboidrato e dar um parecer
    fprintf(procuradorSaida, "Para um diabético controlado:\n");    
    fprintf(procuradorSaida, "glicemia <= 100.\n"); 
    fprintf(procuradorSaida, "carboidrato <= 200.\n");

    //fechar arquivos
    fclose(procuradorEntrada);
    fclose(procuradorSaida);
    return 1;
}

void calcularModaGlicemia(Celula *lista, FILE *procuradorSaida) {
    Celula *p1, *p2;
    int valor, valorModa;
    int qtdValor, qtdValorModa = 0;

    Celula *listaModa = NULL;
      
    for (p1 = lista; p1; p1 = p1->prox) {
        if (valor == p1->valor) {
            continue;
        }
        valor = p1->valor;
        qtdValor = 0;
        if (valor != valorModa) {
            for (p2 = lista; p2; p2 = p2->prox) {
                if (valor == p2->valor) {
                    qtdValor++;
                }
                if (valor < p2->valor) {
                    break; //vamos sair do segundo for
                }

            }
            if (qtdValor > qtdValorModa) {
                qtdValorModa = qtdValor;
                valorModa = valor;
                listaModa = destruir(listaModa);
                listaModa = inserirOrdenado(valorModa, listaModa);
            }

            if (qtdValor == qtdValorModa) {
                valorModa = valor;
                listaModa = inserirControleDuplicidade(valorModa, listaModa);
            }
        }
    }

    Celula *p;
    cout <<  "Moda da Glicemia: ";
    for (p = listaModa; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << " aparece(m) " << qtdValorModa << " vezes na lista" << endl;

    fprintf(procuradorSaida, "Moda da Glicemia: ");
    for (p = listaModa; p; p = p->prox) {
        fprintf(procuradorSaida, "%d\t", p->valor);
    }
    fprintf(procuradorSaida, " aparece(m) %d vezes\n", qtdValorModa);   
}

void calcularModaInsulina(Celula *lista, FILE *procuradorSaida) {
    Celula *p1, *p2;
    int valor, valorModa;
    int qtdValor, qtdValorModa = 0;

    Celula *listaModa = NULL;
      
    for (p1 = lista; p1; p1 = p1->prox) {
        if (valor == p1->valor) {
            continue;
        }
        valor = p1->valor;
        qtdValor = 0;
        if (valor != valorModa) {
            for (p2 = lista; p2; p2 = p2->prox) {
                if (valor == p2->valor) {
                    qtdValor++;
                }
                if (valor < p2->valor) {
                    break; //vamos sair do segundo for
                }
            }
            if (qtdValor > qtdValorModa) {
                qtdValorModa = qtdValor;
                valorModa = valor;
                listaModa = destruir(listaModa);
                listaModa = inserirOrdenado(valorModa, listaModa);
            }

            if (qtdValor == qtdValorModa) {
                valorModa = valor;
                listaModa = inserirControleDuplicidade(valorModa, listaModa);
            }
        }
    }

    Celula *p;
    cout <<  "Moda da Insulina: ";
    for (p = listaModa; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << " aparece(m) " << qtdValorModa << " vezes na lista" << endl;

    fprintf(procuradorSaida, "Moda da Insulina: ");
    for (p = listaModa; p; p = p->prox) {
        fprintf(procuradorSaida, "%d\t", p->valor);
    }
    fprintf(procuradorSaida, " aparece(m) %d vezes\n", qtdValorModa);
}

void calcularModaCalorias(Celula *lista, FILE *procuradorSaida) {
    Celula *p1, *p2;
    int valor, valorModa;
    int qtdValor, qtdValorModa = 0;

    Celula *listaModa = NULL;
      
    for (p1 = lista; p1; p1 = p1->prox) {
        if (valor == p1->valor) {
            continue;
        }
        valor = p1->valor;
        qtdValor = 0;
        if (valor != valorModa) {
            for (p2 = lista; p2; p2 = p2->prox) {
                if (valor == p2->valor) {
                    qtdValor++;
                }
                if (valor < p2->valor) {
                    break; //vamos sair do segundo for
                }
            }
            if (qtdValor > qtdValorModa) {
                qtdValorModa = qtdValor;
                valorModa = valor;
                listaModa = destruir(listaModa);
                listaModa = inserirOrdenado(valorModa, listaModa);
            }

            if (qtdValor == qtdValorModa) {
                valorModa = valor;
                listaModa = inserirControleDuplicidade(valorModa, listaModa);
            }
        }
    }

    Celula *p;
    cout <<  "Moda da Calorias: ";
    for (p = listaModa; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << " aparece(m) " << qtdValorModa << " vezes na lista" << endl;

    fprintf(procuradorSaida, "Moda da Calorias: ");
    for (p = listaModa; p; p = p->prox) {
        fprintf(procuradorSaida, "%d\t", p->valor);
    }
    fprintf(procuradorSaida, " aparece(m) %d vezes\n", qtdValorModa);
}

void calcularModaCarboidrato(Celula *lista, FILE *procuradorSaida) {
    Celula *p1, *p2;
    int valor, valorModa;
    int qtdValor, qtdValorModa = 0;

    Celula *listaModa = NULL;
      
    for (p1 = lista; p1; p1 = p1->prox) {
        if (valor == p1->valor) {
            continue;
        }
        valor = p1->valor;
        qtdValor = 0;
        if (valor != valorModa) {
            for (p2 = lista; p2; p2 = p2->prox) {
                if (valor == p2->valor) {
                    qtdValor++;
                }
                if (valor < p2->valor) {
                    break; //vamos sair do segundo for
                }
            }
            if (qtdValor > qtdValorModa) {
                qtdValorModa = qtdValor;
                valorModa = valor;
                listaModa = destruir(listaModa);
                listaModa = inserirOrdenado(valorModa, listaModa);
            }

            if (qtdValor == qtdValorModa) {
                valorModa = valor;
                listaModa = inserirControleDuplicidade(valorModa, listaModa);
            }
        }
    }

    Celula *p;
    cout <<  "Moda da Carboidrato: ";
    for (p = listaModa; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << " aparece(m) " << qtdValorModa << " vezes na lista" << endl;

    fprintf(procuradorSaida, "Moda da Carboidrato: ");
    for (p = listaModa; p; p = p->prox) {
        fprintf(procuradorSaida, "%d\t", p->valor);
    }
    fprintf(procuradorSaida, " aparece(m) %d vezes\n", qtdValorModa);
}

void calcularMedianaGlicemia(Celula *lista, FILE *procuradorSaida) {
    int qtd = contarElementos(lista);
    int metade = qtd / 2;
    int i;
    Celula *p;
    
    if (qtd % 2 == 1) { //qtd eh impar, logo mostra o elemento do meio
        for (i = 0, p = lista; i < metade; i++, p = p->prox);

        cout <<  "Mediana da Glicemia: " << p->valor << endl;
        fprintf(procuradorSaida, "Mediana da Glicemia: %d\n", p->valor);    
    } else { //qtd eh par, logo mostra-se os DOIS elementos do meio
        for (i = 0, p = lista; i < metade - 1; i++, p = p->prox);

        cout <<  "Mediana da Glicemia: " << p->valor << " - " << p->prox->valor << endl;
        fprintf(procuradorSaida, "Mediana da Glicemia: %d - %d\n", p->valor, p->prox->valor);   
    }
}

void calcularMedianaInsulina(Celula *lista, FILE *procuradorSaida) {
    int qtd = contarElementos(lista);
    int metade = qtd / 2;
    int i;
    Celula *p;
    
    if (qtd % 2 == 1) { //qtd eh impar, logo mostra o elemento do meio
        for (i = 0, p = lista; i < metade; i++, p = p->prox);

        cout <<  "Mediana da Insulina: " << p->valor << endl;
        fprintf(procuradorSaida, "\nMediana da Insulina: %d\n", p->valor);    
    } else { //qtd eh par, logo mostra-se os DOIS elementos do meio
        for (i = 0, p = lista; i < metade - 1; i++, p = p->prox);

        cout <<  "Mediana da Insulina: " << p->valor << " - " << p->prox->valor << endl;
        fprintf(procuradorSaida, "Mediana da Insulina: %d - %d\n", p->valor, p->prox->valor);   
    }
}

void calcularMedianaCalorias(Celula *lista, FILE *procuradorSaida) {
    int qtd = contarElementos(lista);
    int metade = qtd / 2;
    int i;
    Celula *p;
    
    if (qtd % 2 == 1) { //qtd eh impar, logo mostra o elemento do meio
        for (i = 0, p = lista; i < metade; i++, p = p->prox);

        cout <<  "Mediana da Calorias: " << p->valor << endl;
        fprintf(procuradorSaida, "Mediana da Calorias: %d\n", p->valor);    
    } else { //qtd eh par, logo mostra-se os DOIS elementos do meio
        for (i = 0, p = lista; i < metade - 1; i++, p = p->prox);

        cout <<  "Mediana da Calorias: " << p->valor << " - " << p->prox->valor << endl;
        fprintf(procuradorSaida, "Mediana da Calorias: %d - %d\n", p->valor, p->prox->valor);   
    }
}

void calcularMedianaCarboidrato(Celula *lista, FILE *procuradorSaida) {
    int qtd = contarElementos(lista);
    int metade = qtd / 2;
    int i;
    Celula *p;
    
    if (qtd % 2 == 1) { //qtd eh impar, logo mostra o elemento do meio
        for (i = 0, p = lista; i < metade; i++, p = p->prox);

        cout <<  "Mediana da Carboidrato: " << p->valor << endl;
        fprintf(procuradorSaida, "Mediana da Carboidrato: %d\n", p->valor);    
    } else { //qtd eh par, logo mostra-se os DOIS elementos do meio
        for (i = 0, p = lista; i < metade - 1; i++, p = p->prox);

        cout <<  "Mediana da Carboidrato: " << p->valor << " - " << p->prox->valor << endl;
        fprintf(procuradorSaida, "Mediana da Carboidrato: %d - %d\n", p->valor, p->prox->valor);   
    }
}


void calcularMediaGlicemia(Celula *lista, FILE *procuradorSaida) {
    double media = somarElementos(lista) / contarElementos(lista);
    cout <<  "Média da Glicemia: " << media << endl;
    fprintf(procuradorSaida, "Média da Glicemia: %.2f\n", media);
}

void calcularMediaInsulina(Celula *lista, FILE *procuradorSaida) {
    double media = somarElementos(lista) / contarElementos(lista);
    cout <<  "Média da Insulina: " << media << endl;
    fprintf(procuradorSaida, "Média da Insulina: %.2f\n", media);
}

void calcularMediaCalorias(Celula *lista, FILE *procuradorSaida) {
    double media = somarElementos(lista) / contarElementos(lista);
    cout <<  "Média da Calorias: " << media << endl;
    fprintf(procuradorSaida, "Média da Calorias: %.2f\n", media);
}

void calcularMediaCarboidrato(Celula *lista, FILE *procuradorSaida) {
    double media = somarElementos(lista) / contarElementos(lista);
    cout <<  "Média da Carboidrato: " << media << endl;
    fprintf(procuradorSaida, "Média da Carboidrato: %.2f\n", media);
}

void exibir(Celula *lista, string frase) {
    if (!lista) {
        return;
    }
    cout << frase << endl;
    Celula *p;
    for (p = lista; p ; p = p->prox) {
        cout << p->valor << endl;
    }

}

Celula *inserirDesordenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox);

    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado

    //retornar o primeiro elemento
    return lista;
}

Celula *inserirOrdenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    Celula *p, *pR;
    for (pR = NULL, p = lista; p != NULL; pR = p, p = p->prox) {
        if (valor <= p->valor) { //encontramos a posição do valor
            break;  //sai do for      
        }
    }
    //existem 2 motivos para sair do for:
    //1o pq o p chegou no final da lista - sabe-se então que o valor será o último elemento
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //2o pq o break executou - ou o valor pode ser o primeiro ou pode estar no meio
    if (p == lista) {
        novo->prox = lista; //novo->prox = p;
        return novo;
    }
    //não é o primeiro e nem o último, ou seja, está no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

Celula *inserirControleDuplicidade(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    Celula *p, *pR;
    for (pR = NULL, p = lista; p != NULL; pR = p, p = p->prox) {
        if (valor == p->valor) {
            free(novo);
            return lista;
        }
        if (valor <= p->valor) { //encontramos a posição do valor
            break;  //sai do for      
        }
    }
    //existem 2 motivos para sair do for:
    //1o pq o p chegou no final da lista - sabe-se então que o valor será o último elemento
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //2o pq o break executou - ou o valor pode ser o primeiro ou pode estar no meio
    if (p == lista) {
        novo->prox = lista; //novo->prox = p;
        return novo;
    }
    //não é o primeiro e nem o último, ou seja, está no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

Celula *destruir(Celula *lista) {
    if (!lista) {
        return lista;
    }
    Celula *pR, *p;

    for (pR = lista, p = lista->prox; p ; pR = p, p = p->prox) {
        free(pR);
    }
    free(pR);

    return NULL;
}

int contarElementos(Celula *lista) {
   Celula *p;
   int contador = 0;

    if (!lista) {
        return contador;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        contador++;
    } 
    return contador;
}

int somarElementos(Celula *lista) {
   Celula *p;
   int soma = 0;

    if (!lista) {
        return soma;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        soma = soma + p->valor;
    } 
    return soma;
}