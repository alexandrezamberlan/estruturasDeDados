import java.util.Stack;

public class Pilha {
    public static void main(String a[]) {
        Stack<Integer> pilha = new Stack<>();

        pilha.push(10);
        pilha.push(15);
        pilha.push(5);        

        System.out.println(pilha);
        System.out.println(pilha.peek());

        if (pilha.contains(6)) {
            System.out.println("localizado");
        } else {
            System.out.println("nao localizado");
        }

        pilha.pop();
        System.out.println("Pilha alterada\n " + pilha);

        
    }
}