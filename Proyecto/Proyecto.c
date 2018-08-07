#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
/*Colores*/
#define JUGADOR_1 "\x1b[41m"
#define JUGADOR_2 "\x1b[46m"
#define DEFAULT_COLOR "\x1b[0m"
#define CASILLA_VACIA "\x1b[47m"
//programa
void
mostrar_tablero (int tablero[8][8]){
	
	int i, j;
	
	printf ("\n");
	for (i=0; i<8; i++){
	printf ("\t \t \t \t \t");
	// esta funcion imprime colores segun los valores que tiene la matriz
	// 0 es una casilla vacia, 1 son fichas del rojas y 2 son fichas cyan
		for (j=0; j<8; j++){
			if (tablero[i][j] == 1){
				printf ("%s  %s", JUGADOR_1, DEFAULT_COLOR);
			}
			else if (tablero[i][j] == 2){
				printf ("%s  %s", JUGADOR_2, DEFAULT_COLOR);
			}
			else{
				printf ("%s  %s", CASILLA_VACIA, DEFAULT_COLOR);
			}
			printf ("   ");
		}
		
		printf ("\n");
		printf ("\n");
	}
}

void
revision (int jugadas, int registro[64], int jugador){
	system ("clear");
	char pausa;
	//esta funcion recibe el numero total de jugadas, el jugador inicial y el registro de jugadas
	//partira diciendo que el jugador que partio lanzo una ficha en x columna
	//y despues el jugador 2, asi hasta que hayan hecho la cantidad total de jugadas
	for (int i = 1; i<=jugadas; i++){
		printf ("En la jugada %d, el jugador %d soltó una ficha en la columna %d\n", i, jugador, registro[i-1]);
		scanf ("%c", &pausa);
		if (jugador == 1){
			jugador = 2;
		}
		else{
			jugador = 1;
		}
	}
	
}

void
pantalla_final (int ganador, int registro[64], int jugadas, int inicial){
	//aqui se mostrara al jugador que haya alineado 4 fichas
	int seleccion;
	if (ganador != 0){
		printf ("\t\t\t\t\t\t********************\n");
		printf ("\t\t\t\t\t\t*GANO EL JUGADOR %d *\n", ganador);
		printf ("\t\t\t\t\t\t********************\n");
		sleep (1);
	}
	//en caso de no ser ninguno y que el juego termino por hacer 64 jugadas (llenar el tablero) y nadie gano, se dice que empataron
	else{
		printf ("\t\t\t\t\t\t********************\n");
		printf ("\t\t\t\t\t\t*   ES UN EMPATE   *\n");
		printf ("\t\t\t\t\t\t********************\n");
		sleep (1);
	}
	printf ("\t¿Que desea hacer?\n");
	printf ("\n");
	printf ("1.- Revisar partida\n");
	printf ("2.- Menu Principal\n");
	printf ("3.- Salir\n");
	scanf ("%d", &seleccion);
	// se muestra un menu de opciones y se puede escoger si revisar, volver al menu o terminar el juego
	switch (seleccion){
		case 1:
			revision (jugadas, registro, inicial);
			break;
		case 2:
			system ("clear");
			main();
			break;
		case 3:
			printf ("***Gracias por jugar***");
			system ("exit");
			break;
		default:
			system ("exit");
			break;
		}
}

int 
determinar_partida (){
	// se determina que jugador parte, generando un numero al azar, 1 o 2
	int partida;
	partida = (rand ()%2) + 1;
	
	return partida;
}

int 
verificar_diagonal_2(int tablero[8][8]){
	int i, j,start;
	int alineadas = 1;
	int trigger = 0;
	// se verifica si hay 4 fichas en diagonal del mismo color, de derecha a izquierda
	for (start = 3; start<8; start++){
		i = start;
		j = 7;
		for (int k = 0; k<start; k++){
			if (tablero[i][j] != 0){
				if (alineadas == 4){
					trigger = tablero[i][j];
				}
				else if (tablero[i][j] == tablero[i-1][j-1]){
					alineadas++;
				}
				else{
					alineadas = 1;
				}
				i--;
				j--;
			}
		}
	}
	for (start = 6; start>2; start--){
		i = 7;
		j = start;
		for (int k = 7; k>0; k--){
			if (tablero[i][j] != 0){
				if (alineadas == 4){
					trigger = tablero[i][j];
				}
				else if (tablero[i][j] == tablero[i-1][j-1]){
					alineadas++;
				}
				else{
					alineadas = 1;
				}
				i--;
				j--;
			}
		}
	}
	return trigger;
}	

int //AME ESTE CODIGO
verificar_diagonal_1 (int tablero[8][8]){
	int i, j,start;
	int alineadas = 1;
	int trigger = 0;
	// se verifica si hay 4 fichas en diagonal del mismo color, de izquierda a derecha
	for (start = 3; start<8; start++){
		i = start;
		j = 0;
		for (int k = 0; k<start; k++){
			if (tablero[i][j] != 0){
				if (alineadas == 4){
					trigger = tablero[i][j];
				}
				else if (tablero[i][j] == tablero[i-1][j+1]){
					alineadas++;
				}
				else{
					alineadas = 1;
				}
				i--;
				j++;
			}
		}
	}
	for (start = 1; start<5; start++){
		i = 7;
		j = start;
		for (int k = 7; k>start; k--){
			if (tablero[i][j] != 0){
				if (alineadas == 4){
					trigger = tablero[i][j];
				}
				else if (tablero[i][j] == tablero[i-1][j+1]){
					alineadas++;
				}
				else{
					alineadas = 1;
				}
				i--;
				j++;
			}
		}
	}
	return trigger;
}

int 
verificar_vertical (int tablero[8][8]){
	
	//se verifica si hay 4 fichas en vertical, de abajo a arriba
	int i,j;
	int alineaciones = 1;
	int trigger = 0;
	for (i=0; i<=7;i++){
		for (j=7;j>0;j--){
			if (tablero[j][i] != 0){
				if (tablero[j][i] == tablero[j-1][i]){
					alineaciones++;
					if (alineaciones == 4){
					int ganador = tablero[j][i];
					trigger = ganador;
					}
				}
				
				else{
					alineaciones = 1;
				}
			}
		}
	}
	return trigger;		
}

int 
verificar_horizontal (int tablero[8][8]){
	
	//se verifica si hay 4 fichas del mismo color en horizontal, de izquierda a derecha
	int i,j;
	int alineaciones = 1;
	int trigger = 0;
	for (i=7; i>=0;i--){
		for (j=0;j<7;j++){
			if (tablero[i][j] != 0){
				if (tablero[i][j] == tablero[i][j+1]){
					alineaciones++;
				}
				else{
					alineaciones = 1;
				}
			}
			if (alineaciones == 4){
					int ganador = tablero[i][j];
					trigger = ganador;
			}
		}
	}
	return trigger;		
}

int
i_artificial (int tablero[8][8], int registro[64], int jugadas){
	int jugada;
	//si no se ha hecho ninguna jugada, lanzara una ficha a cualquier columna
	if (jugadas==0){
	jugada = (rand ()%8)+1;
		}
	// en cambio, si ya se ha hecho una jugada, lanzara una ficha sobre o junto a la de la jugada anterior
	else{
		jugada = registro[jugadas-1] + ((rand ()%2) - (rand ()%2));
		if (jugada == 0){
			jugada = 1;
		}
		else if (jugada == 9){
			jugada = 8;
		}
	}
	return jugada;
}
	
int
verificar (int tablero[8][8]){
	// se llama a 4 verificadores diferentes segun la direccion
	int victoria = 0;
	int horizontal, vertical, diagonal_1, diagonal_2;
	
	horizontal = verificar_horizontal(tablero);
	vertical = verificar_vertical(tablero);
	diagonal_1 = verificar_diagonal_1(tablero);
	diagonal_2 = verificar_diagonal_2(tablero);
	// en caso que alguno devuelva que hay 4 fichas de algun jugador, se devuelve el termino
	if (horizontal == 1 || vertical == 1 || diagonal_1 == 1 || diagonal_2 == 1){
		victoria = 1;
	}
	else if (horizontal == 2 || vertical == 2 || diagonal_1 == 2 || diagonal_2 == 2){
		victoria = 2;
	}
	return victoria;
}	

void
registrar_jugada(int jugadas, int registro[64], int jugada){
	
	// simplemente se registra que en la jugada n, se lanzo una ficha a la columna x
	registro[jugadas-1] = jugada;
}

void
playmaker (int tablero[8][8], int jugador, int ia, int jugadas, int registro[64]){
	
	int jugada;
	int fichalanzada = 0;
	int fila = 7;
	// se determina si le toca a un jugador humano o a la IA
		if (jugador == 1){
			printf ("A que columa lanza la ficha?");
			scanf ("%d", &jugada);
			}
		else if (ia == 1 && jugador == 2){
			jugada = i_artificial(tablero, registro, jugadas);
			}
		else{
			printf ("A que columa lanza la ficha?");
			scanf ("%d", &jugada);
			}
			
	//especial enfasis en los "jugada-1" en la siguiente seccion
	// primero se verifica que sea una jugada valida
	if (jugada < 1 || jugada > 8 || tablero[0][jugada-1] != 0){
		printf ("Jugada no valida\n");
		playmaker(tablero, jugador, ia, jugadas, registro);
	}
	//despues se coloca la ficha lo mas abajo posible, siendo el limite el fondo u otra ficha
	else{
		while (fichalanzada == 0){
			if (tablero[fila][jugada-1] == 0){
				tablero[fila][jugada-1] = jugador;
				fichalanzada = 1; 
			}
			fila--;
		}
		system ("clear");
		mostrar_tablero (tablero);
		// se notifica que el jugador lanzo una ficha a x columna
	printf ("El jugador %d lanza una ficha en la columna %d\n", jugador, jugada);
	}
	jugadas++;
	registrar_jugada(jugadas, registro, jugada);
}
		
void 
generar_tablero_inicial(int tablero[8][8]){
	
	//se llena un tablero (una matriz), de ceros, que son cambiados por un cuadro blanco en la funcion "mostrar tablero"
	int i, j;
	
	for (i=0; i<8; i++){

		for (j=0; j<8; j++){

			tablero[i][j] = 0;
		}
	}
}
 
void
nucleo (int ia){
	//se inican los datos necesario, el tablero de 8x8, el contador, el registro con 64 espacios, etc.
	int termino=0;
	int tablero[8][8], registro[64];
	int jugador, inicial; 
	int jugadas = 0;
	jugador = determinar_partida();
	inicial = jugador;
	generar_tablero_inicial (tablero);
	mostrar_tablero (tablero);
	printf ("PARTE EL JUGADOR %d\n", jugador);
	// se inicia el ciclo de juego con dos condiciones, ganar o llenar el tablero
	while (termino==0 && jugadas <=64){//este despues sera el interruptor de ganador
		
	playmaker (tablero, jugador, ia, jugadas, registro);
	
	if (jugador == 1){
		jugador = 2;
	}
	else{
		jugador = 1;
	}
	termino = verificar(tablero);
	jugadas++;
	}
	system ("clear");
	//cuando se acaba la partida, se limpia la pantalla, se deja solo el tablero y se va a la pantalla de ganador o final
	mostrar_tablero(tablero);
	pantalla_final(termino, registro, jugadas, inicial);
}

void
creditos(){
	//sinceramente no creo que esto necesita mayor explicacion de lo que es o lo que hace
	printf ("\n");
	printf ("\t\t\t\t\t\t\t\tJuego: 4 en linea\n");
	printf ("\n");
	sleep (1);
	printf ("\t\t\t\t\t\t\tAutores: Lisbeth Jimenez y Arturo Lobos\n");
	printf ("\n");
	sleep (1);
	printf ("\t\t\t\t\t\t\t\tProfesor: Fabio Durán\n");
	printf ("\n");
	sleep (1);
	printf ("\t\t\t\t\t\t\tProyecto final Soluciones Algoritmicas\n");
	printf ("\n");
	sleep (1);
	printf ("\t\t\t\t\t\t\tEscuela de Ingenieria Civil en Bioinformática\n");
	printf ("\n");
	getchar();
	getchar();
	system ("clear");
	main();
}

void
menu_principal(){
	// se muestra un titulo y despues unas opciones
	system ("clear");
	printf ("\t\t\t\t*******************************************************\n");
	printf ("\t\t\t\t*                                                     *\n");
	printf ("\t\t\t\t*                     4 EN LINEA                      *\n");
	printf ("\t\t\t\t*                                                     *\n");
	printf ("\t\t\t\t*******************************************************\n");
	
	sleep (1);
	int seleccion, ia;
	printf ("\n");
	printf ("\n");
	printf ("\n");
	printf ("\n");
	printf ("¿Que desea hacer?\n");
	printf ("1. Jugar solo vs. Computadora\n");
	printf ("2. Jugador vs. Jugador\n");
	printf ("3. Creditos\n");
	scanf ("%d", &seleccion);
	// el jugador elige si jugar solo, contra alguien, o ver quien no durmio la noche anterior para terminar este juego (tengo sueño)
	switch (seleccion){
		case 1:
			ia = 1;
			system ("clear");
			nucleo(ia);
			break;
		case 2:
			ia = 0;
			system ("clear");
			nucleo(ia);
			break;
		case 3:
			system ("clear");
			creditos();
			break;
		default:
			system ("clear");
			printf ("Opcion no valida");
			sleep (1);
			menu_principal();
			break;
		}
	}
	
int main (){
	// la funcion main, solo capta la hora y despues se va al menu principal
	srand (time(0));
	menu_principal();
	
	return 0;
}

	
