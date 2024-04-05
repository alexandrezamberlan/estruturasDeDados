using System;

static void exibir(List<int> lista)
{
    foreach (int item in lista)
    {
        Console.WriteLine(item);
    }
}

List<int> lista = new List<int>();
Random gerador = new Random();
int valor;
for (int i = 0; i < 100; i++)
{
    // Console.Write("Digite um numero inteiro: ");
    // valor = int.Parse(Console.ReadLine());
    valor = gerador.Next(400);
    if (!lista.Contains(valor))
    {
        lista.Add(valor);
        lista.Sort();
    }
}

Console.WriteLine("Tamanho da lista " + lista.Count);
exibir(lista);