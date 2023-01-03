#include "lineaTxt.h"

#include <iostream>
using namespace std;

// CONSTRUCTOR
linea::linea(){}

// MOSTRAR LINEA
void linea::showline()
{
	cout << "\e[A";
	cout << "-> ";
	Pila<char> Aux;
	while(!P.vacia())
	{
		Aux.push(P.tope());
		P.pop();
	}
	while(!Aux.vacia())
	{
		cout << Aux.tope();
		P.push(Aux.tope());
		Aux.pop();
	}
	cout << "|";
	Aux=Q;
	while(!Q.vacia())
	{
		cout << Q.tope();
		Q.pop();
	}
	Q=Aux;
	cout << "    $";
}

// AVANZAR CURSOR
void linea::next()
{
	if(!Q.vacia())
	{
		P.push(Q.tope());
		Q.pop();
	}
}

// RETRASAR CURSOR
void linea::prev()
{
	if(!P.vacia())
	{
		Q.push(P.tope());
		P.pop();
	}
}

// IR AL FINAL
void linea::end()
{
	while(!Q.vacia())
	{
		P.push(Q.tope());
		Q.pop();
	}
}

// IR AL PRINCIPIO
void linea::home()
{
	while(!P.vacia())
	{
		Q.push(P.tope());
		P.pop();
	}
}

// BORRAR ANTERIOR
void linea::del()
{
	if(!P.vacia())
	{
		P.pop();
	}
}

// BORRAR POSICION CURSOR
void linea::supr()
{
	if(!Q.vacia())
	{
		Q.pop();
	}
}

// INSERTAR CARACTER
void linea::ins(char c)
{
	P.push(c);
}

// SOBREESCRIBIR CARACTER
void linea::overw(char c)
{
	P.push(c);
	if(!Q.vacia())
	{
		Q.pop();
	}
}

