import random

class Util:
    def popular_lista(self, lista, n):                
        i = 0
        while (i < n):
            valor = random.randint(0,20)
            if (valor not in lista):
                lista.append(valor)
                lista.sort()
                i += 1

    def exibir_lista(self,frase, lista):
        print(frase)
        for item in lista:
            print(str(item) + "\t", end="")
        
        print()

    def localizar_comuns(self, lista_resultado, listaA, listaB):
        for item1 in listaA:
            for item2 in listaB:
                if (item1 == item2):
                    lista_resultado.append(item1)
            

    def localizar_disjuncao(self,lista_resultado, listaA, listaB):        
        for item1 in listaA:
            localizado = False
            for item2 in listaB:
                if item1 == item2:
                    localizado = True
                    break
                
             
            if not localizado:
                lista_resultado.append(item1)
            
        for item2 in listaB:
            localizado = False
            for item1 in listaA:
                if item1 == item2:
                    localizado = True
                    break
            if not localizado:
                lista_resultado.append(item2)

        lista_resultado.sort()
