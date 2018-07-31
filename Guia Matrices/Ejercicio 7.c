#include <stdio.h>
#include <stdlib.h>

int
sumatoria_fila (int i, int matriz[5][4]){
	
	int total = 0;
	for (int x = 0; x<5; x++){
		
		total = total + matriz[x][i];
	}
	return total;
}

void
imprimir_matriz (int matriz[5][4]){
	system ("clear");
	int i, j, fila[4];
	
	for (i=0; i<5; i++){
		for (j=0; j<4; j++){
			printf ("%d ", matriz[i][j]);
		}
		printf ("\n");
	}
	for (i=0;i<4;i++){
		fila[i] = sumatoria_fila(i, matriz);
		printf ("%d ", fila[i]);
	}
}


void
generar_matriz (){

	int matriz[5][4];
	int i, j, valor;

	printf ("Ingrese los 20 valores para generar una matriz de 4x4: \n");
	
	for (i=0; i<5; i++){

		for (j=0; j<4; j++){
			scanf ("%d", &valor);
			matriz[i][j] = valor;
		}
	}
	imprimir_matriz (matriz);
}

int main(){

	generar_matriz();

	return 0;
}
