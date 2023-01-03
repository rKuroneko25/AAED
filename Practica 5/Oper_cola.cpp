#include <iostream>
#include "Piladin.h"
#include "coladin.h"
#include "colapse.h"
#include "Aerodromo.h"
#include "Oper_cola.h"

bool ejercicio1(Pila<int> P,Cola<int> C)
{
	bool iso=true,cont=true;
	unsigned i;
	C.pop();
	
	while(!C.vacia() && !P.vacia() && cont)
	{
		if(C.frente()!=P.tope())
		{
			iso=false;
		}
	
		i=0;
		
		while(i<2 && cont)
		{	
			if(P.vacia() || C.vacia())
			{
				cont=false;
			}
			else
			{
				P.pop();
				C.pop();
			}
			i++;
		}
	}
	
	if(!P.vacia())
	{
		P.pop();
		if(!P.vacia())
		{
			iso=false;
		}
	}
	
	return iso;
}

Cola<int>& ejercicio2(Cola<int>& C,int a,int b)
{
	Pila<int> P;
	Cola<int> C2;
	unsigned i=0;
	
	while(C.frente()!=a)
	{
		C2.push(C.frente());
		C.pop();
		i++;
	}
	
	do
	{
		P.push(C.frente());
		C.pop();
	}while(P.tope()!=b);
	
	while(!C.vacia())
	{
		C2.push(C.frente());
		C.pop();
	}
	
	for (i ; i!=0 ; i--)
	{
		C.push(C2.frente());
		C2.pop();
	}
	
	while(!P.vacia())
	{
		C.push(P.tope());
		P.pop();
	}
	
	while(!C2.vacia())
	{
		C.push(C2.frente());
		C2.pop();
	}
	
	return C;
}

void ejercicio3(aerodromo& A,bool Op,int m)
{
	Coca<int> Aux(12);
	bool cont=true;
	
	if(Op)
	{
		if(!A.M.llena())
		{
			A.M.push(m);
		}
		else
		{
			A.E.push(m);
		}
	}
	else
	{
		while(cont && !A.M.vacia())
		{
			if(A.M.frente()!=m)
			{
				Aux.push(A.M.frente());
				A.M.pop();
			}
			else
			{
				A.M.pop();
				cont=false;
			}
		}
		while(!Aux.vacia())
		{
			A.M.push(Aux.frente());
			Aux.pop();
		}
		
		while(cont && !A.E.vacia())
		{
			if(A.E.frente()!=m)
			{
				Aux.push(A.E.frente());
				A.E.pop();
			}
			else
			{
				A.E.pop();
				cont=false;
			}
		}
		while(!Aux.vacia())
		{
			A.E.push(Aux.frente());
			Aux.pop();
		}	
	
		while(!A.M.llena() && !A.E.vacia())
		{
			A.M.push(A.E.frente());
			A.E.pop();
		}
	}
}



