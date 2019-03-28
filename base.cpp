#include <stdio.h>
#include <stdlib.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};

void cargar_datos(struct TDatos * Character);
void mostrar_datos(struct TDatos * Character);

void cargar_caracteristicas(struct TCaracteristicas * Character);
void mostrar_caracteristicas(struct TCaracteristicas * Character);


typedef struct TDatos {
	TRaza raza; //nota 1
	Char * apellidonombre; //nota 2
	int edad; //entre 0 a 300
	double salud://100
}tdatos;

typedef struct TCaracteristicas{
	int velocidad;// 1 a 10
	int destreza; //1 a 5
	int fuerza;//1 a 10
	int aivel; //1 a 10
	int armadura; //1 a 10
}caract;

typedef struct TPersonaje {
	TDatos * datospersonales;
	TCaracteristicas * caracteristicas;
}personaje;


int main()
{
	char Nombres[6][10]={"Terry", "John", "Jacob", "Lorenzo", "Roberto"};
	char Apellidos[6][10]={"Lopez","Messi", "Ronaldo", "Reus", "Tapp"};
	return 0;
}
