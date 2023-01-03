
#ifndef Aritmetica
#define Aritmetica

polinomio operator +(const polinomio& a, const polinomio& b);
//Precondición: -
//Postcondición: Devuelve la suma de los dos polinomios

polinomio operator -(const polinomio& a, const polinomio& b);
//Precondición: -
//Postcondición: Devuelve la resta de los dos polinomios

polinomio operator *(const polinomio& a, const polinomio& b);
//Precondición: -
//Postcondición: Devuelve la multiplicación de los dos polinomios

polinomio derivar(const polinomio& a);
//Precondición: -
//Postcondición: Devuelve la derivada del polinomio

#endif
