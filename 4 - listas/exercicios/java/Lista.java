import java.util.ArrayList;
import java.util.Collections;

public class Lista {
    public static void main(String args[]) {
        ArrayList<Integer> lista1 = new ArrayList<Integer>();
        ArrayList<Integer> lista2 = new ArrayList<Integer>();
        ArrayList<Integer> listaComuns = new ArrayList<Integer>();
        ArrayList<Integer> listaDisjuncao = new ArrayList<Integer>();

        Util objeto = new Util();

        objeto.popularLista(lista1, 8);
        objeto.popularLista(lista2, 8);

        objeto.exibirLista("Lista 1", lista1);
        objeto.exibirLista("Lista 2", lista2);

        objeto.localizarComuns(listaComuns, lista1,lista2);
        objeto.exibirLista("Números nas duas listas", listaComuns);

        objeto.localizarDisjuncao(listaDisjuncao, lista1,lista2);
        objeto.exibirLista("Números em uma das listas", listaDisjuncao);
    }
}