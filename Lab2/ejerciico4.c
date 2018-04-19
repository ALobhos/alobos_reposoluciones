#include <stdio.h>

int main()
{
	int gf, gc, puntos;
	char c;
	puntos = 0;
	printf ("Ingrese sus resultados\n");
	while (c!='n' && c!='N'){
		printf ("Goles a favor: ");
		scanf ("%d", &gf);
		printf ("Goles en contra: ");
		scanf ("%d", &gc);
		if (gf>gc){
			puntos = puntos + 3;
		}
		else if (gf==gc){
			puntos++;
		}
		while (getchar()!='\n');
		printf ("¿Queda otro partido por contar? (s/n):  ");
		scanf ("%c", &c);
	}
	printf ("Sus puntos hasta ahora son: %d puntos", puntos);
	return 0;
}
