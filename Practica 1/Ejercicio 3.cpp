/*3. Utilizando rand(), escriba una funci�n que genere un n�mero pseudoaleatorio de coma
flotante y precisi�n doble en el intervalo continuo [a, b].*/

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




