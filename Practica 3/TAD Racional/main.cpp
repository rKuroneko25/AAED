#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
	racional a(1,2),b(1,2);
	
	a/=b; 
	
	cout << "\n           " << a.num() << "/" << a.den() << endl;
}
