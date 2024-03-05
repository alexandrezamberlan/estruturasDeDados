import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

import java.util.Scanner;

public class Lista1 {
    public static void conectarBase(ArrayList<String> lista) {
        try {
            BufferedReader leitor = new BufferedReader(new FileReader("numeros.txt"));
            String linha;
            while ((linha = leitor.readLine()) != null) {
                 lista.add(linha);
            }              
            lista.sort(null);

            leitor.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }    
    }

    public static void gravarBanco(ArrayList<String> lista) {
        try {
            OutputStreamWriter escritor = new OutputStreamWriter(new FileOutputStream("numeros.txt"));                        
        
            for (String i : lista) {
                escritor.append(i + "\n");
            }
            escritor.close();
        } catch(Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        ArrayList<String> listaNomes = new ArrayList<String>();
        conectarBase(listaNomes);
        Scanner teclado = new Scanner(System.in);
        String nome;
        while (true) {
            System.out.print("Digite um numero ou 0 para finalizar: ");
            nome = teclado.nextLine().toUpperCase();
            if (nome.equals("0")) {
                break;
            }
            if (!listaNomes.contains(nome)) {
                listaNomes.add(nome);
                listaNomes.sort(null);
                gravarBanco(listaNomes);
            } else {
                System.out.println("Numero já cadastrado");
            }
        }        
        for (String i : listaNomes) {
            System.out.println(i);
        }
    }
}