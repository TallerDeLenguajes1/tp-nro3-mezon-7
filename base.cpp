#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};
void cargar_datos(struct TDatos * Character);
//void mostrar_datos(struct TDatos * Character);

//void cargar_caracteristicas(struct TCaracteristicas * Character);
//void mostrar_caracteristicas(struct TCaracteristicas * Character);


typedef struct TDatos {
	TRaza raza; //nota 1
	char * ApellidoNombre; //nota 2
	int edad; //entre 0 a 300
	double salud;//100
}tdatos;

typedef struct TCaracteristicas
{
	int velocidad;// 1 a 10
	int destreza; //1 a 5
	int fuerza;//1 a 10
	int aivel; //1 a 10
	int armadura; //1 a 10
}caract;

typedef struct TPersonaje 
{
	TDatos * DatosPersonales;
	TCaracteristicas * caracteristicas;
}personaje;

char Nombres[6][10]={"Terry", "John", "Jacob", "Lorenzo", "Roberto"};
char Apellidos[6][10]={"Lopez","Messi", "Ronaldo", "Reus", "Tapp"};
char Razas[6][10] = {"Orco", "Humano", "Mago", "Enano", "Elfo"};

void main()
{
	srand(time(NULL));
	
	struct TDatos * Character= (struct TDatos *) malloc(sizeof(struct TDatos));
	cargar_datos(Character);
	
}
void cargar_datos(struct TDatos * Character)
{
	int random = rand() % 5;
	
	Character->raza = random;
	strcpy(Nombres[random])
	Character->ApellidoNombre = Nombres[random];
	printf("%s\n", Razas[Character->raza]);
	printf("%s\n", Character->ApellidoNombre);

}
//void mostrar_datos(struct TDatos * Character)
