def procurar_palavra_no_arquivo(palavra, nome_arquivo):
    try:
        with open(nome_arquivo, 'r') as arquivo:
            for linha in arquivo:
                if palavra in linha:
                    return True
    except FileNotFoundError:
        print(nome_arquivo, "é um arquivo não encontrado.")
    return False

def main():
    import sys
    
    if len(sys.argv) != 3:
        print("Quantidade de argumentos inválida")
        sys.exit(0)

    nome_arquivo = sys.argv[1]
    palavra = sys.argv[2]

    print("Arquivo de busca:", nome_arquivo)
    print("Palavra de busca:", palavra)

    if procurar_palavra_no_arquivo(palavra, nome_arquivo):
        print("Palavra encontrada")
    else:
        print("Palavra não encontrada")

if __name__ == "__main__":
    main()
