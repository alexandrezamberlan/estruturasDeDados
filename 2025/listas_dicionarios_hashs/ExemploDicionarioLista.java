import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

public class ExemploDicionarioLista {
    public static void main(String[] args) {
        ArrayList<Integer> glicemias = new ArrayList<>();
        Random gerador = new Random();
        for (int i = 0; i < 2000; i++) {
            glicemias.add(gerador.nextInt(45, 100));
        }

        int valorAnalisado;
        int contador;
        ArrayList<Integer> analisados = new ArrayList<>();
        Map<Integer, Integer> ocorrencias = new HashMap<>();
        for (Integer glicemia : glicemias) {
            valorAnalisado = glicemia;
            contador = 0;
            if (!analisados.contains(valorAnalisado)) {
                for (Integer glicemia2 : glicemias) {
                    if (glicemia2 == valorAnalisado) {
                        contador++;
                    }
                }
                analisados.add(valorAnalisado);
                ocorrencias.put(valorAnalisado, contador);
            }
        }

        // Convertendo para uma lista de entradas (pares chave-valor)
        List<Map.Entry<Integer, Integer>> lista = new ArrayList<>(ocorrencias.entrySet());

        // Ordenando a lista pelos valores (decrescente)
        lista.sort((e1, e2) -> e2.getValue().compareTo(e1.getValue()));

        // Criando um LinkedHashMap para manter a ordem ordenada
        Map<Integer, Integer> dicionarioOrdenado = new LinkedHashMap<>();
        for (Map.Entry<Integer, Integer> entrada : lista) {
            dicionarioOrdenado.put(entrada.getKey(), entrada.getValue());
        }

        // Exibindo o dicionário ordenado por valor (decrescente)
        for (Map.Entry<Integer, Integer> entrada : dicionarioOrdenado.entrySet()) {
            System.out.println("Chave: " + entrada.getKey() + ", Valor: " + entrada.getValue());
        }
    }
}
