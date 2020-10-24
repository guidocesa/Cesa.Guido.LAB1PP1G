#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[21];
    char sexo;
    int estaVacio;
}eCliente;

/** \brief Muestra todos los clientes contenidos en el array, sus nombres, id y sexo.
 *
 * \param clientes[] eCliente
 * \param largo int
 * \return void
 *
 */
void listarClientes(eCliente clientes[], int largo);

/** \brief Devuelve el puntero al nombre del cliente con el id recibido.
 *
 * \param clientes[] eCliente
 * \param largo int
 * \param id int
 * \return char*
 *
 */
char* obtenerNombreCliente(eCliente clientes[], int largo, int id);

#endif // CLIENTE_H_INCLUDED
