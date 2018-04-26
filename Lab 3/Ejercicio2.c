// se crea un procedimiento que imprimirá la representacion del termómetro
// se crea una funcion que dibuja la linea del termometro
// se inicia la funcion principal
// se pregunta cuantos grados marca el termometro como maximo
// se pregunta cuanto esta marcando el termometro actualmente
// el proceso esta dividida en 2 partes
// el primer bucle imprime el 0 y los multiplos de 10 (que se comprueban utilizando el resto)
// el segundo bucle imprime | en cada multiplo de 10
// la funcion utiliza un bucle que imprime guiones (-) hasta que el numero de guion es la temperatura que sea la que se indico al inicio
// habiendose dibujado el termometro el programa termina



#include <stdio.h>
#include <stdlib.h>

void
dibujar_termometro (int tmaxima){
	int numero, linea;
	
	for (numero=0;numero<=tmaxima;numero++){
	
		if ((numero%10)==0){
			printf ("%d", numero);
		}
		else if ((numero%10)==1){
			printf("");
		}
		else{
			printf (".");
		}
	}
	printf ("\n");
	for (linea=0; linea<=tmaxima; linea++){
		
		if ((linea%10)==0){
			printf ("|");
		}
		else{
			printf (" ");
		}
	}
	printf("\n");
}



int
temperatura_marcada(int tmarcada){
	int grado;
	for (grado=0;grado<=tmarcada;grado++){
		
		if (grado==tmarcada){
			printf("*");
		}
		else{
			printf("-");
		}
	}
	return tmarcada;
}

int main()
{
	int tmaxima, tmarcada;

	printf ("***FABRICA DE TERMOMETROS***\n");
	printf ("\n");
	printf ("¿Cuantos grados muestra su termometro?:  ");
	scanf ("%d", &tmaxima);
	printf ("¿Cuantos grados quiere que marque?:  ");
	scanf ("%d", &tmarcada);
	
	dibujar_termometro(tmaxima);
	temperatura_marcada(tmarcada);
	
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
