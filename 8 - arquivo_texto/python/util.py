from atomo import Atomo

class Util:
    @staticmethod
    def popular_arquivo_no_hash(tabela_hash, nome_arquivo):
        try:
            with open(nome_arquivo, "r", encoding='utf8') as leitor:
                for linha in leitor:
                    dados_linha = linha.split(';')
                    dados_linha[3] = dados_linha[3].replace('\n','\0')
                    atomo = Atomo(dados_linha[0], dados_linha[1], dados_linha[2], dados_linha[3])
                    tabela_hash.add(atomo)
        except Exception as e:
            print(e)

    @staticmethod
    def mostrar_hash(tabela_hash):
        for atomo in tabela_hash:
            print(atomo)