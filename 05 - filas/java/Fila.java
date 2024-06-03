import java.util.LinkedList;
import java.util.Queue;

// Estruturas de Dados
//     - físicas: variáveis
//     - abstratas: pilha(stack), lista(list), fila(queue)
//          pilha: push/add/append e pop/remove -> topo
//          lista: add/append, remove, contains, sort -> ordenação e controle de duplicidade
//          fila: add/append (final) e remove (inicio)
// FILA - FIFO - First In, First Out

public class Fila {
    public static void main(String[] args) {
        Queue<Integer> filaNumeros = new LinkedList<Integer>();

        filaNumeros.add(50);
        filaNumeros.add(5);
        filaNumeros.add(15);

        System.out.println("Exibindo fila");
        System.out.println(filaNumeros);

        System.out.println("Exibindo inicio ou cabeça/head da fila");
        System.out.println(filaNumeros.peek());

        System.out.println("Exibindo se fila esta ou nao vazia");
        System.out.println(filaNumeros.isEmpty());

        System.out.println("Exibindo o tamanho da fila");
        System.out.println(filaNumeros.size());

        System.out.println("Verificando se 5 esta ou nao na fila");
        System.out.println(filaNumeros.contains(5));
    }
}
