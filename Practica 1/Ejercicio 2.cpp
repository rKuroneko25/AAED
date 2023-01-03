/*2. Escriba un programa que simule 10 000 000 de tiradas de un dado. Imprima las frecuencias
relativas que se obtienen para cada una de las caras. Emplee la función del ejercicio anterior.*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(){
	
	int a,b;
	float c [6]={0};
	srand(time(NULL));
	for (double i=0 ; i < 10000000 ; i++){
		a=1+rand()%(6);
		switch(a){
			case 1: c[0]++;break;
			case 2: c[1]++;break;
			case 3: c[2]++;break;
			case 4: c[3]++;break;
			case 5: c[4]++;break;
			case 6: c[5]++;break;
		}
	}
	
	cout << "Frecuencias relativas:" << setprecision(4) << endl;
	
	for (int i=0 ; i<6 ; i++){
		cout << i+1 << " -> " << c[i]/10000000 << endl; 
	}

}
