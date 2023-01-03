#include <iostream>
#include <cstring>
#include "Pila2.h"
#include "E_S_Pilas.h"
#include "Oper_pila.h"

using namespace std;
	
int main()
{
	char cad[64];
	Pila<int> P;
	bool error=false;
	unsigned sel;
	int a,b;
	char name[10]="messi.txt";
	
	do
	{
		cout << "\n Elige ejercicio:\n (1) Comprobar X&Y\n (2) Comprobar A#B#C#D\n (3) Invertir segmento de pila\n (4) Sumar filas fichero\n (5) Simular linea de texto" << endl;
		cin >> sel;
		
		switch(sel)
		{
			case 1:
			{
				Entrada_cad(cad);
				Salida_cad(ejercicio1(cad));
				error=false;
				break;
			}
			case 2:
			{
				Entrada_cad(cad);
				Salida_cad(ejercicio2(cad));
				error=false;
				break;
			}
			case 3:
			{
				P = Entrada_3(a,b);
				Salida_3(ejercicio3(P,a,b));
				error=false;
				break;
			}
			case 4:
			{
				Entrada_4(name);
				ejercicio4(name);
				//Salida_4(name);  No funciona por fallo del compilador
				error=false;
				break;
			}
			case 5:
			{
				ejercicio5();
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
