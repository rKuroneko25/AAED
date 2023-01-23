#include "simbolo.h"

#include <iostream>
using namespace std;

sim::sim(){}

void sim::insertar(trazo T)
{
	S.insertar(T,S.fin());
}

void sim::ctrl_Z(unsigned n)
{
	while(S.primera()!=S.fin() && n!=0)
	{
		S.eliminar(S.anterior(S.fin()));
		n--;
	}
}

sim sim::sym_Y() const
{
	sim res;
	trazo aux;
	Lista<trazo>::posicion p=S.primera();
	while(p!=S.fin())
	{
		aux = S.elemento(p);
		if(aux.dir%2==0)
		{
			aux.dir = (aux.dir+2)%4;	
		}
		res.S.insertar(aux,res.S.fin());
		p=S.siguiente(p);
	}
	return res;
}

sim sim::sym_X() const
{
	sim res;
	trazo aux;
	Lista<trazo>::posicion p=S.primera();
	while(p!=S.fin())
	{
		aux = S.elemento(p);
		if(aux.dir%2!=0)
		{
			aux.dir = (aux.dir+2)%4;	
		}
		res.S.insertar(aux,res.S.fin());
		p=S.siguiente(p);
	}
	return res;
}

sim sim::sym_XY() const
{
	sim aux;
	aux = this->sym_X();
	aux = aux.sym_Y();
	return aux;
}

void sim::salida()
{
	Lista<trazo>::posicion p=S.primera();
	trazo aux;
	while(p!=S.fin())
	{
		aux = S.elemento(p);
		switch(aux.dir)
		{
			case 0: cout << "<- "; break;
			case 1: cout << "/\\ "; break;
			case 2: cout << "-> "; break;
			case 3: cout << "\\/ "; break;
		} 
		p = S.siguiente(p);
	}
}
