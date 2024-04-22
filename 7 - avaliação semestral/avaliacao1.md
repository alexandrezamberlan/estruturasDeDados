# Avaliação Semestral 1

Fazer um programa na linguagem Java ou C#. O programa deve conter o seguinte menu. E deve funcionar no modo console.

Menu
1 - Listar atletas (nome ou por pontuação decrescente)
2 - Cadastrar atleta
3 - Procurar por atleta (nome ou apelido)
4 - Remover atleta (nome ou apelido)
Opção: 


A Classe de dados deve ser:

class Atleta {
    string fone; //chave primária
    string nome;
    string apelido;
    string dataNascimento;
    int pontuacaoAcumulada;

    //construtor

    //getters setters

    //toString

    //equals

    //hashCode
}

Todo o sistema precisa controlar duplicados. A chave de unicidade é o fone.

Como atividade opcional, colocar os dados persistidos em arquivo .csv
fone;nome;apelido;dataNascimento;pontuacaoAcumulada;

Forma de entrega:

Criar um repositório no seu github pessoal e encaminhar o link para alexz@ufn.edu.br

