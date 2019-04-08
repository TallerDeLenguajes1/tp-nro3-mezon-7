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
int estadisticaspelea(caract * cp, tdatos * Character);



char Nombres[6][10]={"Terry", "John", "Jacob", "Lorenzo", "Roberto"};
char Apellidos[6][10]={"Lopez ","Messi ", "Ronaldo ", "Reus ", "Tapp "};
char Razas[6][10] = {"Orco", "Humano", "Mago", "Enano", "Elfo"};

void main()
{
	int cant;
	printf("Ingrese la cantidad de personajes para cargar:\n");
	scanf("%d", &cant); //5
	srand(time(NULL));
/*	struct TDatos * Character= (struct TDatos *) malloc(sizeof(struct TDatos));
	caract * cp= (caract *) malloc(sizeof(caract));
	cargar_caracteristicas(cp);
	mostrar_caracteristicas(cp);
	cargar_datos(Character);
	mostrar_datos(Character);*/
	TPersonaje * jugadores= (TPersonaje *) malloc(sizeof(TPersonaje));

	for(int i = 0; i < cant; i++)
	{
		
		jugadores[i].caracteristicas = (TCaracteristicas *) malloc(sizeof(TCaracteristicas));
		jugadores[i].DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
		cargar_caracteristicas(jugadores[i].caracteristicas);
		cargar_datos(jugadores[i].DatosPersonales);
		mostrar_datos(jugadores[i].DatosPersonales);
	}

		printf("Seleccione el primer personaje para pelear:\n");
		int num, salud2, salud1;
		scanf("%d", &num);
		mostrar_caracteristicas(jugadores[num].caracteristicas);
		salud2=estadisticaspelea(jugadores[num].caracteristicas, jugadores[num].DatosPersonales);
		printf("Seleccione el segundo personaje para pelear:\n");
		int num2;
		scanf("%d", &num2);
		mostrar_caracteristicas(jugadores[num2].caracteristicas);
		salud1=estadisticaspelea(jugadores[num2].caracteristicas, jugadores[num2].DatosPersonales);
		if (salud1<salud2)
		{
			printf("El segundo personaje seleccionado gano la pelea.%s\n", jugadores[num2].DatosPersonales->ApellidoNombre);
		}

		if (salud1>salud2)
		{
			printf("El primer personaje seleccionado gano la pelea.%s\n", jugadores[num].DatosPersonales->ApellidoNombre);
		}

		if (salud1==salud2){
			printf("Empate");
		}
}
void cargar_datos(struct TDatos * Character)
{
	int random = rand() % 5;// PERSONAJE ALEATORIO
	int random2 = rand() % 5;// NOMBRE ALEATORIO
	int random3 = rand() % 5;// APELLIDO ALEATORIO
	int edadrand = rand() % 300;//EDAD DE 0 A 300
	Character->edad = edadrand;//CARGO LA EDAD
	switch(random){
		case 0:Character->raza=Orco;break;
		case 1:Character->raza=Humano;break;
		case 2:Character->raza=Mago;break;
		case 3:Character->raza=Enano;break;
		case 4:Character->raza=Elfo;break;
	}//CARGO LA RAZA DEL PERSONAJE ALEATORIO
	Character->salud = 100;// SETEO LA SALUD A 100
	char nombre[32], apellido[32];
 	strcpy(nombre, Nombres[random2]);//COPIO LA CADENA NOMBRE[RAZA] EN NOMBRE
 	strcpy(apellido, Apellidos[random3]);//COPIO LA CADENA APELLIDO[RAZA] EN APELLIDO
 	char apenom[65];
 	strcat(apellido,nombre);// CONCATENO LA CADENA APELLIDO Y LA CADENA NOMBRE
 	strcpy(apenom, apellido);// ESTE PASO PODRIA SER INNECESARIO YA QUE MI CADENA COPIADA ESTA EN LA CADENA APELLIDO
 	puts(apenom);
 	Character->ApellidoNombre = apenom;
}

void mostrar_datos(struct TDatos * Character)
{
	printf("Raza : %s\nApellido y Nombre: ", Razas[Character->raza]);//MUESTRO RAZA Y LA CADENA APELLIDONOMBRE
	printf("%s\n", Character->ApellidoNombre);
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

int estadisticaspelea(caract * cp, tdatos * Character){
	int ed= 1 + rand() % 100;
	int pd= (cp->velocidad) * (cp->destreza) * (cp->nivel);
	int va= pd * ed;
	int pdef= cp->armadura * cp->velocidad;
	int mdp=50000;
	int damage=(((va * ed) - pdef) / mdp) * 100;
	int dmtotal=damage*3;
	int saludtotal= Character->salud - dmtotal;
	printf("Poder de Disparo:%d\n", pd);
	printf("Efectividad de Disparo:%d\n", ed);
	printf("Valor de Ataque:%d\n", va);
	printf("Poder de Defensa:%d\n", pdef);
	printf("Ataque provocado(por ronda):%d\n", damage);

	return saludtotal;
}