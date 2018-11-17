#ifndef ARBOL_BINARIO_FUNCIONES_H_INCLUDED
#define ARBOL_BINARIO_FUNCIONES_H_INCLUDED
#include <string.h>
#include<conio.h>
#include <dos.h>
#include <windows.h>
#define m 30
typedef struct
{
    char nombre [m];
    int valor;
} contenido_nodo3;

typedef struct
{
    contenido_nodo3 campos;
    struct nodo3* izquierda;
    struct nodo3* derecha;
}nodo3;
typedef struct
{
    int columns, rows;
}tamanio_de_la_consola;

///.......................................................
/*FUNCIONES PARA MOSTRAR EL ARBOL*/
tamanio_de_la_consola obtener_area_de_la_consola ();
int gotoxy(int , int );
void mostrar_arbol_izquierda(nodo3*, tamanio_de_la_consola);
void mostrar_arbol_derecha(nodo3*, tamanio_de_la_consola, int );
void dibuja_lineas_izquierda(tamanio_de_la_consola);
void dibuja_lineas_derecha (tamanio_de_la_consola, int);
///.........................................................




nodo3* inic_arbol ();
nodo3* inic_nodo ();
nodo3* crear_nodo (contrnido_nodo3);
int esta_en_este (nodo3*, int);
int suma_de_un_campo_en_este (nodo3*);
contenido_nodo3 cargar_nodo ();
void mostrar_nodo(nodo3*);
nodo3* insertar_en_este (nodo3*, contenido_nodo3);
/*void mostrar_en_preorder_este(nodo3*);
void mostrar_en_orden_este(nodo3*);
void mostrar_en_postorder_este(nodo3*);*/
nodo3* cargar_este (nodo3*);
int es_hoja_este_nodo (nodo3* );
///..........Borrar_nodo......................................
nodo3* borrar_nodo (nodo3*, int);
nodo3* nodo_mas_derecha_de_este (nodo3*);
nodo3* nodo_mas_izquierda_de_este (nodo3*);
///...........................................................



#endif // ARBOL_BINARIO_FUNCIONES_H_INCLUDED
