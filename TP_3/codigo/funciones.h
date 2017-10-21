#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[2000];
    int puntaje;
    char linkImagen[200];
}EMovie;

/**
 *  Agrega una pelicula al lugar apuntado por movie, pidiendo los datos por pantalla
 *  @param movie puntero a la estructura para cargar los datos
 */
int agregarPelicula(EMovie *movie);

/**
 *  Muestra un mensaje que se le pasa como parámetro
 *  @param mensaje es el texto que se le muestra al usuario.
 *  @param destino es el campo de la estructura donde se guardan los datos
 */
void pedirString (char* mensaje, char* destino);

/**
 *  Muestra por pantalla una pelicula que se ingresó
 *  @param movies es el puntero a la estructura que contiene la información
 *  @param cantidad es la cantidad de peliculas que hay cargadas
*/
void imprimirPelicula (EMovie *movies, int cantidad);

/**
 *  Modifica los datos de una pelicula
 *  @param movies puntero a la estructura
 *  @param cantidad es la cantidad de peliculas que hay cargadas
 */
void modificarPelicula (EMovie *movies, int cantidad);

/**
 *  Borra una pelicula que se ingresó
 *  @param movie puntero a la estructura
 *  @param cantidad es la cantidad de peliculas que hay cargadas
 */
int borrarPelicula (EMovie *movies, int cantidad);

/**
 *  Compara un array de caracteres y devuelve 1 si la cadena *str comienza con la cadena *pre
 *  @param pre corresponde al prefijo que queremos comparar
 *  @param str corresponde a la cadena
 */
int comienzaCon(const char *pre, const char *str);

/**
 *  Guarda en un archivo los datos cargados de las películas
 *  @param peliculas es el puntero a la estructura para guardar los datos
 *  @param cantidad es la cantidad de peliculas que hay cargadas
 *  @param nombre corresponde al nombre y a la ruta del archivo que creamos para guardar los datos
 */
void guardarArchivo (EMovie* peliculas, int cantidad, char nombre[]);

/**
 *  Carga los datos de las películas que fueron guardadas
 *  @param peliculas modifica las peliculas cargadas que se le pasa
 *  @param cantidad modifica la cantidad de peliculas que se le pasa
 *  @param tamPeliculas modifica el tamaño de peliculas que se le pasa
 *  @param nombre es el nombre del archivo que se va a cargar
 */
void cargarArchivo (EMovie** peliculas, int* cantidad, int* tamPeliculas, char nombre[]);

/**
 *  Genera una pagina web con todas la peliculas cargadas
 *  @param peliculas  es el puntero a la estructura
 *  @param cantidadPeliculas es la cantidad de peliculas que hay cargadas
 *  @param nombre es el nombre del archivo donde se va a guardar la pagina
 */
void html (EMovie* peliculas, int cantidadPeliculas, char nombre[]);

/**
 *  Escribe un fragmento del archivo html que corresponde a la cabecera y al pie
 *  @param nombre es el nombre del archivo que se va a leer y se va a insertar en el archivo de salida
 *  @param archivoSalida corresponde al archivo en el que se van a insertar los fragmentos del html
 */
void escribirFragmento (char nombre[], FILE* archivoSalida);

/**
 *  Escribe los datos de las películas ingresadas en el archivo html
 *  @param peliculas  es el puntero a la estructura
 *  @param cantidad es la cantidad de peliculas que hay cargadas
 *  @param archivoSalida corresponde al archivo en el que se van a insertar los datos de las peliculas cargadas
 */
void escribirPeliculas(EMovie* peliculas, int cantidadPeliculas, FILE* archivoSalida);
#endif // FUNCIONES_H_INCLUDED
