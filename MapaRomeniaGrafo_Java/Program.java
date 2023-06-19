import java.util.LinkedList;
import java.util.Scanner;

class Program {
    public static void main(String[] args)  {
        LinkedList<Cidade> listaHeuristica = new LinkedList<Cidade>();

        System.out.print("\033[H\033[2J");
        System.out.flush();

        Util.montarTabelaHeuristica(listaHeuristica);
        //Util.mostrarListaHeuristica(listaHeuristica);

        //definir o tamanho da matriz/grafo
        int matrizAdjacencia[][] = new int[listaHeuristica.size()][listaHeuristica.size()];
        Util.montarMatrizAdjacencia(matrizAdjacencia, listaHeuristica);

        // Util.mostrarMatrizAdjacencia(matrizAdjacencia, listaHeuristica);

        Scanner teclado = new Scanner(System.in);
        String partida, destino;

        // System.out.print("Digite cidade de origem: ");
        // partida = teclado.nextLine(); 
        // System.out.print("Digite cidade de destino: ");
        // destino = teclado.nextLine();

        // System.out.println("Custo real entre " + partida + " e " + destino + ": " + matrizAdjacencia[Util.trazerIndice(partida, listaHeuristica)][Util.trazerIndice(destino, listaHeuristica)]);


        System.out.print("Digite cidade de origem: ");
        partida = teclado.nextLine(); 
        System.out.print("Digite cidade de destino: ");
        destino = teclado.nextLine();

        if (Grafo.temCaminhoAmplitude(partida, destino, listaHeuristica, matrizAdjacencia)){
            System.out.println("Tem caminho entre essas duas cidades");
        } else {
            System.out.println("NÃO tem caminho entre essas duas cidades");
        }
        Grafo.mostraNodosAmplitude(partida, destino, listaHeuristica, matrizAdjacencia);
    }
}