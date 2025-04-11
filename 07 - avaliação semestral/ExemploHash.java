import java.util.HashSet;
import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;

class Aluno {
    String nome;
    String email;
    
    public Aluno(String nome){
        this.nome = nome;
        this.email = "aqui o email" + nome;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((nome == null) ? 0 : nome.hashCode());
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
        Aluno other = (Aluno) obj;
        if (nome == null) {
            if (other.nome != null)
                return false;
        } else if (!nome.equals(other.nome))
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Aluno [nome=" + nome + ", email=" + email + "]";
    }

    


}
public class ExemploHash {
    public static void main(String[] args) {
        HashSet<Aluno> tabelaHash = new HashSet<>();
        Scanner teclado = new Scanner(System.in);
        String nome;
        for (int i = 0; i < 4; i++) {
            System.out.print("Nome: ");
            nome = teclado.nextLine().toUpperCase();
            Aluno tmp = new Aluno(nome);
            System.out.println("hash aplicado...."+tmp.hashCode());

            if (!tabelaHash.add(tmp)) {
                System.out.println("aluno ja cadastrado...");
            }
        }

        List<Aluno> lista = new LinkedList<>();

        for (Aluno aluno : tabelaHash) {
            System.out.println(aluno);
        }
        
    }
}