#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos);
/*Recibe la variable de tipo int *pResultado donde se guardara el numero.un const char* para el mensaje otro para el mensaje de error,
  tambien recibe int minimo y maximo para los limites de los valores aceptados. recibe la cantidad de reintentos de error, y devuelve
  0 si funciono -1 si no. */

int getInt(int *pResultado);
/*toma el ingreso por consola de un char* y lo transforma en int , lo guarda en la varible pRersultado. devuelve 0 si funciono y -1
  si no funciono*/

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos);
/*Recibe la variable de tipo float *pResultado donde se guardara el numero.un const char* para el mensaje otro para el mensaje de error,
  tambien recibe int minimo y maximo para los limites de los valores aceptados. recibe la cantidad de reintentos de error, y devuelve
  0 si funciono -1 si no. */

int getFloat(float *pResultado);
/*toma el ingreso por consola de un char* y lo transforma en float , lo guarda en la varible pRersultado. devuelve 0 si funciono y -1
  si no funciono*/

int utn_getChar(char* pResultado,const char *mensaje,const char *mensajeError,const char *minimo,const char *maximo,int reintentos);
/*Recibe la variable de tipo char *pResultado donde se guardara el caracter.un const char* para el mensaje otro para el mensaje de error,
  tambien recibe int minimo y maximo para los limites de los caracteres aceptados. recibe la cantidad de reintentos de error, y devuelve
  0 si funciono -1 si no. */


#endif // FUNCIONES_H_INCLUDED
