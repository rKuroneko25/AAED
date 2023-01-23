#include "Coladin.h"
#include "ListaCab.h"
#include "TockenBus.h"
#include "cstring"

Bus::Bus(Computer C)
{
	B.insertar(C,B.fin());
	n_eltos=1;
	Tocken=B.primera();	
}

void Bus::incluir(Computer C)
{
	if(n_eltos!=25)
	{
		B.insertar(C,B.fin());
	}
}

void Bus::eliminar()
{
	if(n_eltos!=1)
	{
		B.elemento(B.primera());
	}
}

void Bus::pass()
{
	if(B.siguiente(Tocken)==B.fin())
	{
		Tocken = B.primera();
	}
	else
	{
		Tocken = B.siguiente(Tocken);	
	}
}

Computer Bus::tocken() const
{
	return B.elemento(Tocken);
}

void Bus::Enviar_trama(Computer A, Computer b)
{
	while((memcmp(B.elemento(Tocken).id,A.id,sizeof A.id))!=0)
	{
		pass();
	}
	Lista<Computer>::posicion p=B.primera();
	bool encontrado=false;
	while(p!=B.fin() && encontrado==false)
	{
		if((memcmp(b.id,B.elemento(p).id,sizeof b.id))==0)
		{
			encontrado=true;
		}
		else
		{
			p=B.siguiente(p);
		}
	}
	
	if(encontrado && !B.elemento(Tocken).Buffer_salida.vacia())
	{
		B.elemento(p).Buffer_entrada.push(B.elemento(Tocken).Buffer_salida.frente());
		B.elemento(Tocken).Buffer_salida.pop();	
	}
}





