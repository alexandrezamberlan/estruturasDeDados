import java.util.List;
import java.util.Random;

public class Util {
    public void popularLista(List<Integer> lista, int n) {
        int valor;
        Random gerador = new Random();
        int i = 0;
        while (i < n) {
            valor = gerador.nextInt(100);
            if (!lista.contains(valor)) {
                lista.add(valor);
                lista.sort(null);
                i++;
            }
        }
    }

    public void exibirLista(String frase, List<Integer> lista) {
        System.out.println(frase);

        for (Integer item : lista) {
            System.out.print(item + "\t");
        }
        System.out.println();
    }

    public void localizarComuns(List<Integer> listaResultado, List<Integer> listaA, 
                                                               List<Integer> listaB) {
        for (Integer item1 : listaA) {
            for (Integer item2 : listaB) {
                if (item1 == item2) {
                    listaResultado.add(item1);
                }
            }    
        }
    }

    public void localizarDisjuncao(List<Integer> listaResultado, List<Integer> listaA, 
                                                                  List<Integer> listaB) {

        boolean localizado;
        for (Integer item1 : listaA) {
            localizado = false;
            for (Integer item2 : listaB) {
                if (item1 == item2) {
                    localizado = true;
                    break;
                }
            }    
            if (!localizado) {
                listaResultado.add(item1);
            }
        }
        
        for (Integer item2 : listaB) {
            localizado = false;
            for (Integer item1 : listaA) {
                if (item1 == item2) {
                    localizado = true;
                    break;
                }
            }    
            if (!localizado) {
                listaResultado.add(item2);
            }
        }

        listaResultado.sort(null);
    }
}