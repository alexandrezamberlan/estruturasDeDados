import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ListasDeDicionarios {
    public static void main(String[] args) {
        ArrayList<HashMap<String, String>> turmas = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            turmas.add(new HashMap<String, String>());
        }
        
        turmas.get(0).put("Camille", "Estruturas de Dados");
        turmas.get(0).put("Douglas", "Estruturas de Dados");
        turmas.get(0).put("Alex", "Estruturas de Dados");
        turmas.get(0).put("Giu", "Estruturas de Dados");
        turmas.get(0).put("Gustavo", "Estruturas de Dados");
        turmas.get(0).put("Igor", "Estruturas de Dados");
        //turmas.get(0).sort(null);

        turmas.get(1).put("Giu", "Programação");
        turmas.get(1).put("Gustavo", "Programação");
        turmas.get(1).put("Igor", "Programação");
        //turmas.get(1).sort(null);

        turmas.get(2).put("Fares", "Redes");
        turmas.get(2).put("Leonardo", "Redes");
        turmas.get(2).put("Igor", "Redes");
        //turmas.get(2).sort(null);

        for (Map.Entry<String, String> aluno : turmas.get(0).entrySet()) {
            String nome = aluno.getKey();
            String disciplina = aluno.getValue();
            System.out.println("Nome: " + nome + ", Disciplina: " + disciplina);
        }

        for (HashMap<String, String> turma : turmas) {
            for (String aluno : turma.keySet()) {
                System.out.println(aluno + " - " + turma.get(aluno));
            }
            System.out.println("________");
        }

        //System.out.println("Alunos e suas disciplinas");
    }
}
