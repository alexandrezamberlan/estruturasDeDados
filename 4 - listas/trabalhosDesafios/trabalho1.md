# Trabalho 1

Na linguagem C++ ou nas linguagens estudadas fazer os seguintes PROGRAMAS:
  - Gerar N listas de tamanho M com números aleatórios.
  - Mostrar seus conteúdos.
  - Mostrar os números que aparecem nas N listas.
  - Mostrar os números que aparecem somente em uma das listas.


List<List> listaGenerica = new List<List>();

for (int i = 0; i < 10; i++) {
  listaGenerica.add( new List<Integer>() );
}

listaGenerica[0].add(6);
