# Criando um set
meu_set = {1, 2, 3, 4, 5}

# Adicionando elementos
meu_set.add(6)

# Removendo um elemento
meu_set.remove(3)

# Verificando se um elemento está presente
print(2 in meu_set)  # Saída: True

# Iterando sobre os elementos do set
for elemento in meu_set:
    print(elemento)

# Operações de conjunto
outro_set = {4, 5, 6, 7, 8}

# União
uniao = meu_set | outro_set

# Interseção
intersecao = meu_set & outro_set

# Diferença
diferenca = meu_set - outro_set

print(uniao)
print(intersecao)
print(diferenca)
