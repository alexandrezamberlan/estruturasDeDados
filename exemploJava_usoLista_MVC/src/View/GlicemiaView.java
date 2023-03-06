
package View;

import Model.Glicemia;
import Persistence.Storage;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import javax.swing.JOptionPane;

/**
 * Classe de Visão para exibir dados de glicemia
 * @author laboratorio
 */
public class GlicemiaView {
    
    /**
     * Método que recebe uma lista com dados glicemicos e os exibe na tela
     * @param lista 
     */
    public static void exibir(List<Glicemia> lista) {
        StringBuffer resultado = new StringBuffer();
        for (Glicemia g : lista) {
            resultado.append(g + "\n");
        }
        JOptionPane.showMessageDialog(null, resultado);
    }
    
    public static void cadastrar(List<Glicemia> lista) {
        int glicemia = Integer.parseInt(JOptionPane.showInputDialog(null, "Valor da glicemia"));
        String momento;
        do {
            momento = JOptionPane.showInputDialog(null,"Digite ac (antes de comer ou dc (depois de comer)");
            momento = momento.toLowerCase();
        } while (!momento.equals("ac") && !momento.equals("dc") );
        Date data = new Date();
        SimpleDateFormat dataFormatada = new SimpleDateFormat("dd/MM/yyyy HH:mm");
        String dataHora[] = dataFormatada.format(data).split(" ");
        
        lista.add(new Glicemia(glicemia,momento,dataHora[0],dataHora[1]));
        Storage.gravarNoArquivo(lista);
    }
}
