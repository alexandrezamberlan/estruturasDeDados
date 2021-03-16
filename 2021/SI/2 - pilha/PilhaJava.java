import java.util.Stack;

public class PilhaJava {
    public static void main(String a[]) {
        Stack<Integer> pilha = new Stack<Integer>();

        pilha.push(120);
        pilha.push(210);
        pilha.push(300);
        System.out.println(pilha.peek());

        pilha.pop();
        pilha.pop();
        System.out.println(pilha.peek());
    }
}
