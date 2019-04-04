#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};

struct TDatos 
{
	TRaza raza ; //nota 1
	//int raza;
	char * ApellidoNombre; //nota 2
	int edad; //entre 0 a 300
	double salud;//100
};

struct TCaracteristicas
{
	int velocidad;// 1 a 10
	int destreza; //1 a 5
	int fuerza;//1 a 10
	int nivel; //1 a 10
	int armadura; //1 a 10
};

struct TPersonaje
{
	TDatos * DatosPersonales;
	TCaracteristicas * caracteristicas;
};

char Nombres[6][10]={"Terry", "John", "Jacob", "Lorenzo", "Roberto"};
char Apellidos[6][10]={"Lopez ","Messi ", "Ronaldo ", "Reus ", "Tapp "};
char Razas[6][10] = {"Orco", "Humano", "Mago", "Enano", "Elfo"};
void cargar_datos(struct TDatos * Character);
void mostrar_datos(struct TDatos * Character);
void cargar_caracteristicas(struct TCaracteristicas  * cp);
void mostrar_caracteristicas(struct TCaracteristicas * cp);

void main()
{
	
	srand(time(NULL));
	int cantidad;
	printf("Ingrese N Personajes a Cargar\n");
	scanf("%d", &cantidad); //5	
	TPersonaje * jugadores = (TPersonaje *) malloc (sizeof(TPersonaje) * cantidad);
	for(int i = 0; i < cantidad; i++)
	{
		
		jugadores[i].caracteristicas = (TCaracteristicas *) malloc(sizeof(TCaracteristicas));
		jugadores[i].DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
		cargar_caracteristicas(jugadores[i].caracteristicas);
		cargar_datos(jugadores[i].DatosPersonales);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("Ingrese Personaje a Mostrar\n\n");
		int num;
		scanf("%d", &num);
		mostrar_caracteristicas(jugadores[num].caracteristicas);
		mostrar_datos(jugadores[num].DatosPersonales);
	}
}

void cargar_datos(struct TDatos * Character)
{
	int random = rand() % 5;// PERSONAJE ALEATORIO
	int edadrand = rand() % 300;//EDAD DE 0 A 300
	switch (random)
	{
		case 0:{
			Character->raza = Orco;
			break;
		}
		case 1:{
			Character->raza = Humano;
			break;
		}
		case 2:{
			Character->raza = Mago;
			break;
		}
		case 3:{
			Character->raza = Enano;
			break;
		}
		case 4:{
			Character->raza = Elfo;
			break;
		}
	}
	Character->edad = edadrand;//CARGO LA EDAD
	Character->salud = 100;// SETEO LA SALUD A 100

	/*char nombre[32], apellido[32];
 	strcpy(nombre, Nombres[Character->raza]);//COPIO LA CADENA NOMBRE[RAZA] EN NOMBRE
 	strcpy(apellido, Apellidos[Character->raza]);//COPIO LA CADENA APELLIDO[RAZA] EN APELLIDO
 	char apenom[65];
 	strcat(apellido,nombre);// CONCATENO LA CADENA APELLIDO Y LA CADENA NOMBRE
 	strcpy(apenom, apellido);// ESTE PASO PODRIA SER INECESARIO YA QUE MI CADENA COPIADA ESTA EN LA CADENA APELLIDO*/
	char apenom[32];
	int tipo = Character->raza;
	strcpy(apenom, Apellidos[tipo]);
	strcat(apenom , Nombres[tipo]);
	puts(apenom);
	Character->ApellidoNombre = apenom;
}

void mostrar_datos(struct TDatos * Character)
{
	printf("Raza : %s\nApellido y Nombre: ", Razas[Character->raza]);//MUESTRO RAZA Y LA CADENA APELLIDONOMBRE
	puts(Character->ApellidoNombre);
	printf("Edad : %d \n", Character->edad);//MUESTRO EDAD
	printf("Salud : %2.f \n", Character->salud);// MUESTRO SALUD
}

void cargar_caracteristicas(struct TCaracteristicas * cp)
{
	printf("Cargando datos del personaje, por favor espere.\n");
	cp->velocidad=1 + rand() % (11-1);
	cp->destreza= 1 + rand() % (6-1);
	cp->fuerza= 1 + rand() % (11-1);
	cp->nivel= 1 + rand() % (11-1);
	cp->armadura= 1 + rand() % (11-1);
}

void mostrar_caracteristicas(struct TCaracteristicas * cp)
{
	printf("Velocidad: %d\n", cp->velocidad);
	printf("Destreza: %d\n", cp->destreza);
	printf("Fuerza: %d\n", cp->fuerza);
	printf("Nivel: %d\n", cp->nivel);
	printf("Armadura: %d\n", cp->armadura);
}