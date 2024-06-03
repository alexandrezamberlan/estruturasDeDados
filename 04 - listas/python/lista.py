import random

def exibir(lista):
    for item in lista:
        print(item)

lista = []
for i in range(100):
    #valor = int(input('Digite um numero inteiro: '))
    valor = random.randint(0,400)
    if (valor not in lista):
        lista.append(valor)
        lista.sort()

print("Tamanho da lista ", len(lista))
exibir(lista)