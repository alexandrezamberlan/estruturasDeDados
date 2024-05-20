import java.util.HashSet;

public class ExemploMatrizEspecialTratada {
    public static void criar(int matriz[][], int linhas, int colunas) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                matriz[i][j] = 0;
            }
        }
    }

    public static void exibir(int matriz[][]) {       
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.print(matriz[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        int tamLinha = 5;
        int tamColuna = 5;
        int matrizEspecial[][] = new int[tamLinha][tamColuna];
        ExemploMatrizEspecialTratada.criar(matrizEspecial, 5, 5);
        
        matrizEspecial[0][0] = 5;
        matrizEspecial[2][3] = 5;
        matrizEspecial[4][2] = 5;
        
        //ExemploMatrizEspecialTratada.exibir(matrizEspecial);

        //gera hash a partir da matriz especial
        HashSet<Celula> tabelaHash = new HashSet<Celula>();
        Celula.transformaMatrizEmHash(matrizEspecial, tabelaHash);
        Celula.exibeMatrizEmHash(tabelaHash);

        //gera a matriz especial a partir do hash
        System.out.println("Gerando matriz especial a partir da tabela hash");
        int outraMatriz[][] = new int[Celula.qtdLinhas][Celula.qtdColunas];
        Celula.transformaHashEmMatriz(tabelaHash, outraMatriz);
        ExemploMatrizEspecialTratada.exibir(outraMatriz);
    }
}