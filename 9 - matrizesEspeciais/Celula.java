import java.util.HashSet;

public class Celula {
    int linha;
    int coluna;
    int valor;
    static int qtdLinhas;
    static int qtdColunas;

    public Celula(int linha, int coluna, int valor) {
        this.linha = linha;
        this.coluna = coluna;
        this.valor = valor;
    }

    @Override
    public String toString() {
        return "Celula [linha=" + linha + ", coluna=" + coluna + ", valor=" + valor + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + linha;
        result = prime * result + coluna;
        return result;
    }

    public static void transformaMatrizEmHash(int matriz[][], HashSet<Celula> tabelaHash) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                if (matriz[i][j] != 0) {
                    tabelaHash.add(new Celula(i,j,matriz[i][j]));
                }
            }
        }
        Celula.qtdLinhas = matriz.length;
        Celula.qtdColunas = matriz[0].length;
    }

    public static void transformaHashEmMatriz(HashSet<Celula> tabelaHash, int matriz[][]) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                matriz[i][j] = 0;
            }
        }
        
        for (Celula ponto : tabelaHash) {
            matriz[ponto.linha][ponto.coluna] = ponto.valor;
        }
    }

    public static void exibeMatrizEmHash(HashSet<Celula> tabelaHash) {
        System.out.println("Matriz["+Celula.qtdLinhas+"]["+Celula.qtdColunas+"]");

        for (Celula ponto : tabelaHash) {
            System.out.println(ponto);
        }
    }

}