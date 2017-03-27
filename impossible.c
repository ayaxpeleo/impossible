#include <stdio.h>


int factores(int n1, int n2);
int sonlosnumeros(int n1, int n2);
int sumasok(int n);
int esprimo(int n);
int factores4(int n1, int n2);

int main()
{
	//factores(96);
	//return 0;

	puts("\nX y Y son dos numeros enteros. Ambos numeros son mayores a 1, y la suma de ambos es menor a 100.");
	puts("Sergio y Abraham son dos matematicos. Sergio solamente conoce el resultado de la suma X+Y,");
	puts("y Abraham solamente conoce el producto X*Y. La siguiente conversacion ocurre:");//2, 15	S: 17	A:30
	puts("\n\t1. Abraham: \"No puedo encontrar estos numeros\"");//30: 2,3,5	2*15, 3*10, 5*6
	puts("\t2. Sergio: \"Yo tampoco lo se, pero estaba seguro de que tu tampoco\"");//17:	2+15, 3+14, 4+13, 5+12, 6+11, 7+10, 8+9		ninguno es un par de numeros primos, por lo que Abraham no puede aun saber
	puts("\t3. Abraham: \"Entonces, los acabo de encontrar\"");	//17:	2+15, 3+14, 4+13, 5+12, 6+11, 7+10, 8+9
																//13:	2+11, 3+10, 4+9, 5+8, 6+7
																//11:	2+9, 3+8, 4+7, 5+6
																// 2 y 11 son primos, pero aun tiene 2 opciones más, por lo que no puede saber
	puts("\t4. Sergio: \"Si tu los encontraste, entonces yo tambien los encontre\"");
																//11:
																//2+9	18	2,3,3		2*9, 3*6
																//3+8	24	2,2,2,3		2*12, 3*8, 4*6

	puts("\nPREGUNTA:");
	puts("(Escribelos separados por un espacio)");
	puts("Que numeros son X y Y?: ");

	int n1, n2;
	//scanf("%d %d", &n1, &n2);
	int x, y;
	int ret=1;
	for(x=2;x<99 && ret!=0;x++)
	{
		for(y=2;y<99 && ret!=0;y++)
		{
			if(sonlosnumeros(x, y)==0)
			{
				printf(" **NUMEROS ENCONTRADOS!!**    %d y %d", x, y);
				fgetc(stdin);
				//ret=0;
			}
		}
	}
	return ret;
}

int esprimo(int n)
{
	int c;
	int ret=1;
	for(c=2;c<100;c++)
	{
		if(n%c==0 && n!=c)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

int sumasok(int n)
{
	int c, s1, s2;
	int ret=0;
	for(c=2;c<n;c++)
	{
		s1=c;
		s2=n-c;
		if(esprimo(s1) && esprimo(s2))
		{
			ret = s1;
			break;
		}
	}
	return ret;
}

int sonlosnumeros(int n1, int n2)
{
	int ret = 0;

	if(n1<2 || n2<2)
	{
		puts("Error, uno o ambos numeros no son mayores a 1.");
		ret=1;
	}
	else if(( n1+n2 )>99)
	{
		puts("Error, la suma de ambos numeros no es menor a 100.");
		ret=2;
	}
	else
	{
		if(esprimo(n1) && esprimo(n2))
		{
			printf("\n\t%d x %d = %d, pero esos son los unicos factores, ya que", n1, n2, n1*n2);
			printf("\n\ttanto %d como %d son numeros primos. Abraham si podria ", n1, n2);
			printf("\n\tsaber la suma que tiene Sergio y por lo tanto no se");
			printf("\n\tcumpliria lo que se dice en (1)\n");
			ret = 3;
		}
		else if(sumasok(n1+n2)!=0)
		{
			printf("\n\t%d es el resultado de la suma de %d y %d, y para que se", n1+n2, n1, n2);
			printf("\n\tcumpla lo que se dice en (2), ninguna de las posibles sumas");
			printf("\n\tdebe tener menos de 3 factores. Esto no se cumple por lo menos");
			printf("\n\ten un caso: %d + %d = %d, pues %d y %d ya no se pueden factorizar mas.\n", sumasok(n1+n2), (n1+n2)-sumasok(n1+n2), n1+n2, sumasok(n1+n2), (n1+n2)-sumasok(n1+n2));
			ret = 4;
		}
		else if(factores(n1, n2)==0)
		{
			printf("\n\t**********************************************************************");
			printf("\n\tSi Sergio esta seguro de que Abraham no los tiene (3), eso debe ser porque");
			printf("\n\tde los posibles pares de sumandos, ninguno esta formado por numeros");
			printf("\n\tprimos como %d + %d = %d\n", factores(n1, n2), (n1*n2)/factores(n1, n2), factores(n1, n2)+(n1*n2)/factores(n1, n2));
			ret = 5;
		}
		else
		{
			if(factores4(n1, n2)==1)
			{
				printf("\n\tPara que se cumpla lo que se dice en (4), una vez que Sergio descompone");
				printf("\n\tsu numero en posibles pares de sumandos, solo uno de ellos debe tener");
				printf("\n\tsolamente dos factores, esto no se da por lo menos en el caso de\n");
				printf("\n\t%d + %d = %d\n", n1, n2, n1+n2);
				ret = 6;
				//fgetc(stdin);
			}
		}
	}
	
	return ret;
}
																//17:
																//2+15	30	2,3,5		2*15, 3*10, 5*6
																//3+14	42	2,3,7		2*21, 3*14, 6*7
																//4+13	52	2,2,13		2*26, 4*13
																//5+12	60	2,2,3,5		2*30, 3*20, 4*15, 5*12, 6*10
																//6+11	66	2,3,11		2*33, 3*22, 6*11
																//7+10	70	2,5,7		2*35, 5*14, 7*10
																//8+9	72	2,2,2,3,3	2*36, 3*24, 4*18, 6*12, 8*9
																//El unico que tiene dos factores es el 

																//11:
																//2+9	18	2,3,3		2*9, 3*6
																//3+8	24	2,2,2,3		2*12, 3*8, 4*6
																//4+7	28	2,2,7		2*14, 4*7
																//5+6	30	2,3,5		2*15, 3*10, 5*6
																//Hay dos que tiene dos factores, por lo que Sergio no podría saber aún, los numeros no son validos																
int factores4(int n1, int n2)
{

	int ret=0;
	int c, div, num, f1, f2, n_sum, n_mul, s1, s2, fm1, fn1, fm2, fn2, fcntr, flag_exit, twofactors;
	
	n_sum = n1+n2;
	for(flag_exit=0, c=2, twofactors=0, ret=0;c<(n_sum/2) && flag_exit==0;c++)
	{
		s1=c;
		s2=n_sum-c;

		n_mul=s1*s2;
		printf("\n\t%d + %d = %d, \n\tMUL: %d\t", s1, s2, s1+s2, n_mul);
		for(div=2, num=n_mul, fcntr=0, ret=0;div<=(n_mul/2);div++)
		{
			if(num%div==0 && num!=div)
			{
				f1=div;
				f2=num/div;
				
				if(fcntr==0)
				{
					printf("%d*%d \t", f1, f2);
					fm1=f1;
					fn1=f2;
					fcntr++;
				}
				else if(fcntr==1 && ((f1+f2)!=(fm1+fn1)))//((fm1!=f1 && fn1!=f2)||(fm1!=f1 && fn1!=f2)))
				{
					printf("%d*%d (%d, %d)\t", f1, f2, fm1, fn1);
					fm2=f1;
					fn2=f2;
					fcntr++;
				}
				else if(fcntr==2 && ((f1+f2)!=(fm1+fn1)) && ((f1+f2)!=(fm2+fn2)))// && ((fm1!=f1 && fn1!=f2)||(fm1!=f1 && fn1!=f2)) && ((fm2!=f1 && fn2!=f2)||(fm2!=f1 && fn2!=f2)))
				{
					printf("%d*%d (%d,%d) (%d,%d)\t", f1, f2,fm1,fn1,fm2,fn2);
					//Hay mas de 2 factores, este par de numeros no es valido
					ret = 1;
				}
			}
		}	
		if(ret==0)
		{
			twofactors++;
			printf("\nSolo 2 factores encontrados!!");
		}
	}
	if(twofactors==1)
		return 0;
	else
		return 1;
}

				//52:	2,2,13	2*26	4*13
				//28:	2+26, 3+25, 4+24, 5+23, 6+22, 7+21, 8+20, 9+19, 10+18, 11+17, 12+16, 13+15, 14+14
				//17:	2+15, 3+14, 4+13, 5+12, 6+11, 7+10, 8+9
				//5 y 23 son primos, pero ya no tiene otras opciones, de modo que la respuesta es 17
	
				//17:	2+15, 3+14, 4+13, 5+12, 6+11, 7+10, 8+9
				//13:	2+11, 3+10, 4+9, 5+8, 6+7
				//11:	2+9, 3+8, 4+7, 5+6
				// 2 y 11 son primos, pero aun tiene 2 opciones más, por lo que no puede saber
int factores(int n1, int n2)
{
	int ret=0;
	int c, div, num, f1, f2, s1, s2, sum, primos_cntr, total_cntr;
	
	int n;
	n = n1*n2;
	for(div=2, num=n, ret=0, primos_cntr=0, total_cntr=0;div<n;div++)
	{
		if(num%div==0 && num!=div)
		{
			f1 = num/div;
			f2 = div;
			sum=f1+f2;
			printf("\n\t%d*%d=%d, %d+%d=%d\n", f1, f2, f1*f2, f1, f2, sum);
			for(c=2;c<sum;c++)
			{
				s1=c;
				s2=sum-c;
				printf("%d+%d, ", s1, s2);
				if(esprimo(s1) && esprimo(s2))
				{
					ret = 1;
					primos_cntr++;
					break;
				}
			}
			total_cntr++;
		}
	}

	if ((total_cntr-primos_cntr)>1)
		return 1;
	else
		return 0;
}	