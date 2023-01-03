#include <iostream>
#include "polinom.h"
#include "Arit_POL.h"

polinomio operator +(const polinomio& a, const polinomio& b)
{
	unsigned max;
	double d;
	
	if(a.grado() > b.grado())
	{
		max = a.grado();
	}
	else
	{
		max = b.grado();
	}
	
	polinomio c(max);
	
	for(int i=0 ; i<max+1 ; i++)
	{
		d = a.coeficiente(i)+b.coeficiente(i);
		c.coeficiente(i,d);	
	}
	
	return c;
}

polinomio operator -(const polinomio& a, const polinomio& b)
{
	unsigned max;
	double d;
	
	if(a.grado() > b.grado())
	{
		max = a.grado();
	}
	else
	{
		max = b.grado();
	}
	
	polinomio c(max);
	
	for(int i=0 ; i<max+1 ; i++)
	{
		d = a.coeficiente(i)-b.coeficiente(i);
		c.coeficiente(i,d);	
	}
	
	return c;
}

polinomio operator *(const polinomio& a, const polinomio& b)
{
	unsigned max = a.grado() + b.grado();
	polinomio c(max);
	double d;
	
	for(int i=0 ; i<a.grado()+1 ; i++)
	{
		for(int j=0 ; j<b.grado()+1 ; j++)
		{
			d = a.coeficiente(i)*b.coeficiente(j);
			c.coeficiente(i+j,c.coeficiente(i+j)+d);
		}
	}
	
	return c;
}

polinomio derivar(const polinomio& a)
{
	unsigned max = a.grado(); 
	double c;
	int i;
	
	polinomio b(max);
	for(i=0 ; i<max ; i++)
	{
		c = a.coeficiente(i+1)*(i+1);
		b.coeficiente(i,c);
	}
	b.coeficiente(i,0);

	return b;
}





