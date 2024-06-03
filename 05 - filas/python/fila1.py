import queue

fila_numeros = queue.Queue()

fila_numeros.put("Pedro")
fila_numeros.put("Alice")
fila_numeros.put("Joao")

print("Exibindo fila")
for item in fila_numeros.queue:
    print(item)

print("Exibindo inicio ou cabeça/head da fila")
print(fila_numeros.queue[0])
print("Exibindo final da fila")
print(fila_numeros.queue[-1])

print("Exibindo se fila esta ou nao vazia")
print(fila_numeros.empty())

print("Exibindo o tamanho da fila")
print(fila_numeros.qsize())

print("Verificando se Carlos esta ou nao na fila")
print("Carlos" in fila_numeros.queue)