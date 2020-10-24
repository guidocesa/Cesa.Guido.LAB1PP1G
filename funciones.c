#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "funciones.h"
#include "cliente.h"

int confirmarSalida()
{
    int retorno = 0;
    system("cls");
    printf("Seguro que desea salir del programa? \n 1 : Si \n 0 : No  \n\n Sus cambios o bicicletas no seran guardados. \n");
    fflush(stdin);
    scanf("%i", &retorno);
    return retorno;
}

int mostrarOpcionesYObtenerSeleccion()
{
    int seleccion;
    int seleccionEsCorrecta = 0;

    while(!seleccionEsCorrecta)
    {

        system("cls");
        printf("Por favor seleccione una opcion y presione la tecla enter: \n\n");
        printf("1 - Dar de ALTA una bicicleta.\n");
        printf("2 - Modificar datos de una bicicleta. \n");
        printf("3 - Dar de BAJA una bicicleta. \n");
        printf("4 - Ver todas las bicicletas. \n");
        printf("5 - Ver todas los tipos de bicicletas. \n");
        printf("6 - Ver todas los colores de bicicletas. \n");
        printf("7 - Ver todas los servicios para bicicletas. \n");
        printf("8 - Dar de ALTA un trabajo realizado.\n");
        printf("9 - Ver todos los trabajos realizados.\n");
        printf("10 - Ver todas las bicicletas de un color seleccionado.\n");
        printf("11 - Ver todas las bicicletas de un tipo seleccionado. \n");
        printf("12 - Ver la/las bicicletas con el rodado mas chico. \n");
        printf("13 - Ver las bicicletas ordenadas por tipo. \n");
        printf("14 - Buscar bicicletas de un color y tipo en particular. \n");
        printf("15 - Ver el color mas elegido por los clientes. \n");
        printf("0 - Salir de la base de datos. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 16 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;
}

void formatearString(char marca[])
{
    int i = 0;
    while (marca[i])
    {
        marca[i] = tolower(marca[i]);
        i++;
    }
    marca[0] = toupper(marca[0]);
}

void alertarListadoVacio()
{
    system("cls");
    printf("El listado esta vacio, primero debe hacer un alta.\n\n");
    system("pause");
}

int menuPrincipal(eBicicleta bicicletas[], int largoBicicletas, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios , eTrabajo trabajos[], int largoTrabajos, eCliente clientes[], int largoClientes)
{
    int trabajosRealizados = 0;
    int programaTerminado = 0;
    int opcionSeleccionada;
    while(!programaTerminado)
    {
        opcionSeleccionada = mostrarOpcionesYObtenerSeleccion();
        switch(opcionSeleccionada)
        {
        case 1:
            solicitarDatosYAgregarBicicletaOrdenada(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            break;
        case 2:
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                modificarBicicleta(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            }
            break;
        case 3:
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                darDeBajaBicicleta(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            }
            break;
        case 4:
            system("cls");
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                listarBicicletas(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            }
            break;
        case 5:
            system("cls");
            listarTipos(tipos, largoTipos);
            system("pause");
            break;
        case 6:
            system("cls");
            listarColores(colores, largoColores);
            system("pause");
            break;
        case 7:
            system("cls");
            listarServicios(servicios, largoServicios);
            system("pause");
            break;
        case 8:
            altaTrabajo(trabajos, largoTrabajos, bicicletas, largoBicicletas, servicios, largoServicios, trabajosRealizados);
            trabajosRealizados ++;
            break;
        case 9:
            if(trabajosRealizados == 0)
            {
                alertarListadoVacio();
            }
            else
            {
                listarTrabajos(trabajos, largoTrabajos, servicios, largoServicios, trabajosRealizados);
            }
            break;
        case 10:
            system("cls");
            listarBicicletasPorColor(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 11:
            system("cls");
            listarBicicletasDeUnTipo(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 12:
            system("cls");
            listarBicicletasDeMenorRodado(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 13:
            system("cls");
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                listarBicicletas(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            }
            break;
        case 14:
            system("cls");
            buscarBicicletasDeTipoYColorSeleccionado(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 15:
            system("cls");
            mostarColorPreferidoPorLosClientes(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 0:
            programaTerminado =  confirmarSalida();
            break;
        }
    }

    return 0;

}

void hardcodearDatos(eTipo tipos[], int largoTipos, eColor colores[], int  largoColores,eServicio servicios[], int largoServicios, eCliente clientes[], int largoClientes)
{
    strcpy(tipos[0].descripcion , "Rutera");
    tipos[0].id = 1000;
    strcpy(tipos[1].descripcion , "Carrera");
    tipos[1].id = 1001;
    strcpy(tipos[2].descripcion , "Mountain");
    tipos[2].id = 1002;
    strcpy(tipos[3].descripcion , "BMX");
    tipos[3].id = 1003;

    strcpy(colores[0].nombreColor , "Gris");
    colores[0].id = 5000;
    strcpy(colores[1].nombreColor , "Negro");
    colores[1].id = 5001;
    strcpy(colores[2].nombreColor , "Blanco");
    colores[2].id =5002;
    strcpy(colores[3].nombreColor , "Azul");
    colores[3].id =5003;
    strcpy(colores[4].nombreColor , "Rojo");
    colores[4].id =5004;

    strcpy(servicios[0].descripcion , "Limpieza");
    servicios[0].precio = 250;
    servicios[0].id = 20000;
    strcpy(servicios[1].descripcion , "Parche");
    servicios[1].precio = 300;
    servicios[1].id = 20001;
    strcpy(servicios[2].descripcion , "Centrado");
    servicios[2].precio = 400;
    servicios[2].id = 20002;
    strcpy(servicios[3].descripcion , "Cadena");
    servicios[3].precio = 350;
    servicios[3].id = 20003;

    clientes[0].id = 6000;
    strcpy(clientes[0].nombre, "Juan");
    clientes[0].sexo = 'm';
    clientes[1].id = 6001;
    strcpy(clientes[1].nombre, "Lucas");
    clientes[1].sexo = 'm';
    clientes[2].id = 6002;
    strcpy(clientes[2].nombre, "Marcela");
    clientes[2].sexo = 'f';
    clientes[3].id = 6003;
    strcpy(clientes[3].nombre, "Rodrigo");
    clientes[3].sexo = 'm';
    clientes[4].id = 6004;
    strcpy(clientes[4].nombre, "Lucila");
    clientes[4].sexo = 'f';
}
