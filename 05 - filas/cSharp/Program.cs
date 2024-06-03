using Fila;
using System.Linq;


Queue<Aluno> filaAlunos = new Queue<Aluno>();

filaAlunos.Enqueue(new Aluno(1, "Saccol"));
filaAlunos.Enqueue(new Aluno(7, "Pinheiro"));
filaAlunos.Enqueue(new Aluno(2, "Iago"));

int matricula;
string nome;
for (int i = 0; i < 2; i++)
{
    Console.Write("Matricula: ");
    matricula = int.Parse( Console.ReadLine() );
    
    Console.Write("Nome: ");
    nome = Console.ReadLine();
    filaAlunos.Enqueue(new Aluno(matricula, nome));
}
 
Console.WriteLine("Exibindo fila");
foreach (var item in filaAlunos)
{
  Console.WriteLine(item);
}

Console.WriteLine("Exibindo inicio ou cabeça/head da fila");
Console.WriteLine(filaAlunos.Peek());

Console.WriteLine("Exibindo se fila esta vazia");
Console.WriteLine(filaAlunos.Count()==0);

Console.WriteLine("Exibindo o tamanho da fila");
Console.WriteLine(filaAlunos.Count());

Console.WriteLine("Verificando se 2,Iago esta na fila");
Aluno a = new Aluno(2, "Iago");
Console.WriteLine(filaAlunos.Contains(a));

while (filaAlunos.Count() != 0)
{
    Console.WriteLine("Removendo ..." + filaAlunos.Dequeue());
    try
    {
        Thread.Sleep(3000);
    }
    catch (Exception e)
    {
        Console.WriteLine(e.Message);
    }
}

if (filaAlunos.Count() > 0) Console.WriteLine("Removendo ..." + filaAlunos.Dequeue());



//Queue<string> filaNomes = new Queue<string>();

//filaNomes.Enqueue("Saccol");
//filaNomes.Enqueue("Pinheiro");
//filaNomes.Enqueue("Iago");

//Console.WriteLine("Exibindo fila");
//foreach (var item in filaNomes)
//{
//    Console.WriteLine(item);
//}

//Console.WriteLine("Exibindo inicio ou cabeça/head da fila");
//Console.WriteLine(filaNomes.Peek());

//Console.WriteLine("Exibindo se fila esta vazia");
//Console.WriteLine(filaNomes.Count()==0);

//Console.WriteLine("Exibindo o tamanho da fila");
//Console.WriteLine(filaNomes.Count());

//Console.WriteLine("Verificando se IAGO esta na fila");
//Console.WriteLine(filaNomes.Contains("Iago"));

//while (filaNomes.Count() != 0)
//{
//    Console.WriteLine("Removendo ..." + filaNomes.Dequeue());
//    try
//    {
//        Thread.Sleep(3000);
//    }
//    catch (Exception e)
//    {
//        Console.WriteLine(e.Message);
//    }
//}

//if (filaNomes.Count() != 0) Console.WriteLine("Removendo ..." + filaNomes.Dequeue());




//Queue<int> filaNumeros = new Queue<int>();

//filaNumeros.Enqueue(50);
//filaNumeros.Enqueue(5);
//filaNumeros.Enqueue(15);

//Console.WriteLine("Exibindo fila");
//foreach (var item in filaNumeros)
//{
//    Console.WriteLine(item);
//}

//Console.WriteLine("Exibindo inicio ou cabeça/head da fila");
//Console.WriteLine(filaNumeros.Peek());

//Console.WriteLine("Exibindo se fila esta ou nao vazia");
//Console.WriteLine(filaNumeros.Count()==0);

//Console.WriteLine("Exibindo o tamanho da fila");
//Console.WriteLine(filaNumeros.Count());

//Console.WriteLine("Verificando se 5 esta ou nao na fila");
//Console.WriteLine(filaNumeros.Contains(5));

