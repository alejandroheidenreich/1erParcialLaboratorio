#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "clientes.h"
#include "localidad.h"

int IniciarClientes(clientes* lista, int len)
{
	int check=-1;

	if(!(lista == NULL || len>100 || len<1)){
		check = 0;
		for(int i=0; i<len; i++){
			lista[i].libre = 1;
		}
	}

	return check;
}

clientes CrearCliente(int id){

	clientes unCliente;

	if(id>0){

		unCliente.idCliente = id;
		IngresarCadena("Ingrese Nombre de la Empresa: \n", unCliente.empresa);
		printf("\n");
		PedirValidoNumeroCUIT("Ingrese CUIT de la Empresa:\n", "ERROR debe tener 11 digitos (sin espacios y guiones)- ", unCliente.cuit);
		printf("\n");
		IngresarCadena("Ingrese direccion de la Empresa: \n", unCliente.direccion);
		printf("\n");
		//IngresarCadena("Ingrese localidad de la Empresa: \n", unCliente.localidad);
		printf("\n");


	}

	return unCliente;
}

void ImprimirClientes(clientes* listaClientes, int tamC, localidades* listaLocalidades, int tamL){

	printf("==========================================================================================\n");
	printf("| ID |		EMPRESA	   |	 CUIT	 |   	DIRECCION	   | 	LOCALIDAD	 |\n");
	printf("==========================================================================================\n");
	for(int i=0; i<tamC-1; i++){
		if(listaClientes[i].libre==0){
		printf("|%4d| %20s| %13s| %-24s| %-20s|\n", listaClientes[i].idCliente,listaClientes[i].empresa,listaClientes[i].cuit,listaClientes[i].direccion,listaClientes[i].localidad);
		printf("==========================================================================================\n");
		}
	}

}

int AltaClientes(clientes* lista, int tam, int id, char* empresa, char* cuit, char* direccion, int localidad){
	int check=0;

	if(lista != NULL && (tam<100 || tam>1)){
			for(int i=0; i<tam; i++){
				if(lista[i].libre==1){
					check=1;
					lista[i].idCliente = id;
					strcpy(lista[i].empresa, empresa);
					strcpy(lista[i].cuit, cuit);
					strcpy(lista[i].direccion, direccion);
					lista[i].idLocalidad=localidad;
					lista[i].libre = 0;
					break;
				}
			}
		}

	return check;
}

int VerificarClienteCargado(clientes* lista, int tam){
	int check=0;

	for (int i=0; 1<tam; i++){
		if(lista[i].libre == 1){
			check=1;
			break;
		}
	}

	return check;
}

int EncontrarClientePorID(clientes* lista, int tam, int id)
{
	int i;

		if(lista != NULL && (tam<100 || tam>1)){
			i = 0;
			for(i=0; i<tam; i++){
				if(lista[i].idCliente==id && lista[i].libre==0){
					break;
				}
			}
			if(i==tam){
				i=-1;
			}
		}

    return i;
}

int ModClientes(clientes* listaClientes, int tam, localidades* listaLocalidades, int tamL){
	int check=-2;
	int id;
	int pos;
	int opcion;
	ImprimirClientes(listaClientes,tam, listaLocalidades, tamL);
	id=PedirValidoNumeroEntero("Ingrese ID del cliente a modificar\n", "ID INVALIDO - ");

	pos = EncontrarClientePorID(listaClientes, tam, id);

	if(pos  == -1 || listaClientes[pos].libre==1 ){
		printf("ERROR - Cliente no encontrado\n");
	}
	else{
		do{
		clear();
		printf("==================================\n");
		printf("||    Modificacion de Cliente   ||\n");
		printf("==================================\n\n");
		printf("\n\tQue dato desea modificar?\n");
		printf("\t1- Direccion\n\t2- Localidad\n\t3- ATRAS\n\n");
		opcion = IngresarEntero("\n\tIngrese una opcion: ",1,3);
		switch(opcion){
			case 1:
				IngresarCadena("Modifique Direccion del Cliente: ", listaClientes[pos].direccion);
				check=-1;
				break;

			case 2:
				//PedirLocalidad (localidades* lista, int tam, char* localidad)
				//IngresarCadena("Modifique Localidad del Cliente: ", lista[pos].localidad);
				check=pos;
				break;

		}
		}while(opcion!=3);
	}

	return check;
}

int BajaCliente(clientes* lista, int tam)
{
	int check = 0;
	int id;
	int pos;

	id=PedirValidoNumeroEntero("Ingrese ID del cliente a dar de BAJA", "ID INVALIDO - ");

	pos = EncontrarClientePorID(lista, tam, id);

	if(pos  == -1 || lista[pos].libre==1 ){
		printf("ERROR - Cliente no encontrado\n");
	}
	else{
		check = 1;
		lista[pos].libre=1;
	}

	return check;
}

int ModLocalidadCliente(clientes* lista, int tam, int posCliente, int idLocalidad)
{
	int check=0;

	lista[posCliente].idLocalidad = idLocalidad;

	return check;
}
