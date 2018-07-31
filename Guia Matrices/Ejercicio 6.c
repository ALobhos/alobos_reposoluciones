#include <stdio.h>
void
maxmin_semana(matriz[7][24]){
	
	int i=0;
	int j=0;
	int maxima;
	int minima;
	
	for ()


void
imprimir_matriz (int matriz[24][7]){
	
	int i, j;
	
	for (i=0; i<24; i++){
		for (j=0; j<7; j++){
			printf ("%d° ", matriz[i][j]);
		}
		printf ("\n");
	}
}
void
generar_matriz (){

	int matriz[7][24];
	int i, j, temperatura;

	for (i=0; i<7; i++){

		for (j=0; j<24; j++){
			
			printf ("Ingrese temperatura de la hora %d del dia %d", j, i+1);
			scanf ("%d", &temperatura);
			matriz[i][j] =  temperatura;
			//suerte y paciencia ingresando las 168 temperaturas 
		}
	}
	imprimir_matriz (matriz);
	maxmin_semana(matriz);
	maxmin_dia(matriz);
	media_semana(matriz);
	media_dia(matriz);
	dias_calor(matriz);
}

int main(){

	generar_matriz();

	return 0;
}
