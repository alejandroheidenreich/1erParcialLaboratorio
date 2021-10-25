
#ifndef IMPRIMIR_H_
#define IMPRIMIR_H_

/// @fn int ImprimirClientesPedidosPendientes(clientes*, int, pedidos*, int)
/// @param listaClientes
/// @param tamC
/// @param listaPedidos
/// @param tamP
/// @return imprime una lista de clientes con todos sus datos junto con la cantidad de pedidos
/// de recolección que posee en estado=0 (pendiente)
int ImprimirClientesPedidosPendientes(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP);

/// @fn int ImprimirPedidosPendientes(clientes*, int, pedidos*, int)
/// @param listaClientes
/// @param tamC
/// @param listaPedidos
/// @param tamP
/// @return una imprime lista de los pedidos que se encuentren en estado=0
/// (pendiente) con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
int ImprimirPedidosPendientes(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP);

/// @fn int ImprimirPedidosProcesados(clientes*, int, pedidos*, int)
/// @param listaClientes
/// @param tamC
/// @param listaPedidos
/// @param tamP
/// @return una lista de los pedidos que se encuentren en estado=1
/// “Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico.
int ImprimirPedidosProcesados(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP);

/// @fn int LocalidadPedidosPendientes(clientes*, int, pedidos*, int)
/// @param listaClientes
/// @param tamC
/// @param listaPedidos
/// @param tamP
/// se pide una localidad, e indica la cantidad de pedidos pendientes para dicha localidad.
/// @return
int LocalidadPedidosPendientes (clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP);

/// @fn int CantidadRecicladoPorCliente(clientes*, int, pedidos*, int)
/// @param listaClientes
/// @param tamC
/// @param listaPedidos
/// @param tamP
/// Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
/// @return
int CantidadRecicladoPorCliente(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP);

int ClientesMasPedidosEstado(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP, int estado);

int ClientesMasPedidosTotal(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP);

#endif /* IMPRIMIR_H_ */
