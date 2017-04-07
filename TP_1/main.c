#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular la suma (A+B)
4. Calcular la resta (A-B)
5. Calcular la division (A/B)
6. Calcular la multiplicacion (A*B)
7. Calcular el factorial (A!)
8. Calcular todas las operaciones
9. Salir
� Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.
� En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
(donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
� Deber�n contemplarse los casos de error (divisi�n por cero, etc)
� Documentar todas las funciones
*/

int main()
{
    int flagA = 0;
    int flagB = 0;
    float A;
    float B;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        if (flagA == 1)
        {
            printf("1- Ingresar 1er operando (A = %.2f)\n", A);
        }
        else
        {
            printf("1- Ingresar 1er operando (A = no ingresado)\n");
        }
        if (flagB == 1)
        {
            printf("2- Ingresar 2do operando (B = %.2f)\n", B);
        }
        else
        {
            printf("1- Ingresar 1er operando (B = no ingresado)\n");
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Ingrese un valor para A: ");
            scanf("%f",&A);
            flagA = 1;
            break;
        case 2:
            printf("Ingrese un valor para B: ");
            scanf("%f",&B);
            flagB = 1;
            break;
        case 3:
            Suma(A,B,flagA,flagB);
            break;
        case 4:
            Resta(A,B,flagA,flagB);
            break;
        case 5:
            Division(A,B,flagA,flagB);
            break;
        case 6:
            Multiplicacion(A,B,flagA,flagB);
            break;
        case 7:
            Factorial(A,flagA);
            break;
        case 8:
            TodasLasOperaciones(A,B,flagA,flagB);
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
