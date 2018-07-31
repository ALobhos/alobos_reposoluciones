#include <stdio.h>

int calcular_filas (int multiplo,int multiplicador){

	int total;
	total = multiplicador * multiplo;

	return total;
}

int calcular_total (int factor, int cuadrado){

	int total;
	total = (cuadrado * cuadrado) * factor;

	return total;
}


void
generar_matriz (int N){

	int matriz[N][N];
	int i, j, valor, filas, total;
	
	printf ("¿Con que valor desea rellenar la matriz? \n");
	scanf ("%d", &valor);

	for (i=0; i<N; i++){

		for (j=0; j<N; j++){

			matriz[i][j] = valor;

			printf ("%d ", matriz[i][j]);
		}

		printf ("\n");
	}
	
	filas = calcular_filas (valor, N);

	total = calcular_total (valor, N);


	printf ("La sumatoria de las filas es %d, mientras que el total de toda la matriz sumada es %d", filas, total);
}

int main(){

	int N;

	printf ("Ingrese valor N para generar matriz: ");
	scanf ("%d", &N);

	generar_matriz(N);

	return 0;
}

