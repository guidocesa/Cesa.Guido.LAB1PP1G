#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "color.h"

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
int agregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, char marca[21], int idTipo, int idColor, float rodado);

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
void solicitarDatosYAgregarBicicletaOrdenada(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores);

/** \brief Pide un ID para borrar una bicicleta y llama a borrarBicicletaPorID
 *
 * \param bicicletas[] eBicicleta
 * \param largo int
 * \return void
 *
 */
void darDeBajaBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores);

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
void modificarBicicleta(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores);

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
void listarBicicletas(eBicicleta bicicletas[], int largo, eTipo tipos[], int largoTipos, eColor colores[], int largoColores);

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

#endif // BICICLETA_H_INCLUDED
