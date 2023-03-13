typedef struct no {
    string nome;
    int qtdDisciplinas;
    struct no *prox;
} Celula;

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.length(); i++)
    {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

Celula *inserirListaSimples(string nome, Celula *lista) {
  // alocar memória
  Celula *novo = (Celula *)calloc(1,sizeof(Celula));
  Celula *p, *pR;
  bool jaExiste = false;

  // depositar valores
  novo->nome = nome;
  novo->qtdDisciplinas = 1;
  novo->prox = NULL;

  // para a primeira alocação
  if (!lista)
    return novo;

  // definir a posicao do valor na lista, ou seja, percorrer a lista
  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {

    if (novo->nome.compare(p->nome) == 0) { // nomes iguais
      cout << "nomes iguais ....\n";
      p->qtdDisciplinas = p->qtdDisciplinas + 1;
      free(novo);
      return lista;
    }

    if (novo->nome.compare(p->nome) < 0) {
      cout << "entrei aqui\n";
      break;
    }
  }
  
  // no inicio
  if (p == lista) {
    novo->prox = lista;
    return novo;
  }
  // no fim
  if (!p) {
    pR->prox = novo;
    return lista;
  }
  // no meio
  pR->prox = novo;
  novo->prox = p;
  return lista;
}

void exibirListaSimples(Celula *lista) {
    if (!lista) return;

    Celula *p;
    for (p = lista; p; p = p->prox) {
        cout << p->nome << ". Matriculado em: " << p->qtdDisciplinas << " disciplina(s)\n";
    }
    cout << endl;
}

