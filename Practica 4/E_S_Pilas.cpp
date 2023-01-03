#include <iostream>
#include <fstream>
#include <cstring>

#include "Pila2.h"
#include "E_S_Pilas.h"
//#include "flujo.h"

using namespace std;

void Entrada_cad(char* cad)
{
	cout << "Introduce una cadena:\n";
	cin >> cad;
}

void Salida_cad(bool b)
{
	if(b)
	{
		cout << "Se cumple la condicion";
	}
	else
	{
		cout << "No se cumple la condicion";
	}
}

Pila<int> Entrada_3(int& a, int& b)
{
	char s[64];
	Pila<int> P;
	cout << "Introduce delimitador a: " << endl;
	cin >> a;
	cout << "Introduce delimitador b: " << endl;
	cin >> b;
	cout << "Introduce una secuencia de enteros: " << endl;
	cin >> s;
	for (unsigned i=strlen(s) ; i!=0 ; i--)
	{
		unsigned j=s[i-1]-'0';
		P.push(j);
	}
	return P;
}

void Salida_3(Pila<int> P)
{
	while (!P.vacia())
	{
		cout << P.tope();
		P.pop();
	}
}

void Entrada_4(char* name)
{
	char boff[64];
	fstream f(name,fstream::out | fstream::in | fstream::trunc);
	
	cout << "Introduce un numero" << endl;
	cin >> boff;
	f << boff;
	f << "\n";
	
	cout << "Introduce otro numero" << endl;
	cin >> boff;
	f << boff;
	f << "\n";
}

/*void Salida_4(char* name)
{
	Pila<int> P,Q,R;
	fstream f(name);
	
	f >> P >> Q >> R;
	
	while(!R.vacia())
	{
		cout << R.tope();
		R.pop();
	}
}*/



