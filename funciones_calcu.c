#include <stdio.h>
#include <stdlib.h>
#include "funciones_calcu.h"

int sumarDosEnteros(int val1, int val2, int *resultado)
{
    *resultado =val1 + val2;
    return 0;
}

int restarDosEnteros(int val1, int val2, int *resultado)
{
    *resultado = val1 - val2;
    return 0;
}

int dividirDosEnteros(int val1, int val2, float *resultado)
{
    int ret = -1;
    if (val2 == 0)
    {
        ret = -1;
    }else
        {
            *resultado = (float)val1/val2;
            ret = 0;
        }
    return ret;
}

int multiplicarDosEnteros(int val1, int val2, int *resultado)
{
    *resultado = val1 * val2;
    return 0;
}

int factorialDeUnNumero(int val1, long int *resultado)
{
    int i;
    int ret = 0;
    long int buffer;
    buffer = val1;
    val1--;
    if (val1<0)
    {
        ret = -1;
    }else if (val1 == 0)
        {
            buffer = 1;
        }else
            {
                for (i=1;i<val1;val1--)
                {
                    buffer *= val1;
                }
            }
    *resultado = buffer;
    return ret;
}

int mostrarMenuCalculadora (int a, int b)
{
    system("clear");
    printf("1. Ingresar 1er operando (A=%d) \n2. Ingresar 2do operando (B=%d) \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir\n",a,b);
    return 0;
}

int informarResultados(int suma, int resta, float division,int divisionError, int multiplicacion, long int factorial1,long int factorial2)
{
    printf("El resultado de A+B es: %d \nEl resultado de A-B es: %d\n",suma, resta);
    if (!divisionError)
    {
        printf("El resultado de A/B es: %.2f\n",division);
    }else
        {
            printf("No es posible dividir por cero\n");
        }
    printf("El resultado de A*B es: %d\n",multiplicacion);
    printf("El factorial de A es: %ld y El factorial de B es: %ld\n",factorial1,factorial2);
    return 0;
}









