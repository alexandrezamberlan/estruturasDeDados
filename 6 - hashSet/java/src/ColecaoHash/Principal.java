package ColecaoHash;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;




public class Principal {
	
	public static void main(String[] args) {
		Scanner teclado = new Scanner(System.in);
		String valor;
		
		HashSet<String> hash = new HashSet<String>();
		for (int i = 0; i < 6; i++) {
			System.out.print("Digite nome: ");
			valor = teclado.nextLine();
			if (!hash.add(valor)) {				
				System.out.println("Valor ja cadastrado!!");
				
			}
		}
		
		
		
		for (String item : hash) {
			System.out.println(item);
		}
		
		
		
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
