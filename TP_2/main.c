#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    EPersona datos[CANTIDAD];
    char seguir='s';
    int opcion=0;
    int i;

    for(i=0; i < CANTIDAD; i++)
    {
        datos[i].estado = 0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        printf("\n");
        // ignora el ENTER detras del numero
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                i = obtenerEspacioLibre(datos);
                if(i == -1)
                {
                    printf("No hay mas registros libres para guardar personas\n");
                }
                else
                {
                    agregarPersona(datos, i);
                }
                break;
            case 2:
                borrarPersona(datos);
                break;
            case 3:
                ordenarPorNombre(datos);
                imprimirLista(datos);
                break;
            case 4:
                histograma(datos);

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
