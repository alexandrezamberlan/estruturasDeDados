import java.util.LinkedList;

import javax.swing.JOptionPane;

public class Lista {
    public static void main(String args[]) {
        System.out.println("Turma de ED testando um tipo de lista");

        //Vector
        //ArrayList
        //List
        //LinkedList
        //....

        LinkedList<Integer> lista = new LinkedList<Integer>();
        int valor;
        do {
            valor = Integer.parseInt(JOptionPane.showInputDialog(null, "Informe um valor inteiro: "));
            if (valor == -1) break;
            if (!lista.contains(valor)) {
                lista.add(valor);
            }
        } while (true);

        JOptionPane.showMessageDialog(null,lista);
        JOptionPane.showMessageDialog(null, "A lista tem " + lista.size() + " elementos");
    }
}