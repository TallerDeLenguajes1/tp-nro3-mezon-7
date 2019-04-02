#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};

void cargar_datos(struct TDatos * datospersonales);
void mostrar_datos(struct TDatos * datospersonales);

typedef struct TDatos {
	TRaza raza; //nota 1
	char * apellidonombre; //nota 2
	int edad; //entre 0 a 300
	double salud;//100
}tdatos;

typedef struct TCaracteristicas{
	int velocidad;// 1 a 10
	int destreza; //1 a 5
	int fuerza;//1 a 10
	int nivel; //1 a 10
	int armadura; //1 a 10
}caract;

typedef struct TPersonaje {
	TDatos * datospersonales;
	TCaracteristicas * caracteristicas;
}personaje;

void cargar_caracteristicas(caract * cp);
void mostrar_caracteristicas(caract * cp);

int main()
{
	srand(time(NULL));
	caract * cp= (caract *) malloc(sizeof(caract));
	cargar_caracteristicas(cp);
	mostrar_caracteristicas(cp);
	char Nombres[6][10]={"Terry", "John", "Jacob", "Lorenzo", "Roberto"};
	char Apellidos[6][10]={"Lopez","Messi", "Ronaldo", "Reus", "Tapp"};
	return 0;
}

void cargar_caracteristicas(caract * cp){
	printf("Cargando datos del personaje, por favor espere.\n");
	cp->velocidad=1 + rand() % (11-1);
	cp->destreza= 1 + rand() % (6-1);
	cp->fuerza= 1 + rand() % (11-1);
	cp->nivel= 1 + rand() % (11-1);
	cp->armadura= 1 + rand() % (11-1);
}

void mostrar_caracteristicas(caract * cp){
	printf("Velocidad: %d\n", cp->velocidad);
	printf("Destreza: %d\n", cp->destreza);
	printf("Fuerza: %d\n", cp->fuerza);
	printf("Nivel: %d\n", cp->nivel);
	printf("Armadura: %d\n", cp->armadura);
}