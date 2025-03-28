public class Aluno 
{
    public int Matricula;
    public String Nome;
    public String Email;

    public Aluno(int matricula, String nome) 
    {
        this.Matricula = matricula;
        this.Nome = nome;
        this.Email = this.gerarEmail();
    }

    public String gerarEmail() 
    {
        string []vetorNomes;
        vetorNomes = this.Nome.ToLower().Split(" ");
        return vetorNomes[0] + "." + vetorNomes[vetorNomes.Count() - 1] + "@ufn.edu.br";
    }

    public override string ToString()
    {
        return "Aluno [nome=" + Nome + ", email=" + Email + "]";
    }

    public override bool Equals(object obj)
    {
        if (obj == null || !(obj is Aluno))
        {
            return false;
        }
        Aluno aluno = (Aluno)obj;
        return this.Email.Equals(aluno.Email);
    }
}