using System.Collections.Generic;

HashSet<Atomo> tabelaHash = new HashSet<Atomo>();

string nomeArquivo = "../atomos.csv";
Util.popularArquivoNoHash(tabelaHash, nomeArquivo);
Util.mostrarHash(tabelaHash);
