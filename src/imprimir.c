
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "clientes.h"
#include "pedidos.h"

int ImprimirClientesPedidosPendientes(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP){
	int check=0;
	int pendientes;

	for(int i=0; i<tamC;i++){
		if(listaClientes[i].libre == 0){
			check=1;
			pendientes=0;
			printf("ID: %d\nEmpresa: %s\nCUIT: %s\nDireccion: %s\nLocalidad: %s\n",listaClientes[i].idCliente,listaClientes[i].empresa,listaClientes[i].cuit,listaClientes[i].direccion,listaClientes[i].localidad);
			for(int j=0; j<tamP; j++){
				if(listaPedidos[j].idCliente == listaClientes[i].idCliente && listaPedidos[j].estado == 0){
					pendientes++;
				}
			}
			printf("Cantidad de Pedidos Pendientes: %d\n", pendientes);
		}
	}

	return check;
}

int ImprimirPedidosPendientes(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP){
	int check=0;


	for(int i=0; i<tamP; i++){
		if(listaPedidos[i].estado==0){
			for(int j=0; j<tamC; j++){
				if(listaClientes[j].idCliente == listaPedidos[i].idCliente && listaClientes[j].libre == 0){
					check=1;
					printf("CUIT: %s\nDireccion del cliente: %s\n",listaClientes[j].cuit,listaClientes[j].direccion);
					printf("Cantidad de kilos a recolectar: %f\n",listaPedidos[i].kilos);
				}

			}
		}
	}
	return check;
}

int ImprimirPedidosProcesados(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP){
	int check=0;


	for(int i=0; i<tamP; i++){
		if(listaPedidos[i].estado==1){
			for(int j=0; j<tamC; j++){
				if(listaClientes[j].idCliente == listaPedidos[i].idCliente && listaClientes[j].libre == 0){
					check=1;
					printf("CUIT: %s\nDireccion del cliente: %s\n",listaClientes[j].cuit,listaClientes[j].direccion);
					printf("Cantidad de kilos reciclados de HDPE: %f\n",listaPedidos[i].kilosReciclados[0]);
					printf("Cantidad de kilos reciclados de LDPE: %f\n",listaPedidos[i].kilosReciclados[1]);
					printf("Cantidad de kilos reciclados de PP: %f\n\n",listaPedidos[i].kilosReciclados[2]);
				}

			}
		}
	}
	return check;
}

int LocalidadPedidosPendientes (clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP, localidades* listaLocalidades, int tamL){
	int check=1;
	char localidad[51];
	int comp;
	int pos;
	int cantPendientes=0;
	int flag=0;

	//IngresarCadena("Ingrese una localidad\n", localidad);
	check=PedirLocalidad(listaLocalidades, tamL, localidad);
	if(check==0){
		printf("No se ha encontrado ningun cliente en esa localidad\n\n");
	}
	else{
		for(int i=0; i<tamC; i++){
			//comp = strcmp(localidad,listaClientes[i].localidad);
			if(listaClientes[i].idLocalidad == check && listaClientes[i].libre == 0){
				flag=1;
				for(int j=0; j<tamP; j++){
					if(listaClientes[i].idCliente==listaPedidos[j].idCliente && listaPedidos[j].estado==0){
						cantPendientes++;
					}
				}
			}
		}
		if(flag == 1){
			pos = EncontrarLocalidadPorID(listaLocalidades, tamL, check);
			printf("En la localidad de %s hay %d pedidos pendientes\n\n",listaLocalidades[pos].localidad,cantPendientes);
		}
		else{
			printf("No se ha encontrado ningun cliente en esa localidad\n\n");
	}

	}


	return check;
}

int CantidadRecicladoPorCliente(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP){
	int check=0;
	float total;
	int cant=0;

	for(int i=0;i<tamC; i++ ){
		if(listaClientes[i].libre==0){
			check=1;
			cant++;
			for(int j=0; j<tamP; j++){
				if(listaClientes[i].idCliente == listaPedidos[j].idCliente && listaPedidos[j].estado==1){
					total = listaPedidos[i].kilosReciclados[0]+listaPedidos[i].kilosReciclados[1]+listaPedidos[i].kilosReciclados[2];
				}
			}
		}
	}

	total=CalcularPromedio(total,cant);

	printf("Cantidad de Kilos de Polopropileno Reciclado por Cliente: %.2f\n",total);

	return check;
}

int ClientesMasPedidosEstado(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP, int estado){
	int check= 0;
	int flag=0;
	int cant=0;
	int pos;
	int cantMayor;
	int idMayor;

	for(int i=0; i<tamC; i++){
		if(listaClientes[i].libre==0){
			for(int j=0; j<tamP; j++){
				if(listaPedidos[j].idCliente==listaClientes[i].idCliente && listaPedidos[j].estado==estado){
					cant++;
				}
			}
			if(flag==0 || cant>cantMayor){
				cantMayor=cant;
				idMayor = listaClientes[i].idCliente;
			}
		}

	}

	pos=EncontrarClientePorID(listaClientes, tamC, idMayor);

	printf("Empresa: %s\n", listaClientes[pos].empresa);

	return check;
}


int ClientesMasPedidosTotal(clientes* listaClientes, int tamC, pedidos* listaPedidos, int tamP){
	int check= 0;
	int flag=0;
	int cant=0;
	int pos;
	int cantMayor;
	int idMayor;

	for(int i=0; i<tamC; i++){
		if(listaClientes[i].libre==0){
			for(int j=0; j<tamP; j++){
				if(listaPedidos[j].idCliente==listaClientes[i].idCliente && listaPedidos[j].estado!=-1){
					cant++;
				}
			}
			if(flag==0 || cant>cantMayor){
				cantMayor=cant;
				idMayor = listaClientes[i].idCliente;
			}
		}

	}

	pos=EncontrarClientePorID(listaClientes, tamC, idMayor);

	printf("Empresa: %s\n", listaClientes[pos].empresa);

	return check;
}
