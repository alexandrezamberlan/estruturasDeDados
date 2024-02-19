# Estruturas de Dados
Disciplina de estruturas de dados da UFN, contendo códigos dos programas e métodos discutidos e trabalhados em laboratório.

## Conceitos
  - Estruturas de Dados Físicas: são estruturas de armazenamento de dados em memória principal. São dependentes da linguagem de programação
  
  - Estruturas de Dados Abstratas: são algoritmos com operações específicas (inserir, pesquisar, atualizar, deletar) para melhor gestão da memória. Por serem algoritmos, são independentes de linguagem
    - Pilha (Stack): Last In, First Out (LIFO) - Ultimo que entra é o primeiro a sair
      - operações: inserir (add ou append ou push) e remover (remove ou delete ou pop)
      - topo (peek)
      - outros métodos: isEmpty() ou empty()
      - aplicações: backups, problemas em jogos de lógica, gerenciamento de processos em SO
        
    - Lista (List): Ordenação (quando possível)
      - operações: inserir (add ou append), pesquisar (contains ou in), atualizar (set), deletar (remove ou delete)
      - outros métodos: size() ou Count() ou len(lista); isEmpty ou Empty
      - aplicações: guardar dados ordenados (pesquisar mais eficiente)
        
    - Fila (Queue): First In, First Out - Primeiro que entra é o primeiro a sair
      - operações: inserir (final ou na cauda/tail - add) ou remover (início ou na cabeça/head - remove)
      - outros métodos: isEmpty ou Empty; size ou Count
      - aplicações: quando há necessidade de gerenciar prioridades
        
    - Árvore (Tree): Armazenamento para busca eficaz
      - operações: inserir (add), pesquisar (contains), atualizar (set), deletar (remove)
      - aplicações: técnicas de IA ou jogos de lógica ou simplesmente eletrônicos
        
    - Grafo (Graph): Roteamento ou Percurso
      - operações: inserir (add), pesquisar (contains), atualizar (set), deletar (remove)
      - usa matriz de adjacência
      - aplicações: técnicas de IA para escolher o melhor caminho

