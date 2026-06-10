List<Aluno> alunos = new List<Aluno>();
Aluno tmp;
string nome;
int matricula = 1;
string opcao;

while (true) {
    Console.Write("Digite nome: ");
    nome = Console.ReadLine().ToUpper();
    tmp = new Aluno(matricula, nome);
    if (alunos.Contains(tmp)) {
        Console.WriteLine("Aluno com este email ja cadastrado!");
        // System.gc();
    } else {
        alunos.Add(tmp);
        Console.WriteLine("Aluno cadastrado com a matricula de numero " + matricula);
        Console.WriteLine("E com o email " + tmp.Email);
        matricula++;
    }
    Console.Write("Continua? [1-Sim; Outra tecla-Nao]");
    opcao = Console.ReadLine();
    if (opcao != "1")
        break;
}    

alunos.Sort((aluno1, aluno2) => aluno1.Nome.CompareTo(aluno2.Nome));

Console.WriteLine("Relacao alunos");
foreach (Aluno aluno in alunos) {
    Console.WriteLine(aluno);
}