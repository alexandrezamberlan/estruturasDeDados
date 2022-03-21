import java.util.Stack;
public class Pilha {
    public static void main(String a[]) {
        Stack<Integer> pilha = new Stack<>();

        pilha.push(15);
        pilha.push(20);
        pilha.push(50);
        pilha.push(100);

        pilha.pop();
        pilha.pop();
        
        System.out.println(pilha.peek());
        System.out.println(pilha);

        System.out.println("A pilha contem " + pilha.size() + " elementos\n");

        int descobre = 15;

        System.out.println(descobre + " esta na pilha? " + pilha.indexOf(descobre));
    }
}