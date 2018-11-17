#include <stdio.h>
#include <stdlib.h>
#include "funciones_arbol_binario.h"


nodo3* inic_arbol ()
{
    nodo3* retorno=NULL;
    return retorno;
}
nodo3* inic_nodo ()
{
    nodo3* retorno=NULL;
    return retorno;
}

nodo3* crear_nodo (contenido_nodo3 datos)
{
    nodo3* nuevo_nodo=(nodo3*) malloc (sizeof(nodo3));
    nuevo_nodo->campos=datos;
    nuevo_nodo->derecha=inic_nodo();
    nuevo_nodo->izquierda=inic_nodo();

    return nuevo_nodo;

}

int esta_en_este (nodo3* arbol, int este_dato)
{
    int esta=0;
    if (arbol != inic_arbol)
    {
        if (arbol->campos.valor == este_dato)
            esta=1;
        else if (!esta_en_este (arbol->derecha, este_dato))
        {
            esta=esta_en_este (arbol->izquierda, este_dato);
        }
        else
        {
            esta=1;
        }
    }

    return esta;
}

int suma_de_un_campo_en_este (nodo3* arbol)
{
    int sumatoria=0;
    if (arbol != inic_arbol())
    {
        sumatoria=suma_de_un_campo_en_este(arbol->derecha);
        sumatoria=sumatoria+arbol->campos.valor;
        sumatoria=sumatoria+ suma_de_un_campo_en_este (arbol->izquierda);
    }

    return sumatoria;
}


contenido_nodo3 cargar_nodo ()
{
    contenido_nodo3 datos;
    fflush(stdin);
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(datos.nombre);
    printf("Ahora ingrese la edad\n");
    fflush(stdin);
    scanf("%i", &datos.valor);
    return datos;
}



nodo3* insertar_en_este (nodo3* arbol, contenido_nodo3 estos_datos)
{

    if (arbol == inic_arbol())
    {
        arbol=crear_nodo(estos_datos);

    }
    else
    {

        if (estos_datos.valor > arbol->campos.valor)
        {
            arbol->derecha=insertar_en_este(arbol->derecha, estos_datos);
        }
        else
        {
            arbol->izquierda=insertar_en_este(arbol->izquierda, estos_datos);
        }
    }
    return arbol;
}


nodo3* cargar_este (nodo3* arbol)
{
    char control="s";
    contenido_nodo3 datos;
    while (control != 'n')
    {
        datos=cargar_nodo();
        arbol=insertar_en_este(arbol, datos);
        printf("Desea cargar otro nodo? s/n \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return arbol;
}

int gotoxy(int x, int y)
{
    COORD coord;
    HANDLE h_stdout;

    coord.X = x;
    coord.Y = y;

    if ((h_stdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
        return 0;

    if (SetConsoleCursorPosition(h_stdout, coord) == 0)
        return 0;

    return 1;
}



tamanio_de_la_consola obtener_area_de_la_consola ()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    tamanio_de_la_consola tdc;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    tdc.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    tdc.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return tdc;
}


void mostrar_arbol (nodo3* arbol)
{
    system("cls");
    tamanio_de_la_consola datos=obtener_area_de_la_consola();
    tamanio_de_la_consola posicion;
    posicion.columns=datos.columns/2;
    posicion.rows=datos.rows;
    posicion.rows=0;
    printf("%i",posicion.columns);
    mostrar_arbol_izquierda(arbol,posicion);
    gotoxy(0, 15);
    printf("\n");

}


void mostrar_arbol_izquierda(nodo3* a_mostrar, tamanio_de_la_consola posicion)
{
    int distancia_al_nodo_raiz;
    gotoxy(posicion.columns,posicion.rows);
    if (a_mostrar != inic_arbol())
    {
        mostrar_nodo(a_mostrar);
        if (!es_hoja_este_nodo(a_mostrar))
        {
            dibuja_lineas_izquierda(posicion);
        }
        posicion.rows=posicion.rows+2;
        posicion.columns=posicion.columns/2;
        distancia_al_nodo_raiz=posicion.columns;
        mostrar_arbol_izquierda(a_mostrar->izquierda,posicion);
        posicion.columns=posicion.columns*3;
        mostrar_arbol_derecha(a_mostrar->derecha, posicion,distancia_al_nodo_raiz/2);

    }
}

void dibuja_lineas_izquierda (tamanio_de_la_consola datos)
{
    int i;
    int hasta=((datos.columns/2)*3+5);
    int desde=((datos.columns/2)+5);
    int pos_nodo_raiz=(datos.columns/2)+2;
    int posicionamiento=(datos.columns/2);
    gotoxy(posicionamiento+5, datos.rows+1);
    printf("v");
    for (i=3; i<hasta-desde; i++)
    {
        if (i== pos_nodo_raiz)
        {
            printf("+");
        }
        printf("-");
    }
    printf("v");
}


void mostrar_arbol_derecha(nodo3* a_mostrar, tamanio_de_la_consola posicion, int distancia_al_nodo_raiz)
{
    gotoxy(posicion.columns,posicion.rows);

    if (a_mostrar != inic_arbol())
    {
        mostrar_nodo(a_mostrar);
        if (!es_hoja_este_nodo(a_mostrar))
        {
            dibuja_lineas_derecha(posicion, distancia_al_nodo_raiz);
        }
        posicion.rows=posicion.rows+2;
        posicion.columns=posicion.columns-distancia_al_nodo_raiz;
        mostrar_arbol_derecha(a_mostrar->izquierda, posicion, distancia_al_nodo_raiz/2);
        posicion.columns=posicion.columns+distancia_al_nodo_raiz*2;
        mostrar_arbol_derecha(a_mostrar->derecha, posicion, distancia_al_nodo_raiz/2);

    }
}



void dibuja_lineas_derecha (tamanio_de_la_consola datos,int distancia_al_nodo_raiz)
{
    int i;
    int posicionamiento=datos.columns-distancia_al_nodo_raiz;
    int condicion=distancia_al_nodo_raiz*2;
    gotoxy(posicionamiento+5, datos.rows+1);
    printf("v");
    for (i=3; i<condicion; i++)
    {
        if (i== distancia_al_nodo_raiz+2)
        {
            printf("+");
        }
        printf("-");
    }
    printf("v");
}

void mostrar_nodo(nodo3* a_mostrar)
{
    if (a_mostrar != inic_arbol())
    {
        char buffer [50];
        sprintf(buffer, "%s (%d)",a_mostrar->campos.nombre,a_mostrar->campos.valor);
        printf("[%s]",buffer);
    }
    else
    {
        printf("[NULL]");
    }
}

int es_hoja_este_nodo (nodo3* a_verficar)
{
    int respuesta = 0;
    if ((a_verficar->derecha == inic_nodo()) && (a_verficar->izquierda == inic_nodo()))
    {
        respuesta=1;
    }

    return respuesta;
}


nodo3* borrar_nodo (nodo3* arbol, int valor)
{
    nodo3* piboteo;
    if (arbol != inic_arbol())
    {

        if (arbol->campos.valor == valor)
        {

            if (es_hoja_este_nodo(arbol)==1)
            {

                free(arbol);
                arbol=inic_arbol();
            }
            else
            {
                if (arbol->izquierda != inic_arbol())
                {
                   piboteo= nodo_mas_derecha_de_este(arbol->izquierda);
                   arbol->campos=piboteo->campos;
                   arbol->izquierda=borrar_nodo(arbol->izquierda, piboteo->campos.valor);
                }
                else
                {
                    if (arbol->derecha != inic_arbol())
                    {
                        piboteo=nodo_mas_izquierda_de_este(arbol->derecha);
                        arbol->campos=piboteo->campos;
                        arbol->derecha=borrar_nodo(arbol->derecha, piboteo->campos.valor);
                    }
                }
            }
        }
        else
        {
            if (arbol->campos.valor > valor)
            {
                arbol->izquierda=borrar_nodo(arbol->izquierda,valor);
            }
            else
            {
                arbol->derecha=borrar_nodo(arbol->derecha, valor);
            }
        }
    }
    return arbol;
}


nodo3* nodo_mas_derecha_de_este (nodo3* arbol)
{
    nodo3* retorno;
    if (arbol->derecha == inic_arbol())
    {
        retorno=arbol;
    }
    else
    {
        retorno=nodo_mas_derecha_de_este(arbol->derecha);
    }
    return retorno;

}


nodo3* nodo_mas_izquierda_de_este (nodo3* arbol)
{
        nodo3* retorno;
    if (arbol->izquierda == inic_arbol)
    {
        retorno=arbol;
    }
    else
    {
        retorno=nodo_mas_izquierda_de_este(arbol->izquierda);
    }
    return retorno;

}







