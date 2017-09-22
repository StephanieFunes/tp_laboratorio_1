#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tam corresponde a la cantidad de elementos del array.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tam corresponde a la cantidad de elementos del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], long int dni, int tam);

/**
 * Lee por pantalla el nombre, dni y edad de una persona y la guarda.
 * @param lista el array donde se guardarán las personas.
 * @param posicion la posicion de la persona que se desea agregar.
 */
void cargarDatos (EPersona lista[], int posicion);

/**
 * Borra a la persona en la posición que se le pasa.
 * @param lista el array se pasa como parametro.
 * @param posicion la posicion de la persona que se desea borrar.
 */
void borrarPersona (EPersona lista[], int posicion);

/**
 * Imprime por pantalla las persona cargadas de la lista.
 * @param lista el array se pasa como parametro.
 * @param tam corresponde a la cantidad de elementos del array.
 */
void mostrarPersonas (EPersona lista[], int tam);

/**
 * Carga el nombre, dni y edad de varias personas pre-definidas sin intervención del usuario.
 * @param lista el array donde se guardarán las personas.
 * @param tam corresponde a la cantidad de elementos del array.
 */
void cargarDatosDePrueba (EPersona lista[], int tam);

/**
 * Ordena la lista de personas de forma cresciente por nombre.
 * @param lista el array se pasa como parametro.
 * @param tam corresponde a la cantidad de elementos del array.
 */
void ordenarPersonas (EPersona lista[], int tam);

/**
 * Imprime un histograma de edades separados en tres grupos.
 * @param lista el array se pasa como parametro.
 * @param tam corresponde a la cantidad de elementos del array.
 */
 void histograma(EPersona lista[], int tam);

/**
 * Devuelve "*" o " " según corresponda para la fila y el contador actuales.
 * @param fila el número de fila del gráfico.
 * @param contador la cantidad de peronas en el grupo actual.
 */
 char asterisco(int fila, int contador);

/**
 * Devuelve el mayor entre ambos parámetros.
 * @param a primer número.
 * @param b segundo número.
 */
 int maximo(int a, int b);

#endif // FUNCIONES_H_INCLUDED
