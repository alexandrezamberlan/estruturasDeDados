#include <stdio.h>
#include <stdlib.h>
#define TAM_L 50
#define TAM_C 30

typedef struct matTab {
  int linha;
  int coluna;
  float valor;
  struct matTab *prox;
} MEBD;

MEBD *inserir(int lin, int col, float val, MEBD *matriz){
  MEBD *novo, *p;

  novo = (MEBD*) malloc (sizeof (MEBD));
  novo->linha = lin;
  novo->coluna = col;
  novo->valor = val;
  novo->prox = NULL;
  if (!matriz) return novo;

  for (p = matriz; p->prox; p = p->prox){
    if (p->linha == lin && p->coluna == col) {
      printf("Coordenada jah informada\n");
      free(novo);
      return matriz;
    }
  }
  p->prox = novo;
  return matriz;
}

void exibir (MEBD *matriz){
  printf("\n\nImprimindo a lista da matriz esparsa\n\n");
  if (matriz){
    while (matriz){
      printf ("Linha: %d  Coluna: %d   Valor: %.2f\n", matriz->linha, matriz->coluna, matriz->valor);
      matriz = matriz->prox;
    }
  } else printf("Matriz Esparsa vazia!!\n");
}

int main (){
  MEBD *matrizE = NULL;
  float matrizO[TAM_L][TAM_C];

  int i,j, cont;
  float val;

  /*fazer uma rotina que popule a matriz origem com alguns elementos
    não nullos e o restante com nulos.*/
  //inicializando a matriz com zeros
  for (i = 0; i < TAM_L; i++)
    for (j = 0; j < TAM_C; j++)
      matrizO[i][j] = 0.0;

  for (cont = 0; cont < 3; cont++) {
    do {
      printf("Digite coordenada linha: ");
      scanf("%d",&i);
    } while (i < 0 || i >= TAM_L);

    do {
      printf("Digite coordenada coluna: ");
      scanf("%d",&j);
    } while (j < 0 || j >= TAM_C);

    do {
      printf("Digite um valor nao nulo: ");
      scanf("%f", &val);
    } while(val == 0.0);

    matrizO[i][j] = val;
  }

  // fazer rotina que popule a matriz esparsa (lista) com elementos
  // não nulos da matriz original.
  for (i = 0; i < TAM_L; i++)
    for (j = 0; j < TAM_C; j++)
      if (matrizO[i][j] != 0.0)
        matrizE = inserir(i, j, matrizO[i][j], matrizE);


  printf("DIGITANDO MAIS UM ELEMENTO PARA VERIFICAR DUPLICIDADE\nDigite coordenada linha: ");
  scanf("%d",&i);
  printf("Digite coordenada coluna: ");
  scanf("%d",&j);
  printf("Digite um valor nao nulo: ");
  scanf("%f", &val);
  matrizE = inserir(i, j, val, matrizE);

  // exibir a matriz esparsa.
  exibir(matrizE);
  system("pause");
  return 0;
}
