#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
}eColor;

/** \brief Muestra todos los colores del listado recibido.
 *
 * \param colores[] eColor
 * \param largo int
 * \return void
 *
 */
void listarColores(eColor colores[], int largo);

/** \brief Devuelve el puntero al String del nombre del id de color recibido.
 *
 * \param colores[] eColor
 * \param largo int
 * \param id int
 * \return char*
 *
 */
char* obtenerNombreColor(eColor colores[], int largo, int id);

/** \brief Muestra la lista de colores y devuelve el id del color seleccionado por el usuario.
 *
 * \param colores[] eColor
 * \param largo int
 * \return int
 *
 */
int pedirIdColor(eColor colores[], int largo);

#endif // COLOR_H_INCLUDED
