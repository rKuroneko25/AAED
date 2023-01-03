/*4. Escriba un programa que genere 10 000 000 de números pseudoaleatorios de precisión doble en el intervalo [0, 1] 
e imprima la media de los valores y = 4 ·v 1 - x 2 correspondientes a cada número x. Emplee la función del ejercicio anterior.*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	
	long double a,b=0;
	srand(time(NULL));
	
	for (double i=0 ; i < 10000000 ; i++){
		a = 0 + (float) (rand()) / (RAND_MAX);
		b = b + 4*sqrt(1-(a*a));
	}
	
	cout << b/10000000 << endl;
}	
