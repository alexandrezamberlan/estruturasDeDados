// Estrutura de Dados
//     - Tipos:
//         - ED Físicas: variáveis (primitivas, estruturadas)
//             - DEPENDENTE DE LINGUAGEM
//         - ED Abstratas: algoritmos de gestão de dados em memória
//             - Pilha:    LIFO -> inserir e remover no topo
//             - Lista:    Ordenação -> percorrer, inserir, remover, atualizar
//             - Fila:     FIFO -> inserir no fim e remover do início
//             - Árvore:   ED não linear com otimização de busca
//             - Grafo:    ED não linear para roteamento

//     - ED Abstratas elas focam na alocação dinâmica
//         - a medida que o programa precisa ou não de memória,
//         é alocado ou desalocado em tempo de programação

//     - Recursos para manipular ED Abstratas
//         - métodos ou funções (tinha retorno) ou procedimentos (void)
//         - matrizes de 1 dimensão = vetor
//         - struct: heterogeneidade
//         - ponteiros: malloc e free
//         - arquivo texto
//             - xml, json, ...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 5

#include "util.h"

int main() {
    Cliente vetor[TAM];
    
    popular(vetor, TAM);
    exibir(vetor, TAM);

    return 1;
}

