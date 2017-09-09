float sumarDosOperandos (float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno + numeroDos;

    return resultado;
}

float restarDosOperandos (float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno - numeroDos;

    return resultado;
}

float dividirDosOperandos (float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno / numeroDos;

    return resultado;
}

float multiplicarDosOperandos (float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno * numeroDos;

    return resultado;
}

void Factorial (int numeroUno)
{
    int i;
    unsigned long long acum = 1, acumAnterior = 1;

    for(i = 1; i <= numeroUno; i++)
    {
        acumAnterior = acum;
        acum = acum * i;

        if(acum/acumAnterior != i)//Detecta overflow
        {
            printf("Error. El numero es demasiado grande\n");
            printf("El maximo factorial que se pudo calcular es %d! = %llu\n", i-1, acumAnterior);
            return;
        }
    }

    printf("El factorial de %d es: %llu\n",numeroUno, acum);

}
