import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

class Processo {
    int id;
    String descricao;

    public Processo(int id, String descricao) {
        this.id = id;
        this.descricao = descricao;
    }

    @Override
    public String toString() {
        return "Processo [id=" + id + ", descricao=" + descricao + "]";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Processo other = (Processo) obj;
        if (id != other.id)
            return false;
        return true;
    }
}

public class Fila {
    public static void main(String[] args) {
        Queue<Processo> filaNormal = new LinkedList<>();
        Queue<Processo> filaUrgente = new LinkedList<>();

        //0 a 99 - processos urgentes - inserir na fila de urgentes
        //100 a 199 - processos normais - inserir na fila de normais
        //0 - remove cabeca fila urgente
        //100 - remove cabeca fila normal 
        Random gerador = new Random();
        int numeroProcesso;
        Processo processoAtendido;
        for (int i = 0; i < 1000; i++) {
            numeroProcesso = gerador.nextInt(200);
            if (numeroProcesso == 0){
                if (!filaUrgente.isEmpty()) {
                    processoAtendido = filaUrgente.poll();
                    System.out.println("ATENÇÃO...Processo urgente atendido: " + processoAtendido.id);
                }                 
            } else if (numeroProcesso == 100) {
                if (!filaNormal.isEmpty()) {
                    processoAtendido = filaNormal.poll();
                    System.out.println("ATENÇÃO...Processo normal atendido: " + processoAtendido.id);
                }
            } else if (numeroProcesso > 0 && numeroProcesso < 100) {
                Processo tmp = new Processo(numeroProcesso,"processo urgente");
                if (!filaUrgente.contains(tmp)){
                    System.out.println("Processo urgente inserido..." + tmp.id);
                    filaUrgente.add(tmp);
                }
            } else {
                Processo tmp = new Processo(numeroProcesso,"processo normal");
                if (!filaNormal.contains(tmp)) {
                    System.out.println("Processo normal inserido..." + tmp.id);
                    filaNormal.add(tmp);
                }
            }
        }

        System.out.println("Processos urgentes não atendidos..." + filaUrgente.size());
        for (Processo p : filaUrgente) {
            System.out.println(p);
        }

        System.out.println("Processos normais não atendidos..." + filaNormal.size());
        for (Processo p : filaNormal) {
            System.out.println(p);
        }


    }
}
