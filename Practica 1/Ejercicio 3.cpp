/*3. Utilizando rand(), escriba una función que genere un número pseudoaleatorio de coma
flotante y precisión doble en el intervalo continuo [a, b].*/

#include <iostream>
#include <ctime>


using namespace std;
double FF(double,double);

int main(){	
	double a=1,b=6;
	srand(time(NULL));
	
	for (int i=0 ; i<20 ; i++){
		cout << "el numero es: " << FF(a,b) << endl;
	}
}	

double FF(double a,double b){
	return a + ((double)rand() / RAND_MAX) * (b-a);
}




