import java.util.LinkedList;
import java.util.List;

public class Recursao {


    public static void exibirR(List<Integer> lista, int n) { //A
        if (n > 0) { //B

            System.out.println(lista.get(n - 1));

            exibirR(lista, n - 1); //C -> ponto de recursão
            
        }
    }

    public static void exibirCaracteresR(String frase, int n) { //A
        if (n > 0) { //B

            System.out.print(frase.charAt(n - 1));

            exibirCaracteresR(frase, n - 1); //C -> ponto de recursão
            
        }
    }

    public static void main(String a[]) {
        List<Integer> listaNumeros = new LinkedList<>();

        listaNumeros.add(1);
        listaNumeros.add(2);
        listaNumeros.add(3);
        listaNumeros.add(4);

        exibirR(listaNumeros, listaNumeros.size());   
        
        System.out.println();
        String frase = "Turma de ED com alunos nota 10";
        exibirCaracteresR(frase, frase.length());
    }
}