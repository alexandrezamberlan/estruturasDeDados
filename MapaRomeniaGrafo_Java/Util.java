import java.util.LinkedList;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;

class Util
{
    public static void montarTabelaHeuristica(LinkedList<Cidade> listaHeuristica) {
        //abrir o arquivo de heuristicas
        try {
            String nomeArquivo = "heuristicasRomenia.map";        
            File file = new File(nomeArquivo);
            
            String linha="";
            Scanner leitor = new Scanner(file);
            String dadosLinha[];
    
            while (leitor.hasNextLine()) {
                linha = leitor.nextLine();
                dadosLinha = linha.split("@");
                listaHeuristica.add(new Cidade(dadosLinha[0], Integer.parseInt(dadosLinha[1])));
            }                 
            leitor.close();
        } catch (Exception e) {
            System.out.println("Problemas para tratar o arquivo!!");
        }        
    }

    public static void mostrarListaHeuristica(LinkedList<Cidade> listaHeuristica) {
        for (Cidade cidade : listaHeuristica) {
            System.out.println(cidade);
        }
    }

    public static int trazerEstimativa(String cidade, LinkedList<Cidade> listaHeuristica) {
        for (int i = 0; i < listaHeuristica.size(); i++) {
            if (listaHeuristica.get(i).nome.toUpperCase().equals(cidade.toUpperCase())) {
                return listaHeuristica.get(i).estimativa;
            }
        }
        return -1;
    }

    public static int trazerIndice(String cidade, LinkedList<Cidade> listaHeuristica) {
        for (int i = 0; i < listaHeuristica.size(); i++)         {
            if (listaHeuristica.get(i).nome.toUpperCase().equals(cidade.toUpperCase()))
            {
                return i;
            }
        }
        return -1;
    }

    public static void inicializarMatriz(int matrizAdjacencia[][], LinkedList<Cidade> listaHeuristica) {
        for (int i = 0; i < listaHeuristica.size(); i++) {
            for (int j = 0; j < listaHeuristica.size(); j++) {
                matrizAdjacencia[i][j] = 0;
            }
        }
    }

    public static void montarMatrizAdjacencia(int matrizAdjacencia[][], LinkedList<Cidade> listaHeuristica) {
        //abrir o arquivo do mapa
        String nomeArquivo = "mapaRomenia.map";
        try {            
            File file = new File(nomeArquivo);
            String linha="";
            Scanner leitor = new Scanner(file);
            String dadosLinha[];

            Util.inicializarMatriz(matrizAdjacencia, listaHeuristica);
    
            while (leitor.hasNextLine()) {
                linha = leitor.nextLine();
                dadosLinha = linha.split("@");
                int indiceOrigem = Util.trazerIndice(dadosLinha[0], listaHeuristica);
                int indiceDestino = Util.trazerIndice(dadosLinha[1], listaHeuristica);
                matrizAdjacencia[indiceOrigem][indiceDestino] = Integer.parseInt(dadosLinha[2]);
            }                 
            leitor.close();
        } catch (Exception e) {
            System.out.println("Problemas para tratar o arquivo!!");
        }   
    }

    public static void mostrarMatrizAdjacencia(int matrizAdjacencia[][], LinkedList<Cidade> listaHeuristica) {
        for (Cidade cidade : listaHeuristica) {
            System.out.print("   " + cidade.nome.charAt(0) + "\t");
        }
        System.out.println();
        
        for (int i = 0; i < listaHeuristica.size(); i++) {
            System.out.print(listaHeuristica.get(i).nome.charAt(0));
            for (int j = 0; j < listaHeuristica.size(); j++)
            {
                System.out.print("   " + matrizAdjacencia[i][j] + "\t");
            }
            System.out.println();
        }
    }
}