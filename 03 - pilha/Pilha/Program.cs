//para criar um projeto C# de console
//c:\pastaTrabalho>dotnet new console -n <nomeProjeto>

//para rodar um projeto C# no console
//c:\pastaTrabalho\pastaProjeto>dotnet run

void exibir(Stack<int> pilha)
{
    foreach (var item in pilha)
    {
        Console.WriteLine(item);
    }
}

Stack<int> pilha = new Stack<int>();

pilha.Push(10);
pilha.Push(5);
pilha.Push(15);

exibir(pilha);

//Console.WriteLine(pilha.Peek());


Console.WriteLine(pilha.Contains(6));

Console.WriteLine("o elemento do topo: ", (int)pilha.Pop());
