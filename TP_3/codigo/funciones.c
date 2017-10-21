#include "funciones.h"

int agregarPelicula(EMovie *movie)
{
    pedirString("Ingrese el titulo: ", movie->titulo);

    pedirString("Ingrese el genero: ", movie->genero);

    printf("Ingrese la duracion: ");
    scanf("%d",&movie->duracion);
    if(movie->duracion <= 0)
    {
        printf("Error: la duración debe ser positiva\n");
        return 0;
    }

    pedirString("Ingrese la descripcion: ", movie->descripcion);

    printf("Ingrese el puntaje: ");
    scanf("%d",&movie->puntaje);
    if(movie->puntaje < 1 || movie->puntaje > 10)
    {
        printf("Error. El puntaje debe corresponder a un numero entre 1 y 10\n");
        return 0;
    }

    pedirString("Ingrese la direccion de la imagen: ", movie->linkImagen);
    if(!comienzaCon("http://", movie->linkImagen) && !comienzaCon("https://", movie->linkImagen))
    {
        printf("Error. La direccion de la imagen debe ser una url valida\n");
        return 0;
    }

    printf("\n");

    return 1;
}

int comienzaCon(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

void pedirString (char* mensaje, char* destino)
{
    fflush(stdin);
    printf("%s", mensaje);
    gets(destino);
}

int borrarPelicula (EMovie *movies, int cantidad)
{
    int i;
    char titulo[20];

    pedirString("Ingrese el titulo de la pelicula que desa borrar: ", titulo);

    for(i=0; i<cantidad; i++)
    {
        if(strcmp(movies[i].titulo,titulo)==0)
        {
            memcpy(movies+i, movies + cantidad - 1, sizeof(EMovie));
            return 1;
        }
    }

    return 0;
}

void modificarPelicula (EMovie *movies, int cantidad)
{
    int i;
    char titulo[20];

    pedirString("Ingrese el titulo de la pelicula que desa modificar: ", titulo);

    for(i=0; i<cantidad; i++)
    {
        if(strcmp(movies[i].titulo,titulo)==0)
        {
            agregarPelicula(movies+i);
            return;
        }
    }
}

void imprimirPelicula (EMovie *movies, int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        printf("Titulo: %s\n", movies[i].titulo);
        printf("Descripcion: %s\n", movies[i].descripcion);
        printf("Duracion: %d\n", movies[i].duracion);
        printf("Puntaje: %d\n", movies[i].puntaje);
        printf("Genero: %s\n", movies[i].genero);
        printf("Link Imagen: %s\n", movies[i].linkImagen);
    }
}
void guardarArchivo (EMovie* peliculas, int cantidad, char nombre[])
{
    FILE* archivo;

    archivo = fopen(nombre, "wb");

    if(archivo == NULL)
    {
        printf("No se pudo guardar el archivo\n");
    }
    else
    {
        fwrite(peliculas, sizeof(EMovie),cantidad,archivo);
        fclose(archivo);
        printf("Los datos se han guardado correctamente\n");
    }
}

void cargarArchivo (EMovie** peliculas, int* cantidad, int* tamPeliculas, char nombre[])
{
    FILE* archivo;
    int tamArchivo;
    EMovie* datos;

    archivo = fopen(nombre, "r");

    if(archivo == NULL)
    {
        printf("No se encontraron datos guardados.\n");
    }
    else
    {
        fseek(archivo, 0L, SEEK_END);
        tamArchivo = ftell(archivo); //cantidad de bytes del archivo
        rewind(archivo);

        datos = malloc(tamArchivo);

        if(datos == NULL)
        {
            printf("No hay memoria disponible\n");
            return;
        }

        fread(datos, 1,tamArchivo,archivo);
        fclose(archivo);

        if(*peliculas != NULL)
        {
            free(*peliculas);// estoy liberando peliculas de la memoria antes de cargarlas nuevamente del archivo
        }
        *peliculas = datos;
        *cantidad = tamArchivo/sizeof(EMovie);
        *tamPeliculas = *cantidad;
        printf("Los datos se han cargado correctamente\n");
    }
}

void html (EMovie* peliculas, int cantidadPeliculas, char nombre[])
{
    FILE* archivoSalida;

    archivoSalida = fopen(nombre, "w");


    if(archivoSalida != NULL)
    {
        escribirFragmento("cabecera.html", archivoSalida);
        escribirPeliculas(peliculas, cantidadPeliculas, archivoSalida);
        escribirFragmento("pie.html", archivoSalida);
        fclose(archivoSalida);

    }
    else
    {
        printf("No se pudo generar el archivo html\n\n");
    }
}

void escribirFragmento (char nombre[], FILE* archivoSalida)
{
    FILE* archivo;
    char buffer[1000];
    size_t bytes;//variante de los enteros

    archivo = fopen(nombre, "r");

    if(archivo == NULL)
    {
        printf("No se pudo leer el archivo %s\n", nombre);
        return;
    }

    do
    {
        bytes = fread(buffer, 1, sizeof(buffer), archivo);//cantidad de bytes que leyó
        fwrite(buffer, 1, bytes, archivoSalida);//escribe en el buffer la cantidad de bytes que leyó

    }while(bytes > 0);//cuando termina de leer devuelve 0

    fclose(archivo);

}

void escribirPeliculas(EMovie* peliculas, int cantidadPeliculas, FILE* archivoSalida)
{
    int i;

    for(i=0; i<cantidadPeliculas; i++)
    {
        fprintf(archivoSalida, "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                        "<img class='img-responsive img-rounded' src='%s'\n"
                        "alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                        "<a href='#'> %s </a>\n"
                    "</h3>\n"
                    "<ul>\n"
                        "<li>Género: %s</li>\n"
                        "<li>Puntaje:%d</li>\n"
                        "<li>Duración: %d</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                "</article>\n\n", peliculas[i].linkImagen, peliculas[i].titulo, peliculas[i].genero, peliculas[i].puntaje, peliculas[i].duracion, peliculas[i].descripcion);
    }

}
