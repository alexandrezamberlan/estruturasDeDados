import java.util.TreeSet;

class Aluno implements Comparable<Aluno>{
    int matricula;
    String nome;

    public Aluno(int matricula, String nome) {
        this.matricula = matricula;
        this.nome = nome;
    }

    @Override
    public int compareTo(Aluno o) {
        if (this.matricula < o.matricula)
            return -1;
        return 1;
    }

    @Override
    public String toString() {
        return "Aluno [matricula=" + matricula + ", nome=" + nome + "]";
    }
}

public class Principal {
    public static void main(String args[]) {
        TreeSet<Aluno> arvore = new TreeSet<>();

        arvore.add(new Aluno(100,"andre"));
        arvore.add(new Aluno(5,"pedro"));
        arvore.add(new Aluno(5,"pedro"));
        arvore.add(new Aluno(1,"moro"));
        arvore.add(new Aluno(15,"wendel"));

        System.out.println(arvore);

    }
}