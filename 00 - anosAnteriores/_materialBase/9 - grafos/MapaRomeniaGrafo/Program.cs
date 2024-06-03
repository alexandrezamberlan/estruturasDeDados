using System;
using System.Collections.Generic;


namespace MapaRomeniaGrafo
{
    class Program
    {
        public static void Main(string[] args)
        {
            List<Cidade> listaHeuristica = new List<Cidade>();
            Util.montarTabelaHeuristica(listaHeuristica);

            //definir o tamanho da matriz/grafo
            int[,] matrizAdjacencia = new int[listaHeuristica.Count, listaHeuristica.Count];
            Util.montarMatrizAdjacencia(matrizAdjacencia, listaHeuristica);

            Util.mostrarMatrizAdjacencia(matrizAdjacencia, listaHeuristica);

            string partida = "Arad";
            string destino = "Timisoara";

            Console.WriteLine("Custo real entre " + partida + " e " + destino + ": " + matrizAdjacencia[Util.trazerIndice(partida, listaHeuristica), Util.trazerIndice(destino, listaHeuristica)]);

            Console.Write("Digite cidade: ");
            string cidade = Console.ReadLine();
            Console.WriteLine( Util.trazerEstimativa(cidade, listaHeuristica) );           
        }
    }
}
