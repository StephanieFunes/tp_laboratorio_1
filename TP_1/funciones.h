#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
/**
 * \param numeroUno corresponde al primer numero que se va a sumar
 * \param numeroDos corresponde al segundo numero que se va a sumar
 * \return devuelve la suma de dos numeros
 */
float sumarDosOperandos (float numeroUno, float numeroDos);
/**
 * \param numeroUno corresponde al primer numero que se va a restar
 * \param numeroDos corresponde al segundo numero que se va a restar
 * \return devuelve la resta de dos numeros
 */
float restarDosOperandos (float numeroUno, float numeroDos);

/**
 * \param numeroUno corresponde al primer numero que se va a dividir
 * \param numeroDos corresponde al segundo numero que se va a dividir
 * \return devuelve la division de dos numeros
 */
float dividirDosOperandos (float numeroUno, float numeroDos);

/**
 *\param numeroUno corresponde al primer numero que se va a multiplicar
 * \param numeroDos corresponde al segundo numero que se va a multiplicar
 * \return devuelve la multiplicacion de dos numeros
 */
float multiplicarDosOperandos (float numeroUno, float numeroDos);

/**
 *\param numeroUno corresponde al primer numero del que se calculara el factorial
 * \return el factorial de un numero
 */
void Factorial (int numeroUno);



#endif // FUNCIONES_H_INCLUDED
