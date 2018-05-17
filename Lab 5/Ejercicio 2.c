/*
 * Se inicia la funcion principal
 * Se pide al usuario que ingrese un numero natural, si el usuario no cumple, se limpia la pantalla y se llama a la funcion principal hasta que se ingrese un valor valido
 * Se llama a la funcion descomponedora del numero
 * Esta funcion descompone el numero en sus unidades y las suma (se usa resto de 10 para determinar las unidades)
 * Se retorna la suma de los numeros
 * Si la suma de los numeros es igual o mayor a 10, el numero toma el valor de la raiz y se envia a descomponer denuevo
 * Cuando la raiz tenga un solo digito (menor que 10), se imprime la raiz y se termina el programa
*/

#include <stdio.h>
#include <stdlib.h>

int
descomponer (int numero){
	int unidad;
	int raiz = 0;
	while (numero!=0){
	unidad = (numero%10);
	numero = (numero-unidad) / 10;
	raiz =  raiz + unidad;
}
	
	 
	return raiz;
	
}

void 
imprimir (int raiz){
	printf ("La raiz digital es: %d", raiz);
}



int main(void)
{
	int numero, raiz_digital;
	
	printf ("Ingrese un numero natural:");
	scanf ("%d", &numero);
	if (numero <= 0){
		system ("clear");
		main();
	}
	raiz_digital = descomponer (numero);
	
	if (raiz_digital >= 10){
		numero = raiz_digital;
		raiz_digital = descomponer (numero);
	}
	imprimir (raiz_digital);
	return 0;
}
