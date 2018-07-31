#include <stdio.h>

void
generar_matriz (int N){

	int matriz[N][N];
	int i, j;

	for (i=0; i<N; i++){

		for (j=0; j<N; j++){

			if (i==j){
				matriz[i][j] = 1;
			}
			else{
				matriz[i][j] = 0;
			}
			
			printf ("%d ", matriz[i][j]);
		}

		printf ("\n");
	}
}

int main(){
	int N;

	printf ("Ingrese valor N para generar matriz: ");
	scanf ("%d", &N);

	generar_matriz(N);

	return 0;
}

