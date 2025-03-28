from aluno import Aluno

class Principal:
    alunos = []
    matricula = 1
    while (True):
        nome = input("Digite nome: ").upper()
        tmp = Aluno(matricula, nome)

        if (tmp in alunos):
            print("Aluno com este email ja cadastrado!")
        else:
            alunos.append(tmp)
            print("Aluno cadastrado com a matricula de numero ", matricula)
            print("E com o email ", tmp.email)
            matricula+=1
        
        opcao = input("Continua? [1-Sim; Outra tecla-Nao]")
        if (opcao != "1"):
            break

    alunos.sort(key=lambda aluno: aluno.nome)

    print("Relacao alunos")
    for aluno in alunos:
        print(aluno)
    