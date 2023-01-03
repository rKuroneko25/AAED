/*5. Escriba un programa que genere 10 000 000 de permutaciones pseudoaleatorias de los 6
primeros números naturales e imprima cuántas de ellas están ordenadas*/

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
	int a=0,v[6]={1,2,3,4,5,6},w[6];
	memcpy(w,v,sizeof v);
	for(double i=0 ; i<10000000 ; i++){
		random_shuffle(v,v+6);
		if (memcmp(w,v,sizeof v)==0){
			a++;
		}
	}
	cout << "Hay " << a << " permutaciones ordenadas" << endl;
}
