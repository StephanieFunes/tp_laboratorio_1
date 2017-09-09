#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    int operandoUnoCargado = 0;
    int operandoDosCargado = 0;

    float operandoUno;
    float operandoDos;
    float suma;
    float resta;
    float division;
    float multiplicacion;

    while(seguir=='s')
    {
        printf("MENU\n");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        printf("Opcion: ");
        scanf("%d",&opcion);

        while(opcion < 1 || opcion > 9)
        {
            printf("Ha ingresado una opcion incorrecta. Intentelo nuevamente\n\n");
            break;
        }

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: ");
                scanf("%f", &operandoUno);
                operandoUnoCargado = 1;

                break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%f", &operandoDos);
                operandoDosCargado = 1;

                break;
            case 3:

                if(operandoUnoCargado == 0 || operandoDosCargado == 0)
                {
                    printf("Error. No se han ingresado ambos operandos.\n");
                    break;
                }

                else
                {
                    suma = sumarDosOperandos(operandoUno, operandoDos);
                    printf("El resultado de la suma de los numeros %.f y %f es : %f\n\n",operandoUno, operandoDos,suma);
                }

                break;
            case 4:
                if(operandoUnoCargado == 0 || operandoDosCargado == 0)
                {
                    printf("Error. No se han ingresado ambos operandos.\n");
                    break;
                }

                else
                {
                    resta = restarDosOperandos(operandoUno, operandoDos);
                    printf("El resultado de la resta de los numeros %f y %f es : %f\n\n",operandoUno, operandoDos,resta);
                }

                break;
            case 5:
                if(operandoUnoCargado == 0 || operandoDosCargado == 0)
                {
                    printf("Error. No se han ingresado ambos operandos.\n");
                    break;
                }
                if(operandoDos == 0)
                {
                    printf("Error. No se puede dividir por 0\n\n");
                    break;
                }

                else
                {
                   division = dividirDosOperandos(operandoUno,operandoDos);
                   printf("El resultado de la division de los numeros %.2f y %.2f es : %f\n\n",operandoUno, operandoDos,division);

                }
                break;

            case 6:

                if(operandoUnoCargado == 0 || operandoDosCargado == 0)
                {
                    printf("Error. No se han ingresado ambos operandos.\n");
                    break;
                }

                else
                {
                   multiplicacion = multiplicarDosOperandos(operandoUno,operandoDos);
                   printf("El resultado de la multiplicacion de los numeros %.2f y %.2f es : %.2f\n\n",operandoUno, operandoDos, multiplicacion);

                }

                break;
            case 7:

                if(operandoUnoCargado == 0)
                {
                    printf("Error. No se ha ingresado el primer operando.\n");
                    break;
                }

                if(operandoUno - (int)operandoUno != 0)
                {
                    printf("Error. Ingrese un numero sin parte decimal\n");
                }

                if(operandoUno < 0)
                {
                    printf("Error. Ingrese un numero positivo\n");
                }

                else
                {
                    Factorial((int)operandoUno);
                }

                break;
            case 8:

                if(operandoUnoCargado == 0 || operandoDosCargado == 0)
                {
                    printf("Error. No se han ingresado ambos operandos.\n");
                    break;
                }

                else
                {
                    suma = sumarDosOperandos(operandoUno, operandoDos);
                    printf("El resultado de la suma de los numeros %.2f y %.2f es : %.2f\n\n",operandoUno, operandoDos,suma);

                    resta = restarDosOperandos(operandoUno, operandoDos);
                    printf("El resultado de la resta de los numeros %.2f y %.2f es : %.2f\n\n",operandoUno, operandoDos,resta);

                    if(operandoDos == 0)
                    {
                        printf("Error. No se puede dividir por 0\n\n");
                    }

                    else
                    {
                        division = dividirDosOperandos(operandoUno,operandoDos);
                        printf("El resultado de la division de los numeros %.2f y %.2f es : %.2f\n\n",operandoUno, operandoDos,division);

                    }

                    if(operandoUno - (int)operandoUno != 0)
                    {
                        printf("Error. Ingrese un numero sin parte decimal\n");
                    }

                    if(operandoUno < 0)
                    {
                        printf("Error. No se puede calcular el factorial de un numero negativo\n\n");
                    }

                    else
                    {
                        Factorial((int)operandoUno);
                    }

                    multiplicacion = multiplicarDosOperandos(operandoUno,operandoDos);
                    printf("El resultado de la multiplicacion de los numeros %.2f y %.2f es : %.2f\n\n",operandoUno, operandoDos, multiplicacion);

                }
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }


    return 0;
}
