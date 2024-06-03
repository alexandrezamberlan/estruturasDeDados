using System;
using System.Collections.Generic;
using System.IO;

class Util {   
    public static void popularArquivoNoHash(HashSet<Atomo> tabelaHash, string nomeArquivo) {
        try {
            // To read the entire file at once
            if (File.Exists(nomeArquivo)) //o método de classe Exists() é invocado pela classe File
            {
                //le o conteúdo do arquivo linha por linha e armazena em uma lista//hash
                string[] linhas = File.ReadAllLines(nomeArquivo);
                string[] dados;
                for (int i = 0; i < linhas.Length; i++)
                {
                    dados = linhas[i].Split(";"); 
                    Atomo atomo = new Atomo(dados[0], dados[1], dados[2], dados[3]);
                    tabelaHash.Add(atomo);
                 }
            } else {
                Console.WriteLine("Arquivo não localizado");
            }
        } catch(Exception e) {
            Console.WriteLine(e);
        }
    }

    public static void mostrarHash(HashSet<Atomo> tabelaHash){
        foreach (var atomo in tabelaHash) {
            Console.WriteLine(atomo);
        }
    }
}