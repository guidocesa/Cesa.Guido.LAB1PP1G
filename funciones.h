#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "bicicleta.h"
#include "trabajo.h"
#include "color.h"
#include "servicio.h"
#include "cliente.h"

/** \brief Confirma la salida del programa
 *
 * \return int
 *
 */
int confirmarSalida();

/** \brief Muestra todas las opciones del menu y devuelve la seleccionada por el usuario.
 *
 * \return int
 *
 */
int mostrarOpcionesYObtenerSeleccion();

/** \brief Formatea el String de manera que solo la primer letra sea la Mayuscula.
 *
 * \param marca[] char
 * \return void
 *
 */
void formatearString(char marca[]);

/** \brief Llama a la funcion correspondiente segun lo que devuelva mostrarOpcionesYObtenerSeleccion, tambien contiene el blucle que mantiene al programa en ejecucion.
 *
 * \param bicicletas[] eBicicleta
 * \param largoBicicletas int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param servicios[] eServicio
 * \param largoServicios int
 * \param trabajos[] eTrabajo
 * \param largoTrabajos int
 * \return int
 *
 */
int menuPrincipal(eBicicleta bicicletas[], int largoBicicletas, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios , eTrabajo trabajos[], int largoTrabajos, eCliente clientes[], int largoClientes);

/** \brief Funcion auxiliar para settear los colores, tipos, y servicios de las bicicletas
 *
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param servicios[] eServicio
 * \param largoServicios int
 * \return void
 *
 */
void hardcodearDatos(eTipo tipos[], int largoTipos, eColor colores[], int  largoColores,eServicio servicios[], int largoServicios, eCliente clientes[], int largoClientes);

/** \brief Alerta que el listado no tiene elementos por consola.
 *
 * \return void
 *
 */
void alertarListadoVacio();

#endif // FUNCIONES_H_INCLUDED
