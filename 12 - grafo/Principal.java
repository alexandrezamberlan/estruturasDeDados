import java.util.ArrayList;

class Grafo {
    public int matrizAdjacencia[][];
    public ArrayList<String> vertices;
    public int qtdVertices;
    public int qtdArestas;

    public Grafo(ArrayList<String> vertices) {
        this.vertices = new ArrayList<>();
        this.vertices.addAll(vertices);
        this.qtdVertices = vertices.size();
        this.qtdArestas = 0;
        this.matrizAdjacencia = new int[this.qtdVertices][this.qtdVertices];
        for (int i = 0; i < this.qtdVertices; i++) {
            for (int j = 0; j < this.qtdVertices; j++) {
                this.matrizAdjacencia[i][j] = 0;
            }
        }
    }

    public void inserirArestaSimetrica(String origem, String destino) {        
        int indiceOrigem = this.vertices.indexOf(origem);
        int indiceDestino = this.vertices.indexOf(destino);
        if (origem.equalsIgnoreCase(destino) || indiceOrigem == -1 || indiceDestino == -1) {
            return;
        }

        if (this.matrizAdjacencia[indiceOrigem][indiceDestino] == 0) {
            this.matrizAdjacencia[indiceOrigem][indiceDestino] = 1;
            this.qtdArestas++;
        } if (this.matrizAdjacencia[indiceDestino][indiceOrigem] == 0) {
            this.matrizAdjacencia[indiceDestino][indiceOrigem] = 1;
            this.qtdArestas++;
        }
    }

    public void show() {
        for (int i = 0; i < this.qtdVertices; i++) {
            System.out.print(this.vertices.get(i) + "\t\t\t");
            for (int j = 0; j < this.qtdVertices; j++) {
                if (this.matrizAdjacencia[i][j] != 0) {
                    System.out.print(this.vertices.get(j) + "\t\t\t");
                }
            }
            System.out.println();
        }
    }

    public int mostrarGrau(String cidade) {
        int indice = this.vertices.indexOf(cidade);
        if (indice == -1) return -27;
        int qtd = 0;
        for (int i = 0; i < this.qtdVertices; i++) {
            if (this.matrizAdjacencia[indice][i] != 0) {
                qtd++;
            }
            if (this.matrizAdjacencia[i][indice] != 0) {
                qtd++;
            }
        }
        return qtd;
    }

    
}

public class Principal {
    public static void main(String args[]){
        ArrayList<String> cidades = new ArrayList<>();
        cidades.add("Sao Pedro");
        cidades.add("Santa Maria");
        cidades.add("Agudo");
        cidades.add("Santa Cruz");
        cidades.add("Itaara");
        cidades.add("Sao Martinho");
        cidades.add("Julio de Castilhos");
        cidades.add("Cruz Alta");
        cidades.add("Soledade");
        cidades.add("Lajeado");
        cidades.add("Porto Alegre");

        cidades.sort(null);
        
        Grafo grafo_rs = new Grafo(cidades);
        grafo_rs.inserirArestaSimetrica("Sao Pedro","Santa Maria");
        grafo_rs.inserirArestaSimetrica("Santa Maria","Agudo");
        grafo_rs.inserirArestaSimetrica("Agudo","Santa Cruz");
        grafo_rs.inserirArestaSimetrica("Santa Cruz","Porto Alegre");
        grafo_rs.inserirArestaSimetrica("Porto Alegre","Lajeado");
        grafo_rs.inserirArestaSimetrica("Lajeado","Soledade");
        grafo_rs.inserirArestaSimetrica("Soledade","Cruz Alta");
        grafo_rs.inserirArestaSimetrica("Cruz Alta","Julio de Castilhos");
        grafo_rs.inserirArestaSimetrica("Julio de Castilhos","Itaara");
        grafo_rs.inserirArestaSimetrica("Itaara","Sao Martinho");
        grafo_rs.inserirArestaSimetrica("Itaara","Santa Maria");

        grafo_rs.show();

        String cidade = "Itaara";
        System.out.println("Grau da cidade de " + cidade + ": " + grafo_rs.mostrarGrau(cidade));
    }
}