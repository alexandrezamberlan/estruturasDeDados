import java.util.HashSet;

class Celula {
    public int linha;
    public int coluna;
    public int valor;

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

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Celula other = (Celula) obj;
        if (linha != other.linha)
            return false;
        if (coluna != other.coluna)
            return false;
        return true;
    }

    public static int dimensaoLinha;
    public static int dimensaoColuna;

    public static void transformarMatrizEmHash(int matriz[][], HashSet<Celula> tabelaHash) {
       
        for (int i = 0; i < MatrizEspecial.TAML; i++) {
            for (int j = 0; j < MatrizEspecial.TAMC; j++) {
                if (matriz[i][j] != 0) {
                    tabelaHash.add(new Celula(i,j,matriz[i][j]));
                }
            }    
        }
        dimensaoLinha = MatrizEspecial.TAML;
        dimensaoColuna = MatrizEspecial.TAMC;
    }

    public static void exibirHash(HashSet<Celula> tabelaHash) {
        for (Celula item : tabelaHash) {
            System.out.println(item);
        }
        System.out.println("Dimensoes da matriz original: [" + dimensaoLinha + "][" + dimensaoColuna + "]");
    }
}


public class MatrizEspecial {
    final static int TAML = 10;
    final static int TAMC = 10;

    public static void zerarMatriz(int matriz[][]) {
        for (int i = 0; i < TAML; i++) {
            for (int j = 0; j < TAMC; j++) {
                matriz[i][j] = 0;
            }    
        }
    }

    public static void mostrarMatriz(int matriz[][]) {
        for (int i = 0; i < TAML; i++) {
            for (int j = 0; j < TAMC; j++) {
                System.out.print(matriz[i][j] + "\t");
            }    
            System.out.println();
        }

    }


    public static void main(String[] args) {
        int matriz[][] = new int[TAML][TAMC];
        zerarMatriz(matriz);
        matriz[0][0] = 100;
        matriz[5][5] = 100;
        matriz[9][9] = 100;

        mostrarMatriz(matriz);

        HashSet<Celula> tabelaHash = new HashSet<Celula>();

        Celula.transformarMatrizEmHash(matriz, tabelaHash);
        Celula.exibirHash(tabelaHash);
        
    }
}
