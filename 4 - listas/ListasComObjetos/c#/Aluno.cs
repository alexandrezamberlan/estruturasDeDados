
public class Aluno 
{
	public string Nome {get;set;}
	public int Idade {get;set;}
	public string Curso {get;set;}
	
	public Aluno(string nome, int idade, string curso) 
    {
		this.Nome = nome;
		this.Idade = idade;
		this.Curso = curso;
	}
	
    public override string ToString() {
        return "[nome=" + Nome + ", idade=" + Idade + ", curso=" + Curso + "]";
    }  
    
    public override bool Equals(Object obj) {
        Aluno other = (Aluno) obj;
        if (!Nome.Equals(other.Nome))
            return false;
        if (Idade != other.Idade)
            return false;
        return true;
    }

    
}
