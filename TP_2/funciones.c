#include "funciones.h"

int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int i;
    int posicion = -1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 0)
        {
           posicion = i;
           break;
        }
    }
    return posicion;
}

int obtenerEspacioLibreDos(EPersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 0)
        {
           return i;
        }
    }
    return -1;
}

void cargarDatos (EPersona lista[], int posicion)
{
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(lista[posicion].nombre);

    printf("Ingrese la edad: ");
    scanf("%d", &lista[posicion].edad);

    printf("Ingrese el dni: ");
    scanf("%ld", &lista[posicion].dni);

    lista[posicion].estado = 1;

}

int buscarPorDni(EPersona lista[], long int dni, int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado != 0 && dni == lista[i].dni)
        {
            return i;
        }
    }

    return -1;
}

void borrarPersona (EPersona lista[], int posicion)
{
    char respuesta;

    printf("\nNombre: %s\nEdad: %d\nDni: %ld\n", lista[posicion].nombre, lista[posicion].edad, lista[posicion].dni);

    printf("\nEsta seguro que desea borrar los datos?'s'/'n': ");
    respuesta = getche();

    if(respuesta == 's')
    {
        lista[posicion].estado = 0;
        printf("\nLos datos han sido borrados correctamente\n");
    }

    else
    {
        printf("\nAccion cancelada por el usuario\n");
    }

}

void ordenarPersonas (EPersona lista[], int tam)
{
    int i;
    int j;
    EPersona aux;

    for(i = 0; i < tam-1; i++)
    {
        if(lista[i].estado == 0)
        {
            continue;
        }

        for(j = i+i; j < tam; j++)
        {
            if(lista[j].estado == 0)
            {
                continue;
            }

            if(stricmp(lista[i].nombre, lista[j].nombre) > 0)
            {
              strcpy(aux.nombre, lista[i].nombre);
              strcpy(lista[i].nombre, lista[j].nombre);
              strcpy(lista[j].nombre, aux.nombre);

              aux.edad = lista[i].edad;
              lista[i].edad = lista[j].edad;
              lista[j].edad = aux.edad;

              aux.dni = lista[i].dni;
              lista[i].dni = lista[j].dni;
              lista[j].dni = aux.dni;
            }
        }
    }
}

void mostrarPersonas(EPersona lista[], int tam)
{
    int i;

    for(i=0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            continue;
        }

        printf("\nNombre: %s\n", lista[i].nombre);
        printf("Edad: %d\n", lista[i].edad);
        printf("Dni: %ld\n", lista[i].dni);
    }
}

void cargarDatosDePrueba (EPersona lista[], int tam)
{
    int i;
    int cantidad;

    for(i=0; i < tam; i++)
    {
        lista[i].estado = 0;
    }

    EPersona precargado[] = {
        {"Jose", 25, 1, 36456789},
        {"Alejandro", 26, 1, 36123123},
        {"Pedro", 34, 1, 28345123},
        {"Maria", 45, 1, 56789567},
        {"Carolina", 24, 1, 36345678}
    };

    if (tam < 5)
    {
        cantidad = tam;
    }
    else
    {
        cantidad = 5;
    }

    for(i=0; i<cantidad; i++)
    {
        strcpy(lista[i].nombre, precargado[i].nombre);
        lista[i].edad = precargado[i].edad;
        lista[i].estado = precargado[i].estado;
        lista[i].dni = precargado[i].dni;
    }
}

void histograma(EPersona lista[], int tam)
{
    int i;
    int k;
    int contadorMenores = 0;
    int contadorJovenes = 0;
    int contadorMayores = 0;

    for(i=0; i < tam; i++)
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
    if(a > b)
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
    if(fila > contador)
    {
        return ' ';
    }
    else
    {
        return '*';
    }
}
