using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lista
{
    internal class Util
    {
        public void popularLista(List<int> lista, int n)
        {
            int valor;
            Random gerador = new Random();
            int i = 0;
            while (i < n)
            {
                valor = gerador.Next(20);
                if (!lista.Contains(valor))
                {
                    lista.Add(valor);
                    lista.Sort();
                    i++;
                }
            }
        }

        public void exibirLista(String frase, List<int> lista)
        {
            Console.WriteLine(frase);

            foreach (var item in lista)
            {
                Console.Write(item + "\t");
            }
            Console.WriteLine();
        }

        

        public void localizarDisjuncao(List<int> lista_resultado, List<int> listaA,
                                                                  List<int> listaB)
        {

            Boolean localizado;
            foreach (var item1 in listaA)
            {
                localizado = false;
                foreach (var item2 in listaB)
                {
                    if (item1 == item2)
                    {
                        localizado = true;
                        break;
                    }
                }
                if (!localizado)
                {
                    lista_resultado.Add(item1);
                }
            }

            foreach (var item2 in listaB)
            {
                localizado = false;
                foreach (var item1 in listaA)
                {
                    if (item1 == item2)
                    {
                        localizado = true;
                        break;
                    }
                }
                if (!localizado)
                {
                    lista_resultado.Add(item2);
                }
            }

            lista_resultado.Sort();
        }
    }
}
