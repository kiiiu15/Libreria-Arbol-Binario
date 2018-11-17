#include <stdio.h>
#include <stdlib.h>
#include "funciones_arbol_binario.h"



int main ()
{
    nodo3* arbol=inic_arbol();
    arbol=cargar_este(arbol);
    mostrar_arbol(arbol);
    printf("%d\n", suma_de_un_campo_en_este(arbol));
    /*while (1)
    {
       mostrar_arbol(arbol);
       system("pause");
    }*/

    return 0;
}
