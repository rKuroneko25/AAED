#ifndef binario
#define binario

#include "ListaCab.h"
#include "Piladin.h"
#include <cstring>

#include <iostream>
using namespace std;

class Binario
{
public:
	Binario();
	Binario(char cad[]);
	Binario NOT() const;
	Binario AND(Binario B) const;
	Binario OR(Binario B) const;
	Binario XOR(Binario B) const;
	Binario SHL(int x) const;
	Binario SHR(int x) const;
	void mostrar() const;
private:
	Lista<bool> L;
};

Binario::Binario(){}

Binario::Binario(char cad[])
{
	Pila<char> P;
	for(unsigned i=0 ; i<strlen(cad) ; i++)
	{
		P.push(cad[i]);
	}
	while(!P.vacia())
	{
		if(P.tope()=='1')
		{
			L.insertar(true,L.fin());
		}
		else
		{
			L.insertar(false,L.fin());
		}
		P.pop();
	}
}

Binario Binario::NOT() const
{
	Binario R;
	typename Lista<bool>::posicion p = L.primera();
	while(p!=L.fin())
	{
		R.L.insertar(!L.elemento(p),R.L.fin());
		p = L.siguiente(p);
	}
	return R;
}

Binario Binario::AND(Binario B) const
{
	Binario R;
	typename Lista<bool>::posicion p = L.primera(),q = B.L.primera();
	while(p!=L.fin() || q!=B.L.fin())
	{
		if(p!=L.fin() && q!=B.L.fin())
		{
			R.L.insertar((L.elemento(p) && R.L.elemento(q)),R.L.fin());
			p = L.siguiente(p);
			q = B.L.siguiente(q);
		}
		else
		{
			if(q!=B.L.fin())
			{
				R.L.insertar(false,R.L.fin());
				q = B.L.siguiente(q);
			}
			else
			{
				R.L.insertar(false,R.L.fin());
				p = L.siguiente(p);
			}
		}	
	}
	return R;
}

Binario Binario::OR(Binario B) const
{
	Binario R;
	typename Lista<bool>::posicion p = L.primera(),q = B.L.primera();
	while(p!=L.fin() || q!=B.L.fin())
	{
		if(p!=L.fin() && q!=B.L.fin())
		{
			R.L.insertar((L.elemento(p) || R.L.elemento(q)),R.L.fin());
			p = L.siguiente(p);
			q = B.L.siguiente(q);
		}
		else
		{
			if(q!=B.L.fin())
			{
				R.L.insertar(R.L.elemento(q),R.L.fin());
				q = B.L.siguiente(q);
			}
			else
			{
				R.L.insertar(L.elemento(p),R.L.fin());
				p = L.siguiente(p);
			}
		}	
	}
	return R;
}

Binario Binario::XOR(Binario B) const
{
	Binario R;
	typename Lista<bool>::posicion p = L.primera(),q = B.L.primera();
	while(p!=L.fin() || q!=B.L.fin())
	{
		if(p!=L.fin() && q!=B.L.fin())
		{
			R.L.insertar((L.elemento(p) ^ R.L.elemento(q)),R.L.fin());
			p = L.siguiente(p);
			q = B.L.siguiente(q);
		}
		else
		{
			if(q!=B.L.fin())
			{
				R.L.insertar(R.L.elemento(q),R.L.fin());
				q = B.L.siguiente(q);
			}
			else
			{
				R.L.insertar(L.elemento(p),R.L.fin());
				p = L.siguiente(p);
			}
		}	
	}
	return R;
}

Binario Binario::SHL(int x) const
{
	Binario R;
	typename Lista<bool>::posicion p = L.primera();
	for(unsigned i=x ; i ; i--)
	{
		R.L.insertar(false,R.L.fin());
	}
	while(p!=L.fin())
	{
		R.L.insertar(L.elemento(p),R.L.fin());
		p = L.siguiente(p);
	}
	for(unsigned i=x ; i ; i--)
	{
		R.L.eliminar(R.L.anterior(R.L.fin()));
	}
	return R;
}

Binario Binario::SHR(int x) const
{
	Binario R;
	typename Lista<bool>::posicion p = L.primera();
	while(p!=L.fin())
	{
		R.L.insertar(L.elemento(p),R.L.fin());
		p = L.siguiente(p);
	}
	for(unsigned i=x ; i ; i--)
	{
		R.L.insertar(false,R.L.fin());
	}
	for(unsigned i=x ; i ; i--)
	{
		R.L.eliminar(R.L.primera());
	}
	return R;	
}

void Binario::mostrar() const
{
	Pila<bool> P;
	typename Lista<bool>::posicion p = L.primera();
	cout << "Resultado: ";
	while(p!=L.fin())
	{
		P.push(L.elemento(p));
		p = L.siguiente(p);
	}
	while(!P.vacia())
	{
		cout << P.tope();
		P.pop();
	}
	cout << endl;
}

#endif
