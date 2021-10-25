#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "clientes.h"
#include "localidad.h"

int IniciarLocalidades(localidades* lista, int len)
{
	int check=-1;

	for(int i=0; i<len; i++){
		check = 0;
		lista[i].idLocalidad = -1;
	}


	return check;
}

int EncontrarLocalidadPorID(localidades* lista, int tam, int id)
{
	int i;

	i = 0;
	for(i=0; i<tam; i++){
		if(lista[i].idLocalidad==id){
			break;
		}
	}
	if(i==tam){
		i=-1;
	}

    return i;
}

int CrearNuevaLocalidad (localidades* lista, int tam, int id, char* localidad){
	int check = 0;

	for(int i=0; i<tam; i++){
		if(lista[i].idLocalidad == -1){
			check = 1;
			lista[i].idLocalidad=id;
			strcpy(lista[i].localidad, localidad);
			break;
		}
	}

	return check;
}

int PedirLocalidad (localidades* lista, int tam, char* localidad){
	int check=0;
	int comp;

	IngresarCadena("Ingrese localidad de la Empresa: \n", localidad);

	for(int i=0; i<tam; i++){
		comp = strcmp(localidad,lista[i].localidad);
		if(comp == 0 && lista[i].idLocalidad != -1){
			check = lista[i].idLocalidad;
			break;
		}
	}


	return check;
}


