Listas circulares têm o mesmo struct que listas simples e pilha.

typedef struct no {
    int valor;
    struct no *prox;
} Celula;

A diferença que o último elemento aponta para o primeiro elemento, tornando a lista infinita ou 
circular.

Listas circulares têm todas as operações de uma lista, inclusive controle de duplicidade e 
ordenação

SIMPLES
 12 B -> 20 C -> 30 .
 A       B       C

 lista = A


CIRCULAR
 12 B -> 20 C -> 30 D -> 70 A 
 A       B       C       D

 lista = A

 Em listas circulares, o PERCURSO é diferente das listas simples.

 Exibir/contar/pesquisar na lista simples.
 for (p = lista; p != NULL; p = p->prox) {
     //exibir
     //contar
     //pesquisar
 }

    A   B   C   D
    10b 20c 30d 40a
                p

    lista = A

 Exibir/contar/pesquisar na lista circular.
 for (p = lista; p->prox != lista; p = p->prox) {
     //exibir
     //contar
     //pesquisar
 }
 //tudo que está dentro do for deve ser executado fora do for para aplicar no último elemento
 //exibir
 //contar
 //pesquisar