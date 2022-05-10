
package Persistence;

import Model.Glicemia;
import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author laboratorio
 */
public class Storage {
    /**
     * Método que recebe uma lista de valores glicemicos por referencia,
     * abre um arquivo com dados de glicemia e popula a lista
     * 
     * @param lista 
     */
    public static void popularListaDoArquivo(List<Glicemia> lista) {
        Glicemia glicemia;
        String content="";
        String line[];
        try {
            File file = new File("dadosGlicemia.txt");
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine()) {
                content = scanner.nextLine();
                line = content.split(";");
                glicemia = new Glicemia(Integer.parseInt(line[0]),
                                        line[1], line[2],line[3]);
                lista.add(glicemia);
            }
            scanner.close();            
        } catch (IOException e) {
            System.out.println("Error! File not found");
        }
    }
}
