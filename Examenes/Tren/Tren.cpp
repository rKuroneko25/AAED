#include "Piladin.h"
#include "Tren.h"

tren::tren(){}

void tren::desp_izq()
{
	if(!Der.vacia())
	{
		Izq.push(Der.tope());
		Der.pop();
		if(Der.vacia())
		{
			Der.push(Izq.tope());
			Izq.pop();
		}
	}
}

void tren::desp_der()
{
	if(!Izq.vacia())
	{
		Der.push(Izq.tope());
		Izq.pop();
	}
}

void tren::BV()
{
	if(!Der.vacia())
	{
		Der.pop();
		if(Der.vacia() && !Izq.vacia())
		{
			Der.push(Izq.tope());
			Izq.pop();
		}
	}
}

vagon tren::OV() const
{
	return Der.tope();
}

bool tren::vacio() const
{
	return Der.vacia(); // La pila de la derecha no puede estar vacia a menos que el tren este vacio
}
