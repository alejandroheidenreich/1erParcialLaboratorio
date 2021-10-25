

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct
{
    int idCliente;
    char empresa[51];
    char cuit[15];
    char direccion[51];
    int idLocalidad;

    int libre; // 1 vacio, 0 lleno

} clientes;

/// @fn int IniciarClientes(clientes*, int)
/// @param list
/// @param len
/// verifica que los parametros sean validos, y cambia todos los valores del campo libre a 1
/// de la lista de clientes
/// @return -1 = error, 0 = OK
int IniciarClientes(clientes* list, int len);

/// @fn clientes CrearCliente(int)
/// @param id
/// el usuario carga todos los campo de una estructura clientes execptuando la id que llega como parametro
/// @return dicha estrcutura clientes
clientes CrearCliente(int id);

/// @fn void ImprimirClientes(clientes*, int)
/// @param listaClientes
/// @param tamC
/// imprime toda la lista de clientes mientras tengan libre = 0
void ImprimirClientes(clientes* listaClientes, int tamC, localidades* listaLocalidades, int tamL);

/// @fn int AltaClientes(clientes*, int, int, char*, char*, char*, char*)
/// @param lista
/// @param tam
/// @param id
/// @param empresa
/// @param cuit
/// @param direccion
/// @param localidad
/// añade nuevo cliente a la lista y cambia el estado libre a 0
/// @return 0 error, 1 ok
int AltaClientes(clientes* lista, int tam, int id, char* empresa, char* cuit, char* direccion, int localidad);

/// @fn int VerificarClienteCargado(clientes*, int)
/// @param lista
/// @param tam
/// verifica si hay espacio en el vector para un nuevo cliente (libre=1)
/// @return 0 error, 1 OK
int VerificarClienteCargado(clientes* lista, int tam);

/// @fn int EncontrarClientePorID(clientes*, int, int)
/// @param lista
/// @param tam
/// @param id
/// busca en la lista de clientes, dicho cliente que tenga la id que llega por parametro
/// @return el indice del cliente en el vector, o error "-1"
int EncontrarClientePorID(clientes* lista, int tam, int id);

/// @fn int ModClientes(clientes*, int)
/// @param lista
/// @param tam
/// se pide id para encontrar el cliente a modificar, verifica si el cliente existe, yluego se pregunta que dato desea modificar
/// @return 1 se logro modificar, 0 error
int ModClientes(clientes* lista, int tam);

/// @fn int BajaCliente(clientes*, int)
/// @param lista
/// @param tam
/// se pide id para encontrar el cliente a dar de baja, verifica si el cliente existe, y luego cambia el campo "libre" a 1;
/// @return 0 error, 1 se dio de baja
int BajaCliente(clientes* lista, int tam);

int ModLocalidadCliente(clientes* lista, int tam, int posCliente, int idLocalidad);

#endif /* CLIENTES_H_ */
