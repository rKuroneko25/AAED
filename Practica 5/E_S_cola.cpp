#include <iostream>
#include <cstring>
#include "Piladin.h"
#include "coladin.h"
#include "colapse.h"
#include "E_S_cola.h"

using namespace std;

void entrada_pila(Pila<int>& P)
{
	unsigned n;
	cout << "Introduce una secuencia de numeros para la Pila (Ctrl + Z para parar de introducir)" << endl;
	while(cin >> n)
	{
		P.push(n);
	}
}

void entrada_cola(Cola<int>& C)
{
	unsigned n;
	cout << "Introduce una secuencia de numeros para la Cola (Ctrl + Z para parar de introducir)" << endl;
	cin.clear();
	while(cin >> n)
	{
		C.push(n);
	}
}

void salida1(bool ta_bien)
{
	if(ta_bien)
	{
		cout << "Es una pila isomorfica";
	}
	else
	{
		cout << "No es una pila ismorfica";
	}
}

void entrada_2(Cola<int>& C, int& a, int& b)
{
	char cad[64];
	cout << "Introduce elemento delimitador a: ";
	cin >> a;
	cout << "Introduce elemento delimitador b: ";
	cin >> b;
	cout << "Introduce una cadena de enteros" << endl;
	cin >> cad;
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		C.push(cad[i]-'0');
	}
}

void salida_2(Cola<int>& C)
{
	while(!C.vacia())
	{
		cout << C.frente();
		C.pop();
	}
}

bool entrada_3(int& a)
{
	unsigned n;
	cout << " Introduce una operacion:\n (1) Entrada\n (2) Salida" << endl;
	cin >> n;
	cout << " Introduce la matricula (4 digitos): ";
	cin >> a;
	if(n==1)
	{
		return true; // Entrada
	}
	else
	{
		return false; // Salida
	}
}

void salida_3(aerodromo A)
{
	cout << "Aerodromo: ";
	for (unsigned i=0 ; i<12 ; i++)
	{
		if(A.M.vacia())
		{
			cout << "____ ";
		}
		else
		{
			cout << A.M.frente() << " ";
			A.M.pop();
		}
	}
	cout << "\nCola de espera: ";
	while(!A.E.vacia())
	{
		cout << A.E.frente() << " ";
		A.E.pop();		
	}	
}



