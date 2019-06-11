#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"r");
    if (pFile!=NULL && parser_EmployeeFromText(pFile , pArrayListEmployee)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if (pFile!=NULL && parser_EmployeeFromBinary(pFile , pArrayListEmployee)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int bufferId;
    char bufferNombre[4096];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    Employee* pEmployee;

    if (pArrayListEmployee!=NULL)
    {
        utn_getName("\nIngrese nombre: ","\nError",1,20,1,bufferNombre);
        utn_getUnsignedInt("\nIngrese horas trabajadas: ","\nError",1,6,1,30000,1,&bufferHorasTrabajadas);
        utn_getUnsignedInt("\nIngrese Sueldo: ","\nError",1,6,1,30000,1,&bufferSueldo);
        bufferId=employee_generarId();
        pEmployee=employee_new();
        if (pEmployee!=NULL &&
            employee_setId(pEmployee,bufferId)==0 &&
            employee_setNombre(pEmployee,bufferNombre)==0 &&
            employee_setHorasTrabajadas(pEmployee,bufferHorasTrabajadas)==0 &&
            employee_setSueldo(pEmployee,bufferSueldo)==0 &&
            ll_add(pArrayListEmployee,pEmployee)==0)
            {
                retorno=0;
            }
            else
            {
                printf("\nNo se pudo agregar el empleado.");
            }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int retorno=-1;
    int id;
    int bufferIdNode;
    char bufferNombre[128];
    int bufferSueldo;
    int bufferHorasTrab;
    char opcion;
    Employee *bufferEmployee;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),0,30000,1,&id);
        bufferIdNode=controller_searchIdEmployee(pArrayListEmployee,id);
        if(bufferIdNode==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {       //copiar printf de alta
                bufferEmployee=ll_get(pArrayListEmployee,bufferIdNode);
                employee_printNode(bufferEmployee);
                utn_getChar("\nModificar: \nA: Nombre. \nB: Horas trabajadas. \nC: Sueldo \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,bufferNombre);
                        employee_setNombre(bufferEmployee,bufferNombre);
                        break;
                    case 'B':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,30000,1,&bufferHorasTrab);
                        employee_setHorasTrabajadas(bufferEmployee,bufferHorasTrab);
                        break;
                    case 'C':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),0,30000,1,&bufferSueldo);
                        employee_setSueldo(bufferEmployee,bufferSueldo);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int bufferIdNode;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        utn_getUnsignedInt("\nID a eliminar: ","\nError",1,6,0,30000,1,&id);
        bufferIdNode=controller_searchIdEmployee(pArrayListEmployee,id);
        if(bufferIdNode==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListEmployee,bufferIdNode);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int lenLista;
    if (pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)!=0)
    {
        lenLista=ll_len(pArrayListEmployee);
        for (i=0;lenLista>i;i++)
        {
           employee_printNode(ll_get(pArrayListEmployee,i));
        }
    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if (pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_comparaNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int size;
    int bufferId;
    char bufferNombre[4096];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    Employee* pEmployee;
    FILE* fp = fopen(path,"w+");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<size;i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee,&bufferId);
            employee_getNombre(pEmployee,bufferNombre);
            employee_getHorasTrabajadas(pEmployee,&bufferHorasTrabajadas);
            employee_getSueldo(pEmployee,&bufferSueldo);

            fprintf(fp,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int size;
    Employee* pEmployee;
    FILE* fp = fopen(path,"w+b");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);
            fwrite(pEmployee,sizeof(Employee),1,fp);
        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}
int controller_searchIdEmployee(LinkedList* pArrayListEmployee, int id)
{
    int retorno=-1;
    int lenLista;
    int i;
    int bufferId;
    if (pArrayListEmployee!=NULL && id>0 && ll_len(pArrayListEmployee)!=0)
    {
        lenLista=ll_len(pArrayListEmployee);
        for (i=0;i<lenLista;i++)
        {
            employee_getId(ll_get(pArrayListEmployee,i),&bufferId);
            if (id==bufferId)
            {
                retorno=i;
                break;
            }
        }

    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}






