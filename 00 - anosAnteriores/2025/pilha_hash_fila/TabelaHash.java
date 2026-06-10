import java.util.HashSet;
import java.util.Scanner;

class Peca {
    int codigo;
    String descricao;
    
    public Peca(int codigo, String descricao) {
        this.codigo = codigo;
        this.descricao = descricao;
    }

    @Override
    public String toString() {
        return "Peca [codigo=" + codigo + ", descricao=" + descricao + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + codigo;
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
        Peca other = (Peca) obj;
        if (codigo != other.codigo)
            return false;
        return true;
    }

}

public class TabelaHash {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        String descricao;
        int codigo;
        HashSet<Peca> tabelaHash = new HashSet<Peca>();

        for (int i = 0; i < 4; i++) {
            System.out.print("Codigo: ");
            codigo = teclado.nextInt();
            teclado.nextLine();
            System.out.print("Descrição: ");
            descricao = teclado.nextLine();
            if (tabelaHash.add(new Peca(codigo, descricao))) {
                System.out.println("Peca com sucesso na tabela hash...");
            } else {
                System.out.println("Peca já existente na tabela hash");
            }
        }

        for (Peca n : tabelaHash) {
            System.out.println(n + " - " + n.hashCode());
        }
    }
}
