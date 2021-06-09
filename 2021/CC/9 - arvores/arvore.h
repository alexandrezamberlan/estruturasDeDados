typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} Arvore;

Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor < raiz->valor) { //avançar ou empilhar para a esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else { //avançar ou empilhar para a direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        return raiz;
    } else {
        //se estamos aqui, pq chegamos em um folha e estamos prontos para adicionar o nodo na árvore
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;
        return novo;
    }
}

void exibir(Arvore *raiz, int nivel) {
    if (raiz) {
        exibir(raiz->dir, nivel + 1); //empilhando tudo para direita, busca-se exibir os maiores primeiro
        
        for (int i = 0; i < nivel; i++) {
            printf("   ");
        }
        printf("%d(%d)\n", raiz->valor,nivel); 

        exibir(raiz->esq, nivel + 1); //empilhando tudo para esquerda, busca-se exibir os menores
    }
}

int contarNos(Arvore *raiz) {
    if (raiz) {
        return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
    } else {
        return 0;
    }
}

int somarNos(Arvore *raiz) {
    if (raiz) {
        return raiz->valor + somarNos(raiz->esq) + somarNos(raiz->dir);
    } else {
        return 0;
    }
}

int contarNosPares(Arvore *raiz) {
    if (raiz) {
        if (raiz->valor % 2 == 0)
            return 1 + contarNosPares(raiz->esq) + contarNosPares(raiz->dir);
        return 0 + contarNosPares(raiz->esq) + contarNosPares(raiz->dir);
    } else {
        return 0;
    }
}

int localizar(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) return 1; //valor encontrado, começa o processo de desempilhamento
        if (valor < raiz->valor) { //testar o lado esquerdo da árvore
            return localizar(valor, raiz->esq);
        } else { //testar o lado direito da árvore
            return localizar(valor, raiz->dir);
        }
    } else {
        return 0; //valor não localizado, começa o processo de desempilhamento
    }
}

int localizarNivel(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) return 0; //valor encontrado, começa o processo de desempilhamento
        if (valor < raiz->valor) { //testar o lado esquerdo da árvore
            int resultadoEmpilhamento = localizarNivel(valor, raiz->esq);
            if (resultadoEmpilhamento != -1) return resultadoEmpilhamento + 1;
            return resultadoEmpilhamento; //continuo informando que valor não foi localizado
        } else { //testar o lado direito da árvore
             int resultadoEmpilhamento = localizarNivel(valor, raiz->dir);
            if (resultadoEmpilhamento != -1) return resultadoEmpilhamento + 1;
            return resultadoEmpilhamento; //continuo informando que valor não foi localizado
        }
    } else {
        return -1; //valor não localizado, começa o processo de desempilhamento
    }
}

int contarVezes(int valor, Arvore *raiz) {
    if (raiz) {
        int qtdVezesEsquerda = contarVezes(valor, raiz->esq);//empilhar tudo para esquerda
        int qtdVezesDireita = contarVezes(valor, raiz->dir);//empilhar tudo para direita

        //so então testar, ou seja, o teste vem das folhas em direção a raiz
        if (valor == raiz->valor) return 1 + qtdVezesEsquerda + qtdVezesDireita;
        return 0 + qtdVezesEsquerda + qtdVezesDireita;
    } else {
        return 0;
    }
}

int multiplos(int valor, Arvore *raiz) {
    if (raiz) {
        int qtdVezesEsquerda = multiplos(valor, raiz->esq);//empilhar tudo para esquerda
        int qtdVezesDireita = multiplos(valor, raiz->dir);//empilhar tudo para direita

        //so então testar, ou seja, o teste vem das folhas em direção a raiz
        if (raiz->valor % valor == 0) return 1 + qtdVezesEsquerda + qtdVezesDireita;
        return 0 + qtdVezesEsquerda + qtdVezesDireita;
    } else {
        return 0;
    }
}

int contarFolhas(Arvore *raiz){
    if (raiz) {
        if (!raiz->esq && !raiz->dir) return 1;
        return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
    } else {
        return 0;
    }
}

void mostrarFolhas(Arvore *raiz){
    if (raiz) {
        if (!raiz->esq && !raiz->dir) printf("%d\t", raiz->valor);
        
        mostrarFolhas(raiz->esq);
        mostrarFolhas(raiz->dir);
    } 
}

int contarNaoFolhas(Arvore *raiz){
    if (raiz) {
        if (raiz->esq || raiz->dir) return 1 + contarNaoFolhas(raiz->esq) + contarNaoFolhas(raiz->dir);
    } 
    return 0;
}

Arvore *podar(Arvore *raiz){
    if (raiz) {
        if (!raiz->esq && !raiz->dir) {
            free(raiz);
            return NULL;
        }
        raiz->esq = podar(raiz->esq);
        raiz->dir = podar(raiz->dir);
        return raiz;
    } else {
        return NULL;
    }
}
/*
            46(0)
        13(1)
    11(2)           30(2)          
                            32(3)
                                    41(4)
                    
*/
Arvore *excluir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) { //valor localizado para ser excluido
            //descobrir se é folha
            if (!raiz->esq && !raiz->dir) {
                free(raiz);
                return NULL;
            } else {  //se nao for folha, pegar o filho da esquerda como novo pai
                Arvore *novoPai = raiz->esq;
                Arvore *r;
                for (r = novoPai->dir; r->dir; r = r->dir); //levando o ponteiro r para a porçao mais a direita do novoPai

                r->dir = raiz->dir;

                free(raiz);
                return novoPai;
            }
        } else { //valor não localizado... preciso avançar na árvore, ou para esquerda ou para direita
            if (valor < raiz->valor)
                raiz->esq = excluir(valor, raiz->esq); //vai pra esquerda
            else raiz->dir = excluir(valor, raiz->dir); //vai pra direita
        }
        return raiz;
    } else {
        return NULL;
    }
}

//RED -> visita Raiz; vai para Esquerda; vai para Direita
void exibirRED(Arvore *raiz) {
    if (raiz) {
        printf("%d\n", raiz->valor); //antes do primeiro empilhamento
        exibirRED(raiz->esq);
        exibirRED(raiz->dir);
    }
}

//ERD -> vai para Esquerda; visita Raiz; vai para Direita
void exibirERD(Arvore *raiz) {
    if (raiz) {
        exibirERD(raiz->esq);
        printf("%d\n", raiz->valor); //depois do primeiro empilhamento
        exibirERD(raiz->dir);
    }
}

//EDR -> vai para Esquerda; vai para Direita; visita Raiz
void exibirEDR(Arvore *raiz) {
    if (raiz) {
        exibirEDR(raiz->esq);
        exibirEDR(raiz->dir);
        printf("%d\n", raiz->valor); //depois de todos os empilhamentos
    }
}

/*
                            100
            20                                150
    10              25
                            50

RED: 100 20 10 25 50 150 -> pré-fixado
ERD: 10 20 25 50 100 150  -> percurso ordenado -> infixado
EDR: 10 50 25 20 150 100  -> percurso das folhas à raiz -> pós-fixado

                46(0)
        13(1)
    11(2)           
              33(2)       
                    35(3)
                            41(4)

RED: 46 13 11 37 33 41 
ERD: 11 13 33 37 41 46
EDR: 11 33 41 37 13 46


*/