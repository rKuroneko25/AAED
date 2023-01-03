
#ifndef Aritmetica
#define Aritmetica

polinomio operator +(const polinomio& a, const polinomio& b);
//Precondici�n: -
//Postcondici�n: Devuelve la suma de los dos polinomios

polinomio operator -(const polinomio& a, const polinomio& b);
//Precondici�n: -
//Postcondici�n: Devuelve la resta de los dos polinomios

polinomio operator *(const polinomio& a, const polinomio& b);
//Precondici�n: -
//Postcondici�n: Devuelve la multiplicaci�n de los dos polinomios

polinomio derivar(const polinomio& a);
//Precondici�n: -
//Postcondici�n: Devuelve la derivada del polinomio

#endif
