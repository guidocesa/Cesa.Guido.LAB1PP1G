#include <stdio.h>
#include <stdlib.h>
#define BICICLETASMAXIMAS 200
#define TOTALTRABAJOS 200
#define TOTALTIPOS 4
#define TOTALCOLORES 5
#define TOTALSERVICIOS 4

typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    float rodado;
    int estaVacio;
}eBicicleta;

typedef struct
{
    int id;
    char descripcion[21];
}eTipo;

typedef struct
{
    int id;
    char nombreColor[21];
}eColor;

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
}eServicio;

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int estaVacio;
}eTrabajo;

void inicializarListado(eBicicleta bicicletas[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        bicicletas[i].estaVacio = 1;
        bicicletas[i].idTipo = 0;
        bicicletas[i].idColor = 0;
    }
}

void inicializarTrabajos(eTrabajo trabajos[], int largo)
{
    for(int i = 0; i < largo; i++)
    {
        trabajos[i].estaVacio = 1;
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
        printf("0 - Salir de la base de datos. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 10 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;
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

void listarServicios(eServicio servicios[], int largo)
{
    int i = 0;
    printf("ID\t PRECIO\t DESCRIPCION\n");
    printf("--------------------------------------------------------------------\n\n");
    while(i < largo)
    {
        printf("%i\t%f\t%s\n\n", servicios[i].id , servicios[i].precio ,servicios[i].descripcion);
        i++;
    }
}

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

int agregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, char marca[21], int idTipo, int idColor, float rodado)
{
    int retorno = 0;
    int i = 0;
    int fueAgregado = 0;
    int id = obtenerIdLibre(bicicletas ,  largo);
    while(!fueAgregado && i < largo)
    {
        if( idTipo < bicicletas[i].idTipo ||
           bicicletas[i].estaVacio ||
           (idTipo == bicicletas[i].idTipo) && rodado < bicicletas[i].rodado)
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
                    bicicletas[i].estaVacio = 0;
                    fueAgregado = 1;
                }
                else
                {
                    retorno = -1;
                }
           }
           else
           {
                    bicicletas[i].id = id;
                    strcpy(bicicletas[i].marca , marca);
                    bicicletas[i].idTipo = idTipo;
                    bicicletas[i].idColor = idColor;
                    bicicletas[i].rodado = rodado;
                    bicicletas[i].estaVacio = 0;
                    fueAgregado = 1;
           }
        }
        i++;
    }
    if( i == 1000 && !fueAgregado)
    {
        retorno = -1;
    }
    return retorno;
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

void solicitarDatosYAgregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores)
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;

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
        printf("Por favor ingrese el rodado de la bicicleta seguido de la tecla enter.  \n\n");
        fflush(stdin);
        scanf("%f" , &rodado);
    }while(rodado < 20 || rodado > 29);

    agregarBicicletaOrdenada(bicicletas , largo, marca, idTipo, idColor, rodado);
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

void darDeBajaBicicleta(eBicicleta bicicletas[], int largo)
{
    int id;
    system("cls");
    printf("Ingrese el ID de la bicicleta que desea dar de baja y luego presione enter. \n\n");
    fflush(stdin);
    scanf("%i" , &id);

    int fueBorrado = borrarBicicletaPorId(bicicletas , id, largo);

    if(!fueBorrado)
    {
        printf("Ese ID de bicicleta no se encuentra en el sistema, por favor checkee en el listado. /n");
        system("pause");
    }
}

void modificarBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores)
{
    system("cls");
    int idAModificar;
    int idEncontrado = 0;
    int i = 0;
    int confimacion = 0;

    printf("Por favor ingrese el numero de ID de la bicicleta a modificar seguido de la tecla enter.");
    fflush(stdin);
    scanf("%i", &idAModificar);

    while(!idEncontrado && !bicicletas[i].estaVacio)
    {
        if(bicicletas[i].id == idAModificar)
        {
            idEncontrado = 1;
        }
        i++;
    }

    if(idEncontrado)
    {
        borrarBicicletaPorId(bicicletas, idAModificar, largo);
        solicitarDatosYAgregarBicicletaOrdenada(bicicletas, largo, tipos, largoTipos, colores, largoColores);

    }
    else
    {
        printf("No se pudo encontrar una bicicleta con ese Id, por favor confirme que sea el correcto.");
        system("pause");
    }
}

char* obtenerNombreColor(eColor colores[], int largo, int id)
{
    for(int i = 0 ; i < largo ; i++ )
    {
        if(colores[i].id == id)
        {
            return colores[i].nombreColor;
        }
    }
}

char* obtenerDescTipo(eTipo tipos[], int largo, int id)
{
    for(int i = 0 ; i < largo ; i++ )
    {
        if(tipos[i].id == id)
        {
            return tipos[i].descripcion;
        }
    }
}

void listarBicicletas(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores)
{
    int i = 0;
    char colorAMostrar[21];
    char tipoAMostrar[21];
    system("cls");
    printf("ID\t MARCA\t\t IDTIPO\t IDCOLOR\t RODADO\n");
    printf("--------------------------------------------------------------------\n\n");
    while(!bicicletas[i].estaVacio)
    {
        strcpy(colorAMostrar, obtenerNombreColor(colores, largoColores, bicicletas[i].idColor) );
        strcpy(tipoAMostrar, obtenerDescTipo(tipos, largoTipos, bicicletas[i].idTipo) );

        printf("%i\t%s\t\t%s\t%s\t%f\n", bicicletas[i].id, bicicletas[i].marca, tipoAMostrar, colorAMostrar, bicicletas[i].rodado);
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

void agregarTrabajo(eTrabajo trabajos[],int idBicicleta,int  idServicio,int  dia,int  mes,int  anio, int trabajosRealizados)
{
    eFecha fecha;
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.anio = anio;

    trabajos[trabajosRealizados].idBicicleta = idBicicleta;
    trabajos[trabajosRealizados].idServicio = idServicio;
    trabajos[trabajosRealizados].fecha = fecha;

    trabajosRealizados ++;
}

void altaTrabajo(eTrabajo trabajos[], int largoTrabajos,eBicicleta bicicletas[], int largoBicicletas,eServicio servicios[],int largoServicios, int trabajosRealizados)
{

    int idBicicleta;
    int idServicio;
    int dia;
    int mes;
    int anio;

    system("cls");
    printf("Por favor ingrese el id de la bicicleta seguido de la tecla enter. \n\n");
    fflush(stdin);
    scanf("%i" , &idBicicleta);

    if(idEstaEnElListado(idBicicleta, bicicletas, largoBicicletas))
    {
        do
        {
            system("cls");
            printf("Por favor ingrese el id del servicio a realizar. \n\n");
            listarServicios(servicios, largoServicios);
            fflush(stdin);
            scanf("%i" , &idServicio);
        }while(idServicio < 20000 || idServicio > 20004);

        do
        {
            system("cls");
            printf("Por favor ingrese el numero de dia de hoy. \n\n");
            fflush(stdin);
            scanf("%i" , &dia);
        }while(dia < 1 || dia > 31);

        do
        {
            system("cls");
            printf("Por favor ingrese el numero de mes. \n\n");
            fflush(stdin);
            scanf("%i" , &mes);
        }while(mes < 1 || mes > 12);

        do
        {
            system("cls");
            printf("Por favor ingrese el anio. \n\n");
            fflush(stdin);
            scanf("%i" , &anio);
        }while(anio < 1980 || anio > 2100);

        agregarTrabajo(trabajos, idBicicleta, idServicio, dia, mes, anio, trabajosRealizados);
        trabajosRealizados++;

    }
    else
    {
        printf("No hay una bicicleta con ese ID. \n\n");
        system("pause");
    }
}

int menuPrincipal(eBicicleta bicicletas[], int largoBicicletas, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios , eTrabajo trabajos[], int largoTrabajos)
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
            solicitarDatosYAgregarBicicletaOrdenada(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores);
            break;
        case 2:
            modificarBicicleta(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores);
            break;
        case 3:
            darDeBajaBicicleta(bicicletas, largoBicicletas);
            break;
        case 4:
            listarBicicletas(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores);
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
            break;
        case 9:
            //listarTrabajos();
            break;
        case 0:
            programaTerminado =  confirmarSalida();
            break;
        }
    }

}

void hardcodearDatos(eTipo tipos[], int largoTipos, eColor colores[], int  largoColores,eServicio servicios[], int largoServicios)
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

}

int main()
{
    eTrabajo trabajos[TOTALTRABAJOS];
    eTipo tipos[TOTALTIPOS];
    eColor colores[TOTALCOLORES];
    eServicio servicios[TOTALSERVICIOS];
    eBicicleta bicicletas[BICICLETASMAXIMAS];
    hardcodearDatos(tipos, TOTALTIPOS, colores, TOTALCOLORES, servicios, TOTALSERVICIOS);
    inicializarListado(bicicletas, BICICLETASMAXIMAS);
    inicializarTrabajos(trabajos, TOTALTRABAJOS);
    menuPrincipal(bicicletas, BICICLETASMAXIMAS, tipos, TOTALTIPOS, colores, TOTALCOLORES, servicios, TOTALSERVICIOS, trabajos, TOTALTRABAJOS);
}
