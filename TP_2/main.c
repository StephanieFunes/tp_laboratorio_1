#include "funciones.h"
#define TAM 10

int main()
{
    EPersona lista[TAM];
    char seguir='s';
    int opcion=0;
    int i;
    int posicion;
    long int dni;

    for(i=0; i<TAM; i++)
    {
        lista[i].estado = 0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Datos de prueba\n");
        printf("5- Imprimir grafico de edades\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                posicion = obtenerEspacioLibre(lista, TAM);

                if(posicion != -1)
                {
                    cargarDatos (lista, posicion);
                }
                else
                {
                    printf("No hay mas espacio disponible\n\n");
                }
                break;
            case 2:

                printf("Ingrese el dni de la persona que desea borrar: ");
                scanf("%ld", &dni);

                posicion = buscarPorDni(lista,dni,TAM);

                if(posicion != -1)
                {
                    borrarPersona(lista, posicion);
                }
                else
                {
                    printf("\nDni inexistente\n");
                }
                break;
            case 3:
                ordenarPersonas(lista, TAM);
                mostrarPersonas(lista, TAM);

                break;
            case 4:
                cargarDatosDePrueba(lista,TAM);

                break;

            case 5:
                histograma(lista,TAM);
                break;

            case 6:
                seguir = 'n';
                break;
        }

        putchar('\n');
    }

    return 0;
}
