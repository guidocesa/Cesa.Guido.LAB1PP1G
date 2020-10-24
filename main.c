#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "funciones.h"
#include "cliente.h"
#define BICICLETASMAXIMAS 200
#define TOTALTRABAJOS 200
#define TOTALTIPOS 4
#define TOTALCOLORES 5
#define TOTALSERVICIOS 4
#define CLIENTESHARDCODEADOS 5

int main()
{
    eTrabajo trabajos[TOTALTRABAJOS];
    eTipo tipos[TOTALTIPOS];
    eColor colores[TOTALCOLORES];
    eServicio servicios[TOTALSERVICIOS];
    eBicicleta bicicletas[BICICLETASMAXIMAS];
    eCliente clientes[CLIENTESHARDCODEADOS];
    hardcodearDatos(tipos, TOTALTIPOS, colores, TOTALCOLORES, servicios, TOTALSERVICIOS, clientes, CLIENTESHARDCODEADOS);
    inicializarListado(bicicletas, BICICLETASMAXIMAS);
    inicializarTrabajos(trabajos, TOTALTRABAJOS);
    menuPrincipal(bicicletas, BICICLETASMAXIMAS, tipos, TOTALTIPOS, colores, TOTALCOLORES, servicios, TOTALSERVICIOS, trabajos, TOTALTRABAJOS, clientes, CLIENTESHARDCODEADOS);

    return 0;
}
