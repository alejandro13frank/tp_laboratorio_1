#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones_calcu.h"
#include "funciones.h"

int main()
{
    int x=0;
    int y=0;
    int option;
    int flagVaribleA=0;
    int flagVaribleB=0;
    int sumados;
    int restados;
    int multiplicados;
    float divididos;
    long int factorialA;
    long int factorialB;
    int falloDivision=0;

    do{
        mostrarMenuCalculadora(x,y);
        if (!utn_getNumero(&option,"ingresa opcion: ","error, opcion invalida",1,5,3))
        {
            switch (option)
            {
                case 1:
                    utn_getNumero(&x,"ingrese un numero entre 0 y 100: ","numero invalido, reintente",0,100,10);
                    flagVaribleA = 1;
                    break;
                case 2:
                    utn_getNumero(&y,"ingrese un numero entre 0 y 100: ","numero invalido, reintente",0,100,10);
                    flagVaribleB = 1;
                    break;
                case 3:
                    if (flagVaribleA==1 && flagVaribleB==1)
                    {
                        sumarDosEnteros(x, y, &sumados);
                        restarDosEnteros(x, y, &restados);
                        falloDivision = dividirDosEnteros(x, y, &divididos);
                        multiplicarDosEnteros(x, y, &multiplicados);
                        factorialDeUnNumero(x, &factorialA);
                        factorialDeUnNumero(y, &factorialB);
                    }else printf("Faltan ingresar valores!!\n");
                    break;
                case 4:
                    if (flagVaribleA==1 && flagVaribleB==1)
                    {
                        informarResultados(sumados, restados, divididos, falloDivision, multiplicados, factorialA, factorialB);
                        __fpurge(stdin);
                        getchar();
                    }else printf("Faltan ingresar valores!!\n");
                    break;
            }
        }
    }while (option!=5);
    return 0;
}

