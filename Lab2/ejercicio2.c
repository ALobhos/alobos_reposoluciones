#include <stdio.h>

int main()
{
	int n, filas, resto, inicio, act, rep;
	inicio = 0;
	printf ("Ingrese numero entero positivo: ");
	scanf ("%d", &n);
	filas=0;
	act=0;
	resto = (2*n)-1;
	rep = 0;
	
	
	
	while (rep<n) {
	inicio = 1;
	while (filas!=inicio){
		act++;
		printf ("%d", act);
		filas++;
	}
	while (filas!=resto){
		act--;
		printf ("%d", act);
		filas++;
	}
	rep++;
	inicio++;
}


	return 0;
}


		
