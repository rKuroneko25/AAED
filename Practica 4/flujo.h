#ifndef flujo
#define flujo

#include "pila2.h"
#include <fstream>
using namespace std;

// Apila en P los valores númericos de los dígitos
// extraídos del flujo de entrada fe
fstream& operator >>(fstream& fe, Pila<int>& P)
{
	char cifra;
	while (fe.get( cifra ) && cifra != '\n') // leer caracteres hasta fin de línea
		P.push(cifra -= '0'); // convierte un dígito en su valor numérico
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
