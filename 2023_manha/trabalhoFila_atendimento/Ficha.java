import java.time.LocalDateTime;    
import java.time.format.DateTimeFormatter; 

public class Ficha {
    private int conteudo;
    private String dataHora;
    
    public Ficha(int conteudo) {
        this.conteudo = conteudo;
        DateTimeFormatter dh = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");  
        LocalDateTime now = LocalDateTime.now();  
        this.dataHora = dh.format(now); 
    }
    
    public int getConteudo() {
        return this.conteudo;
    }

    public String getDataHora() {
        return dataHora;
    }


    


}
