import java.util.LinkedList;
import java.util.Scanner;

class Program {
    public static void main(String[] args)  {
        LinkedList<Cidade> listaCidades = new LinkedList<Cidade>();

        System.out.print("\033[H\033[2J");
        System.out.flush();

        Util.montarListaCidades(listaCidades);
        Util.mostrarlistaCidades(listaCidades);

        //definir o tamanho da matriz/grafo
        int matrizAdjacencia[][] = new int[listaCidades.size()][listaCidades.size()];
        Util.montarMatrizAdjacencia(matrizAdjacencia, listaCidades);

        Util.mostrarMatrizAdjacencia(matrizAdjacencia, listaCidades);

        Scanner teclado = new Scanner(System.in);
        String partida, destino;

        System.out.print("Digite cidade de origem: ");
        partida = teclado.nextLine(); 
        System.out.print("Digite cidade de destino: ");
        destino = teclado.nextLine();

        // if (Grafo.temCaminhoAmplitude(partida, destino, listaCidades, matrizAdjacencia)){
        //     System.out.println("Tem caminho entre essas duas cidades");
        // } else {
        //     System.out.println("NÃO tem caminho entre essas duas cidades");
        // }
         Grafo.mostraNodosAmplitude(partida, destino, listaCidades, matrizAdjacencia);
    }
}