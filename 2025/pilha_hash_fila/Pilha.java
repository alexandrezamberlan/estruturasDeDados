import java.util.Stack;
import java.util.Scanner;

class Processo {
    int id;
    String descricao;

    public Processo(int id, String descricao) {
        this.id = id;
        this.descricao = descricao;
    }

    @Override
    public String toString() {
        return "Processo [id=" + id + ", descricao=" + descricao + "]";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Processo other = (Processo) obj;
        if (id != other.id)
            return false;
        return true;
    }
}

public class Pilha {
    public static void main(String a[]) {
        Stack<Integer> pilhaInteiros = new Stack<>();

        pilhaInteiros.push(6);
        pilhaInteiros.push(1);
        pilhaInteiros.push(3);

        System.out.println(pilhaInteiros.pop());        

        System.out.println(pilhaInteiros);

        Stack<Processo> pilhaProcessos = new Stack<>();

        //equals é chamado automaticamente pelo contains que algumas vezes é chamado pelo add
        int id = 100;
        String descricao;
        Scanner teclado = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            System.out.print("Descreva o processo: ");
            descricao = teclado.nextLine();
            Processo tmp = new Processo(id, descricao);
            if (!pilhaProcessos.contains(tmp)) {
                pilhaProcessos.push(tmp);
                id++;
            }
        }

        System.out.println("retirando ....." + pilhaProcessos.pop());
        System.out.println("retirando ....." + pilhaProcessos.pop());

        //System.out.println(pilhaProcessos.peek());
        for (Processo p : pilhaProcessos) {
            System.out.println(p);
        }


    }
}