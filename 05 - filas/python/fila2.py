import queue 
import time

from aluno import Aluno

fila_alunos = queue.Queue()

fila_alunos.put(Aluno(1,"Saccol"))
fila_alunos.put(Aluno(7,"Pinheiro"))
fila_alunos.put(Aluno(2,"Iago"))

for i in range(2):    
    matricula = input("Matricula: ")
    nome = input("Nome: ")
    fila_alunos.put(Aluno(matricula, nome))

print("Exibindo fila")
for item in fila_alunos.queue:
    print(item)

print("Exibindo inicio ou cabeça/head da fila")
print(fila_alunos.queue[0])

print("Exibindo final da fila")
print(fila_alunos.queue[-1])

print("Exibindo se fila esta vazia")
print(fila_alunos.empty())

print("Exibindo o tamanho da fila")
print(fila_alunos.qsize())    

print("Verificando se 2,Iago esta na fila")
a = Aluno(2,"Iago")
print(a in fila_alunos.queue)

while (not fila_alunos.empty()):
    print("Removendo ...")
    print(str(fila_alunos.get_nowait()))
    time.sleep(1)
    
# print("Removendo ..." + str(fila_alunos.get_nowait()))
