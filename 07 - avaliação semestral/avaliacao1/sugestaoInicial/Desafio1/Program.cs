using System.Collections.Generic;



public class Desafio1
{
    public static void Main(string[] args)
    {
        List<List<int>> listaGenerica = new List<List<int>>();

        Random gerador = new Random();

        int tamanhoListaGenerica = 10;
        int tamanhoListaInterna = 20;
        int valor;
        for (int i = 0; i < tamanhoListaGenerica; i++)
        {
            listaGenerica.Add(new List<int>());
            for (int j = 0; j < tamanhoListaInterna; j++)
            {
                valor = gerador.Next(0,400);
                if (!listaGenerica[i].Contains(valor))
                {
                    listaGenerica[i].Add(valor);
                    listaGenerica[i].Sort();
                }
            }
        }

        int k = 1;
        foreach (var umaLista in listaGenerica)
        {
            Console.WriteLine("Exibindo a lista " + k);
            foreach (var umNumero in umaLista)
            {
                Console.WriteLine(umNumero);
            }
            k++;
        }

        //for (int i = 0; i < listaGenerica.size(); i++)
        //{
        //    System.out.println("Exibindo a lista " + (i + 1));
        //    for (int j = 0; j < listaGenerica.get(i).size(); j++)
        //    {
        //        System.out.println(listaGenerica.get(i).get(j));
        //    }
        //}
    }
}

//listaGenerica[ [1,7,8], [2,7,10], [], [] ,[] ,[], []]