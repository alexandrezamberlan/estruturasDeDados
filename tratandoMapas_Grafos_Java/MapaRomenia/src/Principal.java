
import java.io.FileNotFoundException;
import java.io.FileReader;
import javax.swing.JFileChooser;
import java.util.List;
import java.util.LinkedList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Principal {

    public static void montarTabelaHeuristica(List<Cidade> listaHeuristica) {
        JFileChooser janelaCarregarArquivo = new JFileChooser();
        janelaCarregarArquivo.setMultiSelectionEnabled(false);

        //montar lista ou hash/dicionário com as heurística
        if (janelaCarregarArquivo.showOpenDialog(janelaCarregarArquivo) == JFileChooser.APPROVE_OPTION) {
            try {
                //Arquivo.lerArquivo(janelaCarregarArquivo.getSelectedFile());
                Grafo.criarListaHeuristica(new FileReader(janelaCarregarArquivo.getSelectedFile()), listaHeuristica);
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            }

            System.out.println("Quantidade de cidades/estados: " + listaHeuristica.size());
            for (int i = 0; i < listaHeuristica.size(); i++) {
                System.out.println(listaHeuristica.get(i));
            }
        }
    }
    
    public static void montarMatrizAdjacencia(int matrizAdjacencia[][], List<Cidade> listaHeuristica) {     
        JFileChooser janelaCarregarArquivo = new JFileChooser();
        janelaCarregarArquivo.setMultiSelectionEnabled(false);
        if (janelaCarregarArquivo.showOpenDialog(janelaCarregarArquivo) == JFileChooser.APPROVE_OPTION) {
            try {
                Grafo.preencherMatrizAdjacencia(new FileReader(janelaCarregarArquivo.getSelectedFile()), matrizAdjacencia, listaHeuristica);
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Principal.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println("Matriz de adjacencia");
            Grafo.mostrarMatrizAdjacencia(matrizAdjacencia, listaHeuristica);
        }
    }

    public static void main(String a[]) {

        List<Cidade> listaHeuristica = new LinkedList<>();
        Principal.montarTabelaHeuristica(listaHeuristica);
        
        //definir o tamanho da matriz/grafo
        int matrizAdjacencia[][] = new int[listaHeuristica.size()][listaHeuristica.size()];
        Principal.montarMatrizAdjacencia(matrizAdjacencia, listaHeuristica);

        System.exit(1);
    }
}
