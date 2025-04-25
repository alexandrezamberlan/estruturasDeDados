import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class Principal {

	/***
	 * método estático ou de classe responsável por gerar processos aleatórios entre 1 a 1000
	 * distribuindo em duas filas
	 * @param filaPrioritaria - fila prioritaria (números abaixo de 500)
	 * @param filaNormal - fila normal (números acima de 500)
	 * @param quantidadeProcessos - total de processos a serem simulados
	 */
	public static void gerarProcessosEmFilas(Queue<Processo> filaPrioritaria, Queue<Processo> filaNormal, int quantidadeProcessos) {
		Random gerador = new Random();		
		int numeroProcessoGerado;
		
		// rotina para gerar 10000 processos entre 1 e 1000
		for (int i = 0; i < quantidadeProcessos; i++) {
			numeroProcessoGerado = gerador.nextInt(0, 1001);

			switch (numeroProcessoGerado) {
			case 0:
				// rotina para retirar da fila prioritaria
				System.out.println("ATENDENDO: " + filaPrioritaria.poll());
				break;
			case 500:
				// rotina para retirar da fila normal
				System.out.println("ATENDENDO: " + filaNormal.poll());
				break;

			default:
				// rotina para inserir processo na fila de prioritaria
				if (numeroProcessoGerado < 500) {
					Processo processoTmp = new Processo(numeroProcessoGerado, "Processo de alta prioridade");
					if (!filaPrioritaria.contains(processoTmp)) {
						filaPrioritaria.offer(processoTmp); // filaPrioritaria.add(processoTmp);
						System.out.println(processoTmp);
					}
					// rotina para inserir processo na fila normal
				} else {
					Processo processoTmp = new Processo(numeroProcessoGerado, "Processo normal");
					if (!filaNormal.contains(processoTmp)) {
						filaNormal.offer(processoTmp); // filaNormal.add(processoTmp);
						System.out.println(processoTmp);
					}
				}
				break;
			}
		}
	}

	/***
	 * método estático que exibe processos existentes em fila
	 * @param fila - contem uma fila normal ou prioritaria
	 * @param frase - texto a ser exibido no cabeçalho da exibição ou listagem
	 */
	public static void exibirProcessosNaoAtendidos(Queue<Processo> fila, String frase) {
		System.out.println(frase);
		System.out.println("Total de processos nao atendidos: " + fila.size());
		
		for (Processo processo : fila) {
			System.out.println(processo);
		}
	}
	
	public static void main(String[] args) {
		Queue<Processo> filaPrioritaria = new LinkedList<>();
		Queue<Processo> filaNormal = new LinkedList<>();
		
		gerarProcessosEmFilas(filaPrioritaria, filaNormal, 1000);
		exibirProcessosNaoAtendidos(filaPrioritaria,"Fila prioritaria");
		exibirProcessosNaoAtendidos(filaNormal,"Fila normal");
		

	}

}
