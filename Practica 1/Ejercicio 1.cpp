/*1. Utilizando rand(), escriba una funci�n que genere un n�mero pseudoaleatorio entero en el
intervalo discreto [a, b].*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
	
	int a,b;
	srand(time(NULL));
	cout << "eres realmente insano " << 1+rand()%(6) << " veces" << endl;
	
}
