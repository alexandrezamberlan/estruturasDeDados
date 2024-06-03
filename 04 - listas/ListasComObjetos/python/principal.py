from aluno import Aluno

lista_alunos = []    

for i in range(3):   
    nome = input("Nome: ").upper()    
    idade = input("Idade: ")    
    curso = input("Curso: ").upper()
    
    obj = Aluno(nome,idade,curso)
    
    if obj not in lista_alunos:
        lista_alunos.append(obj)
        lista_alunos.sort(key = lambda aluno: aluno.nome and aluno.idade)
    else:
        print("Aluno ja cadastrado")
    
for aluno in lista_alunos:
    print(aluno)

nome = input("Nome para remoção: ")
idade = input("Idade do aluno a ser removido: ")

try:
    lista_alunos.remove(Aluno(nome,idade,None))

    print("Lista apos remocao")
    for aluno in lista_alunos:
        print(aluno)
except:
    print("Nome nao encontrado")
