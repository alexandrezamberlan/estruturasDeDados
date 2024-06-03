import java.io.BufferedReader;

import java.io.FileReader;
import java.util.HashSet;

public class Util {
    public static void popularArquivoNoHash(HashSet<Atomo> tabelaHash, String nomeArquivo) {
        try {
            FileReader arquivo = new FileReader(nomeArquivo);
            BufferedReader leitor = new BufferedReader(arquivo);

            String linha;
            String[] dadosLinha;
            while ((linha = leitor.readLine()) != null) {
                dadosLinha = linha.split(";"); 
                Atomo atomo = new Atomo(dadosLinha[0], dadosLinha[1], dadosLinha[2], dadosLinha[3]);
                tabelaHash.add(atomo);
            }
            arquivo.close();
        } catch(Exception e) {
            System.out.println(e);
        }
    }

    public static void mostrarHash(HashSet<Atomo> tabelaHash) {
        for (Atomo atomo : tabelaHash) {
            System.out.println(atomo);
        }
    }
}
