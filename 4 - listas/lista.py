lista = []

for i in range(4):
    valor = int(input('Digite um numero inteiro: '))
    if (valor not in lista):
        lista.append(valor)
        lista.sort()

print(lista)