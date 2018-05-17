#include <stdio.h>
#include <stdlib.h>

int
descomponer (int numero){
	
	int digito;
	
	digito = numero%10;
	
	return digito;
}

int 
reducir (int numero, int digito){
	
	numero = (numero-digito) / 10;
	return numero;
}

int 
comparar_primero(int n1,int n2,int n3,int n4){
	int mayor1, mayor2, mayor
	
	mayor1 = comparar1y2(n1,n2);
	mayor2 = comparar3y4(n3,n4);
	
	mayor = compararmayores(mayor1,mayor2)
	
	return mayor;
}

// pregunte como hacer de forma corta esta parte (no programando 16 condicionales que seria ineficiente, y las respuestas me dejaron peor)
// ante la proximidad de un certamen de quimica (en la hora siguiente), conservo mi sanidad mental omitiendo este programa
int
numero_mayor (int n1,int n2,int n3,int n4){
	primero = comparar_primero(n1, n2, n3, n4);
	mayor = (primero * 1000) + (segundo*100) + (tercero * 10) + cuarto;
	printf ("El numero mayor es: %d", mayor);
	return mayor;
	
}

void 
numero_menor (int mayor){

	int imprimir;
	while (mayor!=0){
		imprimir = mayor%10;
		printf ("%d", imprimir);
		mayor = mayor - imprimir;
		mayor = mayor / 10;
	}
}

int main()
{
	int numero, n1, n2, n3, n4, mayor;
	
	printf ("Ingrese un numero de 4 digitos diferentes: ");
	scanf ("%d", &numero);
	
	if (numero <=1000 || numero >=9999){
		system ("clear");
		main();
	}
	
	n1 = descomponer(numero);
	numero = reducir (numero, n1);
	n2 = descomponer(numero);
	numero = reducir (numero, n2);
	n3 = descomponer(numero);
	numero = reducir (numero, n3);
	n4 = descomponer(numero);
	
	
	mayor = numero_mayor(n1,n2,n3,n4);
	printf ("El mayor numero a formar es: %d \n", mayor);
	printf ("El menor numero a formar es:");
	numero_menor(mayor);
	
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
