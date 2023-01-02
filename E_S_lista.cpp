#include "ListaCab.h"
#include "Lista_Ord.h"
#include "E_S_lista.h"
#include "cstring"

#include <iostream>
using namespace std;

// EJERCICIO 3
int Entrada_1(Lista<int>& L)
{
	char cad[64];
	int x,n;
	cout << "Introduce un numero a eliminar" << endl;
	cin >> x;
	cout << "Introduce una cadena de numeros" << endl;
	cin >> cad;
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		n = cad[i]-'0';
		L.insertar(n,L.fin());
	}
	return x;
}

// EJERCICIO 3, 5 Y 7
void Salida_lista(Lista<int> L)
{
	Lista<int>::posicion p = L.primera();
	while(p!=L.fin())
	{
		cout << L.elemento(p);
		p = L.siguiente(p);
	}
}

// EJERCICIO 4
void Entrada_2(Listaord<int>& L1, Listaord<int>& L2)
{
	char cad[64];
	int n;
	cout << "Introduce una cadena de numeros" << endl;
	cin >> cad;
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		n = cad[i]-'0';
		L1.insertar(n);
	}
	cout << "Introduce otra cadena de numeros" << endl;
	cin >> cad;
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		n = cad[i]-'0';
		L2.insertar(n);
	}
}

// EJERCICIO 4
void Salida_listaord(Listaord<int> L)
{
	Listaord<int>::posicion p = L.primera();
	while(p!=L.fin())
	{
		cout << L.elemento(p);
		p = L.siguiente(p);
	}
}

// EJERCICIO 5
Lista<int>::posicion Entrada_3(Lista<int>& L)
{
	Lista<int>::posicion p=L.primera();
	int n;
	char cad[64];
	
	cout << "Introduce una cadena de numeros" << endl;
	cin >> cad;
	
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		n = cad[i]-'0';
		L.insertar(n,L.fin());
	}
	
	cout << "Introduce una posicion a partir de la cual mostrar la cadena" << endl;
	cin >> n;
	
	for(unsigned i=1 ; i<n ; i++)
	{
		p=L.siguiente(p);
	}
	
	return p;
}

// EJERCICIO 7
void Entrada_7(Lista<Lista<int>>& LInic)
{	
	int n;
	char cad[64];
	Lista<int> L;
	Lista<Lista<int>>::posicion p=LInic.primera();
	unsigned j=0;
	
	cout << "Introduce una cadena con los datos de las distintas listas separados por guiones" << endl;
	cin >> cad;

	for(unsigned i=0 ; i<strlen(cad) ; i++, j++)
	{
		while (cad[j]!='-' && cad[j]!='\0')
		{
			n = cad[j]-'0';
			L.insertar(n,L.fin());
			j++;
			i++;	
		}
		
		LInic.insertar(L,p);
		p=LInic.siguiente(p);
		
		while(L.primera()!=L.fin())
		{
			L.eliminar(L.primera());
		}
	}
}

