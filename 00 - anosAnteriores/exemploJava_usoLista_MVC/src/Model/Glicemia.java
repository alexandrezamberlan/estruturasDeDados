package Model;

/**
 * Classe que guarda dados de glicemia de um paciente diabetico
 * @author laboratorio
 */
public class Glicemia {
    int valorGlicemia;
    String momento; //ac ou dc
    String data;
    String hora;
    
    /**
     * Construtor vazio
     */
    public Glicemia() {}

    /**
     * Método construtor para instanciar um objeto glicemia com todos os seus atributos
     * @param valorGlicemia
     * @param momento
     * @param data
     * @param hora 
     */
    public Glicemia(int valorGlicemia, String momento, String data, String hora) {
        this.valorGlicemia = valorGlicemia;
        this.momento = momento;
        this.data = data;
        this.hora = hora;
    }

    /**
     * Getter do valorGlicemia
     * @return o valor da glicemia de um determinado instante
     */
    public int getValorGlicemia() {
        return valorGlicemia;
    }

    /**
     * Método que define um valor de glicemia
     * @param valorGlicemia 
     */
    public void setValorGlicemia(int valorGlicemia) {
        this.valorGlicemia = valorGlicemia;
    }

    /**
     * 
     * @return 
     */
    public String getMomento() {
        return momento;
    }

    
    public void setMomento(String momento) {
        this.momento = momento;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public String getHora() {
        return hora;
    }

    public void setHora(String hora) {
        this.hora = hora;
    }

    @Override
    public String toString() {
        return "Glicemia{" + "valorGlicemia=" + valorGlicemia + ", momento=" + momento + ", data=" + data + ", hora=" + hora + '}';
    }
    
    
    
    
}
