
import java.util.ArrayList;

public class Principal {
    public static void main(String[] args) {
        //ler o arquivo e montar o grafo
        ArrayList<String> vertices = new ArrayList<>();
        ArrayList<String> linhasDoArquivo = new ArrayList<>();
        String nomeArquivo = "C:\\Users\\laboratorio\\Downloads\\mapaCentral.txt";
        
        Grafo.lerArquivo_montarGrafo(nomeArquivo, vertices, linhasDoArquivo);  
        Grafo g = new Grafo(vertices);                
        //montar as conexoes do arquivo - SIMETRICO
        g.montarConexoesSimetricas(linhasDoArquivo);                
        //exibir grafo
        g.mostrarMatriz();
        //g.mostrarGrafo();

        String cidadeO = "AGUDO";
        String cidadeD = "SAO PEDRO";
        System.out.println("\n\nMostrando caminho entre " + cidadeO + " e " + cidadeD);
     
        System.out.println("Profundidade");
        g.temCaminhoProfundidade(cidadeO, cidadeD);
        
        System.out.println("Largura");
        g.temCaminhoLargura(cidadeO, cidadeD);
    }
    
}
