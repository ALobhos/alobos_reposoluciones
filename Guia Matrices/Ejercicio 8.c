#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void
axial_matriz (int n, int m, int matriz[n][m]){
	
	printf ("Matriz invertida: \n");
	
	for (int i=n-1; i>=0; i--){
		for (int j = 0; j<m; j++){
			printf ("%d ", matriz[i][j]);
		}
		printf ("\n");
	}
}


int
numero_aleatorio (){
	
	int numero = rand() %21;
	
	return numero;
}

void
generar_matriz (int N, int m){

	int matriz[N][m];
	int i, j;

	printf ("Matriz original: \n");
	
	for (i=0; i<N; i++){

		for (j=0; j<m; j++){

			matriz[i][j] = numero_aleatorio();

			printf ("%d ", matriz[i][j]);
		}

		printf ("\n");
	}
	printf ("\n");
	axial_matriz(N, m, matriz);
}

int main(){
	int N, m;

	printf ("Ingrese valor N y M para generar matriz: ");
	scanf ("%d", &N);
	scanf ("%d", &m);
	generar_matriz(N, m);

	return 0;
}
