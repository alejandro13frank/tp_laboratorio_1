#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define TEXT_SIZE 51

typedef struct
{
    int id;
    int isEmpty;
    //-----------------
    char name[TEXT_SIZE];
    int sector;
    float salary;
    char lastName[TEXT_SIZE];

}Employee;

int employee_obtenerDatos(Employee employee,int* contadorID);

int employee_Inicializar(Employee *employees, int size);

int employee_buscarEmpty(Employee *employees, int size, int* posicion);

int employee_buscarID(Employee *employees, int size, int valorBuscado, int* posicion);

int employee_baja(Employee *employees, int sizeArray);

int employee_modificar(Employee *employees, int sizeArray);

int employee_ordenarPorNombreYSector(Employee *employees,int size,int orden);

int employee_listar(Employee *employees, int size);

int employee_addEmployee(Employee* employees, int size, int id, char *name,char *lastName,float salary,int sector);

int employee_estaVacio(Employee *employees, int size);

int employee_calcularSalarioTotal(Employee *employees, int size);

float employee_calcularPormedioSalarios(Employee *employees, int size);

int employee_mostrarEmpleadoPlusSalarioProm(Employee *employees, int size,float salarioProm);

#endif // EMPLOYEE_H_INCLUDED
