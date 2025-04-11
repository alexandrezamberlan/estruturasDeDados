import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class DicionarioEquipes {
    public static void main(String[] args) {
        //nome, cidade
        Map<String,String> equipes = new HashMap<String,String>();

        String nome, cidade;
        String opcao;
        Scanner teclado = new Scanner(System.in);
        do {
            System.out.print("Nome equipe: ");
            nome = teclado.nextLine().toUpperCase();
            System.out.print("Nome cidade: ");
            cidade = teclado.nextLine().toUpperCase();

            if (!equipes.containsKey(nome))
                equipes.put(nome,cidade);
            else    
                System.out.println("Equipe ja cadastrada....");

            System.out.print("1 - Continua; Outra tecla encerra: ");
            opcao = teclado.nextLine();
            if (!opcao.equals("1")){
                break;
            }

        } while(true);

        for (Map.Entry<String,String> equipe : equipes.entrySet()) {
            System.out.println("Time: " + equipe.getKey() +". Cidade: " + equipe.getValue());
        }

    }
}