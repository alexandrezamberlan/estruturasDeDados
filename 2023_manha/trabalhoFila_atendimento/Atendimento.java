import java.util.LinkedList;
import java.util.Queue;

import javax.swing.JOptionPane;  

public class Atendimento {
    public static void main(String[] args) {
        Queue<Ficha> filaNormal = new LinkedList<Ficha>();
        Queue<Ficha> filaPrioritaria = new LinkedList<Ficha>();
        int contadorFilaNormal = 1;
        int contadorFilaPrioritaria = 1000;
        int contadorAtendimentos = 3;
        String opcao = "";
        Ficha ficha;
        do {
            try {
                opcao = JOptionPane.showInputDialog(null,"1 - Ficha normal\n2 - Ficha prioritaria\n3 - Chama atendimento\n");
                switch (opcao) {
                    case "1":
                        ficha = new Ficha(contadorFilaNormal);
                        filaNormal.add(ficha);
                        contadorFilaNormal++;
                        JOptionPane.showMessageDialog(null,"Voce retirou a ficha normal ..... " + ficha.getConteudo() + " - " + ficha.getDataHora());        
                        contadorAtendimentos++;
                        break;
                    case "2":
                        ficha = new Ficha(contadorFilaPrioritaria);
                        filaPrioritaria.add(ficha);
                        contadorFilaPrioritaria++;
                        JOptionPane.showMessageDialog(null,"Voce retirou a ficha prioritaria ..... " + ficha.getConteudo() + " - " + ficha.getDataHora());                                
                        contadorAtendimentos++;
                        break;
                    case "3":  
                        //System.out.println("asdfasdf asdf as" + (contadorAtendimentos % 3)  + " ssafasfd" +contadorAtendimentos);                  
                        if (contadorAtendimentos % 3 == 1 && !filaPrioritaria.isEmpty()) {
                            ficha = filaPrioritaria.peek();                        
                            JOptionPane.showMessageDialog(null,"Chamando a ficha prioritaria ..... " + ficha.getConteudo());        
                            filaPrioritaria.poll(); //faz a mesma coisa que o remove, so que se a fila estiver vazia, nao da erro
                        } else if (!filaNormal.isEmpty()) {
                            ficha = filaNormal.peek();                        
                            JOptionPane.showMessageDialog(null,"Chamando a ficha normal ..... " + ficha.getConteudo());        
                            filaNormal.poll(); //faz a mesma coisa que o remove, so que se a fila estiver vazia, nao da erro
                        }
                        break;                
                    default:
                        JOptionPane.showMessageDialog(null,"Opcao invalida");        
                        break;
                }
            } catch(Exception e) {
                break; //para sair do while
            }
        } while (!opcao.equals("4"));

        System.exit(0);

        
    }
}