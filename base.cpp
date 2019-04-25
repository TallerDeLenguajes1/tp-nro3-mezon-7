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

char Nombres[6][10]={"Terry ", "John ", "Jacob ", "Lorenzo ", "Roberto "};
char Apellidos[6][10]={"Lopez ","Messi ", "Ronaldo ", "Reus ", "Tapp "};
char Razas[6][10] = {"Orco", "Humano", "Mago", "Enano", "Elfo"};
void cargar_datos(struct TDatos * Character);
void mostrar_datos(struct TDatos * Character);
void cargar_caracteristicas(struct TCaracteristicas  * cp);
void mostrar_caracteristicas(struct TCaracteristicas * cp);
void actualizar_salud(struct TDatos * Character, int damage);
//int personaje_ataque(struct TCaracteristicas * cp, int efectividad_disparo);
//int personaje_recibe(struct TCaracteristicas * cp);
int salud_actual(struct TDatos * Character);
void crearpersonaje(struct TPersonaje ** Persona, int cantidad);
int Actualizar_datos(struct TCaracteristicas * ataca, struct TCaracteristicas * recibe, int efectividad_disparo);

#define ROUNDS 1
void main()
{
	
	srand(time(NULL));
	int i, cantidad;
	printf("Ingrese Personajes a Cargar\n");
	scanf("%d", &cantidad); //5	
	TPersonaje * jugadores;
	crearpersonaje(&jugadores, cantidad);
	char apenom[50];
	for(i = 1; i <= cantidad; i++)
	{
		
		jugadores[i].caracteristicas = (TCaracteristicas *) malloc(sizeof(TCaracteristicas));
		jugadores[i].DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
		cargar_caracteristicas(jugadores[i].caracteristicas);  
		cargar_datos(jugadores[i].DatosPersonales);
		int tipo = (jugadores[i].DatosPersonales)->raza;
		strcpy(apenom, Apellidos[tipo]);
		strcat(apenom , Nombres[tipo]);
		jugadores[i].DatosPersonales->ApellidoNombre = (char *) malloc(sizeof(char)*(strlen(apenom)));
	    jugadores[i].DatosPersonales->ApellidoNombre = strdup(apenom);
	  
	}
	int num, num_per1, num_per2;
	bool PERSONAJE1 = false, PERSONAJE2 = false;
	while(!PERSONAJE2)
	{
		printf("Elegi tu  %s personaje\n", PERSONAJE1 ? "segundo" : "primer");
		scanf("%d", &num);
		if(num >= 0 && num <= cantidad)
		{
			
			if(PERSONAJE1 && !PERSONAJE2)
			{
				if(num != num_per1)
				{
					num_per2 = num;
					printf("----PERSONAJE NUMERO 2----\n        ---%d---\n",num_per2);
					PERSONAJE2 = true;
				}
				else
				{
					printf("----PERSONAJE YA ELEGIDO ----\n   ---INGRESE NUEVAMENTE---\n\n");
				}
			}
			if(!PERSONAJE1)
			{
				num_per1 = num;
				printf("----PERSONAJE NUMERO 1----\n        ---%d---\n",num_per1);
				PERSONAJE1 = true;
			}
		}
		else
		{
			printf("----PERSONAJE INEXISTENTE ----\n   ---INGRESE NUEVAMENTE---\n\n");
		}
	}
	printf("\n\n----PERSONAJE NUMERO 1----\n        ---%d---\n",num_per1);
	mostrar_caracteristicas(jugadores[num_per1].caracteristicas);
	mostrar_datos(jugadores[num_per1].DatosPersonales);
	printf("\n----PERSONAJE NUMERO 2----\n        ---%d---\n",num_per2);
	mostrar_caracteristicas(jugadores[num_per2].caracteristicas);
	mostrar_datos(jugadores[num_per2].DatosPersonales);
	int num_round = 1, efectividad_disparo, damage, damage_total[2] = {0,0};
	bool ataca_personaje1 = true;
	for(int j = 0; j < ROUNDS; j++)
	{
		printf("----A PELEAR ----\n   ---ROUND %d---\n\n",num_round);

		if(ataca_personaje1)
		{
			for(i = 0; i < 3; i++)
			{
				efectividad_disparo = 1 + rand() % 100;
				damage = Actualizar_datos(jugadores[num_per1].caracteristicas, jugadores[num_per2].caracteristicas, efectividad_disparo);
				actualizar_salud(jugadores[num_per2].DatosPersonales, damage);
				damage_total[0] += damage;
			}
			ataca_personaje1 = false;
		}
		else
		{
			for(i = 0; i < 3; i++)
			{
				efectividad_disparo = 1 + rand() % 100;
				damage = Actualizar_datos(jugadores[num_per2].caracteristicas, jugadores[num_per1].caracteristicas, efectividad_disparo);
				actualizar_salud(jugadores[num_per1].DatosPersonales, damage);
				damage_total[1] += damage;
			}
		}
		num_round++;
		printf("----SALUD PERSONAJE 1 ----      ----SALUD PERSONAJE 2 ----\n   --- %d---             --- %d---\n\n",salud_actual(jugadores[num_per1].DatosPersonales),salud_actual(jugadores[num_per2].DatosPersonales));
	}

	if(damage_total[0] == damage_total[1])
	{
		printf("---------EMPATE-------\n");
	}
	else if(damage_total[0]>damage_total[1])printf("---------GANO PERSONAJE 1------DAMAGE CAUSADO %4d ------\n",damage_total[0]);
	else if(damage_total[1]>damage_total[0])printf("---------GANO PERSONAJE 2------DAMAGE CAUSADO %4d ------\n",damage_total[1]);
		
}

int Actualizar_datos(struct TCaracteristicas * ataca, struct TCaracteristicas * recibe, int efectividad_disparo)
{
	int max_damage = 50000;
	int poder_disparo =(ataca->destreza*ataca->fuerza*ataca->nivel);
	int valor_ataque = (poder_disparo*efectividad_disparo);
	int armadura = (recibe->armadura*recibe->velocidad);
	int damage_total = (((valor_ataque*efectividad_disparo)-armadura)/max_damage) * 100;
	return damage_total;
}

void crearpersonaje(struct TPersonaje ** Persona, int cantidad)
{
	*Persona = (TPersonaje*) malloc(sizeof(TPersonaje) * cantidad);
}
int salud_actual(struct TDatos * Character)
{
	return Character->salud;
}

void actualizar_salud(struct TDatos * Character, int damage)
{
	int aux;
	aux = Character->salud;
	
	if( aux <= 0)
		Character->salud = 0;
	else
		Character->salud = aux - damage;
}

/*int personaje_ataque(struct TCaracteristicas * cp, int efectividad_disparo)
{
	int poder_disparo = cp->destreza*cp->fuerza*cp->nivel;
	int valor_ataque = poder_disparo*efectividad_disparo;
	return valor_ataque;
}
int personaje_recibe(struct TCaracteristicas * cp)
{
	return (cp->armadura*cp->velocidad);
}*/
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

}

void mostrar_datos(struct TDatos * Character)
{
	printf("\t Raza : %s\nApeNombre:  ", Razas[Character->raza]);//MUESTRO RAZA Y LA CADENA APELLIDONOMBRE
	puts(Character->ApellidoNombre);
	printf("\t Edad : %d \n", Character->edad);//MUESTRO EDAD
	printf("\t Salud : %2.f \n", Character->salud);// MUESTRO SALUD
}

void cargar_caracteristicas(struct TCaracteristicas * cp)
{
	cp->velocidad = 1 + rand() % 10;
	cp->destreza = 1 + rand() % 5;
	cp->fuerza = 1 + rand() % 10;
	cp->nivel = 1 + rand() % 10;
	cp->armadura = 1 + rand() % 10;
}

void mostrar_caracteristicas(struct TCaracteristicas * cp)
{
	printf("\t Velocidad: %d\n", cp->velocidad);
	printf("\t Destreza: %d\n", cp->destreza);
	printf("\t Fuerza: %d\n", cp->fuerza);
	printf("\t Nivel: %d\n", cp->nivel);
	printf("\t Armadura: %d\n", cp->armadura);
}