#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum TRaza{Orco, Humano, Mago, Enano, Elfo};

void cargar_datos(struct TDatos * datospersonales);
void mostrar_datos(struct TDatos * datospersonales);


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
	int nivel; //1 a 10
	int armadura; //1 a 10
}caract;

typedef struct TPersonaje 
{
	TDatos * DatosPersonales;
	TCaracteristicas * caracteristicas;
}personaje;

void cargar_caracteristicas(caract * cp);
void mostrar_caracteristicas(caract * cp);



char Nombres[6][10]={"Terry", "John", "Jacob", "Lorenzo", "Roberto"};
char Apellidos[6][10]={"Lopez ","Messi ", "Ronaldo ", "Reus ", "Tapp "};
char Razas[6][10] = {"Orco", "Humano", "Mago", "Enano", "Elfo"};

void main()
{
	srand(time(NULL));
	struct TDatos * Character= (struct TDatos *) malloc(sizeof(struct TDatos));
	caract * cp= (caract *) malloc(sizeof(caract));
	cargar_caracteristicas(cp);
	mostrar_caracteristicas(cp);
	cargar_datos(Character);
	mostrar_datos(Character);	
}
void cargar_datos(struct TDatos * Character)
{
	int random = rand() % 5;// PERSONAJE ALEATORIO
	int edadrand = rand() % 300;//EDAD DE 0 A 300
	Character->edad = edadrand;//CARGO LA EDAD
	Character->raza = random;//CARGO LA RAZA DEL PERSONAJE ALEATORIO
	Character->salud = 100;// SETEO LA SALUD A 100
	char nombre[32], apellido[32];
 	strcpy(nombre, Nombres[random]);//COPIO LA CADENA NOMBRE[RAZA] EN NOMBRE
 	strcpy(apellido, Apellidos[random]);//COPIO LA CADENA APELLIDO[RAZA] EN APELLIDO
 	char apenom[65];
 	strcat(apellido,nombre);// CONCATENO LA CADENA APELLIDO Y LA CADENA NOMBRE
 	strcpy(apenom, apellido);// ESTE PASO PODRIA SER INECESARIO YA QUE MI CADENA COPIADA ESTA EN LA CADENA APELLIDO
	Character->ApellidoNombre = apenom;
}

void mostrar_datos(struct TDatos * Character)
{
	printf("Raza : %s\nApellido y Nombre: ", Razas[Character->raza]);//MUESTRO RAZA Y LA CADENA APELLIDONOMBRE
	puts(Character->ApellidoNombre);
	printf("Edad : %d \n", Character->edad);//MUESTRO EDAD
	printf("Salud : %2.f \n", Character->salud);// MUESTRO SALUD
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