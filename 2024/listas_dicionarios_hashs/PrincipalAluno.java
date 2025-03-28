import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PrincipalAluno {
    public static void main(String[] args) {
        List<Aluno> alunos = new ArrayList<>();
        Aluno tmp;
        String nome;
        int matricula = 1;
        String opcao;
        Scanner teclado = new Scanner(System.in);

        while (true) {
            System.out.print("Digite nome: ");
            nome = teclado.nextLine().toUpperCase();
            tmp = new Aluno(matricula, nome);
            if (alunos.contains(tmp)) {
                System.out.println("Aluno com este email ja cadastrado!");
                System.gc();
            } else {
                alunos.add(tmp);
                System.out.println("Aluno cadastrado com a matricula de numero " + matricula);
                System.out.println("E com o email " + tmp.email);
                matricula++;
            }
            System.out.print("Continua? [1-Sim; Outra tecla-Nao]");
            opcao = teclado.nextLine();
            if (!opcao.equals("1"))
                break;
        }    
        
        alunos.sort((aluno1, aluno2) -> aluno1.nome.compareTo(aluno2.nome));

        System.out.println("Relacao alunos");
        for (Aluno aluno : alunos) {
            System.out.println(aluno);
        }
    }
}
