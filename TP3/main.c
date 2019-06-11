#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();
    /*controller_loadFromText("data.csv",listaEmpleados);
    controller_addEmployee(listaEmpleados);

    controller_saveAsText("dataCopia.csv",listaEmpleados);
    controller_saveAsBinary("dataBinario.csv",listaEmpleados);
    controller_loadFromBinary("dataBinario.csv",listaEmpleados);
    controller_saveAsText("dataTextoDeBinario.csv",listaEmpleados);
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                controller_saveAsText("dataCopia.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
     do
    {
        printf("\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2) Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
        printf("\n3) Alta de empleado");
        printf("\n4) Modificar datos de empleado");
        printf("\n5) Baja de empleado");
        printf("\n6) Listar empleados");
        printf("\n7) Ordenar empleados");
        printf("\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9) Guardar los datos de los empleados en el archivo data.csv (modo binario)");
        utn_getUnsignedInt("\n\n10) Salir\n","\nError",1,sizeof(int),1,60,1,&opcion);
        switch(opcion)
        {
            case 1: //
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2: //
                controller_loadFromBinary("dataBinario.csv",listaEmpleados);
                break;

            case 3: //
                controller_addEmployee(listaEmpleados);
                break;

            case 4: //
                controller_editEmployee(listaEmpleados);
                break;

            case 5: //
                controller_removeEmployee(listaEmpleados);
                break;

            case 6: //
                controller_ListEmployee(listaEmpleados);
                break;

            case 7: //
                controller_sortEmployee(listaEmpleados);
                break;

            case 8: //
                controller_saveAsText("dataCopia.csv",listaEmpleados);
                break;

            case 9: //
                controller_saveAsBinary("dataBinario.csv",listaEmpleados);
                break;

            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10); //

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
