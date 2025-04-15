public class Aluno {
    public int matricula;
    public String nome;
    public String email;

    public Aluno(int matricula, String nome) {
        this.matricula = matricula;
        this.nome = nome;
        this.email = this.gerarEmail();
    }

    public String gerarEmail() {
        String vetorNomes[];
        vetorNomes = this.nome.toLowerCase().split(" ");
        return vetorNomes[0] + "." + vetorNomes[vetorNomes.length - 1] + "@ufn.edu.br";
    }

    @Override
    public String toString() {
        return "Aluno [nome=" + nome + ", email=" + email + "]";
    }

    @Override
    public boolean equals(Object obj) {       
        Aluno aluno = (Aluno) obj;        
        if (this.email.equals(aluno.email))
            return true;
        return false;
    }
    
    
}