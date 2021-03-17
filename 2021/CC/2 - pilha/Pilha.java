import java.util.Stack;

// package 2021.CC.2 - pilha;

public class Pilha {
    public static void main(String args[]) {
        Stack<Integer> pilha = new Stack<>();
        // na pilha as operações são:
        // inserir -> push() ou add()
        // remover -> pop()
        // ver o topo -> peek()
        // ver se esta vazia -> isEmpty() 
        pilha.push(4);
        pilha.push(2);
        pilha.push(10);
        pilha.push(3);

        System.out.println("Valor do topo é: " + pilha.peek());
    }
}
