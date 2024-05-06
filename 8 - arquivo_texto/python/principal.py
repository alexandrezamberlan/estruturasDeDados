from util import Util

tabela_hash = set()

nome_arquivo = "../atomos.csv"
Util.popular_arquivo_no_hash(tabela_hash, nome_arquivo)
Util.mostrar_hash(tabela_hash)
