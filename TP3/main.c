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
    char nombreArchivoBinario[20];
    char nombreArchivoTexto[20];
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2) Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
        printf("\n3) Alta de empleado");
        printf("\n4) Modificar datos de empleado");
        printf("\n5) Baja de empleado");
        printf("\n6) Listar empleados");
        printf("\n7) Ordenar empleados por Nombre");
        printf("\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9) Guardar los datos de los empleados en el archivo data.csv (modo binario)");
        utn_getUnsignedInt("\n\n10) Salir\n","\nError",1,sizeof(int),1,60,1,&opcion);
        switch(opcion)
        {
            case 1: //
                utn_getString("\nIngrese nombre de archivo a abrir (data.csv):","\nError ",1,20,1,nombreArchivoTexto);
                controller_loadFromText(nombreArchivoTexto,listaEmpleados);
                break;

            case 2: //
                utn_getString("\nIngrese nombre de archivo a abrir (dataBinario.csv):","\nError ",1,20,1,nombreArchivoBinario);
                controller_loadFromBinary(nombreArchivoBinario,listaEmpleados);
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
                utn_getString("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoTexto);
                controller_saveAsText(nombreArchivoTexto,listaEmpleados);
                break;

            case 9: //
                utn_getString("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoBinario);
                controller_saveAsBinary(nombreArchivoBinario,listaEmpleados);
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
