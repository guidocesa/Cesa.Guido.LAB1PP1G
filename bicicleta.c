#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "funciones.h"


void inicializarListado(eBicicleta bicicletas[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        bicicletas[i].estaVacio = 1;
        bicicletas[i].idTipo = 0;
        bicicletas[i].idColor = 0;
    }
}

int obtenerIdLibre(eBicicleta bicicletas[] , int largo)
{
    int idNuevo = 1;
    int i = 0;
    while(i < largo && !bicicletas[i].estaVacio)
    {
        if(idNuevo == bicicletas[i].id)
        {
            idNuevo ++;
            i = 0;//Se tiene que hacer ya que no puedo garantizar que el id nuevo no se repita con los que ya cicle
        }
        else
        {
            i++;
        }
    }
    return idNuevo;

}

void listarTipos(eTipo tipos[], int largo)
{
    int i = 0;
    printf("ID\t DESCRIPCION\n");
    printf("--------------------------------------------------------------------\n\n");
    while(i < largo)
    {
        printf("%i\t%s\n\n", tipos[i].id , tipos[i].descripcion);
        i++;
    }
}

int moverBicicletasDesde(int posicionInicial, eBicicleta bicicletas[], int largo)
{
    int retorno;
    if(bicicletas[(largo - 1)].estaVacio)
    {
        for(int i = (largo - 1) ; i > posicionInicial ; i--)
        {
            bicicletas[i] = bicicletas[i - 1];
        }
        bicicletas[posicionInicial].estaVacio = 1;
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int agregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, char marca[], int idTipo, int idColor, float rodado, int idCliente)
{
    int i = 0;
    int fueAgregado = 0;
    int id = obtenerIdLibre(bicicletas ,  largo);
    while(!fueAgregado && i < largo)
    {
        if( idTipo < bicicletas[i].idTipo ||
           bicicletas[i].estaVacio ||
           ((idTipo == bicicletas[i].idTipo) && rodado < bicicletas[i].rodado))
        {
           if(!bicicletas[i].estaVacio)
           {
                if(moverBicicletasDesde(i , bicicletas, largo))
                {
                    bicicletas[i].id = id;
                    strcpy(bicicletas[i].marca , marca);
                    bicicletas[i].idTipo = idTipo;
                    bicicletas[i].idColor = idColor;
                    bicicletas[i].rodado = rodado;
                    bicicletas[i].idCliente = idCliente;
                    bicicletas[i].estaVacio = 0;
                    fueAgregado = 1;
                }
           }
           else
           {
                    bicicletas[i].id = id;
                    strcpy(bicicletas[i].marca , marca);
                    bicicletas[i].idTipo = idTipo;
                    bicicletas[i].idColor = idColor;
                    bicicletas[i].rodado = rodado;
                    bicicletas[i].idCliente = idCliente;
                    bicicletas[i].estaVacio = 0;
                    fueAgregado = 1;
           }
        }
        i++;
    }
    return fueAgregado;
}

int solicitarDatosYAgregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int idCliente;
    int bicicletaAgregada=0;

    system("cls");
    printf("Por favor ingrese la marca de la bicicleta y luego la tecla enter. \n\n");
    fflush(stdin);
    gets(marca);
    formatearString(marca);

    do
    {
        system("cls");
        printf("Por favor ingrese el id del tipo de bicicleta seguido de la tecla enter. \n\n");
        listarTipos(tipos, largoTipos);
        fflush(stdin);
        scanf("%i" , &idTipo);
    }while(idTipo < 1000 || idTipo > 1003);

    do
    {
        system("cls");
        printf("Por favor ingrese el ID del color seguido de la tecla enter.  \n\n");
        listarColores(colores, largoColores);
        fflush(stdin);
        scanf("%i" , &idColor);
    }while(idColor < 5000 || idColor > 5004);

    do
    {
        system("cls");
        printf("Por favor ingrese el rodado de la bicicleta seguido de la tecla enter. (Rodados validos: 20, 26, 27.5, 29) \n\n");
        fflush(stdin);
        scanf("%f" , &rodado);
    }while(!(rodado == 20.00 || rodado == 26.00 || rodado == 27.50 || rodado == 29.00));

    do
    {
        system("cls");
        printf("Por favor ingrese el id del cliente duenio de la bicicleta seguido de la tecla enter.  \n\n");
        listarClientes(clientes, largoClientes);
        fflush(stdin);
        scanf("%i" , &idCliente);
    }while(idCliente < 6000 || idCliente > (6000 + largoClientes - 1));


    if(agregarBicicletaOrdenada(bicicletas , largo, marca, idTipo, idColor, rodado, idCliente))
    {
        bicicletaAgregada = 1;
    }

    return bicicletaAgregada;
}

int darDeBajaBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    int id;
    system("cls");
    printf("Ingrese el ID de la bicicleta que desea dar de baja y luego presione enter. \n\n");
    listarBicicletas(bicicletas, largo, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
    fflush(stdin);
    scanf("%i" , &id);

    int fueBorrado = borrarBicicletaPorId(bicicletas , id, largo);

    if(!fueBorrado)
    {
        printf("Ese ID de bicicleta no se encuentra en el sistema, por favor checkee en el listado. /n");
        system("pause");
    }

    return fueBorrado;
}

int borrarBicicletaPorId(eBicicleta bicicletas[], int id, int largo)
{
    int fueBorrada = 0;
    for(int i = 0 ; i < largo ; i++)
    {
        if(bicicletas[i].id == id)
        {
            for(int u = i ; u < (largo - 1); u ++)
            {
                bicicletas[u] = bicicletas[u + 1];
            }
            bicicletas[largo - 1].estaVacio = 1;
            fueBorrada = 1;
            break;
        }
    }
    return(fueBorrada);
}

int mostrarMenuModificacion()
{
    int seleccion;

    do
    {
        system("cls");
        printf("Seleccione que desea modificar:\n\n1. Color\n2. Tipo\n3. Rodado\n4. Marca");
        fflush(stdin);
        scanf("%i", &seleccion);
    }while(seleccion < 1 || seleccion > 4);

    return seleccion;

}

int modificarBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    system("cls");
    int idAModificar;
    int idEncontrado = 0;
    int i = 0;
    int bicicletaModificada = 0;

    printf("Por favor ingrese el numero de ID de la bicicleta a modificar seguido de la tecla enter.\n");
    listarBicicletas(bicicletas, largo, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
    printf("\n\n");
    fflush(stdin);
    scanf("%i", &idAModificar);

    while(!idEncontrado && !bicicletas[i].estaVacio && i < largo)
    {
        if(bicicletas[i].id == idAModificar)
        {
            idEncontrado = 1;
        }
        i++;
    }
    i--;

    if(idEncontrado)
    {
        int idTipoNuevo;
        int idColorNuevo;
        float rodadoNuevo;
        char marcaNueva[21];

        int seleccion = mostrarMenuModificacion();
        eBicicleta aux = bicicletas[i];
        switch(seleccion)
        {
            case 1:

                do
                {
                    system("cls");
                    printf("Por favor ingrese el ID del color seguido de la tecla enter.  \n\n");
                    listarColores(colores, largoColores);
                    fflush(stdin);
                    scanf("%i" , &idColorNuevo);
                }while(idColorNuevo < 5000 || idColorNuevo > 5004);
                aux.idColor = idColorNuevo;
                break;

            case 2:

                do
                {
                    system("cls");
                    printf("Por favor ingrese el id del tipo de bicicleta seguido de la tecla enter. \n\n");
                    listarTipos(tipos, largoTipos);
                    fflush(stdin);
                    scanf("%i" , &idTipoNuevo);
                }while(idTipoNuevo < 1000 || idTipoNuevo > 1003);
                aux.idTipo = idTipoNuevo;
                break;

            case 3:

                do
                {
                    system("cls");
                    printf("Por favor ingrese el rodado de la bicicleta seguido de la tecla enter. (Rodados validos: 20, 26, 27.5, 29)  \n\n");
                    fflush(stdin);
                    scanf("%f" , &rodadoNuevo);
                }while(!(rodadoNuevo == 20.00 || rodadoNuevo == 26.00 || rodadoNuevo == 27.50 || rodadoNuevo == 29.00));
                aux.rodado = rodadoNuevo;
                break;

            case 4:

                printf("Por favor ingrese la marca de la bicicleta y luego la tecla enter. \n\n");
                fflush(stdin);
                gets(marcaNueva);
                formatearString(marcaNueva);
                strcpy(aux.marca , marcaNueva);

                break;
        }
        borrarBicicletaPorId(bicicletas, bicicletas[i].id, largo);
        agregarBicicletaOrdenada(bicicletas, largo, aux.marca, aux.idTipo, aux.idColor, aux.rodado, aux.idCliente);
        bicicletaModificada = 1;

    }
    else
    {
        printf("No se pudo encontrar una bicicleta con ese Id, por favor confirme que sea el correcto.");
        system("pause");
    }

    return bicicletaModificada;
}

void mostrarBicicleta(eBicicleta bicicleta, eColor colores[], int largoColores, eTipo tipos[], int largoTipos, eCliente clientes[], int largoClientes)
{
    char color[21];
    char tipo[21];
    char nombreCliente[21];


    strcpy(color, obtenerNombreColor(colores, largoColores, bicicleta.idColor) );
    strcpy(tipo, obtenerDescTipo(tipos, largoTipos, bicicleta.idTipo) );
    strcpy(nombreCliente, obtenerNombreCliente(clientes, largoClientes, bicicleta.idCliente));

    printf("%i\t%s\t\t%s\t%s\t%.2f\t%s\n", bicicleta.id, bicicleta.marca, tipo, color, bicicleta.rodado, nombreCliente);
}

void listarBicicletas(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    int i = 0;
    printf("ID\t MARCA\t\t TIPO\t COLOR\t RODADO\t CLIENTE\n");
    printf("--------------------------------------------------------------------\n\n");
    while(!bicicletas[i].estaVacio)
    {
        mostrarBicicleta(bicicletas[i], colores, largoColores, tipos, largoTipos, clientes, largoClientes);

        i++;
    }
    system("pause");
}

int idEstaEnElListado(int idBicicleta,eBicicleta bicicletas[],int largoBicicletas)
{
    int idEncontrado = 0;
    int i =0;
    while(!idEncontrado && i < largoBicicletas)
    {
        if(idBicicleta == bicicletas[i].id)
        {
            idEncontrado = 1;
        }
    }
    return idEncontrado;
}

char* obtenerDescTipo(eTipo tipos[], int largo, int id)
{
    char* retorno;

    for(int i = 0 ; i < largo ; i++ )
    {
        if(tipos[i].id == id)
        {
            retorno = tipos[i].descripcion;
        }
    }
    return retorno;
}

void listarBicicletasPorColor(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    int idColorSeleccionado;
    int i = 0;
    idColorSeleccionado = pedirIdColor(colores, largoColores);

    system("cls");
    printf("ID\t MARCA\t\t TIPO\t COLOR\t RODADO\t CLIENTE\n");
    printf("--------------------------------------------------------------------\n\n");
    while(!bicicletas[i].estaVacio)
    {
        if(bicicletas[i].idColor == idColorSeleccionado)
        {
            mostrarBicicleta(bicicletas[i], colores, largoColores, tipos, largoTipos, clientes, largoClientes);
        }
        i++;
    }
}


int pedirIdTipo(eTipo tipos[], int largo)
{

    int idSeleccionado;
    do
    {

        system("cls");
        printf("Por favor ingrese el id del tipo que desea seleccionar seguido de la tecla enter.");
        listarTipos(tipos, largo);
        fflush(stdin);
        scanf("%i", &idSeleccionado);
    }while(idSeleccionado < 1000 || idSeleccionado > 1003);

    return idSeleccionado;
}

void listarBicicletasDeUnTipo(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    int idTipoSeleccionado;
    int i = 0;
    idTipoSeleccionado = pedirIdTipo(tipos, largoTipos);

    system("cls");
    printf("ID\t MARCA\t\t TIPO\t COLOR\t RODADO\t CLIENTE\n");
    printf("--------------------------------------------------------------------\n\n");
    while(!bicicletas[i].estaVacio)
    {
        if(bicicletas[i].idTipo == idTipoSeleccionado)
        {

            mostrarBicicleta(bicicletas[i], colores, largoColores, tipos, largoTipos, clientes, largoClientes);
        }
        i++;
    }
}

void listarBicicletasDeMenorRodado(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    int rodadoMasChicoEncontrado = 0;
    int esPrimeraBici = 1;
    int i = 0;



    while(i < largo && !bicicletas[i].estaVacio)
    {
        if(esPrimeraBici || rodadoMasChicoEncontrado > bicicletas[i].rodado)
        {
            rodadoMasChicoEncontrado = bicicletas[i].rodado;
            esPrimeraBici = 0;
        }
    }
    i = 0;
    while(i < largo && !bicicletas[i].estaVacio)
    {
        if(rodadoMasChicoEncontrado == bicicletas[i].rodado)
        {
            mostrarBicicleta(bicicletas[i], colores, largoColores, tipos, largoTipos, clientes, largoClientes);
        }
        i++;
    }
}

void buscarBicicletasDeTipoYColorSeleccionado(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    int idColorSeleccionado = pedirIdColor(colores, largoColores);
    system("cls");
    int idTipoSeleccionado = pedirIdTipo(tipos, largoTipos);
    system("cls");


    int i = 0;
    printf("ID\t MARCA\t\t TIPO\t COLOR\t RODADO\t CLIENTE\n");
    printf("--------------------------------------------------------------------\n\n");
    while(!bicicletas[i].estaVacio)
    {
        if(bicicletas[i].idColor == idColorSeleccionado && bicicletas[i].idTipo == idTipoSeleccionado)
        {
            mostrarBicicleta(bicicletas[i], colores, largoColores, tipos, largoTipos, clientes, largoClientes);
        }
        i++;
    }

}

void mostarColorPreferidoPorLosClientes(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes)
{
    int i = 0;
    int contadorColores[largoColores];

    int x = 0;

    while(x < largoColores)
    {
        contadorColores[x] = 0;
        x++;
    }

    while(!bicicletas[i].estaVacio && i < largo)
    {
        contadorColores[ (bicicletas[i].idColor - 5000) ] ++;
        i++;
    }

    int mayorCantidad;
    int primeraPasada = 1;

    for(int u = 0; u < largoColores ; u++)
    {
        if(primeraPasada || mayorCantidad < contadorColores[u])
        {
            mayorCantidad = contadorColores[u];
            primeraPasada = 0;
        }
    }

    printf("El/Los colores con mayor cantidad de bicicletas son: \n\n");

    for(int j = 0; j < largoColores ; j++)
    {
        if(mayorCantidad == contadorColores[j])
        {
            printf("%s : %i\n", colores[j].nombreColor, mayorCantidad);
        }
    }

}


