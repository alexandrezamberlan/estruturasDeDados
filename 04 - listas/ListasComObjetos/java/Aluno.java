
public class Aluno {
	String nome;
	int idade;
	String curso;
	
	public Aluno(String nome, int idade, String curso) {
		this.nome = nome;
		this.idade = idade;
		this.curso = curso;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public int getIdade() {
		return idade;
	}
	
	public void setIdade(int idade) {
		this.idade = idade;
	}
	
	public String getCurso() {
		return curso;
	}
	
	public void setCurso(String curso) {
		this.curso = curso;
	}

    @Override
    public String toString() {
        return "[nome=" + nome + ", idade=" + idade + ", curso=" + curso + "]";
    }  

    @Override
    public boolean equals(Object obj) {
        Aluno other = (Aluno) obj;
        if (!nome.equals(other.nome))
            return false;
        if (idade != other.idade)
            return false;
        return true;
    }

    
}
