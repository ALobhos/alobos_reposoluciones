// se crea una funcion que calcula cuanto hay que pagar cada mes
// se crea un procedimiento imprime el pago total realizado
// se incia la funcion main
// se presenta el titulo
// se llama a la funcion que calcula los pagos mensuales, duplicando el pago anterior hasta que se terminen los meses
// en la funcion se emplea un bucle ademas de calcular el pago (duplicando la cuota anterior) y que  ademas suma los pagos en un variable que acumula el total pagado hasta ahora
// ya realizado el bucle 20 veces el programa termina



#include <stdio.h>
#include <stdlib.h>

int
dinero_por_mes(int mes, int pago, int total){

	//pago inicial es 10
	pago = 10;
	total = 0;
	for (mes=1;mes<=20;mes++)
	{
	
		printf ("El mes %d la cuota corresponde a %d$\n", mes, pago);
		total = total + pago;
		pago = pago * 2;
	}
	return total; 
}


void
pago_total(int total){
	
	printf ("El total pagado al final de las cuotas es: %d\n", total);
	
}


int main()
{
	int mes, pago, total;
	
	printf ("***Calculo de cuotas y pago total***\n");
	
		total = dinero_por_mes (mes, pago, total);
		pago_total(total);
		return 0;
	}
	
		
		
