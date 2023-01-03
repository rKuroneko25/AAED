#include <iostream>
#include "polinom.h"
#include "E_S_POL.h"
#include "Arit_POL.h"

using namespace std;

int main()
{
	int operacion;
	bool error = false;
	polinomio a(50),b(50);
		
	do
	{
		cout << "Elija una operacion" << endl << "1. Sumar" << endl << "2. Restar" << endl << "3. Multiplicar" << endl << "4. Derivar" << endl;
		cin >> operacion;

		switch(operacion)
		{
			case 1:
			{ 
				cout << "Introduce los datos del polinomio a: " << endl; 
				Entrada(a);
				cout << "Introduce los datos del polinomio b: " << endl; 
				Entrada(b);
				Salida(a+b);
				break;
			}
			case 2:
			{
				cout << "Introduce los datos del polinomio a: " << endl; 
				Entrada(a);
				cout << "Introduce los datos del polinomio b: " << endl; 
				Entrada(b);
				Salida(a-b);
				break;
			}
			case 3:
			{
				cout << "Introduce los datos del polinomio a: " << endl; 
				Entrada(a);
				cout << "Introduce los datos del polinomio b: " << endl; 
				Entrada(b);
				Salida(a*b);
				break;
			}
			case 4:
			{
				cout << "Introduce los datos del polinomio: " << endl; 
				Entrada(a);
				Salida(derivar(a));
				break;
			}
			default:
			{
				error = true;
				cout << "Opcion no valida" << endl;
				break;
			}
		}
	}while(error);
}
