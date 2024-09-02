# 1ª Avaliação Semestral de Sistemas Distribuídos - 2024
## Unidade 1 - Curso de Ciëncia da Computação - UFN - Prof. Alexandre Zamberlan
### Nome: ______________________________________________

1. **Explique a diferença entre arquitetura cliente-servidor e arquitetura peer-to-peer em sistemas distribuídos. Quais são as principais vantagens e desvantagens de cada uma?**

2. **Explique a diferença de Sistemas Distribuídos de Sistemas Paralelos.**

3. **O que é sincronização em sistemas distribuídos? Compare e contraste a sincronização baseada em relógio lógico e a sincronização baseada em relógio físico.**

4. **Explique o recurso exclusão mútua**

5. **Defina o termo "escalabilidade" em sistemas distribuídos. Quais são os principais desafios enfrentados ao tentar escalar um sistema distribuído?**

6. **O que são 'locks' em sistemas distribuídos e como eles são usados para gerenciar o acesso a recursos compartilhados? Quais são os problemas associados ao uso de locks, como o deadlock?**

7. **Em sistemas distribuídos, algumas vezes os processos compartilham memória. Quais são os problemas envolvidos e como resolver tal situação, garantindo sincronização**

8. **Descreva o papel das 'threads' em sistemas distribuídos. Como a criação e o gerenciamento de threads podem impactar o desempenho de um sistema distribuído?**

9. **Você foi solicitado a desenvolver um programa que realiza as seguintes operações:**

 1) Leitura de Arquivos: O programa deve ler o conteúdo de múltiplos arquivos de texto. Cada arquivo contém uma lista de números inteiros (um por linha).
 2) Armazenamento em Listas: O conteúdo de cada arquivo deve ser armazenado em uma lista separada.
 3) Ordenação: Após a leitura e armazenamento dos números, o programa deve ordenar cada lista individualmente.
 4) Escrita em Arquivo: O conteúdo ordenado de cada lista deve ser escrito em um novo arquivo de texto. Cada lista deve ser salva em um arquivo com o mesmo nome que o arquivo original, mas com um sufixo "_sorted".

Aqui está o esqueleto do código fornecido:

```python
import os

def read_file(file_path):
    with open(file_path, 'r') as file:
        return [int(line.strip()) for line in file]

def write_file(file_path, data):
    with open(file_path, 'w') as file:
        for item in data:
            file.write(f"{item}\n")

def sort_list(data):
    return sorted(data)

def process_files(input_files):
    for file in input_files:
        data = read_file(file)
        sorted_data = sort_list(data)
        output_file = f"{os.path.splitext(file)[0]}_sorted.txt"
        write_file(output_file, sorted_data)

# Lista de arquivos a serem processados
input_files = ['file1.txt', 'file2.txt', 'file3.txt']
process_files(input_files)
```

**Pergunta:**

9.1. **Identificação de Pontos de Paralelismo:** Analise o código fornecido e identifique possíveis pontos em que a criação e o uso de threads podem melhorar o desempenho do programa. Considere a leitura de arquivos, a ordenação das listas e a escrita de arquivos. Explique como a utilização de threads pode otimizar essas operações.

9.2. **Modificação do Código:** Baseado em sua análise, modifique o código para incluir o uso de threads nos pontos identificados. Mostre como os threads podem ser implementados e justifique suas escolhas.

**Dicas:**

- Considere o impacto da leitura e escrita de arquivos em termos de I/O e como threads podem ajudar a realizar essas operações em paralelo.
- Avalie a possibilidade de paralelizar a ordenação das listas, especialmente se elas forem grandes e a ordenação for computacionalmente intensiva.
- Lembre-se de que o Python possui a biblioteca `threading` para gerenciar threads, e a sincronização pode ser necessária para evitar condições de corrida, se aplicável.


10. Explain the main principles of the Brazilian General Data Protection Law (LGPD) and discuss how it impacts companies that process personal data. The answer can be written in Portuguese.
