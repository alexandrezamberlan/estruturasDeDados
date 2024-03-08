
package Controller;

import Model.Glicemia;
import Persistence.Storage;
import View.GlicemiaView;

import java.util.LinkedList;
import java.util.List;
import javax.swing.JOptionPane;

/**
 * Classe de controle da aplicação
 * @author laboratorio
 */
public class Controller {
    /**
     * Método principal que controla a aplicação
     * @param args 
     */
    public static void main(String[] args) {
        List<Glicemia> listaDadosGlicemicos = new LinkedList<>();
        
        
        String opcao;
        StringBuffer menu = new StringBuffer();
        menu.append("1 - Popular lista de glicemia\n");
        menu.append("2 - Exibir lista de glicemia\n");
        menu.append("3 - Cadastrar dado de glicemia\n");
        menu.append("7 - Sair");
        do {
            opcao = JOptionPane.showInputDialog(null, menu);
            
            switch (opcao) {
                case "1" : //popular
                    Storage.popularListaDoArquivo(listaDadosGlicemicos);
                    break;
                case "2" : //exibr
                    if (listaDadosGlicemicos.isEmpty()) {
                        JOptionPane.showMessageDialog(null, "Carregue o arquivo de glicemia ou salve algum dado");
                    } else {
                        GlicemiaView.exibir(listaDadosGlicemicos);
                    }
                    break;
                case "3" : //cadastrar glicemia
                    GlicemiaView.cadastrar(listaDadosGlicemicos);
                    
                    break;
                case "7" : JOptionPane.showMessageDialog(null, "Obrigado por "
                        + "usar o sistema");
                    break;    
                default : JOptionPane.showMessageDialog(null, "Opção inválida");
            }
            
            if (opcao.equals("7")) break;
            
        } while (true);
    
        System.exit(0);
    }
}
