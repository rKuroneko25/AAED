/*4. Repita los experimentos empleando un esquema adaptativo de medida y compruebe gr�ficamente que obtiene 
resultados similares. Considere que la resoluci�n del cron�metro es 1 �s y el m�ximo error relativo admitido 
0, 5 ppm = 0, 5 �s/s.*/

#include <iostream>
#include "ordenacion.h"
#include <algorithm>
#include <cstring>
#include "cronometro.h"

static void burbujea(int* i, int* j);
static void inserta(int* i, int* j);

const int n = 9;
const double e_abs = 1e-6,e_rel = 5e-7;
using namespace std;
cronometro c;

int main(){
	for (int n=1000 ; n<20001 ; n+=1000){
		
		int w[n]={0},x[n]={0},v[n]={0},r=0;
		
		for (int j=0 ; j<n ; j++){
			v[j]=j+1;
		}
		
		memcpy(w,v,sizeof v);
		double k = 0;
		
		c.activar();
		do{	
			memcpy(x,w,sizeof v);
			ordenacion_intercambio(x,x+n);
			random_shuffle(w,w+n);
			r++;
		}while(c.tiempo() < e_abs/e_rel+e_abs);
		c.parar();
		
		cout << "Za demorao " << c.tiempo()/r << " zesgundo" << endl;
	}
}

// Ordenaci�n por intercambio directo del rango [p, f).

void ordenacion_intercambio(int* p, int* f)
{
  for (int* i = p; i != f - 1; ++i)
    burbujea(i, f);
}

// Desciende el m�nimo del rango [i, j) 
// hasta la posici�n i.

static void burbujea(int* i, int* j)
{
  for (int* k = j - 1; k != i; --k) {
    if (*k < *(k - 1))
      std::swap(*k, *(k - 1));
  }
}
