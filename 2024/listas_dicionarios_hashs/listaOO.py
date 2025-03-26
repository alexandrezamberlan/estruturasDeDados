class Aluno:
    def __init__(self, matricula, nome):
        self.matricula = matricula
        self.nome = nome.upper()
        self.gerar_email()

    def gerar_email(self):
        vetor_nomes = self.nome.split()
        self.email = vetor_nomes[0] + "." + vetor_nomes[-1] + "@aluno.com"
        self.email = self.email.lower()
    
    def __str__(self):
        return f"{self.matricula} - {self.nome} - {self.email}"
    
    def __eq__(self, outro):     
        return self.email == outro.email

alunos = []
matricula = 1

while True:
    nome = input("Digite nome completo: ")
    alunoTmp = Aluno(matricula, nome)
    if alunoTmp in alunos:
        print("Aluno ja cadastrado!")
    else:
        alunos.append(alunoTmp)
        matricula += 1
    opcao = input("Deseja continuar? (S/N): ")
    if opcao.upper() == "N":
        break

alunos.sort(key=lambda x: x.nome)

for aluno in alunos:
    print(aluno)