import java.util.ArrayList;
import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {        
        ArrayList<Aluno> listaAlunos = new ArrayList<Aluno>();
       

        String nome, curso, idade;
        
        Scanner teclado = new Scanner(System.in);
        Aluno obj;
        for (int i = 0; i < 3; i++) {
            System.out.print("Nome: ");
            nome = teclado.nextLine().toUpperCase();            
            System.out.print("Idade: ");
            idade = teclado.nextLine();
            System.out.print("Curso: ");
            curso = teclado.nextLine().toUpperCase();
            obj = new Aluno(nome,Integer.parseInt(idade),curso);
            if (!listaAlunos.contains(obj)) {
                listaAlunos.add(obj);
                listaAlunos.sort((aluno1, aluno2) -> aluno1.getNome().compareTo(aluno2.getNome()));
            } else {
                System.out.println("Aluno ja cadastrado");
            }
        }

        for (Aluno aluno : listaAlunos) {
            System.out.println(aluno);
        }

        

        
    }
}