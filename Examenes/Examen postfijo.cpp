/* 
Podemos expresar una expresión aritmética de dos formas diferentes:
- Infijo: (A + B) * (C + D) | | X / Y * Z + W
- Postfijo: AB+CD+* | | XY/Z*W+

Dada una expresión postfijo en forma de cadena de caracteres y una lista de
las variables que aparecen en dicha expresión junto a sus respectivos valores,
programa una función que devuelva el resultado de evaluar la expresión,
haciendo uso del TAD Pila.

Para simplificar el problema asumiremos que la expresión postfijo es correcta,
que consta sólo de dos operadores elementales (+, -, *, y /) y que los
operandos son variables cuyo nombre constan de un solo carácter

Ejemplo:
Teniendo las variables A = 2, B = 3, C = 1, D = 2
- AB+CD+* = 15
*/

#include <iostream>
#include "Piladin.h"

double fun(char* cad1, char* cad2);
double valor(char c, char* cad);
double op(char c, double op1, double op2);

using namespace std;

int main()
{
	char cad1[8] = "XY/Z*W+";
	char cad2[9] = "X1Y2Z2W2";
	double res = fun(cad1,cad2);
	cout << "El resultado es: " << res << endl;
}

double fun(char* cad1, char* cad2)
{
	Pila<double> P1,P2;
	double res=0,a=0,b=0;
	for(unsigned i=0 ; cad1[i]!='\0' ; i++)
	{
		if(cad1[i]=='+' || cad1[i]=='-' || cad1[i]=='*' || cad1[i]=='/')
		{
			if(P1.vacia())
			{
				b=P2.tope();
				P2.pop();
				a=P2.tope();
				P2.pop();
			}
			else
			{
				b=P1.tope();
				P1.pop();
				
				if(P1.vacia())
				{
					a=P2.tope();
					P2.pop();
				}
				else
				{
					a=P1.tope();
					P1.pop();
				}
			}
			P2.push(op(cad1[i],a,b));
		}
		else
		{
			P1.push(valor(cad1[i],cad2));
		}
	}
	return P2.tope();
}

double op(char c, double op1, double op2)
{
	double res=0;
	switch(c)
	{
		case '+':
		{
			res=op1+op2;
			break;
		}
		case '-':
		{
			res=op1-op2;
			break;
		}
		case '*':
		{
			res=op1*op2;
			break;
		}
		case '/':
		{
			res=op1/op2;
			break;
		}
	}
	return res;
}

double valor(char c, char* cad)
{
	Pila<char> P;
	unsigned i;
	for (i=0 ; cad[i]!=c ; i++);
	
	i++;
	
	while((cad[i]-'0' >= 0 && cad[i]-'0' <= 9) || cad[i] == '-') // ¿?
	{
		P.push(cad[i]);
		i++;
	}
	
	double res=0,mul=1;
	
	while(!P.vacia())
	{
		if(P.tope()=='-')
		{
			res*=-1;
			P.pop();
		}
		else
		{
			res+=P.tope()-'0'*mul;
			P.pop();
			mul*=10;
		}
	}
	
	return res;
}

