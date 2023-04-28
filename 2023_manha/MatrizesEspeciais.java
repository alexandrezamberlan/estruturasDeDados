import java.util.Random;

import javax.swing.JOptionPane;

class Matriz {
    int matriz[][];
    
    public Matriz(int dimensao) {
        matriz = new int[dimensao][dimensao];

        for (int lin = 0; lin < dimensao; lin++) {
            for (int col = 0; col < dimensao; col++) {
                matriz[lin][col] = 0;
            }
        }
    }

    public String exibir() {
        StringBuffer resposta = new StringBuffer();

        for (int lin = 0; lin < matriz.length; lin++) {
            for (int col = 0; col < matriz.length; col++) {
                resposta.append(matriz[lin][col]);
                resposta.append("   ");
            }
            resposta.append("\n");
        }
        return resposta.toString();
    }

    public void gerarDiagonalPrincipal() {
        Random gerador = new Random(0);
        for (int i = 0; i < matriz.length; i++) {
            matriz[i][i] = gerador.nextInt(1,10);
        }
    }

    public void gerarDiagonalSecundaria() {
        Random gerador = new Random(0);
        for (int lin = 0, col = matriz.length - 1; lin < matriz.length; lin++, col--) {
            matriz[lin][col] = gerador.nextInt(1,10);
        }
    }

    public void gerarTriangularSuperiorDaDiagonalPrincipal() {
        Random gerador = new Random(0);
        for (int lin = 0; lin < matriz.length; lin++) {
            for (int col = lin + 1; col < matriz.length; col++) {
                matriz[lin][col] = gerador.nextInt(1,10);
            }
        }
    }

    public void gerarTriangularInferiorDaDiagonalPrincipal() {
        Random gerador = new Random(0);
        for (int lin = 1; lin < matriz.length; lin++) {
            for (int col = 0; col < lin; col++) {
                matriz[lin][col] = gerador.nextInt(1,10);
            }
        }
    }

    public void gerarTriangularSuperiorDaDiagonalSecundaria() {
        Random gerador = new Random(0);
        for (int lin = 0; lin < matriz.length - 1; lin++) {
            for (int col = 0; col < matriz.length - (lin+1); col++) {
                matriz[lin][col] = gerador.nextInt(1,10);
            }
        }
    }

    public void gerarTriangularInferiorDaDiagonalSecundaria() {
        Random gerador = new Random(0);
        for (int lin = 1; lin < matriz.length; lin++) {
            for (int col = matriz.length - lin; col < matriz.length; col++) {
                matriz[lin][col] = gerador.nextInt(1,10);
            }
        }
    }
}

public class MatrizesEspeciais {
    public static void main(String[] args) {
        int dimensao = Integer.parseInt(JOptionPane.showInputDialog(null,"Entre com a dimensão da matriz"));
        Matriz m = new Matriz(dimensao);
        JOptionPane.showMessageDialog(null, m.exibir(), "Matriz zerada", 3);

        m.gerarDiagonalPrincipal();
        JOptionPane.showMessageDialog(null, m.exibir(), "Matriz com diagonal principal", 3);
        
        m = new Matriz(dimensao);
        m.gerarDiagonalSecundaria();
        JOptionPane.showMessageDialog(null, m.exibir(), "Matriz com diagonal secundaria", 3);

        m = new Matriz(dimensao);
        m.gerarTriangularSuperiorDaDiagonalPrincipal();
        JOptionPane.showMessageDialog(null, m.exibir(), "Matriz triangular superior principal", 3);
        
        m = new Matriz(dimensao);
        m.gerarTriangularInferiorDaDiagonalPrincipal();
        JOptionPane.showMessageDialog(null, m.exibir(), "Matriz triangular inferior principal", 3);
        
        m = new Matriz(dimensao);
        m.gerarTriangularSuperiorDaDiagonalSecundaria();
        JOptionPane.showMessageDialog(null, m.exibir(), "Matriz triangular superior secundaria", 3);

        m = new Matriz(dimensao);
        m.gerarTriangularInferiorDaDiagonalSecundaria();
        JOptionPane.showMessageDialog(null, m.exibir(), "Matriz triangular inferior secundaria", 3);

        System.exit(0);
    }
}