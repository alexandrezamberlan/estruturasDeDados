class Atomo:
    #construtor
    def __init__(self, sigla, eixo_x, eixo_y, eixo_z):
        self.sigla = sigla
        self.x = eixo_x
        self.y = eixo_y
        self.z = eixo_z

    #override do equals
    def __eq__(self, other):
        if isinstance(other, Atomo):
            return self.sigla == other.sigla and self.x == other.x and self.y == other.y and self.z == other.z
        return False
    
    #override do maior que - usado na ordenação
    def __gt__(self, other):
        if self.sigla == other.sigla:
            return self.x < other.x
        return self.sigla < other.sigla
    
    #override do toString
    def __str__(self):
        return "Atomo{" + "sigla=" + self.sigla + ", eixo x=" + self.x + ", eixo y=" + self.y + ", eixo z=" + self.z + '}'
    
    #override do hash
    def __hash__(self):
        return hash((self.sigla, self.x, self.y, self.z))