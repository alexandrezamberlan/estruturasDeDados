import java.util.ArrayList;

public class Recursao {

    public static void exibirR(int i) { //inicialização da variável de controle é no parametro
        if (i > 0){ //teste de parada da recursão
            System.out.println("empilhando...");
            exibirR(i - 1); //transformação da variável de controle ocorre no ponto de recursão
        }
        System.out.println("desempilhando...");
    }

    public static void imprimirR(int i) { //inicializando a variavel de controle
        if (i > 0) { //teste de parada
            imprimirR(i - 1);
            System.out.println(i);            
        }
    }

    public static void exibirVetorR(int []vetor, int n) { //inicialização de n como var. controle
        if (n > 0) { //teste de parada
            //codigos executados no empilhamento
            System.out.println(vetor[n - 1]);
            exibirVetorR(vetor, n - 1); //ponto de recursão, com n sendo modificado
            //codigos executados no desempilhamento
        }
    }

    public static void exibirDecrescenteR(ArrayList<String> lista, int n) {
        if (n > 0) {            
            exibirDecrescenteR(lista, n - 1);
            System.out.println(lista.get(n - 1));
        }
    }

    public static void imprimirNomesGrandesR(ArrayList<String> lista, int n, int tamanho) {
        if (n > 0) {            
            imprimirNomesGrandesR(lista, n - 1, tamanho);
            if (lista.get(n-1).length() >= tamanho) {
                System.out.println(lista.get(n - 1));
            }
        }
    }

    public static void main(String args[]) {
        // for (int i = 0; i < 3; i++) {
        //     System.out.println("oi..");
        // }
        //exibirR(3);
        //imprimirR(4);

        // int []vetor = {4,5,6,7};
        // exibirVetorR(vetor, vetor.length);

        ArrayList<String> nomes = new ArrayList<>();
        nomes.add("Dudu");
        nomes.add("Yuri bagual");
        nomes.add("Gege");
        nomes.add("Pepe legal");
        nomes.add("Ambrozia");
        nomes.sort(null);

        //exibirDecrescenteR(nomes, nomes.size());

        imprimirNomesGrandesR(nomes, nomes.size(), 5);

    }
}