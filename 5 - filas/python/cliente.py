
class Cliente:  
    def __init__(self, fone, nome, ficha):
        self.fone = fone
        self.nome = nome
        self.ficha_atendimento = ficha
    
    def __str__(self):
        return "Cliente: " + self.nome + " : " + self.fone + " -> Ficha: " + self.ficha_atendimento + "\n"
