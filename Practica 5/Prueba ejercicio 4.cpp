#include <iostream>
#include "pilabi.h"

using namespace std;

typedef char charmander; // Ayuda
void pie(Pilabi<charmander>);

int main()
{
	char cad[12] = {"frigorifico"};
	Pilabi<charmander> P,Q;
	for (unsigned i=0 ; cad[i]!='\0' ; i++)
	{
		P.push(cad[i]);
	}
	Q=P;
	pie(Q);
}

void pie(Pilabi<charmander> Q)
{
	while (!Q.vacia())
	{
		cout << Q.tope();
		Q.pop();
	}	
}
