#ifndef flujo
#define flujo

#include "pila2.h"
#include <fstream>
using namespace std;

// Apila en P los valores n�mericos de los d�gitos
// extra�dos del flujo de entrada fe
fstream& operator >>(fstream& fe, Pila<int>& P)
{
	char cifra;
	while (fe.get( cifra ) && cifra != '\n') // leer caracteres hasta fin de l�nea
		P.push(cifra -= '0'); // convierte un d�gito en su valor num�rico
	return fe;
}

// Inserta en el flujo de salida fs la pila P
fstream& operator <<(fstream& fs, Pila<int> P)
{
	while (!P.vacia()){
		fs << P.tope();
		P.pop();
	}
	fs << endl;
	return fs;
}

#endif
