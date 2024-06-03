from celula import Celula

def exibir(matriz):
    # Imprimindo a matriz
    for linha in matriz:
        print(linha)

tam_linha = 5
tam_coluna = 5
matriz_especial = [[0 for _ in range(tam_linha)] for _ in range(tam_coluna)]

matriz_especial[0][0] = 5
matriz_especial[2][3] = 5
matriz_especial[4][2] = 5

exibir(matriz_especial)

#gera hash a partir da matriz especial
tabela_hash = set()
Celula.transforma_matriz_em_hash(matriz_especial, tabela_hash)
Celula.exibe_matriz_em_hash(tabela_hash)

#gera a matriz especial a partir do hash
print("Gerando matriz especial a partir da tabela hash")
outra_matriz = [[0 for _ in range(Celula.qtd_linhas)] for _ in range(Celula.qtd_colunas)]
Celula.transforma_hash_em_matriz(tabela_hash, outra_matriz)
exibir(outra_matriz)
