
#include <cassert>
#include "polinom.h"

polinomio::polinomio(unsigned Max) : gradoMax(Max), pol(new double[Max+1])
{
	for( int i=0 ; i<=gradoMax ; i++)
	{
		pol[i]=0;
	}
}

polinomio::polinomio(const polinomio& poli) : gradoMax(poli.gradoMax), pol(new double[poli.gradoMax+1])
{
	for( int i=0 ; i<=gradoMax ; i++)
	{
		pol[i]=poli.pol[i];
	}
}

polinomio& polinomio::operator =(const polinomio& poli)
{
	if(this!=&poli)
	{
		delete[]pol;
		gradoMax=poli.gradoMax;
		pol=new double[gradoMax+1];
	
		for( int i=0 ; i<=gradoMax ; i++)
		{
			pol[i]=poli.pol[i];
		}
	}
	
	return *this;
}

unsigned polinomio::grado() const
{
	int i=gradoMax;
	bool fin=false;
	
	while (i>0 && fin==false)
	{
		if(pol[i]!=0)
		{
			fin=true;
		}
		i--;	
	}
	
	return i+1;
}

double polinomio::coeficiente(unsigned n) const
{	
	if(n>gradoMax)
	{
		return 0;
	}
	else
	{
		return pol[n];
	}
}

void polinomio::coeficiente(unsigned n, double c)
{
	assert(n<=gradoMax);
	pol[n]=c;		
}

polinomio::~polinomio()
{
	delete[]pol;
}








