#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employee.h"


#define QTY_TIPO 3

int main()
{
    int opcion;
    int contadorIdemployee=0;

    Employee arrayEmployee[QTY_TIPO];
    employee_Inicializar(arrayEmployee,QTY_TIPO);

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",
                      "\nError",1,sizeof(int),1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                employee_alta(arrayEmployee,QTY_TIPO,&contadorIdemployee);
                break;

            case 2: //Modificar
                employee_modificar(arrayEmployee,QTY_TIPO);
                break;

            case 3: //Baja
                employee_baja(arrayEmployee,QTY_TIPO);
                break;

            case 4://Listar
                employee_listar(arrayEmployee,QTY_TIPO);
                break;

            case 5://Ordenar
                employee_ordenarPorString(arrayEmployee,QTY_TIPO);
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
