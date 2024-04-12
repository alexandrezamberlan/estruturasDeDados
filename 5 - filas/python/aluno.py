class Aluno:
    
    def __init__(self, matricula, nome):
        self.matricula = matricula
        self.nome = nome
    
    def __str__(self):
        return "Aluno [matricula=" + str(self.matricula) + ", nome=" + self.nome + "]"

    def __eq__(self, obj):
        if (self.matricula != obj.matricula):
            return False
        if (self.nome != obj.nome):
            return False
        return True
    