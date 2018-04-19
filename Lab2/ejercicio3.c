#include <stdio.h>

int main()
{
	int peso;
	float gramos, gotas, dosis, anios;
	printf ("¿Cuantos kilos pesa el niño?\n");
	scanf ("%d", &peso);
	printf ("¿Cuantos años tiene?\n");
	scanf ("%f", &anios);
	gramos = peso * 0.2;
	gotas = gramos * 25;
	dosis = gotas / 3;
	printf ("Requiere de un total de %f gotas\n", gotas);
	if (anios<1){
		printf ("Esto significa que deberan ser 3 dosis de %f gotas cada una, ya que es menor de 1 año", dosis);
	}
	return 0;
}

