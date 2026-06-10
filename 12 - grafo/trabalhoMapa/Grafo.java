import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Grafo {
    int matrizADJ[][];
    int qtdVertices;
    ArrayList<String> listaVertices;

    /**
     * construtor que monta a listaVertices, qtdVertices e matrizADJ a partir da listaVertices
     * @param listaVertices contém os vértices do grafo ou mapa
     */
    public Grafo(ArrayList<String> listaVertices) {
        this.listaVertices = new ArrayList<>();
        this.listaVertices.addAll(listaVertices);
        
        this.qtdVertices = listaVertices.size();
        
        this.matrizADJ = new int[this.qtdVertices][this.qtdVertices];
        for (int i = 0; i < this.qtdVertices; i++) {
            for (int j = 0; j < this.qtdVertices; j++) {
                this.matrizADJ[i][j] = 0;
            }
        }
    }

    /**
     * metodo que insere um arco simétrico entre origem, destino e passando um custo
     * @param origem vertice de partida
     * @param destino vertice de destino
     * @param custo custo real
     */
    void inserirArestaSimetrica(String origem, String destino, int custo) {
        int indiceOrigem = this.listaVertices.indexOf(origem);
        int indiceDestino = this.listaVertices.indexOf(destino);

        if (this.matrizADJ[indiceOrigem][indiceDestino] == 0) {
            this.matrizADJ[indiceOrigem][indiceDestino] = custo;
            this.matrizADJ[indiceDestino][indiceOrigem] = custo;
        } 
    }

    /**
     * metodo que insere um arco assimétrico entre origem, destino e passando um custo
     * @param origem vertice de partida
     * @param destino vertice de destino
     * @param custo custo real
     */
    void inserirAresta(String origem, String destino, int custo) {
        int indiceOrigem = this.listaVertices.indexOf(origem);
        int indiceDestino = this.listaVertices.indexOf(destino);

        if (this.matrizADJ[indiceOrigem][indiceDestino] == 0) {
            this.matrizADJ[indiceOrigem][indiceDestino] = custo;
        } 
    }

    /**
     * metodo que mostra o grafo não grafico com os custos
     */
    void mostrarGrafo() {
        for (int i = 0; i < this.qtdVertices; i++) {
            // Alinha o nome da cidade de origem à esquerda com 20 caracteres de espaço
            System.out.printf("%-20s: ", this.listaVertices.get(i));
            
            for (int j = 0; j < this.qtdVertices; j++) {
                if (this.matrizADJ[i][j] != 0) {
                    // Monta o texto do destino com o peso: "Cidade(10)"
                    String destinoComPeso = this.listaVertices.get(j) + "(" + this.matrizADJ[i][j] + ")";
                    
                    // Exibe o destino alinhado à esquerda ocupando sempre 20 caracteres
                    System.out.printf("%-20s", destinoComPeso);
                }
            }
            System.out.println();
        }
    }

    /**
     * metodo que exibe os vertices do grafo
     * @param frase
     */
    void mostrarVertices(String frase) {
        System.out.println(frase);
        for (String item : this.listaVertices) {
            System.out.println(item);
        }
    }

    /**
     * método privado e recursivo relacionado a técnica de percurso PROFUNDIDADE
     * @param no vértice de trabalho
     * @param destino vértice de chegada
     * @param visitados estrutura de dados que armazena os vértices já visitados
     */
    private void testaCaminhoProfundidade(int no, int destino, ArrayList<String> visitados) {
        System.out.println(this.listaVertices.get(no));
        for (int col = 0; col < this.qtdVertices; col++) {
            if (this.matrizADJ[no][col] != 0 && !visitados.contains(this.listaVertices.get(col))) {
                if (col == destino) {
                    System.out.println(this.listaVertices.get(col));
                    System.exit(1);
                }                
                visitados.add(this.listaVertices.get(col));
                testaCaminhoProfundidade(col, destino, visitados);
            }
        }
    }
    
    /**
     * método com a técnica PROFUNDIDADE que verifica se tem caminho entre dois vértices
     * @param origem vértice de partida
     * @param destino vértice de chegada
     */
    public void temCaminhoProfundidade(String origem, String destino) {       
        int indiceOrigem = this.listaVertices.indexOf(origem);
        int indiceDestino = this.listaVertices.indexOf(destino);       
        ArrayList<String> visitados = new ArrayList<>();
        visitados.add(origem);
        testaCaminhoProfundidade(indiceOrigem, indiceDestino, visitados);
    }
    
    /**
     * método com a técnica LARGURA/AMPLITUDE que verifica se tem caminho entre dois vértices
     * @param origem vértice de partida
     * @param destino vértice de chegada
     */
    public void temCaminhoLargura(String origem, String destino) {
        int indiceOrigem = this.listaVertices.indexOf(origem);
        int indiceDestino = this.listaVertices.indexOf(destino);       
        ArrayList<String> visitados = new ArrayList<>();
        Queue<String> fila = new LinkedList<>();

        visitados.add(origem);
        int no = this.listaVertices.indexOf(origem);
        
        do {
            System.out.println(this.listaVertices.get(no));
            if (this.listaVertices.get(no).equals(destino)) return;
            
            for (int col = 0; col < this.qtdVertices; col++) {
                if (this.matrizADJ[no][col] != 0 && !visitados.contains(this.listaVertices.get(col))){
                    
                    fila.add(this.listaVertices.get(col));
                    
                    visitados.add(this.listaVertices.get(col));
                }
            }
            if (fila.isEmpty()) {
                break;
            }
            no = this.listaVertices.indexOf(fila.poll());
        } while (true);
    }

    /**
     * método de classe que descobre os vértices em um arquivo de mapa
     * @param arquivoMapa contem o grafo em formato csv
     * @param listaVertices lista dos vértices descobertos
     */
    public static void descobrirVertices(String arquivoMapa, ArrayList<String> listaVertices) {
        Path caminho = Paths.get(arquivoMapa);

        try (BufferedReader leitor = Files.newBufferedReader(caminho)) {
            String linha;
            String dados[];
            while ((linha = leitor.readLine()) != null) {
                //dados[0] => origem
                //dados[1] => destino
                //dados[2] => custo
                dados = linha.split(",");
                if (!listaVertices.contains(dados[0])) {
                    listaVertices.add(dados[0]);
                }
                if (!listaVertices.contains(dados[1])) {
                    listaVertices.add(dados[1]);
                }
            }
            listaVertices.sort((null));

        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }
    }

    /**
     * metodo de classe que recebe um arquivo contendo um mapa e monta o grafo e suas arestas com custos
     * @param arquivoMapa contem o mapa
     * @param g contem o grafo vazio
     */
    public static void montarGrafo(String arquivoMapa, Grafo g) {
        Path caminho = Paths.get(arquivoMapa);

        try (BufferedReader leitor = Files.newBufferedReader(caminho)) {
            String linha;
            String dados[];
            while ((linha = leitor.readLine()) != null) {
                //dados[0] => origem
                //dados[1] => destino
                //dados[2] => custo
                dados = linha.split(",");
                g.inserirAresta(dados[0], dados[1], Integer.parseInt(dados[2]));
            }
        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }
    }

}
