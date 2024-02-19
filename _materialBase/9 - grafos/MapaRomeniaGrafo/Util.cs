using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapaRomeniaGrafo
{
    class Util
    {
        public static void montarTabelaHeuristica(List<Cidade> listaHeuristica)
        {
            //abrir o arquivo de heuristicas
            string nomeArquivo = "..\\..\\..\\heuristicasRomenia.map";

            if (File.Exists(nomeArquivo))
            {
                Console.WriteLine("Arquivo de heuristica localizado e aberto com sucesso");
                string[] linhas = File.ReadAllLines(nomeArquivo);
                string[] dados;
                for (int i = 0; i < linhas.Length; i++)
                {
                    dados = linhas[i].Split("@"); //método de instância que divide uma string em um vetor por algum critério
                    //Console.WriteLine(dados[0] + " - " + dados[1]);
                    listaHeuristica.Add(new Cidade(dados[0], Int32.Parse(dados[1])));
                }
            }
            else
            {
                Console.WriteLine("Arquivo não localizado! Rever caminho!");
                Environment.Exit(1);
            }
        }

        public static int trazerEstimativa(string cidade, List<Cidade> listaHeuristica)
        {
            for (int i = 0; i < listaHeuristica.Count; i++)
            {
                if (listaHeuristica[i].nome.ToUpper().Equals(cidade.ToUpper()))
                {
                    return listaHeuristica[i].estimativa;
                }
            }
            return -1;
        }

        public static int trazerIndice(string cidade, List<Cidade> listaHeuristica)
        {
            for (int i = 0; i < listaHeuristica.Count; i++)
            {
                if (listaHeuristica[i].nome.ToUpper().Equals(cidade.ToUpper()))
                {
                    return i;
                }
            }
            return -1;
        }

        public static void inicializarMatriz(int[,] matrizAdjacencia, List<Cidade> listaHeuristica)
        {
            for (int i = 0; i < listaHeuristica.Count; i++)
            {
                for (int j = 0; j < listaHeuristica.Count; j++)
                {
                    matrizAdjacencia[i, j] = 0;
                }
            }
        }

        public static void montarMatrizAdjacencia(int[,] matrizAdjacencia, List<Cidade> listaHeuristica)
        {
            //abrir o arquivo do mapa
            string nomeArquivo = "..\\..\\..\\mapaRomenia.map";

            if (File.Exists(nomeArquivo))
            {
                Console.WriteLine("Arquivo do mapa localizado e aberto com sucesso");
                Util.inicializarMatriz(matrizAdjacencia, listaHeuristica);
                string[] linhas = File.ReadAllLines(nomeArquivo);
                string[] dados;
                for (int i = 0; i < linhas.Length; i++)
                {
                    dados = linhas[i].Split("@"); //método de instância que divide uma string em um vetor por algum critério
                    //Console.WriteLine(dados[0] + " vai para " + dados[1] + " com custo de " + dados[2]);
                    int indiceOrigem = Util.trazerIndice(dados[0], listaHeuristica);
                    int indiceDestino = Util.trazerIndice(dados[1], listaHeuristica);
                    matrizAdjacencia[indiceOrigem, indiceDestino] = Int32.Parse(dados[2]);
                }
            }
            else
            {
                Console.WriteLine("Arquivo não localizado! Rever caminho!");
                Environment.Exit(1);
            }
        }

        public static void mostrarMatrizAdjacencia(int[,] matrizAdjacencia, List<Cidade> listaHeuristica)
        {
            foreach (var cidade in listaHeuristica)
            {
                Console.Write("   " + cidade.nome[0] + "\t");
            }
            Console.WriteLine();
            
            for (int i = 0; i < listaHeuristica.Count; i++)
            {
                Console.Write(listaHeuristica[i].nome[0]);
                for (int j = 0; j < listaHeuristica.Count; j++)
                {
                    Console.Write("   " + matrizAdjacencia[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }
    }
}
