import os

from util import Util

lista1 = []
lista2 = []
lista_comuns = []
lista_disjuncao = []


objeto = Util()

objeto.popular_lista(lista1, 8)
objeto.popular_lista(lista2, 8)

os.system('cls')

objeto.exibir_lista("Lista 1", lista1)
objeto.exibir_lista("Lista 2", lista2)

os.system('pause')

objeto.localizar_comuns(lista_comuns, lista1, lista2)
objeto.exibir_lista("Numeros comuns nas listas", lista_comuns)

objeto.localizar_disjuncao(lista_disjuncao, lista1, lista2)
objeto.exibir_lista("Numeros disjuntos nas listas", lista_disjuncao)