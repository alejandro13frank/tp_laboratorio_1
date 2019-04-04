#ifndef FUNCIONES_CALCU_H_INCLUDED
#define FUNCIONES_CALCU_H_INCLUDED

int sumarDosEnteros(int val1, int val2, int *resultado);

/*pide dos valores por referencia de tipo int, los suma y los devuelve en la variable
    resultado de tipo int*. devuelve 0 si sali todo bien y -1 si dio un error*/

int restarDosEnteros(int val1, int val2, int *resultado);

/*pide dos valores por referencia de tipo int, los resta y los devuelve en la variable
    resultado de tipo int*. devuelve 0 si sali todo bien y -1 si dio un error*/

int dividirDosEnteros(int val1, int val2, float *resultado);

/*pide dos valores por referencia de tipo int, los divide y los devuelve en la variable
    resultado de tipo float*. devuelve 0 si sali todo bien y -1 si dio un error*/

int multiplicarDosEnteros(int val1, int val2, int *resultado);

/*pide dos valores por referencia de tipo int, los multiplica y los devuelve en la variable
    resultado de tipo int*. devuelve 0 si sali todo bien y -1 si dio un error*/

int factorialDeUnNumero(int val1,long int *resultado);

/*calcula el factorial del valor ingresado por referencia en el primerp parametro y da el resultado
 en el segundo*/

int mostrarMenuCalculadora (int a, int b);

/*muestra el menu y toma los valores que seran reemplazados por x e y en el menu*/

int informarResultados(int suma, int resta, float division, int divisionError, int multiplicacion,long int factorialA,long int factorialB);

/*imprime por pantalla los resultados de las operaciones de la calculadora*/


#endif // FUNCIONES_CALCU_H_INCLUDED
