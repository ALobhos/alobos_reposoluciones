#include <stdio.h>

int main()
{
	// declaracion de todas las variables necesarias (se utilizara float debido a que son notas con decimales)
	float c1, c2, nc, l, sl, tl, nl, t, st, tt, nt, nf;
	sl = 0;
	st = 0;
	tl = 0;
	tt = 0;
	// se debe avisar al programa que las variables anteriores parten desde el 0
	char cn;
	
	// se va a trabajar, pidiendo y calculando datos en bloques
	// no se sabe cuantas notas se tienen en total en los lab o en los controles, por lo que se pedira notas hasta que el usuario diga que son todas
	
	{
		printf ("Notas de laboratorio: \n");
		while (cn!='s' && cn!='S'){
			printf ("¿cual es su nota? : ");
			scanf ("%f", &l);
			sl = sl + l;
			tl++;
			printf ("Son esas todas sus notas (s/n)");
			while (getchar()!='\n');
			scanf ("%c", &cn); 
			// el comando anterior solamente se usa porque, sin el, el programa tiende a fallar
			// "tl" representa la cantidad de notas hasta el momento
			// "sl" representa la suma de todas las notas hasta el momento
			// todo esto para el calculo de la media
		}
		//media = suma de todos los datos, partido en numero de datos
	
		nl = sl / tl;
		cn = 'f';
		// (nl es el promedio) 
	}
	// Mismo procedimiento anterior
	{
		printf ("Notas de controles: \n");
		while (cn!='s' && cn!='S'){
			printf ("¿cual es su nota? : ");
			scanf ("%f", &t);
			st = st + t;
			tt++;
			printf ("Son esas todas sus notas (s/n)");
			while (getchar()!='\n');
			scanf ("%c", &cn); 
		}
		nt = st / tt;
	}
	//en el ultimo caso, sabemos que son 2 notas hasta ahora
	{
		printf ("Ingrese sus dos notas de certamenes: \n");
		
		scanf ("%f", &c1);
		scanf ("%f", &c2);
		
		nc = (c1+c2)/2;
	}
	
	//se va a calcular la media, utilizando los valores de cada promedio (certamen = 70%, laboratorio = 20%, controles = 10%)
	
	nf = (nc * 0.7) + (nt * 0.1) + (nl * 0.2);
	float fal, req, act;
	
	if(nf<4.0 && nf>1)
	{
		act = (nf * 0.7);
		fal = (4 - nf) + act;
		req = ((3 * fal) - (2 * act)) / 0.7;
		
		if(req>7){
			printf ("Ya reprobaste, mejor no pierdas tu tiempo");
		}
		else{
			printf ("Necesitas un %f para aprobar el ramo", req);
		}
	}
	else if(nf>4.0 && nf<7)
	{
		act = ((nf * 0.7) / 7) * 10;
		printf ("Actualmente estas aprobando el ramo, pero trata de no sacarte menos de un %f", act);
	}
	else if(nf==4){
		act = ((nf * 0.7) / 7) * 10;
		printf ("Estas pasando justo, si te sacas menos de un %f te hechaste el ramo", act);
	}
	else{
		printf ("Ingresaste una o mas notas no validas");
	}
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
