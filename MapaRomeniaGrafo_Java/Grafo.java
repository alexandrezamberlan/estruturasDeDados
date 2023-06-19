import java.util.LinkedList;
import java.util.Queue;

public class Grafo {
    public static boolean temCaminhoAmplitude(String origem, String destino, LinkedList<Cidade> lista, int matriz[][]) {
        Queue<Cidade> fila = new LinkedList<Cidade>();
        int visitados[] = new int[lista.size()];
        for (int i = 0; i < visitados.length; i++) {
            visitados[i] = 0;
        }

        int noTrabalho = Util.trazerIndice(origem, lista);       
        int noDestino = Util.trazerIndice(destino, lista);
        visitados[noTrabalho] = 1;
        Cidade cidadeNo = new Cidade();
        try {
            do {
                if (noTrabalho == noDestino) {
                    return true;
                }
                for (int i = 0; i < lista.size(); i++) {                
                    if (matriz[noTrabalho][i] != 0 && visitados[i] == 0) {                        
                        visitados[i] = 1;
                        fila.add(lista.get(i));
                    }
                }                
                cidadeNo = fila.remove();
                noTrabalho = Util.trazerIndice(cidadeNo.nome, lista);        
            } while (cidadeNo != null);
        } catch (Exception e) {
            System.out.println("Falha na fila");
        }
        return false;
    }

    public static void mostraNodosAmplitude(String origem, String destino, LinkedList<Cidade> lista, int matriz[][]) {
        Queue<Cidade> fila = new LinkedList<Cidade>();
        int visitados[] = new int[lista.size()];
        for (int i = 0; i < visitados.length; i++) {
            visitados[i] = 0;
        }

        int noTrabalho = Util.trazerIndice(origem, lista);       
        int noDestino = Util.trazerIndice(destino, lista);
        visitados[noTrabalho] = 1;
        Cidade cidadeNo = new Cidade();
        try {
            do {
                System.out.print(lista.get(noTrabalho).nome + "\t");
                if (noDestino == noTrabalho) return;
                for (int i = 0; i < lista.size(); i++) {                
                    if (matriz[noTrabalho][i] != 0 && visitados[i] == 0) {                        
                        visitados[i] = 1;
                        fila.add(lista.get(i));
                    }
                }                
                cidadeNo = fila.remove();
                noTrabalho = Util.trazerIndice(cidadeNo.nome, lista);        
            } while (cidadeNo != null);
        } catch (Exception e) {
            System.out.println("Falha na fila");
        }
        System.out.println();
    }
}
