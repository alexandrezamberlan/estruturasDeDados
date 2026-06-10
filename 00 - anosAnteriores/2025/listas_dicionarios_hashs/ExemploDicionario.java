import java.util.HashMap;
import java.util.Map;

public class ExemploDicionario {
    public static void main(String[] args) {
        // Criando um dicionário (HashMap)
        Map<Integer, Integer> ocorrencias = new HashMap<>();
        ocorrencias.put(98, 2);
        ocorrencias.put(100, 3);
        ocorrencias.put(105, 5);
        if (ocorrencias.containsKey(98)) {
            System.out.println("Chave 98 existe no dicionário");
        }
        // Percorrendo as chaves e valores com for-each
        for (Map.Entry<Integer, Integer> entrada : ocorrencias.entrySet()) {
            Integer chave = entrada.getKey(); //valor glicemico
            Integer valor = entrada.getValue(); //vezes que apareceu
            System.out.println("Chave: " + chave + ", Valor: " + valor);
        }
    }
}