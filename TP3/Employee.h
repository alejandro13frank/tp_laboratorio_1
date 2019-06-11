#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define TEXT_SIZE 128
typedef struct
{
    int id;
    char nombre[TEXT_SIZE];
    int horasTrabajadas;
    int sueldo;
}Employee;

void employee_setIdInicial(int val);
int employee_generarId(void);
void imprimirMasterId(void);

Employee* employee_new(void);
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setIdStr(Employee* this,char* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadasStr);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setSueldoStr(Employee* this,char* sueldo);

int employee_printNode(Employee *this);
int employee_comparaNombre(void *this,void *that);
#endif // employee_H_INCLUDED
