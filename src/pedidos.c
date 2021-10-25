#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "clientes.h"
#include "pedidos.h"

int IniciarPedidos(pedidos* lista, int tam)
{
	int check=-1;

	if(!(lista == NULL || tam>1000 || tam<1)){
		check = 0;
		for(int i=0; i<tam; i++){
			lista[i].estado = -1;
		}
	}


	return check;
}

void ImprimirPedidos(pedidos* listaPedidos, int tamP, int estado){
	printf("==========================================================\n");
	printf("| ID Pedido |	ID Empresa   |	 Kilos Recolectados	 |\n");
	printf("==========================================================\n");
	if(listaPedidos!=NULL){
		for(int i=0; i<tamP; i++){
			if(listaPedidos[i].estado==estado){
				printf("|%11d| %15d| %25f|\n", listaPedidos[i].idPedido,listaPedidos[i].idCliente,listaPedidos[i].kilos);
				printf("==========================================================\n");
			}
		}
	}
}

int VerificarPedidosEstado(pedidos* lista, int tam, int estado){
	int check=0;

	for (int i=0; 1<tam; i++){
		if(lista[i].estado == estado){
			check=1;
			break;
		}
	}

	return check;
}

pedidos CrearUnPedido(int idPedido,int idCliente){
	pedidos unPedido;

	if(idPedido>0){
		unPedido.idPedido = idPedido;
		unPedido.idCliente = idCliente;

		unPedido.kilos = PedirValidoNumeroFlotante("Ingrese la cantidad de kilos totales a recolectar\n", "ERROR - Cantidad invalida ");
		unPedido.estado = 0;

		}

	return unPedido;
}

int AgregarPedido(pedidos* listaPedidos, int tamP, clientes* listaClientes, int tamC, int id){
	int check=0;
	int idCliente, pos;
	pedidos unPedido;

	if(listaClientes!=NULL){
		ImprimirClientes(listaClientes, tamC);
		idCliente=PedirValidoNumeroEntero("Ingrese ID del cliente para crear el pedido de recoleccion\n", "ID INVALIDO - ");
		pos = EncontrarClientePorID(listaClientes, tamC, idCliente);
		if(pos  == -1 || listaClientes[pos].libre==1 ){
			printf("ERROR - Cliente no encontrado\n");
		}
		else{
			unPedido=CrearUnPedido(id,idCliente);
			for(int i=0; i<tamP; i++){
				if(listaPedidos[i].estado==-1){
					check=1;
					listaPedidos[i].idPedido = unPedido.idPedido;
					listaPedidos[i].idCliente = unPedido.idCliente;
					listaPedidos[i].kilos = unPedido.kilos;
					listaPedidos[i].estado = unPedido.estado;
					break;
				}
			}
		}

	}
	return check;
}

int EncontrarPedidoPorID(pedidos* lista, int tam, int id)
{
	int i;

		if(lista != NULL && (tam<100 || tam>1)){
			i = 0;
			for(i=0; i<tam; i++){
				if(lista[i].idPedido==id && lista[i].estado==0){
					break;
				}
			}
			if(i==tam){
				i=-1;
			}
		}

    return i;
}

int ProcesarResiduos(pedidos* listaPedidos, int tamP, clientes* listaClientes, int tamC){
	int check=0;
	int id,pos,flag=0;
	if(listaPedidos!=NULL){
		ImprimirPedidos(listaPedidos, tamP,0);

		id=PedirValidoNumeroEntero("Ingrese ID del pedido a procesar\n", "ID INVALIDO - ");

		pos = EncontrarPedidoPorID(listaPedidos, tamP, id);

		if(pos  == -1 || listaPedidos[pos].estado != 0){
				printf("ERROR - Pedido no encontrado\n");
		}
		else{
			do{
				listaPedidos[pos].kilosReciclados[0] = IngresarFlotante("Ingrese la cantidad de kilos de HDPE\n",1,10000);
				listaPedidos[pos].kilosReciclados[1] = IngresarFlotante("Ingrese la cantidad de kilos de LPDE\n",1,10000);
				listaPedidos[pos].kilosReciclados[2] = IngresarFlotante("Ingrese la cantidad de kilos de PP\n",1,10000);
				listaPedidos[pos].kilosReciclados[3] = listaPedidos[pos].kilos - (listaPedidos[pos].kilosReciclados[0]+listaPedidos[pos].kilosReciclados[1]+listaPedidos[pos].kilosReciclados[2]);
				if(listaPedidos[pos].kilosReciclados[3]<0){
					printf("Cantidad de Kilos invalido, supera a la cantidad de kilos recolectados\n");
				}
				else{
					flag=1;
					listaPedidos[pos].estado=1;
					check=1;
				}
			}while(flag==0);
		}
	}

	return check;
}
