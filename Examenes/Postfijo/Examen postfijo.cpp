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
#include "ListaCab.h"

struct parametro
{
	char nombre;
	float valor;
};

double fun(char*, Lista<parametro>);
double valor(char c, Lista<parametro>);
double op(char c, double op1, double op2);

using namespace std;

int main()
{
	char cad1[8] = "XY/Z*W+";
	
	Lista<parametro> L;
	
	parametro v;

    v.nombre='X'; v.valor=1;
    L.insertar(v,L.fin());

    v.nombre='Y'; v.valor=2;
    L.insertar(v,L.fin());

    v.nombre='Z'; v.valor=2;
    L.insertar(v,L.fin());

    v.nombre='W'; v.valor=2;
    L.insertar(v,L.fin());
	
	double res = fun(cad1,L);
	cout << "El resultado es: " << res << endl;
}

double fun(char* cad1, Lista<parametro> L)
{
	Pila<double> P1;
	double res=0,a=0,b=0;
	for(unsigned i=0 ; cad1[i]!='\0' ; i++)
	{
		if(cad1[i]=='+' || cad1[i]=='-' || cad1[i]=='*' || cad1[i]=='/')
		{
			b=P1.tope();
			P1.pop();
			a=P1.tope();
			P1.pop();

			P1.push(op(cad1[i],a,b));
		}
		else
		{
			P1.push(valor(cad1[i],L));
		}
	}
	return P1.tope();
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

double valor(char c, Lista<parametro> L)
{
	Lista<parametro>::posicion p=L.primera();
	bool encontrado=false;
	
	while(p!=L.fin() && !encontrado)
	{
		if(L.elemento(p).nombre==c)
		{
			encontrado=true;
		}
		else
		{
			p=L.siguiente(p);
		}
	}
	
	return L.elemento(p).valor;
}

