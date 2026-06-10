import java.util.ArrayList;

public class Principal {
    
    public static void main(String[] args) {
        ArrayList<String> listaVertices = new ArrayList<>();
        String arquivoMapa = "./mapa.csv";

        Grafo.descobrirVertices(arquivoMapa, listaVertices);

        Grafo g = new Grafo(listaVertices);

        // g.mostrarVertices("Lista de cidades...");
        
        System.out.println("Grafo.....");

        Grafo.montarGrafo(arquivoMapa, g);

        g.mostrarGrafo();
    }
}

