using System.Linq;

static void exibir(List<int> lista)
{
    foreach (int item in lista)
    {
        Console.WriteLine(item);
    }
}


List<int> lista = new List<int>();

int valor;
for (int i = 0; i < 4; i++)
{
    Console.Write("Digite um numero inteiro: ");
    valor = int.Parse(Console.ReadLine());
    if (!lista.Contains(valor))
    {
        lista.Add(valor);
        lista.Sort();
    }
}

exibir(lista);