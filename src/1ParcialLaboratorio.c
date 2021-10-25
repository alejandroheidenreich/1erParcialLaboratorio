/*
 ============================================================================
Alejandro Heidenreich

Una empresa de recolección y reciclado de plásticos requiere un sistema que les permita administrar
sus clientes y pedidos de recolección. El programa contará con el siguiente menú:
1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit dirección y localidad. Se generará
un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.
2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.
3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
4) Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un
cliente existente y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y
el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la
empresa.
5) Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan
procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar. Se imprimirán los
pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos. Luego deberán ingresarse la cantidad de kilos
de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
se recolectaron. Por último, se marcará al pedido como “Completado”.
6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
de recolección” que posee en estado “Pendiente”.
7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado
“Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
“Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo
de plástico.
9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "localidad.h"
#include "clientes.h"
#include "pedidos.h"
#include "input.h"
#include "imprimir.h"
#define CLT 100
#define PED 1000
#define LOC 100

int main(void) {
	int opcion;
	int idCliente=1;
	int idPedido=1;
	int idLocalidad=1;
	int flagA=0;
	int posCliente;
	int flagP;
	int verify;
	char* localidad;

	clientes unCliente;
	clientes listaClientes[CLT];
//	clientes listaClientes[CLT]={{100,"EDESUR","123456","Rivadavia 598","Caba",0},
//								{101,"EDENOR","567966","Nazca 123","Caba",0},
//								{102,"JORGITO","987564","Diaz Velez 3123","Caba",0},
//								{103,"AYSA","89756413","Concordia 5173","Moron",0},
//								{104,"NW","606060","ReekWater 123","Valhalla",0}};
	pedidos listaPedidos[PED];
	localidades listaLocalidades[3];



	IniciarClientes(listaClientes,CLT);
	IniciarPedidos(listaPedidos, PED);

	do{
		clear();
		printf("1- Alta de cliente\n2- Modificar datos de cliente\n3- Baja de cliente\n4- Crear pedido de recoleccion\n5- Procesar residuos\n6- Imprimir clientes\n7- Imprimir pedidos pendientes\n8- Imprimir pedidos procesados\n9- Cantidad de pedidos pendientes por localidad\n10- Cantidad de kilos de polipropileno reciclado promedio por cliente\n11- Cliente con más pedidos pendientes\n12- Cliente con más pedidos completados\n13- Cliente con más pedidos\n0- Sailr\n");
		opcion = IngresarEntero("Ingrese una opcion\n",0,10);

		switch(opcion){
			case 1:
				clear();
				printf("==================================\n");
				printf("||        Alta de Clientes      ||\n");
				printf("==================================\n\n");
				unCliente=CrearCliente(idCliente);
				verify=PedirLocalidad (listaLocalidades, LOC, localidad);
				if(verify!=0){
					unCliente.idLocalidad=verify;
				}
				else{
					verify=CrearNuevaLocalidad (listaLocalidades, LOC, idLocalidad, localidad);
					if(verify==1){
						idLocalidad++;
					}
				}
				verify=AltaClientes(listaClientes, CLT, unCliente.idCliente, unCliente.empresa, unCliente.cuit, unCliente.direccion, unCliente.idLocalidad);
				if(verify==1){
					clear();
					printf("Nuevo cliente creado con ID: %d\n", unCliente.idCliente);
					idCliente++;
					flagA=1;
				}

				system("pause");
				break;
			case 2:
				clear();
				printf("==================================\n");
				printf("||   Modificacion de Empleados  ||\n");
				printf("==================================\n\n");
				if(flagA==1){
					verify = ModClientes(listaClientes, CLT);
					if(verify==-1){
						clear();
						printf("Cliente Modificado\n");
					}
					else if(verify!=-1 && verify!=-2){
						posCliente=verify;
						verify=PedirLocalidad(listaLocalidades, LOC, localidad);
						if(verify!=0){
							listaClientes[posCliente].idLocalidad = idLocalidad;
							//unCliente.idLocalidad=verify;
						}
						else{
							verify=CrearNuevaLocalidad (listaLocalidades, LOC, idLocalidad, localidad);
							if(verify==1){
								idLocalidad++;
							}
						}
					}
				}
				else{
					printf("Ningun cliente ha sido dado de alta\n");
				}
			system("pause");
			break;
			case 3:
				clear();
				printf("==================================\n");
				printf("||       Baja de Clientes      ||\n");
				printf("==================================\n\n");
				if(flagA!=0){

					verify = BajaCliente(listaClientes, CLT);

					if(verify==1){
						clear();
						printf("Cliente fue dado de baja\n");
						}
				}
				else{
					printf("Ningun cliente ha sido dado de alta\n");
					system("pause");
					break;
				}

				verify = VerificarClienteCargado(listaClientes, CLT);
				if(verify==1){
					flagA=0;
				}
				system("pause");
				break;
			case 4:
				clear();
				printf("==================================\n");
				printf("||  Crear Pedido de Recoleccion ||\n");
				printf("==================================\n\n");
				if(flagA==1){
					verify = AgregarPedido(listaPedidos,PED,listaClientes, CLT,idPedido);
					if(verify){
						flagP=1;
						idPedido++;
						clear();
						printf("Pedido de recoleccion creado\n");
					}
				}
				else{
					printf("Ningun cliente ha sido dado de alta\n");
				}
				system("pause");
				break;
			case 5:
				clear();
				printf("==================================\n");
				printf("|| 	     Procesar Residuos      ||\n");
				printf("==================================\n\n");
				flagP=VerificarPedidosEstado(listaPedidos, PED, 0);
				if(flagP==1){
					verify=ProcesarResiduos(listaPedidos, PED,listaClientes, CLT);
					if(verify==1){
						printf("Pedido Procesado\n");
					}
				}
				else{
					printf("No hay pedidos creados\n");
				}
				system("pause");
				break;
			case 6:
				clear();
				flagP = VerificarPedidosEstado(listaPedidos, PED, 0);
				if(flagP==1){
					ImprimirClientesPedidosPendientes(listaClientes,CLT,listaPedidos,PED);
				}
				else{
					printf("No hay pedidos creados\n");
				}
				system("pause");
				break;
			case 7:
				clear();
				printf("Pedidos pendientes\n");
				flagP=VerificarPedidosEstado(listaPedidos, PED, 0);
				if(flagP==1){
					ImprimirPedidosPendientes(listaClientes,CLT,listaPedidos,PED);
				}
				else{
					printf("No hay pedidos creados\n");
				}
				system("pause");
				break;
			case 8:
				clear();
				printf("Pedidos procesados\n");
				flagP=VerificarPedidosEstado(listaPedidos, PED, 1);
				if(flagP==1){
				ImprimirPedidosProcesados(listaClientes, CLT,listaPedidos, PED);
				}
				else{
					printf("No hay pedidos creados\n");
				}
				system("pause");
				break;
			case 9:
				clear();
				printf("Pedidos pendientes por localidad\n\n");
				flagP=VerificarPedidosEstado(listaPedidos, PED,0);
				if(flagP==1){
					LocalidadPedidosPendientes (listaClientes,CLT,listaPedidos,PED);
				}
				else{
					printf("No hay pedidos creados\n");
				}
				system("pause");
				break;
			case 10:
				clear();
				printf("Cantidad de kilos reciclados promedio por cliente\n\n");
				flagP=VerificarPedidosEstado(listaPedidos, PED, 1);
				if(flagP==1){
					CantidadRecicladoPorCliente(listaClientes,CLT,listaPedidos,PED);
				}
				else{
					printf("No hay pedidos completados\n");
				}
				system("pause");
				break;
			case 11:
				clear();
				printf("Cliente con más pedidos pendientes\n");
				ClientesMasPedidosEstado(listaClientes, CLT, listaPedidos, PED, 0);
				break;
			case 12:
				clear();
				printf("Cliente con más pedidos completados\n");
				ClientesMasPedidosEstado(listaClientes, CLT, listaPedidos, PED, 1);
				break;
			case 13:
				clear();
				printf("Cliente con más pedidos\n");
				ClientesMasPedidosTotal(listaClientes, CLT, listaPedidos, PED);
				break;
		}

	} while(opcion!=0);

	clear();
	printf("CERRANDO APLICACION\n\n");
	system("pause");
	return EXIT_SUCCESS;
}
