class Aluno:
    
    #metodo construtor
    def __init__(self, nome, idade, curso):
        self.nome = nome
        self.idade = idade
        self.curso = curso
    
    def __str__(self):
        return f"[{self.nome}, {self.idade}, {self.curso}]"
        #return "[nome=" + self.nome + ", idade=" + self.idade + ", curso=" + self.curso + "]"

    def __eq__(self, obj):
        if isinstance(obj, Aluno):    
            if (self.nome != obj.nome):
                return False
            if (self.idade != obj.idade):
                return False
            return True
        return False