
package View;

import Model.Glicemia;
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
}
