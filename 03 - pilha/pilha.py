def exibir(pilha):
    for item in pilha:
        print(item)

pilha = []

pilha.append(6)
pilha.append(10)
pilha.append(5)

exibir(pilha)

print("Tamanho da pilha: ", len(pilha))
print("O topo da pilha: ", pilha[-1])
print("8 esta contido ou nao na pilha? ", 8 in pilha)

pilha.pop()
print("Pilha depois da remocao...")
exibir(pilha)

pilha.clear()
print("Pilha depois da destruicao...")
exibir(pilha)