// se inicia una funcion que consiste en un bucle  que pregunta continuamente cuantas horas trabajo por dia
// el bucle ademas acumula las horas trabajadas en la variable "total"
// se inicia un proceso que recibe las horas totales y el pago por hora, calcula el pago final y lo imprime
// se inicia la funcion principal
// se pregunta cuanto se gana por hora
// se llama a la funcin que cuenta las horas
// despues de contar las horas se llama al proceso que calcula el pago
// el proceso imprime el pago
// habiendo imprimido el pago el programa termina 


#include <stdlib.h>
#include <stdio.h>

int
horas_trabajadas(int horas, int total){
	int dia;
	total = 0;
	for (dia=1;dia<=6;dia++){
		
		
		printf ("¿Cuantas horas trabajo el dia %d?: ", dia);
		scanf ("%d", &horas);
		
		total = total + horas;
		
		horas = 0;
	}	
		return total;
	
}



void
calculo_sueldo(int total, int pagohora, int pago){
	
	
	pago = pagohora * total;
	
	printf ("El pago por sus horas trabajadas es: %d$", pago);
	
}


int main()
{
	int pago, horas, total, pagohora;
		
		printf ("*************** CALCULADORA DE SUELDO ***************\n");
		printf ("\n");
		printf ("¿Cuanto le pagan por hora?: ");
		scanf ("%d", &pagohora);
		total = horas_trabajadas(horas, total);
		calculo_sueldo(total, pagohora, pago);
		return 0;
	}
	






	
	
	
