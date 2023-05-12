RECURSÃO == REPETIÇÃO
    A) inicialização da variável de controle - parâmetro
    B) teste de parada com a variável de controle - primeiro if
    C) transformação da variável de controle - ponto de recursão

void metodoR(int varControle) {
    if (varControle) {
        codigoNoEmpilhamento;

        metodoR(varControle transformada);

        codigoNoDesempilhamento;
    }
}

    VANTAGEM:
        - código enxuto
        - possibilidade de executar código no empilhar e no desempilhar

    DESVANTAGEM:
        - consumo excessivo de memória