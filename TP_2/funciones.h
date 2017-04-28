#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define CANTIDAD 8

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Lee por pantalla el nombre, dni y edad de una persona y la guarda.
 * @param lista el array donde se guardarán las personas.
 * @param posicion la posicion de la persona que se desea agregar.
 */
void agregarPersona(EPersona lista[], int posicion);

/**
 * Ordena la lista de persona de forma cresciente por nombre.
 * @param lista el array se pasa como parametro.
 */
void ordenarPorNombre(EPersona lista[]);

/**
 * Imprime por pantalla las persona cargadas de la lista.
 * @param lista el array se pasa como parametro.
 */
void imprimirLista (EPersona lista[]);

/**
 * Lee por pantalla el dni de la persona a borrar, pide confirmación y la remueve.
 * @param lista el array se pasa como parametro.
 */
void borrarPersona (EPersona lista[]);

/**
 * Intercambia el valor de los parámateros pasador por referencia.
 * @param x el primer valor.
 * @param y el segundo valor.
 */
void swap(int*x, int*y);

/**
 * Imprime un histograma de edades separados en tres grupos.
 * @param lista el array se pasa como parametro.
 */
 void histograma(EPersona lista[]);

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
