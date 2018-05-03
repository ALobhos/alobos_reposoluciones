/*
1.- Iniciar una funcion que reparta los huevos en tres personas
2.- Iniciar funcion principal
3.- Llamar funcion que divide los huevos para que retorne los huevos por persona
4.- Imprimir premisa que justifica el precio de cada huevo
5.- Calcular cuanto fue el aporte de cada uno de los amigos
6.- Imprimir cuanto fue el aporte de cada uno
7.- Calcular cuanto debe pagar a cada amigo en funcion de su aporte y el precio de los huevos
8.- Imprimir cuanto debe pagar a cada uno en realidad
9.- Terminar Algoritmo
*/
#include <stdio.h>
#include <stdlib.h>


float
dividir_huevos (int huevos){
	float ovopercapita;
	ovopercapita = huevos / 3.0;
	
	return ovopercapita;
}



int main()
{ 
	float ovopercapita, aportejuan, aportemanuel, pagojuan, pagomanuel;
	int huevos = 8;
	ovopercapita = dividir_huevos (huevos);
	
	printf ("Primero que todo, si pagara 80 pesos por los 8 huevos significaria que el huevo vale 10 pesos\n");
	printf ("pero si esto fuera cierto significaria que Antonio se comio 8 huevos. \n");
	printf ("\n");
	printf ("El problema dice que se repartieron 8 huevos en partes iguales, por lo que en realidad cada uno se comio %f huevos\n", ovopercapita);
	printf ("asi que en realidad no debe pagar 50 a Juan y 30 a Manuel.\n");
	printf ("La respuesta esta en ver cuantos huevos aporto cada uno:\n");
	
	aportejuan = 5 - ovopercapita;
	aportemanuel = 3 - ovopercapita;
	
	printf ("Juan aportó %.1f huevos\n", aportejuan);
	printf ("Manuel aportó %.1f huevos\n", aportemanuel);
	
	printf ("\n");
	printf ("\n");
	
	
	
	pagojuan = (aportejuan * 100) / 10;
	pagomanuel = (aportemanuel * 100) / 10;
	
	printf ("Por lo que podemos calcular que a Juan le corresponden %.0f pesos, porque es la cantidad de huevo que aportó\n", pagojuan);
	printf ("Mientras que a Manuel le corresponden %.0f pesos, que tambien es la cantidad de huevo que aportó", pagomanuel);
	return 0;
}

	
	
	
	
	
	
	
	
				
