import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.ArrayList;

public class Lista {

    public static void exibir(List<Integer> lista) {
        for (Integer item : lista) {
            System.out.println(item);
        }
    }
    public static void main(String a[]) {
        List<Integer> lista = new ArrayList<Integer>();
        //Scanner teclado = new Scanner(System.in);
        Random gerador = new Random();
        int valor;
        for (int i = 0; i < 100; i++) {
            //System.out.print("Digite um numero inteiro: ");
            //valor = teclado.nextInt();
            valor = gerador.nextInt(400);
            if (!lista.contains(valor)) {
                lista.add(valor);
                lista.sort(null);
            }
        }
        System.out.println("Tamanho da lista " + lista.size());
        exibir(lista);
    }
}