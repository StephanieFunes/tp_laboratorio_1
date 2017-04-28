#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <conio.h>

int obtenerEspacioLibre(EPersona lista[])
{
    int i;

    for(i=0; i<CANTIDAD; i++)
    {
        if(lista[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

void agregarPersona(EPersona lista[], int posicion)
{
    printf("Ingrese el nombre: ");
    gets(lista[posicion].nombre);

    printf("Ingrese la edad: ");
    scanf("%d",&lista[posicion].edad);

    printf("Ingrese el dni: ");
    scanf("%d", &lista[posicion].dni);

    printf("\n");

    lista[posicion].estado = 1;
}

void imprimirLista (EPersona lista[])
{
    int i;

    for(i=0; i<CANTIDAD; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("Nombre: %s\n",lista[i].nombre);
            printf("Edad: %d\n", lista[i].edad);
            printf("DNI: %d\n\n", lista[i].dni);

        }
    }
}

int buscarPorDni(EPersona lista[], int dni)
{
    int i;
    for(i=0;i<CANTIDAD;i++)
    {
        if (lista[i].dni == dni && lista[i].estado == 1)
        {
            return i;
        }
    }
    return -1;
}

void borrarPersona (EPersona lista[])
{
    int dni;
    int i;
    int respuesta;

    printf("Ingrese el dni de la persona a eliminar: ");
    scanf("%d", &dni);
    i = buscarPorDni(lista,dni);

    if (i >= 0)
    {
        printf("%s\n%d\n%d\n", lista[i].nombre,lista[i].edad,lista[i].dni);
        printf("Esta seguro de eliminar a esta persona? 's'/'n'\n");
        respuesta = getch();
        if(respuesta == 's')
        {
            printf("La persona ha sido borrada\n");
            lista[i].estado = 0;
        }
        else
        {
            printf("Accion cancelada por el usuario\n");
        }
    }
    else
    {
        printf("No se encontró el dni %d\n", dni);
    }
}

void ordenarPorNombre(EPersona lista[])
{
    char aux[50];
    int i, j;

    for(i=0; i<CANTIDAD-1; i++)
    {
        for(j=i+1; j<CANTIDAD; j++)
        {
            if(lista[i].estado == 0 || lista[j].estado == 0)
            {
                continue;
            }
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                strcpy(aux,lista[i].nombre);
                strcpy(lista[i].nombre,lista[j].nombre);
                strcpy(lista[j].nombre, aux);

                swap(&lista[i].edad,&lista[j].edad);

                swap(&lista[i].dni, &lista[j].dni);

            }

        }
    }

}

void swap(int*x, int*y)
{
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

void histograma(EPersona lista[])
{
    int i;
    int k;
    int contadorMenores = 0;
    int contadorJovenes = 0;
    int contadorMayores = 0;

    for(i=0; i<CANTIDAD; i++)
    {
        if (lista[i].estado == 0)
        {
            continue;
        }
        if(lista[i].edad < 18)
        {
            contadorMenores ++;
        }
        else if(lista[i].edad <= 35)
        {
            contadorJovenes ++;
        }
        else
        {
            contadorMayores++;
        }
    }

    k = maximo(maximo(contadorMenores,contadorJovenes),contadorMayores);

    for(i = k; i>0; i--)
    {
        printf("\t%c\t%c\t%c\n",
        asterisco(i, contadorMenores),
        asterisco(i, contadorJovenes),
        asterisco(i, contadorMayores));
    }
    printf("\t<18\t18-35\t>35\n");

}

int maximo(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

char asterisco(int fila, int contador)
{
    if(fila>contador)
    {
        return ' ';
    }
    else
    {
        return '*';
    }
}
