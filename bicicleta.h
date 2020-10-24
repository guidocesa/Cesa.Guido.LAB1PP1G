#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "color.h"
#include "cliente.h"

typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    float rodado;
    int idCliente;
    int estaVacio;
}eBicicleta;

typedef struct
{
    int id;
    char descripcion[21];
}eTipo;

/** \brief Inicializa todos los elementos del velctor como estaVacio = true.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \return void
 *
 */
void inicializarListado(eBicicleta bicicletas[], int largo);

/** \brief Devuelve el menor ID libre posible.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \return int
 *
 */
int obtenerIdLibre(eBicicleta bicicletas[] , int largo);

/** \brief Muestra todos los tipos de bicicleta que recibe.
 *
 * \param tipos[] eTipo
 * \param largo int
 * \return void
 *
 */
void listarTipos(eTipo tipos[], int largo);

/** \brief Recibe una posicion la cual dejara libre y mueve todas las bicicletas en una posicion que esten en un indice igual o mas alto al de posicionInicial.
            Devuelve 1 si se pudo realizar y 0 si el vector estaba lleno.
 *
 * \param posicionInicial int
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \return int
 *
 */
int moverBicicletasDesde(int posicionInicial, eBicicleta bicicletas[], int largo);

/** \brief Agrega una bicicleta nueva al listado en la posicion correspondiente segun Tipo y luego rodado.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param marca[21] char
 * \param idTipo int
 * \param idColor int
 * \param rodado float
 * \return int
 *
 */
int agregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, char marca[], int idTipo, int idColor, float rodado, int idCliente);

/** \brief Solicita los datos de la bicicleta nueva a agregar y luego llama a agregarBicicletaOrdenada
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \return void
 *
 */
int solicitarDatosYAgregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Pide un ID para borrar una bicicleta y llama a borrarBicicletaPorID
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \return void
 *
 */
int darDeBajaBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Recibe el ID de la bicicleta a borrar, devuelve 1 si fue borrada y 0 si no se encuentra en el listado. Al borrar la bicicleta acomoda el resto del listado.
 *
 * \param
 * \param
 * \return
 *
 */
int borrarBicicletaPorId(eBicicleta bicicletas[], int id, int largo);

/** \brief Pide al usuario que bicicleta desea modificar, que dato dentro de la misma, y luego la vuelve a ordenar dentro del listado.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \return void
 *
 */
int modificarBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Muestra todas las bicicletas dentro del listado.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \return void
 *
 */
void listarBicicletas(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Devuelve 1 si el ID recibido se encuentra en el listado, 0 si no es asi.
 *
 * \param idBicicleta int
 * \param bicicletas[] eBicicleta
 * \param largoBicicletas int
 * \return int
 *
 */
int idEstaEnElListado(int idBicicleta,eBicicleta bicicletas[],int largoBicicletas);

/** \brief Devuelve el puntero al string que contiene la descripcion del id de tipo recibido.
 *
 * \param tipos[] eTipo
 * \param largo int
 * \param id int
 * \return char*
 *
 */
char* obtenerDescTipo(eTipo tipos[], int largo, int id);

/** \brief Muestra las bicicletas del color seleccionado por el usuario.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param clientes[] eCliente
 * \param largoClientes int
 * \return void
 *
 */
void listarBicicletasPorColor(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Muestra los diferentes tipos y pide al usuario que seleccione uno y retorna el ID del mismo.,
 *
 * \param tipos[] eTipo
 * \param largo int
 * \return int
 *
 */
int pedirIdTipo(eTipo tipos[], int largo);

/** \brief Muestra todas las bicicletas de un tipo seleccionado.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param clientes[] eCliente
 * \param largoClientes int
 * \return void
 *
 */
void listarBicicletasDeUnTipo(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Muestra las bicicletas del menor rodado que se encuentre en la lista.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param clientes[] eCliente
 * \param largoClientes int
 * \return void
 *
 */
void listarBicicletasDeMenorRodado(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Imprime una bicicleta por pantalla.
 *
 * \param bicicleta eBicicleta
 * \param colores[] eColor
 * \param largoColores int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param clientes[] eCliente
 * \param largoClientes int
 * \return void
 *
 */
void mostrarBicicleta(eBicicleta bicicleta, eColor colores[], int largoColores, eTipo tipos[], int largoTipos, eCliente clientes[], int largoClientes);

/** \brief Muestra las bicicletas de un tipo y color seleccionados en especifico.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param clientes[] eCliente
 * \param largoClientes int
 * \return void
 *
 */
void buscarBicicletasDeTipoYColorSeleccionado(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Muestra el/los colores predominantes en las bicicletas del listado.
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param clientes[] eCliente
 * \param largoClientes int
 * \return void
 *
 */
void mostarColorPreferidoPorLosClientes(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

#endif // BICICLETA_H_INCLUDED
