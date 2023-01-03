#include "pila2.h"
#include "lineaTxt.h"
#include "Oper_pila.h"
#include "flujo.h"
#include <iostream>

using namespace std;

bool ejercicio1(char* cad)
{
	unsigned i=0;
	Pila<char> P;
	bool igual=true,aspersan=false;
	
	while(cad[i]!='\0' && aspersan!=true)
	{
		P.push(cad[i]);
		i++;
		if(cad[i]=='&')
		{
			aspersan=true;
		}
	}
	
	if(aspersan==true){
		i++;
		while(cad[i]!='\0' && igual==true)
		{
			if(!P.vacia())
			{
				if(cad[i]!=P.tope())
				{
					igual=false;
				}
				else
				{
					P.pop();
					i++;	
				}
			}
			else
			{
				igual=false;
			}
		}
		if(!P.vacia())
		{
			igual=false;
		}
	}
	else
	{
		igual=false;
	}
	
	return igual;
}

bool ejercicio2 (char* kad)
{
	bool ta_bien=true;
	unsigned j=0,i=0;
	char cad2[64]={0};
	
	while(kad[j]!='\0' && ta_bien==true)
	{
		while(kad[j]!='#' && kad[j]!='\0')
		{
			cad2[i]=kad[j];
			j++;
			i++;
		}
		cad2[i] = '\0';
		ta_bien = ejercicio1(cad2);
		i=0;
		j++;
	}
	
	return ta_bien;
}

Pila<int> ejercicio3(Pila<int>& P, unsigned a, unsigned b)
{
	int eltos[50];
	unsigned i=0,j=0;
	Pila<int> Q;
	bool seguir=true;
	
	while(P.tope()!=a)
	{
		Q.push(P.tope());
		P.pop();
	}
	
	while(seguir)
	{
		eltos[i]=P.tope();
		P.pop();
		if(eltos[i]==b)
		{
			seguir = false;
		}
		i++;
	}
	
	while(j!=i)
	{
		P.push(eltos[j]);
		j++;
	}
	
	while(!Q.vacia())
	{
		P.push(Q.tope());
		Q.pop();
	}
	
	return P;
}

void ejercicio4(char* name)
{
	fstream f(name,fstream::out | fstream::in);
	Pila<int> P,Q,R;
	int aux=0;
	
	f >> P >> Q;
	
	while (!P.vacia() || !Q.vacia())
	{
		if(P.vacia())
		{
			R.push(Q.tope()+aux);
			Q.pop();
		}
		else
		{
			if(Q.vacia())
			{
				R.push(P.tope()+aux);
				P.pop();
			}
			else
			{		
				if ((P.tope()+Q.tope()+aux)>=10)
				{
					R.push(P.tope()+Q.tope()-10+aux);
					P.pop();
					Q.pop();
					aux=1;
				}
				else
				{
					R.push(P.tope()+Q.tope()+aux);
					P.pop();
					Q.pop();
					aux=0;
				}
			}
		}
	}
	f << R;
	f.close();
}

void ejercicio5()
{
	unsigned select;
	char c;
	linea L;
	
	cout << "+---------------------------------------------+" << endl; 
	cout << "| (0) Exit (1) Next (2) Prev (3) Home (4) End |" << endl; 
	cout << "|  (5) Del (6) Supr (7) Insert (8) Overwrite  |" << endl; 
	cout << "+---------------------------------------------+" << endl << endl;
	L.showline();	
	
	do
	{
		cin >> select;
		switch(select)
		{
			case 0: break;
			case 1: L.next(); break;
			case 2: L.prev(); break;
			case 3: L.home(); break;
			case 4: L.end(); break;
			case 5: L.del(); break;
			case 6: L.supr(); break;
			case 7: cin >> c; L.ins(c); break;
			case 8: cin >> c; L.overw(c); break;
			default: cout << "[ Seleccion erronea ]" << endl; break;
		}
		if(select) L.showline();
	}while(select);
}



