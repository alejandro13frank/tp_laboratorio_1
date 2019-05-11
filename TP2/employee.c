#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "employee.h"


/** \brief  To indicate that all position in the employees are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the employees
* \param employees employee Array of employee
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int employee_Inicializar(Employee *employees, int size)
{
    int retorno=-1;
    if(employees!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            employees[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un employees
* \param employees employee Array de employee
* \param size int Tamaño del employees
* \param posicion int* Puntero a la posicion del employees donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int employee_buscarEmpty(Employee *employees, int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(employees!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(employees[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un employees y devuelve la posicion en que se encuentra
* \param employees employee Array de employee
* \param size int Tamaño del employees
* \param posicion int* Puntero a la posicion del employees donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int employee_buscarID(Employee *employees, int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(employees!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(employees[i].isEmpty==1)
                continue;
            else if(employees[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un employees
* \param employees employee Array de employee
* \param size int Tamaño del employees
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int employee_obtenerDatos(Employee employee,int* contadorID)
{
    int retorno=-1;
    if(contadorID!=NULL)
    {
        (*contadorID)++;
        employee.id=*contadorID;
        utn_getSignedInt("\nIngrese Sector: ","\nError",1,sizeof(int),1,&employee.sector);
        utn_getFloat("\nIngrese salario: ","\nError",1,sizeof(float),1,&employee.salary);
        utn_getName("\nIngrese nombre: ","\nError",1,TEXT_SIZE,1,employee.name);
        utn_getName("\nIngrese apellido: ","\nError",1,TEXT_SIZE,1,employee.lastName);
        printf("\n ID: %d\n sector: %d\n salary: %f\n name: %s\n lastName: %s",
                employee.id,employee.sector,employee.salary,employee.name,employee.lastName);
        retorno=0;
    }

    return retorno;
}

int employee_addEmployee(Employee* employees, int size, int id, char *name,char *lastName,float salary,int sector)
{
    int posicion;
    int retorno=0;

    if (employees!=NULL && size>0 && id>=0 && name!=NULL && lastName!=NULL && salary>0)
    {
        employee_buscarEmpty(employees,size,&posicion);
        employees[posicion].isEmpty=0;
        employees[posicion].id=id;
        strncpy(employees[posicion].name,name,sizeof(employees[posicion].name));
        employees[posicion].salary=salary;
        employees[posicion].sector=sector;
        strncpy(employees[posicion].lastName,lastName,sizeof(employees[posicion].lastName));
        retorno =0;

    }
    return retorno;
}


//*****************************************
//Baja valor unico
/** \brief Borra un elemento del employees por ID
* \param employees employee Array de employee
* \param size int Tamaño del employees
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int employee_baja(Employee *employees, int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(employees!=NULL && sizeArray>0)
    {
        employee_listar(employees,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id);
        if(employee_buscarID(employees,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            employees[posicion].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param employees employee Array de employee
* \param size int Tamaño del employees
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int employee_modificar(Employee *employees, int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(employees!=NULL && sizeArray>0)
    {
        employee_listar(employees,sizeArray);
        utn_getUnsignedInt("\nID    a modificar: ","\nError",1,sizeof(int),1,&id);
        if(employee_buscarID(employees,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n Posicion: %d\n ID: %d\n sector: %d\n salary: %f\n name: %s\n lastName: %s",
                       posicion, employees[posicion].id,employees[posicion].sector,employees[posicion].salary,employees[posicion].name,employees[posicion].lastName);
                utn_getChar("\nModificar: \nA: sector \nB: salario \nC: nombre \nD: apellido \nS(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getSignedInt("\nIngrese sector nuevo: ","\nError",1,sizeof(int),1,&employees[posicion].sector);
                        break;
                    case 'B':
                        utn_getFloat("\nIngrese salario nuevo: ","\nError",1,sizeof(float),1,&employees[posicion].salary);
                        break;
                    case 'C':
                        utn_getName("\nIngrese nombre nuevo: ","\nError",1,TEXT_SIZE,1,employees[posicion].name);
                        break;
                    case 'D':
                        utn_getTexto("\nIngrese apellido nuevo: ","\nError",1,TEXT_SIZE,1,employees[posicion].lastName);
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

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un employees
* \param employees employee Array de employee
* \param size int Tamaño del employees
* \param orden int orden ascendente o descente 1-0
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int employee_ordenarPorNombreYSector(Employee *employees,int size, int orden)
{
    int retorno=-1;
    int i, j;
    char bufferName[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferSector;
    float bufferSalary;
    char bufferLastName[TEXT_SIZE];

    if(employees!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strcpy(bufferName,employees[i].name);
            bufferId=employees[i].id;
            bufferIsEmpty=employees[i].isEmpty;

            bufferSector=employees[i].sector;
            bufferSalary=employees[i].salary;
            strcpy(bufferLastName,employees[i].lastName);


            j = i - 1;
            if (orden==0)
            {
                while ((j>=0)  && (bufferSector<employees[i].sector ||
                       (bufferSector==employees[i].sector && strcmp(bufferLastName,employees[j].lastName)<0)))
                {
                    strcpy(employees[j + 1].name,employees[j].name);
                    employees[j + 1].id=employees[j].id;
                    employees[j + 1].isEmpty=employees[j].isEmpty;
                    employees[j + 1].sector=employees[j].sector;
                    employees[j + 1].salary=employees[j].salary;
                    strcpy(employees[j + 1].lastName,employees[j].lastName);
                    j--;
                }
            }else
            {
                while ((j>=0)  && (bufferSector>employees[i].sector ||
                       (bufferSector==employees[i].sector && strcmp(bufferLastName,employees[j].lastName)>0)))
                {
                    strcpy(employees[j + 1].name,employees[j].name);
                    employees[j + 1].id=employees[j].id;
                    employees[j + 1].isEmpty=employees[j].isEmpty;
                    employees[j + 1].sector=employees[j].sector;
                    employees[j + 1].salary=employees[j].salary;
                    strcpy(employees[j + 1].lastName,employees[j].lastName);
                    j--;
                }
            }
            strcpy(employees[j + 1].name,bufferName);
            employees[j + 1].id=bufferId;
            employees[j + 1].isEmpty=bufferIsEmpty;
            employees[j + 1].sector=bufferSector;
            employees[j + 1].salary=bufferSalary;
            strcpy(employees[j + 1].lastName,bufferLastName);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un employees
* \param employees employee Array de employee
* \param size int Tamaño del employees
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int employee_listar(Employee *employees, int size)
{
    int retorno=-1;
    int i;
    if(employees!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(employees[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n sector: %d\n salary: %f\n name: %s\n lastName: %s",
                       employees[i].id,employees[i].sector,employees[i].salary,employees[i].name,employees[i].lastName);
        }
        retorno=0;
    }
    return retorno;
}

int employee_estaVacio(Employee *employees, int size)
{
    int retorno=-1;
    int i;
    if(employees!= NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if (employees[i].isEmpty==0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int employee_calcularSalarioTotal(Employee *employees, int size)
{
    int i;
    int retorno=-1;
    int acumulador=0;
    if (employees!=NULL && size>0)
    {
        for(i=0;i<size;i++)
        {
            if (employees[i].isEmpty)
            {
                continue;
            }else
            {
                acumulador+=employees[i].salary;
            }

        }
        retorno=acumulador;
    }
    return retorno;
}

float employee_calcularPormedioSalarios(Employee *employees, int size)
{
    int salarioTotal;
    int retorno=-1;
    int contador=0;
    int i;
    if (employees!=NULL && size>0)
    {
        salarioTotal=employee_calcularSalarioTotal(employees,size);
        for(i=0;i<size;i++)
        {
            if (employees[i].isEmpty)
            {
                continue;
            }else
            {
                contador++;
            }
        }
        if (contador>0)
        {
            retorno=(float)salarioTotal/contador;
        }
    }
    return retorno;
}

int employee_contarEmpleadosPlusSalarioProm(Employee *employees, int size,float salarioProm)
{
    int i;
    int contador=0;
    int retorno=-1;
    if (employees!=NULL && size>0 && salarioProm>0)
    {
        for(i=0;i<size;i++)
        {
            if (!employees[i].isEmpty && employees[i].salary>salarioProm)
            {
                contador++;
            }
        }
        retorno = contador;
    }
    return retorno;
}
