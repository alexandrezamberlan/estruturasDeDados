import java.io.FileReader;
import java.io.OutputStreamWriter;
import java.io.FileOutputStream;
import java.io.BufferedReader;
import java.util.Scanner;
import java.util.Stack;

public class ArquivoEscrita {
    public static void main(String[] args) {
        String nomeArquivo;
        Scanner teclado = new Scanner(System.in);
        System.out.print("Digite caminho e nome do arquivo: ");
        nomeArquivo = teclado.nextLine();
        OutputStreamWriter procurador;
        String nome, email, idade;
        try {
            procurador = new OutputStreamWriter(new FileOutputStream(nomeArquivo));                        
            System.out.print("Nome: ");
            nome = teclado.next();
            System.out.print("Email: ");
            email = teclado.next();
            System.out.print("Idade: ");
            idade = teclado.next();
            procurador.append(nome.toUpperCase() + ";" + email.toLowerCase() + ";" + idade);
            procurador.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }        
    }      
}
