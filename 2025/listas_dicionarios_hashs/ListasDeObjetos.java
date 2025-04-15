import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Aluno {
    int matricula;
    String nome;
    String email;

    public Aluno(int matricula, String nome){
        this.matricula = matricula;
        this.nome = nome.toUpperCase();
        this.gerarEmail();
    }

    public void gerarEmail(){
        String vetorNome[] = this.nome.split(" ");
        this.email = vetorNome[0] + "." + vetorNome[vetorNome.length-1] + "@aluno.com";
        this.email = this.email.toLowerCase();
    }

    @Override
    public String toString() {
        return "Aluno [matricula=" + this.matricula + ", nome=" + this.nome + ", email=" + this.email + "]";
    }

    @Override
    public boolean equals(Object obj) {
        Aluno other = (Aluno) obj;
        if (other.email.equals(this.email)) { //email eh pk
            return true;
        }
        return false;
    } 
}

public class ListasDeObjetos {
    public static void main(String[] args) {
        List<Aluno> alunos = new ArrayList<Aluno>();
        Scanner teclado = new Scanner(System.in);
        String nome;
        String opcao;
        int matricula = 1;
        Aluno alunoTmp;
        do {
            System.out.print("Digite nome completo: ");
            nome = teclado.nextLine();
            alunoTmp = new Aluno(matricula, nome);
            if (alunos.contains(alunoTmp)) {
                System.out.println("Aluno ja cadastrado!");
            } else {
                alunos.add(alunoTmp);
                matricula++;
            }
            System.out.print("Deseja continuar? (S/N): ");
            opcao = teclado.nextLine();
            if (opcao.equalsIgnoreCase("N")) {
                break;
            }
        } while (true);    
        
        alunos.sort((a1, a2) -> a1.nome.compareTo(a2.nome));

        for (Aluno aluno : alunos) {
            System.out.println(aluno);
        }
    }
}