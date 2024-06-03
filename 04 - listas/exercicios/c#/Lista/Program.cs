using Lista;
using System;
using System.Collections;

List<int> lista1 = new List<int>();
List<int> lista2 = new List<int>();
List<int> listaComuns = new List<int>();
List<int> listaDisjuncao = new List<int>();

Util objeto = new Util();

objeto.popularLista(lista1, 8);
objeto.popularLista(lista2, 8);

objeto.exibirLista("Lista 1", lista1);
objeto.exibirLista("Lista 2", lista2);

listaComuns.AddRange(lista1.Intersect(lista2));
objeto.exibirLista("Números comuns nas duas listas",listaComuns);

listaDisjuncao.AddRange(lista1.Except(lista2));
listaDisjuncao.AddRange(lista2.Except(lista1));
objeto.exibirLista("Números em uma das listas", listaDisjuncao);












