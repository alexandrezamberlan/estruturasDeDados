import java.util.LinkedList;
import java.util.Random;

public class Lista {
    public static void main(String args[]) {
        LinkedList<Integer> lista = new LinkedList<Integer>();

        Random gerador = new Random();
        for (int i = 0; i < 500000; i++) {
            lista.add(gerador.nextInt(100));
        }
        lista.sort(null);
        System.out.println("Ordenação terminada....");
    }
}