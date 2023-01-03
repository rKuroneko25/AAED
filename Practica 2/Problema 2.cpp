/*2. Realice pruebas de caja negra sobre los algoritmos del ejercicio anterior con las técnicas
explicadas en la práctica 2. Utilice como batería de pruebas vectores de n enteros: varíe n
desde 1 hasta 9 y pruebe todas las permutaciones de cada vector.*/

#include <iostream>
#include "ordenacion.h"
#include <algorithm>
#include <cstring>
#include <Windows.h>

static void burbujea(int* i, int* j);
static void inserta(int* i, int* j);

using namespace std;

int main(){
	for (int n=1 ; n<10 ; n++){
		int w[n]={0},x[n]={0},v[n]={0};
		int i=1;
		for (int j=0 ; j<n ; j++){
			v[j]=j+1;
		}
		memcpy(w,v,sizeof v);
		do{
			memcpy(x,w,sizeof v);
			ordenacion_intercambio(x,x+n);
			if(memcmp(x,v,sizeof v)==0){
				cout << "ta bien " << i << endl;
				Sleep(1);
			}
			else{
				cout << "no ta bien " << i << endl; 
			}
			i++;
		}while(next_permutation(w,w+n));
		cout << endl << "---------------------------" << endl << "---------------------------" << endl << endl;
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
