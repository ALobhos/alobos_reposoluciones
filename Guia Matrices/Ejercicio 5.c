#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void 
invertir_matriz (int n, int m, int matriz[n][m]){
	
	printf ("Matriz invertida: \n");
	
	for (int i = 0; i<m; i++){
		for (int j=0; j<n;j++){
			printf ("%d ", matriz[j][i]);
		}
		printf ("\n");
	}
}

int generador_numero (){
	
	int numero = rand() %16;
	
	return numero;
}




void
generar_matriz (int N, int M){

	int matriz[N][M];
	int i, j;

	printf ("Matriz original: \n");

	for (i=0; i<N; i++){

		for (j=0; j<M; j++){

			matriz[i][j] = generador_numero();

			printf ("%d ", matriz[i][j]);
		}

		printf ("\n");
	}
	
	invertir_matriz (N, M, matriz);
}

int main(){
	int N, M;

	srand (time(0));

	printf ("Ingrese valor N y M para generar matriz: ");
	scanf ("%d", &N);
	scanf ("%d", &M);
	generar_matriz(N, M);

	return 0;
}
