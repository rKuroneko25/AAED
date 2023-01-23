#include <iostream>
#include "ListaCab.h"
#include "Piladin.h"
#include "Coladin.h"
#include <cstring>

using namespace std;

Cola<Pila<char>> texto;
void MostrarTexto(Cola<Pila<char>>);

int main()
{
	char aux[64]="El municipl@io";
	
	for(unsigned j=0 ; j<2 ; j++)
	{
		Pila<char> L_aux;
		for(unsigned i=0 ; i<strlen(aux) ; i++)
		{
			L_aux.push(aux[i]);
		}
		memcpy(aux,"ligare@s@",sizeof aux);
		texto.push(L_aux);
	}
	
	MostrarTexto(texto);
}

void MostrarTexto(Cola<Pila<char>> texto)
{
	Pila<char> P_aux,Q_aux;
	bool saltar=false;
	
	while(!texto.vacia())
	{
		saltar=false;
		P_aux = texto.frente();
		
		while(!P_aux.vacia() && saltar==false)
		{
			char c = P_aux.tope();
			if(c=='@')
			{
				P_aux.pop();
			}
			else
			{
				if(c=='#')
				{
					saltar=true;
				}
				else
				{
					Q_aux.push(P_aux.tope());
				}
			}
			P_aux.pop();
		}
		
		while(!Q_aux.vacia())
		{
			cout << Q_aux.tope();
			Q_aux.pop();
		}
		
		if(!saltar)
		{
			cout << endl;
		}
		
		texto.pop();
	}
}











