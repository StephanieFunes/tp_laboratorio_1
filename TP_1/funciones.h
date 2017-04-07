#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/*
 * Funci�n Suma
 * Recibe como par�metros los operandos A y B y los flags indicando si fueron definidos;
 * Si ambos operandos fueron definidos, calclula la suma y la imprime por pantalla. De lo contrario imprime un mensaje de error.
 */
void Suma(float A, float B, int flagA, int flagB)
{
    if(flagA == 1 && flagB == 1)
    {
        printf("El resultado de la suma es: %.2f\n", A + B);
    }
    else
    {
        printf("Debe ingresar un valor para A y para B\n");
    }
}
/*
 * Funci�n Resta
 * Recibe como par�metros los operandos A y B y los flags indicando si fueron definidos;
 * Si ambos operandos fueron definidos, calclula la resta y la imprime por pantalla. De lo contrario imprime un mensaje de error.
 */
void Resta(float A, float B,int flagA,int flagB)
{
    if(flagA == 1 && flagB == 1)
    {
        printf("El resultado de la resta es: %.2f\n",A - B);
    }
    else
    {
        printf("Debe ingresar un valor para A y para B\n");
    }

}
/*
 * Funci�n Division
 * Recibe como par�metros los operandos A y B y los flags indicando si fueron definidos;
 * Si ambos operandos fueron definidos, calclula la divisi�n y la imprime por pantalla.
 * Si el no fueron definos o el divisor es 0 imprime un mensaje de error.
 */
void Division(float A, float B, int flagA, int flagB)
{
    if(flagA == 1 && flagB == 1)
    {
        printf("El resultado de la division es: %.2f\n", A / B);

        if(B == 0.0)
        {
            printf("No puede realizarse esta operacion (B=0)\n");
        }
    }
    else
    {
        printf("Debe ingresar un valor para A y para B\n");
    }
}
/*
 * Funci�n Multiplicaci�n
 * Recibe como par�metros los operandos A y B y los flags indicando si fueron definidos.
 * Si ambos operandos fueron definidos, calclula la multiplaci�n y la imprime por pantalla. De lo contrario imprime un mensaje de error.
 */
void Multiplicacion (float A, float B, int flagA, int flagB)
{
    if(flagA == 1 && flagB == 1)
    {
        printf("El resultado de la multiplicacion es: %.2f\n", A * B);
    }
    else
    {
        printf("Debe ingresar un valor para A y para B\n");
    }
}
/*
 * Funci�n Factorial
 * Recibe como par�metros el operando A y flagA para saber si fue definido.
 * Para saber si el n�mero ingresado es demasiado grande para calcularlo, se utliza una condici�n
 * que imprime un mensaje de error cuando al dividir al producto actual por el anterior,
 * no da el �ltimo n�mero multiplicado. Seguidamente, se muestra un mensaje que indica el m�ximo valor
 * que se pudo calcular.
 * Para usar el %llu en printf() requiere C99
 *
 */
void Factorial (float A, int flagA)
{
    int i;
    unsigned long long acum = 1, acumAnterior = 1;

    if(flagA == 1)
    {
        for(i = 1; i <= A; i++)
        {
            acumAnterior = acum;
            acum = acum * i;

            if(acum/acumAnterior != i)
            {
                printf("Error. El numero es demasiado grande\n");
                printf("El maximo factorial que se pudo calcular es %d! = %llu\n", i-1, acumAnterior);
                return;
            }
        }

        printf("El factorial de A es: %llu\n",acum);
    }
    else
    {
        printf("Debe ingresar un valor para A");
    }

}
/*
 * Funci�n TodasLasOperaciones
 * Recibe como par�metros los operandos A y B y los flags indicando si fueron definidos.
 * Si ambos operandos fueron definidos, calclula la suma, resta, divisi�n, multiplicaci�n y factorial de los mismos
 * y las imprime por pantalla. De lo contrario imprime un mensaje de error.
 *
 */
void TodasLasOperaciones(float A, float B, int flagA, int flagB)
{
    if(flagA == 1 && flagB == 1)
    {
        Suma(A,B,flagA,flagB);
        Resta(A,B, flagA, flagB);
        Division(A,B, flagA, flagB);
        Multiplicacion(A,B, flagA,flagB);
        Factorial(A,flagA);
    }
    else
    {
        printf("Debe ingresar un valor para A y para B\n");
    }

}


#endif // FUNCIONES_H_INCLUDED
