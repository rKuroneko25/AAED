#include <iostream>
#include "polinom.h"
#include "E_S_POL.h"

using namespace std;

void Entrada(polinomio& a)
{
	unsigned max;
	double c;
	
	cout << "Introduce grado del polinomio: ";
	cin >> max;
	
	for(int i=0 ; i<max+1 ; i++)
	{
		if (i==0){
			cout << endl << "Introduce el termino independiente: ";
		}
		else{
			cout << endl << "Introduce el coeficiente " << i << ": ";
		}
		
		cin >> c;
		a.coeficiente(i,c);
	}
	
	cout << endl;
}

void Salida(const polinomio& a)
{
	unsigned max = a.grado();
	int i = max;
	
	while (i!=0)
	{
		if(a.coeficiente(i) != 0)
		{
			if(a.coeficiente(i) > 0)
			{
				cout << " +" << a.coeficiente(i) << "x^" << i;
			}
			else
			{
				cout << " " << a.coeficiente(i) << "x^" << i;
			}
		}
		i--;	
	}
	
	if(a.coeficiente(0) != 0)
	{
		if(a.coeficiente(i) > 0)
		{
			cout << " +" << a.coeficiente(0) << endl;
		}
		else
		{
			cout << " " << a.coeficiente(0) << endl;
		}
	}

}
