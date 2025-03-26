import java.util.ArrayList;

public class ListasDeListas {
    public static void main(String[] args) {
        ArrayList<ArrayList<String>> turmas = new ArrayList<>();
        //turmas [[camille, douglas, alex, giu, gustavo, igor], [giu, gustavo, igor], [fares, leonardo]]
        //turmas é uma lista em que cada posição é uma lista de strings
        //posiçao 0 - estruturas de dados
        //posiçao 1 - programação
        //posiçao 2 - redes
        for (int i = 0; i < 3; i++) {
            turmas.add(new ArrayList<String>());
        }
        
        turmas.get(0).add("Camille");
        turmas.get(0).add("Douglas");
        turmas.get(0).add("Alex");
        turmas.get(0).add("Giu");
        turmas.get(0).add("Gustavo");
        turmas.get(0).add("Igor");
        turmas.get(0).add("Camille");
        turmas.get(0).sort(null);

        turmas.get(1).add("Giu");
        turmas.get(1).add("Gustavo");
        turmas.get(1).add("Igor");
        turmas.get(1).sort(null);

        turmas.get(2).add("Fares");
        turmas.get(2).add("Leonardo");
        turmas.get(2).add("Igor");
        turmas.get(2).sort(null);

        // for (Object aluno : turmas.get(0)) { //turma de estruturas de dados
        //     System.out.println(aluno);
        // }

        for (ArrayList<String> turma : turmas) {
            for (String aluno : turma) {
                System.out.println(aluno);
            }
            System.out.println("________");
        }

        System.out.println("Alunos e suas disciplinas");
        ArrayList<String> alunosAvaliados = new ArrayList<>();
        String avaliado;
        int contador = 0;

        for (ArrayList<String> turma : turmas) {
            for (String aluno : turma) {
                avaliado = aluno;
                contador = 0;
                if (!alunosAvaliados.contains(avaliado)) {
                    alunosAvaliados.add(avaliado);
                    for (ArrayList<String> turma2 : turmas) {
                        for (String aluno2 : turma2) {
                            if (avaliado.equals(aluno2)) {
                                contador++;
                            }
                        }
                    }
                    System.out.println(avaliado + " - " + contador);
                }
            }
            
        }
    }
}