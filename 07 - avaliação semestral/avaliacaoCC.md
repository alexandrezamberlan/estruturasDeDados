# Avaliações ou desafios

## Listas: dicionário ou objeto
1) Fazer um programa em Java, C# ou C++ que receba nomes completos de pessoas (validar se nome foi digitado completo). A partir disso, gerar email da pessoa combinando o primeiro nome com o último nome, separados por '.', mais '@ufn.edu.br'. Por exemplo, João Pedro Garcia -> joao.garcia@ufn.edu.br. Uma vez que o email foi gerado, adicionar o par (nome completo e email) em uma lista. Essa lista pode ser composta por dicionários (email será a chave e nome completo o valor) ou por objetos (da classe Pessoa, com atributos nome e email). Contudo, não pode haver emails repetidos. Ao final, exibir a lista com os dados (nomes e emails).

   - Data de entrega: 25/03/2025
   - Forma de entrega: o programa deve ser disponibilizado no github pessoal do aluno e o link enviado para alexz@ufn.edu.br
  
## Avaliação Parcial - Lista

A avaliação tem como objetivo verificar compreensão e domínio sobre a teoria de Estruturas de Dados com foco em Listas.

### Realização e entrega

A avaliação deve ser respondida em arquivos .txt (contendo respostas das questões teóricas) e arquivos .java, ou .cs, ou .py (contendo os códigos das questões práticas). Esses arquivos serão entregues ao professor, dentro da pasta de cada aluno, com seu nome completo.

### Questões

1) Explique e exemplifique os papéis de Listas, Pilhas, Filas, Árvores e Grafos em Sistemas de Informação.
    - 

2) Qual a diferença entre Listas e Dicionários? Quando devemos usar um ou outro?

3) Ao usarmos listas de objetos com controle de duplicidade, precisamos reescrever o métodos equals() da classe que estamos implementando. Imagine uma classe Turma, em que há os atributos nome, cpf, dataNascimento. A partir daí, implemente a classe e reescreva o método equals() que use o atributo cpf com identficador (chave primária) da classe.

4) Em sua linguagem de preferência, crie um programa (usando funções/métodos) que:
    - preencha N nomes de equipes de futebol, obrigatóriamente em maiúsculo. Esses nomes devem ser armazenados em um dicionário que se possa controlar duplicados.
    - exiba os nomes das equipes cadastradas
    - exiba a quantidade de equipes cadastradas

5) Em sua linguagem de preferência, crie um programa que manipule objetos cidades baseados na classe Cidade, contendo, nome da cidade e sigla do estado do Brasil. O controle de duplicidade deve ser via o nome da cidade. O programa deve apresentar um pequeno Menu, em que o usuário possa:
    - cadastrar uma cidade em lista de cidades: nome completo em maiúsculo e a sigla em maiúsculo
    - listar as cidades cadastradas tendo como ordem de ordenação os nomes das cidades
    - pesquisar uma cidade por seu nome e mostrar o seu estado respectivo (no caso, sigla)
    - remover uma cidade, pesquisando-a por seu nome
    - finalizar o programa
