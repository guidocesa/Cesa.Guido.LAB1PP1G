#include "cliente.h"

void listarClientes(eCliente clientes[], int largo)
{
    int i = 0;
    printf("ID\t NOMBRE\t\t SEXO\n");
    printf("--------------------------------------------------------------------\n\n");
    while(i < largo)
    {
        printf("%i\t%s\t\t%c\n\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
        i++;
    }
}

char* obtenerNombreCliente(eCliente clientes[], int largo, int id)
{
    char* retorno;

    for(int i = 0 ; i < largo ; i++ )
    {
        if(clientes[i].id == id)
        {
            retorno = clientes[i].nombre;
        }
    }
    return retorno;
}
