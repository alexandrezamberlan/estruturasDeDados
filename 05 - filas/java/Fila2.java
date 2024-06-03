import java.util.LinkedList;
import java.util.Queue;

// Estruturas de Dados
//     - físicas: variáveis
//     - abstratas: pilha(stack), lista(list), fila(queue)
//          pilha: push/add/append e pop/remove -> topo
//          lista: add/append, remove, contains, sort -> ordenação e controle de duplicidade
//          fila: add/append (final) e remove (inicio)
// FILA - FIFO - First In, First Out

public class Fila2 {
    public static void main(String[] args) {
        Queue<String> filaNomes = new LinkedList<String>();

        filaNomes.add("Saccol");
        filaNomes.add("Pinheiro");
        filaNomes.add("Iago");

        System.out.println("Exibindo fila");
        System.out.println(filaNomes);

        System.out.println("Exibindo inicio ou cabeça/head da fila");
        System.out.println(filaNomes.peek());

        System.out.println("Exibindo se fila esta vazia");
        System.out.println(filaNomes.isEmpty());

        System.out.println("Exibindo o tamanho da fila");
        System.out.println(filaNomes.size());

        System.out.println("Verificando se IAGO esta na fila");
        System.out.println(filaNomes.contains("IAGO"));
 
        while (!filaNomes.isEmpty()){
            System.out.println("Removendo ..." + filaNomes.poll());
            try {
                Thread.sleep(3000);
            } catch(Exception e){
                System.out.println(e.getMessage());
            }
        }

        System.out.println("Removendo ..." + filaNomes.poll());
    }
}
