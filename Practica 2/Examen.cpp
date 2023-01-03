
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include "cronometro.h"
#include "ordenacion.h"

static void burbujea(int* i, int* j);
static void inserta(int* i, int* j);

const int N = 10;
using namespace std;
cronometro c;

int main(){
	
	int v[N]={0},w[N]={0},x[N]={0},j=0;
	double t=0;
	bool k = true;
	
	srand(time(NULL));
	
	for (int i=0 ; i < N ; i++){
		v[i]=i+1;
	}
	
	memcpy(w,v,sizeof v);
	
	while(j<100 && k == true){
		
		memcpy(x,w,sizeof v);
		c.activar();
		ordenacion_intercambio(x,x+N);
		c.parar();
		
		if(memcmp(v,x,sizeof v)==1){
			k = false;
			for (int n=0 ; n < N ; n++){
				cout << w[n] << " ";
			}
		}
		
		random_shuffle(w,w+N);
		
		t+=c.tiempo();
		j++;
	}
	
	if(k==true){
		cout << "El tiempo promedio es " << t/100 << " segundos" << endl;
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
