import java.util.Stack;

public class Pilha1 {
    public static void main(String args[]) {
        Stack pilha = new Stack();

        pilha.push(10); //push equivalente ao add 
        pilha.push(100);
        pilha.push(12);
        pilha.push(15);

        System.out.println(pilha);

        if (pilha.isEmpty()){
            System.out.println("Pilha vazia!!");
        }

        System.out.println("Topo: " + pilha.peek());

        System.out.println("Quantidade de elementos: " + pilha.size());

        System.out.println("O numero 12 esta ou nao na pilha? " + pilha.contains(12));


    }
}