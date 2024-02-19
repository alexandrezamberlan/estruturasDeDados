
class Cidade {
    public String nome;
    public int estimativa;

    public Cidade() {
        
    }

    public Cidade(String nome, int estimativa)
    {
        this.nome = nome;
        this.estimativa = estimativa;
    }

    public String toString()
    {
        return "Nome: " + this.nome + ". Custo estimado: " + this.estimativa;
    }
}