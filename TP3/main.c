#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    //int option = 1;
    LinkedList* listaEmpleados = ll_newLinkedList();
    controller_loadFromText("data.csv",listaEmpleados);
    controller_addEmployee(listaEmpleados);

    controller_saveAsText("dataCopia.csv",listaEmpleados);
    /*controller_saveAsBinary("dataBinario.csv",listaEmpleados);
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
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
