import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

class Cidade {
    String nomeCidade;
    String siglaEstado;
    
    public Cidade(String nomeCidade, String siglaEstado) {
        this.nomeCidade = nomeCidade;
        this.siglaEstado = siglaEstado;
    }

    public String getNomeCidade() {
        return nomeCidade;
    }

    public void setNomeCidade(String nomeCidade) {
        this.nomeCidade = nomeCidade;
    }

    public String getSiglaEstado() {
        return siglaEstado;
    }

    public void setSiglaEstado(String siglaEstado) {
        this.siglaEstado = siglaEstado;
    }

    @Override
    public String toString() {
        return "Cidade [nomeCidade=" + nomeCidade + ", siglaEstado=" + siglaEstado + "]";
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((nomeCidade == null) ? 0 : nomeCidade.hashCode());
        result = prime * result + ((siglaEstado == null) ? 0 : siglaEstado.hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Cidade other = (Cidade) obj;
        if (nomeCidade == null) {
            if (other.nomeCidade != null)
                return false;
        } else if (!nomeCidade.equals(other.nomeCidade))
            return false;
        if (siglaEstado == null) {
            if (other.siglaEstado != null)
                return false;
        } else if (!siglaEstado.equals(other.siglaEstado))
            return false;
        return true;
    }
}

public class HashCidades {
    static void cadastrar(List<Cidade> cidades) {
        String nome, estado;
        Scanner teclado = new Scanner(System.in);

        System.out.print("Nome cidade: ");
        nome = teclado.nextLine().toUpperCase();
        System.out.print("Estado cidade: ");
        estado = teclado.nextLine().toUpperCase();
        Cidade tmp = new Cidade(nome,estado);
        if (!cidades.contains(tmp)) {
            cidades.add(tmp);
            cidades.sort((c1, c2) -> c1.nome.compareTo(c2.nome));
            //cidade.sort(Comparator.comparing((Cidade c) -> c.nome)
            //           .thenComparing(c -> c.estado));
        }
        else
            System.out.println("Cidade neste estado já cadastrada");

    }

    static void listar(List<Cidade> cidades) {
        System.out.println("Listagem....");
        for (Cidade cidade : cidades) {
            System.out.println(cidade);
        }

    }

    static void pesquisar(List<Cidade> cidades) {
        String nome, estado;
        Scanner teclado = new Scanner(System.in);

        System.out.print("Nome cidade: ");
        nome = teclado.nextLine().toUpperCase();
        List<Cidades> respostas = new ArrayList<>();

        for (Cidades cidade : cidades) {
            if (nome.equals(cidade.nome)) {
                repostas.add(cidade);
            }
        }
        if (respostas.isEmpty()) {
            System.out.println("Cidade nao encontrada");            
        } else {
            for (Cidade cidade : respostas) {
                System.out.println(cidade);
            }
        }
    }

    static void remover(List<Cidade> cidades) {
        String nome, estado;
        Scanner teclado = new Scanner(System.in);

        System.out.print("Nome cidade: ");
        nome = teclado.nextLine().toUpperCase();
        System.out.print("Estado cidade: ");
        estado = teclado.nextLine().toUpperCase();
        Cidade tmp = new Cidade(nome,estado);
        if (cidades.remove(tmp))
            System.out.println("Cidade e estado removidos com sucesso");
        else
            System.out.println("Cidade neste estado nao localizada");

    }

    public static void main(String[] args) {
        List<Cidade> cidades = new ArrayList<>();
        
        char opcao;
        Scanner teclado = new Scanner(System.in);

        do {
            System.out.println("1 - Cadastrar");
            System.out.println("2 - Listar");
            System.out.println("3 - Pesquisar por cidade");
            System.out.println("4 - Remover por cidade");
            System.out.println("5 - Finalizar");
            System.out.print("Opcao: ");
            opcao = teclado.nextLine().charAt(0);

            switch (opcao) {
                case '1':
                    ListaCidades.cadastrar(cidades);   
                    break;
                case '2':
                    ListaCidades.listar(cidades);   
                    break;
                case '3':
                    ListaCidades.pesquisar(cidades);
                    break;
                case '4':
                    //ListaCidades.remover(cidades);
                    break;
                case '5':
                    break;
            
                default:
                    System.out.println("Opcao invalida....");
                    break;
            }

        } while(opcao != '5');
    }
    
    
}
