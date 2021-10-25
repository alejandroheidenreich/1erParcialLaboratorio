

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct
{
	int idLocalidad;
    char localidad[51];

} localidades;

int CrearNuevaLocalidad (localidades* lista, int tam, int id, char* localidad);

int PedirLocalidad (localidades* lista, int tam, char* localidad);

#endif /* LOCALIDAD_H_ */
