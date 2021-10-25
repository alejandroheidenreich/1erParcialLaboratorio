#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define TIPO 4

typedef struct
{
    int idPedido;
    int idCliente;
    float kilos;
    float kilosReciclados[TIPO];
    int estado; //-1 vacio, 0 pendiente, 1 completado

} pedidos;

/// @fn int IniciarPedidos(pedidos*, int)
/// @param lista
/// @param tam
/// inicialice para todos los valores del campo estado en "-1"
/// @return 0 si se realizo sin problemas, de lo contrario "-1"
int IniciarPedidos(pedidos* lista, int tam);

/// @fn void ImprimirPedidos(pedidos*, int, int)
/// @param listaPedidos
/// @param tamP
/// @param estado
/// imprime un listado de todos los pedidos que tienen el estado en (vacio/pendiente/completado)
/// dependiendo del parametro pasado
void ImprimirPedidos(pedidos* listaPedidos, int tamP,int estado);

/// @fn int VerificarPedidosPendientes(pedidos*, int, int)
/// @param lista
/// @param tam
/// @param estado
/// verifica si existe en la lista un pedido pendiente/completado (estado = 0/1)
/// @return 0 si no existe ningun, 1 si encuentra al menos 1
int VerificarPedidosEstado(pedidos* lista, int tam, int estado);

/// @fn pedidos CrearUnPedido(int, int)
/// @param idPedido
/// @param idCliente
/// crear una sola esctructura de un pedido pendiente (kilos a recolectar y estado=0)
/// @return 1 estrucura pedido pendiente
pedidos CrearUnPedido(int idPedido,int idCliente);

/// @fn int AgregarPedido(pedidos*, int, clientes*, int, int)
/// @param listaPedidos
/// @param tamP
/// @param listaClientes
/// @param tamC
/// @param id
/// imprime lista de clientes y espera que el usuario ingrese la id del mismo.
/// verifica que el cliente exista y crea el pedido añadiendolo a la lista.
/// @return 0 si hubo error, 1 si lo creo
int AgregarPedido(pedidos* listaPedidos, int tamP, clientes* listaClientes, int tamC, int id);

/// @fn int EncontrarPedidoPorID(pedidos*, int, int)
/// @param lista
/// @param tam
/// @param id
/// pasa por la lista buscando el id que le llega como parametro
/// @return indice de la lista si hubo error "-1"
int EncontrarPedidoPorID(pedidos* lista, int tam, int id);

/// @fn int ProcesarResiduos(pedidos*, int, clientes*, int)
/// @param listaPedidos
/// @param tamP
/// @param listaClientes
/// @param tamC
/// pide id del pedido, verifica que el pedido este pendiente y luego pide los kilos reciclados de cada uno
/// verificando que no supere al total ingresado previamnete
/// @return hubo error 0, se logro procesar 1
int ProcesarResiduos(pedidos* listaPedidos, int tamP, clientes* listaClientes, int tamC);

#endif /* PEDIDOS_H_ */
