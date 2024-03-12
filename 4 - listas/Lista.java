import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Lista {
    public static void main(String a[]) {
        List<Integer> lista = new ArrayList<Integer>();
        Scanner teclado = new Scanner(System.in);
        int valor;
        for (int i = 0; i < 4; i++) {
            System.out.print("Digite um numero inteiro: ");
            valor = teclado.nextInt();
            if (!lista.contains(valor)) {
                lista.add(valor);
                lista.sort(null);
            }
        }
        System.out.println(lista);
    }
}