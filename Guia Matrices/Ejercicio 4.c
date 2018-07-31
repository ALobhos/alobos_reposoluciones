#include <stdio.h>

void 
imprimir_matriz (int matriz[4][4]){
	
	int i, j;
	
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf ("%d ", matriz[i][j]);
		}
		printf ("\n");
	}
}

int 
comprobar_simetria (int matriz[4][4]){

	int i, j, real;
	real = 0;
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if (j != i){
				if (matriz[i][j] == matriz[j][i]){
					real = 1;
				}
				else {
					real = 0;
				}
				
			}
			
			else if (j>0){
				if (matriz[i][j] == matriz[i-1][j-1]){
					real = 1;
				}
				else {
					real = 0;
				}
			
			}
		}
	}
	return real;
}

void
generar_matriz (){

	int matriz[4][4];
	int i, j, n, simetrica;
	
	printf ("Ingrese valores para rellenar matriz de 4x4 (Los valores se ingresan de izquierda a derecha partiendo por la columna superior)");
	//La matriz siempre sera de 4x4 para la comodidad de este ejercicio, matrices de 5x5 para arriba significa ingresar 25 valores y mas aun
	//por lo que para este ejercicio y que sea dinamico (que no siempre sea la misma matriz), opte por hacer una matriz fija de 4x4 y que asi
	//se ingresen los 16 valores manualmente

	for (i=0; i<4; i++){

		for (j=0; j<4; j++){
			
			scanf ("%d", &n);
			matriz[i][j] = n;
		}
	}
	imprimir_matriz (matriz);
	simetrica = comprobar_simetria (matriz);

	if (simetrica == 1){
		printf ("La matriz es simetrica");
	}
	else{
		printf ("La matriz NO es simetrica");
	}

}

int main(){

	generar_matriz();

	return 0;
}

