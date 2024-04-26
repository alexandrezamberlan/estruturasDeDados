import java.util.Random;
import java.util.List;
import java.util.ArrayList;

public class Desafio {
    public static void main(String args[]) {
        ArrayList<List> listaGenerica = new ArrayList<List>();
        
        Random gerador = new Random();

        int tamanhoListaGenerica = 5000;
        int tamanhoListaInterna = 10000;
        int valor;
        for (int i = 0; i < tamanhoListaGenerica; i++) {
            listaGenerica.add( new ArrayList<Integer>() );
            for (int j = 0; j < tamanhoListaInterna; j++) {
                valor = gerador.nextInt(400);
                if (!listaGenerica.get(i).contains(valor)) {
                    listaGenerica.get(i).add(valor);
                    listaGenerica.get(i).sort(null);
                }                    
            }
        }
        
        for (int i = 0; i < listaGenerica.size(); i++) {
            System.out.println("Exibindo a lista " + (i+1));
            for (int j = 0; j < listaGenerica.get(i).size(); j++) {                
                System.out.println(listaGenerica.get(i).get(j));
            }
        }        
    }
}

//listaGenerica[ [1,7,8], [2,7,10], [], [] ,[] ,[], []]