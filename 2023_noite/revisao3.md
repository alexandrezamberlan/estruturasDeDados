# Aula 3a Semana

## Revisão
    - Estruturas de Dados
        - Físicas: variáveis da linguagem (int, float, char, string, matriz, ...)
        - Abstratas: algoritmos de gestão de memória -> operações de inserir, remover, percorrer, pesquisar,...
            - Pilha:    Regra no inserir e no remover - LIFO -> Last In, First Out
                        - ponteiro para o topo. Lá que ocorrem as duas operações: inserir e remover
                        - para backups
            - Lista:    Regra é a ordenação -> inserir e depois ordenar ou inserir ordenado
                        - ponteiro para o início da lista: todas as operações (percorrer, inserir, remover, pesquisar, ...)
                        - para armazenar e buscar
            - Fila:     Regra no inserir e no remover - FIFO -> First In, First Out
                        - dois ponteiros, um para a cabeça ou início (remover), outro ponteiro para a cauda ou fim (inserir)
                        - para prioridade
            - Árvore:   Estrutura de dados não linear. Um nó pode ter n filhos
                        - excelente para armazenar e buscar de forma eficiente    
            - Grafo:    Estrutura de dados não linear
                        - usada para roteamento -> melhor caminho

    - Alocação:
        - estática: em tempo de programação -> Matrizes e Vetores
        - dinâmica: em tempo de execução -> malloc, free, ...

## Pilha alocação dinâmica

Esta estrutura será comum para pilha, lista simples, lista circular e fila

typedef struct no {
    int valor;
    struct no* prox; //ponteiro que faz o encadeamento ao próximo elemento
} Celula;

//inserir
Celula *inserirPilha(int valor, Celula *topo) {
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar os valores que vieram nos parâmetros
    novo->valor = valor;

    //encadear
    novo->prox = topo; 

    //retornar o topo
    return novo;
}

//remover
Celula *removerPilha(Celula *topo) {
    //verificar se ha elementos
    if (!topo) return topo;

    //guardar o lixo
    Celula *lixo = topo;

    //avancar o topo
    topo = topo->prox;

    //liberar memoria
    free(lixo);

    //retornar o novo topo
    return topo;
}