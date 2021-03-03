#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaCaracter(char letra, char frase[]) {
    int i;
    int qtd = 0;
    for (i = 0; i < strlen(frase); i++) {
        if (letra == frase[i]) {
            qtd++;
        }
    }
    return qtd;
}

int main() {
    char frase[100];
    system("clear");//

    printf("Digite uma frase qualquer: ");
    gets(frase); //equivalente ao scanf, entretanto, captura uma frase com espaços em branco

    char letra;
    printf("Digite um caracter para pesquisar na frase: ");
    letra = getc(stdin); //stdin é o standard input ou seja, o teclado

    int quantasVezesAparece = contaCaracter(letra, frase);

    printf("A letra %c aparece %d vezes na frase %s\n", letra, quantasVezesAparece, frase);

    // printf("\n\nA letra digitada foi: %c\n", letra);
    // printf("\n\nA frase digitada foi: %s\n", frase);
    return 1; //1 é verdade e que deu certo; 0 é falso e que deu errado
}