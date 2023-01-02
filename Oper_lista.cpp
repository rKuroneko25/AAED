#include "ListaCab.h"
#include "Lista_Ord.h"
#include "Piladin.h"
#include "Conjunto_H.h"
#include "binario.h"
#include "Oper_lista.h"

#include <iostream>
#include <cstring>

using namespace std;

// EJERCICIO 3
void obliterar(Lista<int>& L, unsigned x)
{
	Lista<int>::posicion p = L.primera();
	while(p!=L.fin())
	{
		if(L.elemento(p)==x)
		{
			L.eliminar(p);
		}
		else
		{
			p = L.siguiente(p);
		}
	}
}

// EJERCICIO 4
Listaord<int> mezcla(Listaord<int>& L1, Listaord<int>& L2)
{
	Listaord<int> R;
	Listaord<int>::posicion p = L1.primera();
	while(p!=L1.fin())
	{
		R.insertar(L1.elemento(p));
		p = L1.siguiente(p);
	}
	p = L2.primera();
	while(p!=L2.fin())
	{
		R.insertar(L2.elemento(p));
		p = L2.siguiente(p);
	}
	return R;
}

// EJERCICIO 5
void ImprimeInverso(Lista<int>& L, Lista<int>::posicion p)
{
	Lista<int>::posicion q = p;
	Pila<int> P;
	while(q!=L.fin())
	{
		P.push(L.elemento(q));
		q = L.siguiente(q);
	}
	while(!P.vacia())
	{
		cout << P.tope();
		P.pop();
	}
}

// PRUEBA EJERCICIO 6
void conjunto()
{
	int x,n;
	Conjunto<int> C1,C2,C3;
	Conjunto<int>::posicion p;
	char cad[64];
	
	cout << "Introduce una cadena de enteros: ";
	cin >> cad;
	
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		n = cad[i]-'0';
		C1.insertar(n);
	}
	
	cout << "Introduce otra cadena de enteros: ";
	cin >> cad;
	
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		n = cad[i]-'0';
		C2.insertar(n);
	}
	
	cout << "+--------------------------------------+" << endl;
	cout << "| (1) Union (2) Interseccion (3) vacio |" << endl;
	cout << "| (4) Diferencia (5) Mostrar conjunto  |" << endl;
	cout << "+--------------------------------------+" << endl;
	
	do
	{
		cin >> x;
		
		switch(x)
		{
			case 0: break;
			case 1: C3 = C1.union_(C2); break;
			case 2: C3 = C1.interseccion(C2); break;
			case 3:
			{
				if(C3.vacio()) cout << "Es el conjunto vacio";
				else cout << "No es conjunto vacio";
				break;
			}
			case 4: C3 = C1.diferencia(C2); break;
			case 5:
			{
				p=C3.primera();
				cout << "{ ";
				while(p!=C3.fin())
				{
					cout << C3.elemento(p) << " ";
					p=C3.siguiente(p);
				}
				cout << "}";
				break;
			}
			default: cout << "Wrong choice" << endl;
		}	
	}while(x);
}

// EJERCICIO 7
template <typename T> Lista<T> concatenar(const Lista<Lista<T>>& LInic)
{
	typename Lista<Lista<T>>::posicion p;
	typename Lista<T>::posicion q;
	Lista<T> R,L;
	
	for(p = LInic.primera() ; p!=LInic.fin() ; p=LInic.siguiente(p))
	{
		L = LInic.elemento(p);
		for(q = L.primera() ; q!=L.fin() ; q = L.siguiente(q))
		{
			R.insertar(L.elemento(q),R.fin());
			//cout << R.elemento(R.anterior(R.fin()));
		}
	}
	
	return R;
}

// PRUEBA EJERCICIO 8
void binary()
{
	char cad1[64],cad2[64];
	unsigned x;
	bool stay=true;
	int n;
	
	cout << "Introduce una cadena de 0 y 1" << endl;
	cin >> cad1;
	
	cout << "Introduce otra cadena de 0 y 1" << endl;
	cin >> cad2;
	
	Binario B1(cad1),B2(cad2),B3;
	
	cout << endl;
	cout << "+------------------------------------------+" << endl;
	cout << "| (0) Salir (1) AND (2) OR (3) XOR (4) SHL |" << endl;
	cout << "|  (5) SHR (6) NOT (7) Mostrar resultado   |" << endl;
	cout << "+------------------------------------------+" << endl;
	
	do
	{
		cin >> x;
		switch(x)
		{
			case 0: stay = false;
			case 1: B3 = B1.AND(B2); break;
			case 2: B3 = B1.OR(B2); break;
			case 3: B3 = B1.XOR(B2); break;
			case 4:
			{
				cout << "Elige desplazamiento: ";
				cin >> n;
				B3 = B1.SHL(n);
				break;
			}
			case 5:
			{
				cout << "Elige desplazamiento: ";
				cin >> n;
				B3 = B1.SHR(n);
				break;
			}
			case 6: B3 = B1.NOT(); break;
			case 7: B3.mostrar(); break;
			default: cout << "Opcion invalida" << endl; break;
		}
	}while(stay);
}


