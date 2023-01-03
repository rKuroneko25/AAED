#include <iostream>
#include "Piladin.h"
#include "colapse.h"
#include "coladin.h"
#include "Aerodromo.h"
#include "E_S_cola.h"
#include "Oper_cola.h"

using namespace std;
		
int main()
{
	aerodromo A;
	Pila<int> P;
	Cola<int> C;
	bool error=false,op;
	unsigned sel;
	int a=0,b=0;
	
	do
	{
		cout << "\n\n Elige ejercicio:\n (1) Pila isomorfica\n (2) Invertir segmento cola\n (3) Aerodromo\n (4) Salir\n" << endl;
		cin >> sel;
		
		switch(sel)
		{
			case 1:
			{
				entrada_pila(P);
				entrada_cola(C);
				salida1(ejercicio1(P,C));
				error=false;
				break;
			}
			case 2:
			{
				entrada_2(C,a,b);
				salida_2(ejercicio2(C,a,b));
				error=false;
				break;
			}
			case 3:
			{
				op = entrada_3(a);
				ejercicio3(A,op,a);
				salida_3(A);
				error=true;
				break;
			}
			case 4:
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
