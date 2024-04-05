using System;

List<Aluno> listaAlunos = new List<Aluno>();
      
string nome, curso, idade;

Aluno obj;
for (int i = 0; i < 3; i++) 
{
    Console.Write("Nome: ");
    nome = Console.ReadLine();            
    Console.Write("Idade: ");
    idade = Console.ReadLine();
    Console.Write("Curso: ");
    curso = Console.ReadLine();
    obj = new Aluno(nome,int.Parse(idade),curso);
    if (!listaAlunos.Contains(obj)) {
        listaAlunos.Add(obj);
        listaAlunos.Sort((aluno1, aluno2) => aluno1.Nome.CompareTo(aluno2.Nome));
    } else {
        Console.WriteLine("Aluno ja cadastrado");
    }
}

foreach (var aluno in listaAlunos)
{
    Console.WriteLine(aluno);
} 
