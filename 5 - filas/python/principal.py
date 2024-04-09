import queue
from cliente import Cliente

@staticmethod
def chamar(fila, quantidade_atendimento):
    print("entrei no chamar.....")
    try:
        obj = fila.get_nowait()
        print("Chamando ficha ..." + obj.ficha_atendimento)
        quantidade_atendimento += 1
    except Exception as e:
        print(e)

@staticmethod
def menu(fila_normal, fila_prioritaria):
    quantidade_atendimento = 0
    contador_normal = 0
    contador_prioritario = 1000

    while (True):
        print("1 - Normal")
        print("2 - Prioritário")
        print("3 - Chamar")
        print("4 - Finalizar")
        op = input("Opção: ")
        if op == '1':
            contador_normal += 1
            nome = input("Nome do cliente: ").upper()
            fone = input("Fone do cliente: ").upper()
            fila_normal.put(Cliente(fone, nome, contador_normal))     
            print("Imprimindo a ficha ", contador_normal)               
        elif op == '2':
            contador_prioritario += 1
            nome = input("Nome do cliente: ").upper()
            fone = input("Fone do cliente: ").upper()
            fila_prioritaria.put(Cliente(fone, nome, contador_prioritario))
            print("Imprimindo a ficha ", contador_prioritario)
        elif op == '3':            
            if (quantidade_atendimento % 3 == 0):
                #chamar ficha prioritaria
                chamar(fila_prioritaria,quantidade_atendimento)                
            else:
                #chamar ficha normal
                chamar(fila_normal, quantidade_atendimento)
                
        elif op == '4':
            break                
        else:
            print("Opção inválida\n")

fila_normal = queue.Queue()
fila_prioritaria = queue.Queue()

menu(fila_normal, fila_prioritaria)
