class Aluno:
    #construtor
    def __init__(self, matricula, nome):
        self.matricula = matricula
        self.nome = nome
        self.email = self.gerar_email()
    
    def gerar_email(self):
        vetor_nomes = self.nome.lower().split(" ")
        return vetor_nomes[0] + "." + vetor_nomes[-1] + "@ufn.edu.br"
    
    def __str__(self):
        return "Aluno [nome=" + self.nome + ", email=" + self.email + "]"

    def __eq__(self, obj):
        # Verificando se obj é uma instância da classe Aluno
        if not isinstance(obj, Aluno):
            return False
        # Comparando o email dos dois objetos
        return self.email == obj.email


