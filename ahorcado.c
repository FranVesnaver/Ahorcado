#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int menu;					//Opción de menú
int jugar;					//Opción de jugar
int vidas;					//Cantidad de vidas
int derrota;				//Para saber si ya perdimos
char palabra[30];			//Palabra a adivinar
char letra;					//Letra a tirar
char palArriesgar[20];		//Palabra para arriesgar
char letrasAdivinadas[30];	//Cadena para mostrar las letras adivinadas

const char* ElegirPalabra(int num);
int LetraCorrecta(char pal[20], char let);
void ActualizarPalabra(char pal[30], char let, char letrasAdivinadas[30]);

//Validación
void ValidarMenu(int *menu);
void ValidarJugar(int *jugar);

//Interfaz
void MostrarInterfaz(char palabra[30], char letrasAdivinadas[30], int vidas);
void continuar();
void menuPrincipal();
void menuJugar();

int main(){
	system("clear");
	srand(time(NULL));						//Para cambiar la semilla que genera numeros aleatorios y que estos no se repitan
	menu = 0;
	while(menu != 2){
		menuPrincipal();
		ValidarMenu(&menu);
		printf("\n");
		switch (menu){
			case 1: 
				system("clear");
				strcpy(palabra, ElegirPalabra((rand() % 20)+1));			//Se hace con mod 11 +1 para que devuelva un numero del 1 al 10
				/*printf("%s", palabra);*/		//Para facilitar la prueba se muestra la palabra a adivinar
				memset(letrasAdivinadas, '\0', sizeof(letrasAdivinadas));	//Llena la cadena letrasAdivinadas con '\0', para reiniciar las letras adivinadas
				vidas = 5;
				derrota = 0;						//cuando derrota está en 0, el juego está en curso, cuando está en 1 el usuario perdió y cuando está en 2 el usuario ganó
				while(derrota == 0){
					MostrarInterfaz(palabra, letrasAdivinadas, vidas);		//Se muestran las vidas y la palabra
					menuJugar();
					ValidarJugar(&jugar);
					switch(jugar){
						case 1:
							printf("Palabra: ");
							scanf("%19s", palArriesgar);					//Se pone "%19s" para evitar poner una palabra demasiado larga
							if(strcmp(palArriesgar, palabra) == 0)			//Si se adivinó la palabra, se gana 
								derrota = 2;								//y se cambia derrota a 2
							else											//Sino se pierde y
								derrota = 1;								//se cambia derrota a 1
							break;
						case 2:
							printf("Letra: ");
							scanf(" %c", &letra);
							if(isupper(letra))								//para evitar problemas, si la letra ingresada es
								letra = tolower(letra);						//mayúscula, la convertimos a minuscula
							if(LetraCorrecta(palabra, letra)){							//Si la letra ingresada es correcta
								printf("Letra Correcta!!\n");
								ActualizarPalabra(palabra, letra, letrasAdivinadas);	//Se actualizan las letras adivinadas
								if(strcmp(letrasAdivinadas, palabra) == 0)				//Si se completó la palabra
									derrota = 2;										//se gana y se cambia derrota a 2
							}else{														//Si la letra es incorrecta
								vidas--;												//Se resta una vida
								printf("\n¡Letra incorrecta, perdiste una vida!\n");
								if(vidas <= 0)											//Si se terminan las vidas se pierde
									derrota = 1;										//y derrota se cambia a 1
							}
							continuar();
							system("clear");
							break;
					}
				}
				if(derrota == 1){
					system("clear");
					printf("\n\n¡Perdiste! :(\n\n");
					printf("La palabra era %s\n\n", palabra);
					continuar();
				}else{
					system("clear");
					printf("\n\n¡Ganaste! :)\n\n");
					continuar();
				}
				break;
			case 2:
				printf("Saliendo...\n");
				break;
		}
	}
}

//Esta función devuelve una palabra segun el numero que se le pase, que va a ser aleatorio
const char* ElegirPalabra(int num){			//Definimos asi una función que devuelve una cadena
	switch (num){
		case 1:
			return "elefante";
		case 2:
			return "llanura";
		case 3:
			return "felicidad";
		case 4:
			return "plaza";
		case 5:
			return "amistad";
		case 6:
			return "bicicleta";
		case 7:
			return "restaurante";
		case 8:
			return "arcoiris";
		case 9:
			return "limpieza";
		case 10:
			return "viaje";
		case 12:
			return "perro";
		case 13:
			return "flauta";
		case 14:
			return "sacacorcho";
		case 15:
			return "manopla";
		case 16:
			return "canino";
		case 17:
			return "mascotas";
		case 18:
			return "pendorcho";
		case 19:
			return "heladera";
		case 20:
			return "carnaval";
		default:
	}
}

//devuelve 1 si la letra que se le pasa está en la palabra
int LetraCorrecta(char pal[20], char let){
	int i;
	for(i=0; i < strlen(pal); i++){
		if(pal[i] == let)
			return 1;
	}
	return 0;
}

//se encarga de mostrar las vidas restantes y las letras adivinadas
void MostrarInterfaz(char palabra[30], char letrasAdivinadas[30], int vidas){
	int i;
	int longitud;
	longitud = strlen(palabra);
	printf("\n");
	printf("Vidas restantes: %d", vidas);
	printf("\n");
	printf("Palabra: ");
	for(i=0; i < longitud; i++){
		if(letrasAdivinadas[i] == '\0'){				//letrasAdivinadas se va rellenando a medida que se adivinan letras
			printf("_");								//por lo que tiene un '\0' donde hay una letra sin adivinar
		}else{											//Entonces, cuando detecta un '\0' imprime un guion bajo 
			printf("%c", letrasAdivinadas[i]);			//de lo contrario imprime una letra
		}
	}
}

//va rellenando letrasAdivinadas, que lleva las letras adivinadas hasta el momento
void ActualizarPalabra(char pal[30], char let, char letrasAdivinadas[30]){
	int i;
	int longitud;
	longitud = strlen(pal);
	for(i=0; i < longitud; i++){
		if(pal[i] == let){								//Recorre cada letra de la palabra a adivinar, si la letra actual es igual a
			letrasAdivinadas[i] = let;					//la letra que se le pasa, es decir la que tira el usuario, entonces
		}												//se ubica en la misma posición pero en letrasAdivinadas
	}
}

//valida el ingreso de una opcion en el menu
void ValidarMenu(int *menu){
	do{
		scanf("%d", menu);
		if((*menu != 1)&&(*menu != 2)){
			printf("Ingrese una opción válida...\n");
			printf("->");
		}
	}while((*menu != 1)&&(*menu != 2));
}

//valida el ingreso de una opcion en el menu jugar
void ValidarJugar(int *jugar){
	do{
		scanf("%d", jugar);
		if((*jugar != 1)&&(*jugar != 2)){
			printf("Ingrese una opción válida...\n");
			printf("->");
		}
	}while((*jugar != 1)&&(*jugar != 2));
}

//Imprime un cartel y no avanza hasta que el usuario presione enter
void continuar(){
	printf("Presiona 'Enter' para continuar");
	getchar();		//limpia el buffer 
	getchar();		//Espera a que el usuario presione enter
}

void menuPrincipal(){
	system("clear");
	printf("\n");
	printf("/*||AHORCADO||*\\");
	printf("\n");
	printf("1 - Jugar");
	printf("\n");
	printf("2 - Salir");
	printf("\n");
	printf("-> ");
}

void menuJugar(){
	printf("\n\n");
	printf("1- Arriesgar palabra\n");
	printf("2- Tirar letra\n");
	printf("->");
}