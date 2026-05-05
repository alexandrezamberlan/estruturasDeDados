# recursão é uma operação de repetição via empilhamento de processo
# toda repetição precisa de 3 situações de ATENÇÃO:
    # inicialização da variável de controle
    # condição de parada
    # atualização da variável de controle
# contras de usar recursão:
    # pode causar estouro de pilha (stack overflow) se a profundidade da recursão for muito grande
    # pode ser menos eficiente em termos de tempo e memória do que soluções iterativas, 

# pros de usar recursão:
    # pode tornar o código mais simples e fácil de entender
    
def contagem_regressiva(n): # n é a variável de controle
    if n > 0: # condição de parada
        print(n) # codigo executado no empilhamento de processo
        contagem_regressiva(n - 1) # atualização da variável de controle, a cada chamada recursiva o valor de n diminui em 1

def contagem_progressiva(n):
    if n > 0:
        contagem_progressiva(n - 1)
        print(n) #codigo executado no desempilhamento de processo
        
def soma_elementos(n): #inicialização da varia'vel de controle
    if n > 0: #condição de parada
        soma = n + soma_elementos(n - 1) #empilhamento com a atualização da variável de controle
        return soma
    else:
        return 0
        
# def soma_elementos(n):
#     if n > 0:
#         return n + soma_elementos(n - 1)
#     else:
#         return 0

def soma_lista(lista, n):
    if n > 0:
        return lista[n - 1] + soma_lista(lista, n - 1)
    else:
        return 0
    
def conta_pares(lista, n):
    if n > 0:
        if lista[n - 1] % 2 == 0:
            return 1 + conta_pares(lista, n - 1)
        else:
            return 0 + conta_pares(lista, n - 1)
    else:
        return 0
    
def soma_pares(lista, n):
    if n > 0:
        if lista[n - 1] % 2 == 0:
            return lista[n - 1] + soma_pares(lista, n - 1)
        else:
            return 0 + soma_pares(lista, n - 1)
    else:
        return 0
        
if __name__ == "__main__":
    # contagem_regressiva(10)
    # contagem_progressiva(10)
    # print(soma_elementos(10))

    lista = [10, 15, 20, 25, 30]
    # print(soma_lista(lista, len(lista)))
    # print(conta_pares(lista, len(lista)))
    print(soma_pares(lista, len(lista)))
    
 # exercícios de fixação
 # 1) faça uma função recursiva que receba um número, uma lista, seu tamanho/comprimento e retorne a quantidade de vezes que o número aparece na lista. DICA: recursao com retorno de valor (return)
 
 # 2) faça uma função recursiva que receba um número, uma lista, seu tamanho/comprimento e substitua o número pelo valor -1. DICA: recursao sem retorno de valor (sem return)
 
 # 3) faça uma função recursiva que receba um número, uma lista, seu tamanho/comprimento e retorne a posição do número na lista (ou -1 se o número não estiver presente). DICA: recursao com retorno de valor (return)