lista_nomes = []

while (True):
    nome = input("Digite um nome ou sair para finalizar: ").upper()
    if nome == 'SAIR':
        break
    
    if (nome not in lista_nomes):
        lista_nomes.append(nome) #add ou inserir
    else:
        print('Nome já cadastrado')

lista_nomes.sort()

for i in lista_nomes:
    print(i)