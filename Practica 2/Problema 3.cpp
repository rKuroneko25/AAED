/*3. Analice empíricamente los algoritmos del primer ejercicio en el caso promedio. Utilice
permutaciones aleatorias de un vector de enteros que contenga los n primeros números
naturales, donde n variará desde 1 000 hasta 20 000 en incrementos de 1 000.*/

#include <iostream>
#include "ordenacion.h"
#include <algorithm>
#include <cstring>
#include "cronometro.h"

static void burbujea(int* i, int* j);
static void inserta(int* i, int* j);

const int n = 9;
using namespace std;
cronometro c;

int main(){
	for (int n=1000 ; n<20001 ; n+=1000){
		
		int w[n]={0},x[n]={0},v[n]={0};
		
		for (int j=0 ; j<n ; j++){
			v[j]=j+1;
		}
		
		memcpy(w,v,sizeof v);
		double k = 0;
		
		for(int i = 0 ; i<100 ; i++){		
			memcpy(x,w,sizeof v);
			c.activar();
			ordenacion_intercambio(x,x+n);
			c.parar();
			random_shuffle(w,w+n);
			k+=c.tiempo();
		}
		
		cout << "Za demorao " << k/100 << " zesgundo" << endl;
	}
}

// Ordenación por intercambio directo del rango [p, f).

void ordenacion_intercambio(int* p, int* f)
{
  for (int* i = p; i != f - 1; ++i)
    burbujea(i, f);
}

// Desciende el mínimo del rango [i, j) 
// hasta la posición i.

static void burbujea(int* i, int* j)
{
  for (int* k = j - 1; k != i; --k) {
    if (*k < *(k - 1))
      std::swap(*k, *(k - 1));
  }
}
