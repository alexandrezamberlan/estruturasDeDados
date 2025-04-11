package ColecaoHash;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;

public class Principal {

	public static void main(String[] args) {
		HashSet<Double> hash = new HashSet<Double>();
		ArrayList<Double> lista = new ArrayList<Double>();
		Random gerador = new Random();
		long tempoInicio, tempoFim;  
		
		tempoInicio = System.nanoTime();
		for (Double i = 0.0; i < 40000000; i++) {
			hash.add(gerador.nextDouble(10000000));
		}
		System.out.println("Feito");
        tempoFim = System.nanoTime();
        System.out.println("Tempo (ms) para armazenar no hash: " + (tempoFim - tempoInicio)/1000000);

		
        tempoInicio = System.nanoTime();
        lista.addAll(hash);

		System.out.println("Feito passagem do hash para arraylist");
        tempoFim = System.nanoTime();
        System.out.println("Tempo (ms) para passar hash para arraylist: " + (tempoFim - tempoInicio)/1000000);

		
        
        tempoInicio = System.nanoTime();
		lista.sort(null);

		System.out.println("Feito ordenacao");

        tempoFim = System.nanoTime();
        System.out.println("Tempo (ms) para ordenar arraylist: " + (tempoFim - tempoInicio)/1000000);


//		Scanner teclado = new Scanner(System.in);
//		String nome;
//		int matricula;
//		
//		HashSet<Aluno> hashAluno = new HashSet<Aluno>();
//		
//		for (int i = 0; i < 4; i++) {
//			System.out.print("Matricula: ");
//			matricula = teclado.nextInt();
//			teclado.nextLine();
//			System.out.print("Nome: ");
//			nome = teclado.nextLine();
//			
//			if (!hashAluno.add(new Aluno(matricula,nome))) {
//				System.out.println("Aluno com esta matricula ja cadastrado!");
//			}
//		}
//		
//		for (Aluno aluno : hashAluno) {
//			System.out.println("Endereco: " + (""+aluno.matricula).hashCode() + aluno);
//		}
//		
//		ArrayList<Aluno> listaAlunos = new ArrayList<Aluno>();
//		listaAlunos.addAll(hashAluno);
//		
//		listaAlunos.sort((a1, a2) -> ((Integer)a1.getMatricula()).compareTo(a2.getMatricula()));
//	
//		for (Aluno aluno : listaAlunos) {
//			System.out.println(aluno);
//		}
//				
//		

//		HashSet<String> hash = new HashSet<String>();
//		for (int i = 0; i < 6; i++) {
//			System.out.print("Digite nome: ");
//			valor = teclado.nextLine();
//			if (!hash.add(valor)) {				
//				System.out.println("Valor ja cadastrado!!");
//				
//			}
//		}
//		
//		
//		
//		for (String item : hash) {
//			System.out.println(item);
//		}
//		

//		ArrayList<Integer> lista = new ArrayList<Integer>();
//		for (int i = 0; i < 6; i++) {
//			System.out.print("Digite numero: ");
//			valor = teclado.nextInt();
//			if (!lista.contains(valor)) {				
//				lista.add(valor);
//				lista.sort(null);
//			} else {
//				System.out.println("Valor ja cadastrado!!");
//			}
//		}
//		
//		for (Integer item : lista) {
//			System.out.println(item);
//		}

	}

}
