#include "funciones.h"

int main()
{
    EMovie* peliculas = NULL;
    EMovie* peliculasAuxiliar;
    int cantidadPeliculas = 0;
    int tamPeliculas = 0;
    int validar;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Cargar datos de archivo\n");
        printf("6- Guardar datos en archivo\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(cantidadPeliculas == tamPeliculas)
                {
                    peliculasAuxiliar = realloc(peliculas, sizeof(EMovie)*(tamPeliculas + 1));

                    if(peliculasAuxiliar != NULL)
                    {
                        peliculas = peliculasAuxiliar;
                        tamPeliculas ++;
                    }
                    else
                    {
                        printf("No existe más memoria para agregar peliculas\n");
                        break;
                    }
                }

                validar = agregarPelicula(peliculas + cantidadPeliculas);//es lo mismo que &peliculas[cantidad]
                if(validar)
                {
                    cantidadPeliculas ++;
                    printf("La pelicula fue agregada correctamente\n");
                }

                break;

            case 2:
                if(borrarPelicula(peliculas,cantidadPeliculas))
                {
                    printf("La pelicula fue borrada correctamente\n");
                    cantidadPeliculas --;
                    peliculasAuxiliar = realloc(peliculas, sizeof(EMovie)*cantidadPeliculas);

                    if(peliculasAuxiliar != NULL || cantidadPeliculas == 0)
                    {
                        peliculas = peliculasAuxiliar;
                        tamPeliculas = cantidadPeliculas;
                    }
                    else
                    {
                        printf("Cuidado: no se pudo liberar la memoria\n");
                    }
                }
                break;

            case 3:
                modificarPelicula(peliculas,cantidadPeliculas);
                break;

            case 4:
                imprimirPelicula(peliculas,cantidadPeliculas);
                html(peliculas, cantidadPeliculas, "../template/catalogo.html");
                break;
            case 5:
                cargarArchivo(&peliculas, &cantidadPeliculas, &tamPeliculas, "archivo");
                break;

            case 6:
                guardarArchivo(peliculas, cantidadPeliculas, "archivo");
                break;

            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
