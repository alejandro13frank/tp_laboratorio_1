#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entregas.h"
#include "utn.h"

int main()
{
    //int opcion;
    //char nombreArchivoTexto[20];
   // char nombreArchivoBinario[20];
    LinkedList* listaEntregas = ll_newLinkedList();
//    LinkedList* listaEntregas2 = ll_newLinkedList();
    int cantBultos=0;
    int lenLista;
    float pesosTotales;
    FILE* pFile=fopen("resultados.csv","w+");
    fprintf(pFile,"********************\n");
    fprintf(pFile,"Informe de ventas\n");
    fprintf(pFile,"********************");
    controller_loadFromText("data.csv",listaEntregas);
    //controller_ListEntregas(listaEntregas);
    lenLista=ll_len(listaEntregas);
    fprintf(pFile,"\nCantidad de Total de entregas: %d",ll_len(listaEntregas));//1
    controller_cantidadDeEntregasPorTipo(listaEntregas,pFile);
    cantBultos=controller_cantidadDeBultos(listaEntregas,pFile);
    controller_cantidadMaximaDeBultos(listaEntregas,pFile);
    fprintf(pFile,"\nPromedio de Bultos por entrega: %.2f\n",(float)cantBultos/lenLista);
    pesosTotales=controller_pesosTotales(listaEntregas);
    fprintf(pFile,"Promedio peso por Entregas: %2.f\n",(float)pesosTotales/lenLista);
    fprintf(pFile,"********************");

    fclose(pFile);
    /*
    do
    {
        printf("\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        //printf("\n2) Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
        //printf("\n3) Alta de empleado");
        //printf("\n4) Modificar datos de empleado");
        //printf("\n5) Baja de empleado");
        //printf("\n6) Listar empleados");
        //printf("\n7) Ordenar empleados por Nombre");
        //printf("\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9) Guardar los datos de los empleados en el archivo data.csv (modo binario)");
        utn_getUnsignedInt("\n\n10) Salir\n","\nError",1,sizeof(int),1,60,1,&opcion);
        switch(opcion)
        {
            case 1: //
                utn_getString("\nIngrese nombre de archivo a abrir (data.csv):","\nError ",1,20,1,nombreArchivoTexto);
                controller_loadFromText(nombreArchivoTexto,listaEntregas);
                break;

            case 2: //
                utn_getString("\nIngrese nombre de archivo a abrir (dataBinario.csv):","\nError ",1,20,1,nombreArchivoBinario);
                controller_loadFromBinary(nombreArchivoBinario,listaEntregas);
                break;

            case 3: //
                controller_addEntregas(listaEntregas);
                break;

            case 4: //
                controller_editEntregas(listaEntregas);
                break;

            case 5: //
                controller_removeEntregas(listaEntregas);
                break;

            case 6: //
                controller_ListEntregas(listaEntregas);
                break;

            case 7: //
                controller_sortEntregas(listaEntregas);
                break;

            case 8: //
                utn_getString("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoTexto);
                controller_saveAsText(nombreArchivoTexto,listaEntregas);
                break;

            case 9: //
                utn_getString("\nIngrese nombre de archivo a guardar: ","\nError ",1,20,1,nombreArchivoBinario);
                controller_saveAsBinary(nombreArchivoBinario,listaEntregas);
                break;

            case 10://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=10); //

    ll_deleteLinkedList(listaEntregas);
    return 0;*/
    ll_deleteLinkedList(listaEntregas);
    return 0;
}
