/* Iniciar funcion que calcula cuantas personas tendran lectura falsa
 * Iniciar funcion principal
 * Imprimir cuantas personas falsas hay
 * Imprimir cuantas personas de las falsas daran un resultado positivo
 * De esas personas con positivo realizar la comparacion de cuantas realmente estan infectadas (segun dato oficial)
 * Segun cuantas infectadas hay, se imprime el porcentaje real de infectados
*/
#include <stdio.h>

float
calcular_acierto(int total){
	int fallos;
	float porcentaje_error = 0.01;
	fallos = total * (porcentaje_error/100);
	return fallos;
}


int main()
{
	int total, fallos;
	float probabilidadacierto;
	total = 100000;
	printf ("Lo primero es calcular lo que es seguro, 1 de 100000 personas esta realmente infectada\n");
	printf ("y tenemos un test con 99.99 porciento de acierto y un 0.01 porciento de fallo\n");
	printf ("\n");
	fallos = calcular_acierto (total);
	printf ("Supongamos que aplicamos el test a las 100000 personas, si usamos los porcentajes de acierto nos dira que %d personas tienen una lectura falsa\n", fallos);
	printf ("y de esas 10 personas, tenemos 2 opciones con 50 porciento de probabilidad esta infectada o no esta infectada");
	printf ("\n");
	printf ("\n");
	printf ("por lo tanto de esas 10 personas 5 dira que estan infectadas, pero nosotros sabemos que solo 1 de las 100000 deberia estar infectada\n");
	printf ("por lo que si calculamos la probabilidad de estar infectado realmente, es 1 entre 5 personas");
	printf ("\n");
	printf ("\n");
	probabilidadacierto = (1*100)/5;
	printf ("Expresado en porcentajes, solo un %.0f porciento de las personas que el test les resulte positivo, estaran realmente infectadas", probabilidadacierto);
	return 0;
}
