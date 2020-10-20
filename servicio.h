#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "bicicleta.h"

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
}eServicio;

/** \brief Muestra todos los servicios que contiene el listado recibido
 *
 * \param servicios[] eServicio
 * \param largo int
 * \return void
 *
 */
void listarServicios(eServicio servicios[], int largo);

/** \brief Devuelve el puntero al string que contiene la descripcion del servicio recibido como ID.
 *
 * \param servicios[] eServicio
 * \param largoServicios int
 * \param id int
 * \return char*
 *
 */
char* obtenerDescServicio(eServicio servicios[], int largoServicios, int id);

#endif // SERVICIO_H_INCLUDED
