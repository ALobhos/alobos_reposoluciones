/*
* Se inicia la funcion principal
* La funcion principal incluye la hora del sistema y despues pregunta que opcion desea tomar
* Seleccionada la opcion, se le asignan valores a A y B llamando a la funcion que genera numeros aleatorios
* Se comprueba si son valores validos (diferentes) llamando a la funcion validar
* La funcion validar comprobara si son diferentes o iguales, si son iguales, cambiara ambos y volvera a comprobar hasta que sean diferentes
* Se imprime los valores de cada opcion
* Se llama al procedimiento que determina si se gano o se perdio, este comprueba si la opcion elegida es mayor o menor que la otra
* Se pregunta al usuario si quiere volver a intentar
* Si el usuario acepta, se limpia la pantalla y se llama a la funcion principal
* Sino, el programa termina
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
generar_opcion (){
	int opcion;
	opcion = rand ()%11;
	
	return opcion;
}


void
determinar_ganador (int opcionA, int opcionB, int seleccion){
	
	switch (seleccion){
		case 'A':
			if (opcionA > opcionB){
				printf ("¡HAS GANADO!\n");
			}
			else{
				printf ("¡HAS PERDIDO!\n");
			}
			break;
		
		case 'B':
			if (opcionA < opcionB){
				printf ("¡HAS GANADO!\n");
			}
			else{
				printf ("¡HAS PERDIDO!\n");
			}
			break;
		
		default:
			printf ("OPCION NO VALIDA >:C\n");
			break;
		}
}		
				
int
validar (int opcionA, int opcionB){
	
	if (opcionA == opcionB){
		
		opcionA = generar_opcion();
		opcionB = generar_opcions();
		validar (opcionA, opcionB);
	}
	
	return opcionA;
}

void
imprimir_opciones (int opcionA, int opcionB){
	
	printf ("Opcion A: %d \nOpcion B: %d \n", opcionA, opcionB);
}


int main()
{
	int opcionA, opcionB;
	char seleccion;
	
	srand (time (0));
	
	printf ("¿Por que opcion desea apostar, A ó B? \n");
	scanf (" %c", &seleccion);
	
	opcionA = generar_opcion ();
	opcionB = generar_opcion ();
	opcionA = validar(opcionA, opcionB);
	imprimir_opciones (opcionA, opcionB);
	determinar_ganador (opcionA, opcionB, seleccion);
	
	
	printf ("¿Quieres apostar otra vez? (s/n)");
	scanf (" %c", &seleccion);
	
	if (seleccion == 's' || seleccion == 'S'){
		system ("clear");
		main();
	}
	
	return 0;
}

	
	
	
	
					
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
