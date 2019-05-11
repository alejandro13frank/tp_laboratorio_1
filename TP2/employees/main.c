#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employee.h"


#define LEN_ARRAY 3

int main()
{
    int opcion;
    int contadorIdemployee=0;
    int ordenAux=0;
    int posicionAux;
    Employee arrayEmployee[LEN_ARRAY];
    employee_Inicializar(arrayEmployee,LEN_ARRAY);
    Employee employeeAux;
    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar y listar \n6) Informes \n7) Salir\n",
                      "\nError",1,sizeof(int),1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                if (employee_buscarEmpty(arrayEmployee,LEN_ARRAY,&posicionAux)==1)
                {
                     printf("\nNo hay lugares vacios");
                }else
                {
                    employee_obtenerDatos(employeeAux,&contadorIdemployee);
                    employee_addEmployee(arrayEmployee,LEN_ARRAY,employeeAux.id,employeeAux.name,employeeAux.lastName,employeeAux.salary,employeeAux.sector);
                }
             break;

            case 2: //Modificar
                if (!employee_estaVacio(arrayEmployee,LEN_ARRAY))
                {
                    employee_modificar(arrayEmployee,LEN_ARRAY);
                }else
                {
                    printf("\nNo hay empleados para modificar");
                }

                break;

            case 3: //Baja
                if (!employee_estaVacio(arrayEmployee,LEN_ARRAY))
                {
                    employee_baja(arrayEmployee,LEN_ARRAY);
                }else
                {
                    printf("\nNo hay empleados para modificar");
                }
                break;

            case 4://Listar
                if (!employee_estaVacio(arrayEmployee,LEN_ARRAY))
                {
                    employee_listar(arrayEmployee,LEN_ARRAY);
                }else
                {
                    printf("\nNo hay empleados para modificar");
                }
                break;

            case 5://Ordenar
                if (!employee_estaVacio(arrayEmployee,LEN_ARRAY))
                {
                    utn_getSignedInt("ingrese ordenamiento ascendente (1) o descendete (0)","\nValor incorrecto",1,1,1,&ordenAux);
                    employee_ordenarPorNombreYSector(arrayEmployee,LEN_ARRAY,ordenAux);
                    employee_listar(arrayEmployee,LEN_ARRAY);
                }else
                {
                    printf("\nNo hay empleados para modificar");
                }

                break;
            case 6://Ordenar
                if (!employee_estaVacio(arrayEmployee,LEN_ARRAY))
                {
                    printf("\n El salario total es: %d",employee_calcularSalarioTotal(arrayEmployee,LEN_ARRAY));
                    printf("\n El salario promedio es: %f",employee_calcularPormedioSalarios(arrayEmployee,LEN_ARRAY));
                    //printf("\n La cantidad de empleados que supera el promedio es: %d",employee_mostrarEmpleadoPlusSalarioProm(arrayEmployee,LEN_ARRAY,employee_calcularPormedioSalarios(   arrayEmployee,LEN_ARRAY)));
                }else
                {
                    printf("\nNo hay empleados para modificar");
                }

                break;

            case 7://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
