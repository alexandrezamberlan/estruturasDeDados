equipes = {}

while (True):
    nome = input('Nome da equipe: ').upper()
    cidade = input('Cidade da equipe: ').upper()

    if nome not in equipes.keys():
        equipes[nome] = cidade
    else:
        print('Equipe já cadastrada....')
    opcao = input('1 - Continua; Outra tecla encerra: ')
    if opcao != '1':
        break

for chave,valor in equipes.items():
    print(f'Time:{chave} .Cidade: {valor}')
