
public class Cliente {
    public String fone; //55996619445    
    public String nome;
    public int fichaAtendimento;

    public Cliente(String fone, String nome, int ficha){
        this.fone = fone;
        this.nome = nome;
        this.fichaAtendimento = ficha;
    }

    @Override
    public String toString() {
        return "Cliente: " + this.nome + " : " + this.fone + " -> Ficha: " + this.fichaAtendimento + "\n";
    }
}
