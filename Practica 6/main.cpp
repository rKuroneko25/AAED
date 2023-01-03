#include <iostream>
#include "ListaCab.h"
#include "Lista_Ord.h"
#include "E_S_lista.h"
#include "Oper_lista.h"

using namespace std;

int main()
{
	bool error=false;
	unsigned sel;
	int n;
	Lista<int> L;
	Listaord<int> L1,L2;
	Lista<Lista<int>> LInic;
	Lista<int>::posicion p;
	
	do
	{
		cout << "\n\n Elige ejercicio:\n (1) Obliterar elemento\n (2) Mezclar listas\n (3) Imprime inverso\n (4) Conjunto\n (5) Concatenar\n (6) Binario\n (7) Salir\n" << endl;
		cin >> sel;
		
		switch(sel)
		{
			case 1:
			{
				n = Entrada_1(L);
				obliterar(L,n);
				Salida_lista(L);
				error=false;
				break;
			}
			case 2:
			{
				Entrada_2(L1,L2);
				Salida_listaord(mezcla(L1,L2));
				error=false;
				break;
			}
			case 3:
			{
				p = Entrada_3(L);
				ImprimeInverso(L,p);
				error=false;
				break;
			}
			case 4:
			{
				conjunto();
				error=false;
				break;
			}
			case 5:
				Entrada_7(LInic);
				L = concatenar(LInic);
				Salida_lista(L);
				error=false;
				break;
			case 6:
			{
				binary();
				error=false;
				break;
			}
			case 7:
			{
				error=false;
				break;
			}
			default:
			{
				error=true;
				break;
			}
		}
	}while(error);
	
	return 0;	
}
