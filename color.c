#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

void listarColores(eColor colores[], int largo)
{
    int i = 0;
    printf("ID\t COLOR\n");
    printf("--------------------------------------------------------------------\n\n");
    while(i < largo)
    {
        printf("%i\t%s\n\n", colores[i].id , colores[i].nombreColor);
        i++;
    }
}

char* obtenerNombreColor(eColor colores[], int largo, int id)
{
    char* retorno;

    for(int i = 0 ; i < largo ; i++ )
    {
        if(colores[i].id == id)
        {
            retorno = colores[i].nombreColor;
        }
    }
    return retorno;
}

int pedirIdColor(eColor colores[], int largo)
{

    int idSeleccionado;
    do
    {

        system("cls");
        printf("Por favor ingrese el id del color que desea seleccionar seguido de la tecla enter.");
        listarColores(colores, largo);
        fflush(stdin);
        scanf("%i", &idSeleccionado);
    }while(idSeleccionado < 5000 || idSeleccionado > 5004);

    return idSeleccionado;
}
