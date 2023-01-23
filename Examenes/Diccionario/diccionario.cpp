#include "ListaCab.h"
#include "diccionario.h"
#include "string.h"

Diccionario::Diccionario(){}

void Diccionario::crear(char *Ing, char *Esp)
{
	Lista<traduccion>::posicion p=D.primera();
	traduccion aux,aux2;
	bool encontrado=false;
	
	while(p!=D.fin() && encontrado==false)
	{
		aux=D.elemento(p);
		if(!memcmp(aux.Ing,Ing,sizeof Ing))
		{
			encontrado=true;
		}
		else
		{
			p=D.siguiente(p);	
		}
	}
	
	if(encontrado)
	{
		bool repetido;
		Lista<char*>::posicion q=aux.Esp.primera();
		
		while(q!=aux.Esp.fin() && repetido==false)
		{
			if(!memcmp(aux.Esp.elemento(q),Esp,sizeof Esp))
			{
				repetido=true;
			}
			else
			{
				q=aux.Esp.siguiente(q);
			}
		}
		
		if(!repetido)
		{
			aux.Esp.insertar(Esp,aux.Esp.fin());
			D.elemento(p)=aux;
		}
	}
	else
	{
		memcpy(aux2.Ing,Ing,sizeof Ing);
		aux2.Esp.insertar(Esp,aux2.Esp.fin());
		D.insertar(aux2,D.fin());
	}
}

void Diccionario::eliminar(char Ing[], char Esp[])
{
	Lista<traduccion>::posicion p=D.primera();
	traduccion aux,aux2;
	bool encontrado=false;
	
	while(p!=D.fin() && encontrado==false)
	{
		aux=D.elemento(p);
		if(!memcmp(aux.Ing,Ing,sizeof Ing))
		{
			encontrado=true;
		}
		else
		{
			p=D.siguiente(p);	
		}
	}
	
	if(encontrado)
	{
		bool esta;
		Lista<char*>::posicion q=aux.Esp.primera();
		
		while(q!=aux.Esp.fin() && esta==false)
		{
			if(!memcmp(aux.Esp.elemento(q),Esp,sizeof Esp))
			{
				esta=true;
				aux.Esp.eliminar(q);
				D.elemento(p)=aux;
			}
			else
			{
				q=aux.Esp.siguiente(q);
			}
		}
			
		if(esta && aux.Esp.primera()==aux.Esp.fin())
		{
			D.eliminar(p);
		}
	}
}

const Lista<char*>& Diccionario::consultar(char Ing[]) const
{
	Lista<traduccion>::posicion p=D.primera();
	traduccion aux;
	bool encontrado=false;
	
	while(p!=D.fin() && encontrado==false)
	{
		aux=D.elemento(p);
		if(!memcmp(aux.Ing,Ing,sizeof Ing))
		{
			encontrado=true;
		}
		else
		{
			p=D.siguiente(p);	
		}
	}
	
	if(encontrado)
	{
		return D.elemento(p).Esp; // Al devolver por referencia constante no podemos devolver una variable local
	}
}

Diccionario::~Diccionario()
{
	D.~Lista();
}
