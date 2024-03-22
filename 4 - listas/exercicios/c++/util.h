#include <ctime>
#include <cstdlib>
#include <string>


using namespace std;

Lista *popularLista(Lista* lista, int n)
{
    int valor;
    srand(time(NULL));
    int i = 0;
    while (i < n)
    {
        lista = inserir(rand() % 20, lista);
        i++;
    }
    return lista;
}

Lista *localizarComuns(Lista * listaA, Lista * listaB) {
    Lista * listaResultado = NULL;
    Lista *p1, *p2;

    for (p1 = listaA; p1; p1 = p1->prox) {
        for (p2 = listaB; p2; p2 = p2->prox) {
            if (p1->dado == p2->dado){
                listaResultado = inserir(p1->dado, listaResultado);
            }
        }    
    }
    return listaResultado;
} 

Lista *localizarDisjuncao(Lista* listaA, Lista* listaB)
{
    Lista* lista_resultado = NULL;
    bool localizado;
    Lista *p1, *p2;
    for (p1 = listaA; p1; p1 = p1->prox) 
    {
        localizado = false;
        for (p2 = listaB; p2; p2 = p2->prox) {
            if (p1->dado == p2->dado)
            {
                localizado = true;
                break;
            }
        }
        if (!localizado)
        {
            lista_resultado = inserir(p1->dado, lista_resultado);
        }

        for (p2 = listaB; p2; p2 = p2->prox)
        {
            localizado = false;
            for (p1 = listaA; p1; p1 = p1->prox)
            {
                if (p1->dado == p2->dado)
                {
                    localizado = true;
                    break;
                }
            }
            if (!localizado)
            {
                lista_resultado = inserir(p2->dado, lista_resultado);
            }
        }
    }
    return lista_resultado;
}