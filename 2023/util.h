
//criando artificialmente um tipo
typedef struct {
    int matricula;
    char nome[100];
} Cliente;

//metodos de manipulacao do vetor 
void popular(Cliente vetor[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        printf("Nome: ");
        scanf("%s", vetor[i].nome);
        vetor[i].matricula = 100 + rand() % 100;
    }
}

void exibir(Cliente vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s - Matricula: %d\n", vetor[i].nome, vetor[i].matricula);
    }
}
