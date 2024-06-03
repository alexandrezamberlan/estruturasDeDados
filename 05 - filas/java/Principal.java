import java.util.LinkedList;
import java.util.Queue;

import javax.swing.JOptionPane;

public class Principal {

    public static void chamar(Queue<Cliente> fila, int quantidadeAtendimento) throws Exception  {
        Cliente obj = fila.remove();
        JOptionPane.showMessageDialog(null,"Chamando ficha ..." + obj.fichaAtendimento,"Chamando ",JOptionPane.INFORMATION_MESSAGE);
        
        quantidadeAtendimento++;     
    }

    public static void menu(Queue<Cliente> filaNormal, Queue<Cliente> filaPrioritaria) {
        int quantidadeAtendimento = 0;
        int contadorNormal = 0;
        int contadorPrioritario = 1000;


        StringBuffer textoMenu = new StringBuffer();

        textoMenu.append("1 - Normal\n");
        textoMenu.append("2 - Prioritário\n");
        textoMenu.append("3 - Chamar\n");
        textoMenu.append("4 - Finalizar\n");
        String op;
        String fone, nome;
        do {
            op = JOptionPane.showInputDialog(null,textoMenu, "Atendimento Posto de Saúde", JOptionPane.QUESTION_MESSAGE);

            switch (op) {
                case "1":
                    contadorNormal++;
                    nome = JOptionPane.showInputDialog(null, "Nome do cliente", "Senha", JOptionPane.QUESTION_MESSAGE).toUpperCase();
                    fone = JOptionPane.showInputDialog(null, "Fone do cliente", "Senha", JOptionPane.QUESTION_MESSAGE);
                    filaNormal.add(new Cliente(fone, nome, contadorNormal));     
                    System.out.println("passei aqui...");
                    JOptionPane.showMessageDialog(null,"Imprimindo a ficha " + contadorNormal,"Impressão da Ficha", JOptionPane.INFORMATION_MESSAGE);               
                    break;
                case "2":
                    contadorPrioritario++;
                    nome = JOptionPane.showInputDialog(null, "Nome do cliente", "Senha", JOptionPane.QUESTION_MESSAGE).toUpperCase();
                    fone = JOptionPane.showInputDialog(null, "Fone do cliente", "Senha", JOptionPane.QUESTION_MESSAGE);
                    filaPrioritaria.add(new Cliente(fone, nome, contadorPrioritario));
                    JOptionPane.showMessageDialog(null,"Imprimindo a ficha " + contadorPrioritario,"Impressão da Ficha", JOptionPane.INFORMATION_MESSAGE);               
                    break;
                case "3":
                    if (quantidadeAtendimento % 3 == 0) {
                        //chamar ficha prioritaria
                        try {
                            chamar(filaPrioritaria,quantidadeAtendimento);
                        } catch(Exception e) {      
                            try {
                                chamar(filaNormal,quantidadeAtendimento);
                            } catch(Exception e2) {

                            }
                        }
                    } else {
                        //chamar ficha normal
                        try {
                            chamar(filaNormal, quantidadeAtendimento);
                        } catch(Exception e) { 
                            try {
                                chamar(filaPrioritaria,quantidadeAtendimento);
                            } catch(Exception e3) {
                                
                            }                        
                        }
                    }
                    break;
                case "4":
                    
                    break;
            
                default:
                    JOptionPane.showMessageDialog(null,"Opção inválida", "Erro", JOptionPane.ERROR_MESSAGE);
                    break;
            }
        } while (!op.equals("4"));

        
    }

    public static void main(String[] args) {
        Queue<Cliente> filaNormal = new LinkedList<Cliente>();
        Queue<Cliente> filaPrioritaria = new LinkedList<Cliente>();

        menu(filaNormal, filaPrioritaria);

        System.exit(0);
    }
}