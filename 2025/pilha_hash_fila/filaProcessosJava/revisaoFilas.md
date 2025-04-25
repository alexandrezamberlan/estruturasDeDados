# Teoria da Orientação a Objetos
    - tercerização
    - herança
        - classe pai/mãe -> Object



# Estruturas de Dados
    - físicas
    - abstratas
        - listas, dicionários, listas de listas, listas de dicionários, listas de objetos, hashset
            - orientação a objetos
                - reescrita de operações/métodos
                    - toString(), ToString(), __str__, __repr__
                    - equals(), Equals(), __eq__
                    - hashCode(), GetHashCode(), __hash__
        - filas Queue - classe abstrata -> esqueleto com atributos e métodos.... só que não instancia objetos
            - FIFO - First In, First Out
                - operações clássicas:
                    - inserir no final/cauda -> add, 
                    - remover no inicio/cabeça -> remove, 
                - operações herdadas
                    - size
                    - contains
                    - indexOf???

# Cenário de aplicação de filas
    1) gerenciar processos -> id, descrição
        - classe Processo
            atributos -> id, descrição
            metodos -> toString, equals
    2) processos tem prioridades -> processos com id entre 1 e 500 tem alta prioridade e processos entre 501 e 1000 tem baixa prioridade
    3) há duas filas -> normal (processos entre 501 e 1000) e prioritaria (processos entre 1 a 500)
    4) dinâmica:
        - um número aleatório será gerado entre 0 e 1000
             - 0 -> atender/remover a cabeça da fila de prioridade - tratar quando vazia 
             - 500 -> atender/remover a cabeça da fila normal - tratar quando vazia
             - demais números seguem a dinâmica acima -> controle de replicados
        - a dinâmica deve repetir 10000
        - exibir as filas ao final, com os processos não atendidos (mostrando contadores)