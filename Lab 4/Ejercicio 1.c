/*
1.- Iniciar funcion principal
2.- Preguntar numero que se quiere invertir
3.- Llamar funcion que imprime los numeros al reves (impresora)
4.- La funcion hace lo siguiente:
5.- Iniciar bucle que imprime los numeros
6.- El bucle calcula el resto del numero dividido en 10, y posteriormente imprime el resto
7.- Luego se resta el resto al numero 
8.- Ahora que el numero es divisible por 10, se divide en 10 para reducirlo
9.- El bucle se repite hasta que el numero sea 0 y se haya impreso todos los restos (que son el numero al reves)
10.- Se termina el programa
*/
#include <stdio.h>
#include <stdlib.h>

void
impresora(int numero){
	int imprimir;
	while (numero!=0){
		imprimir = numero%10;
		printf ("%d", imprimir);
		numero = numero - imprimir;
		numero = numero / 10;
	}
	
}



int main()
{
	int numero;
	
	printf ("Ingrese numero entero positivo:  ");
	scanf ("%d", &numero);
	
	impresora(numero);
	
	return 0;
}

