#ifndef Oper_pila
#define Oper_pila

#include "pila2.h"

bool ejercicio1(char* cad);
// Precondici�n: Recibe una cadena de caracteres que contiene uno o ningun &
// Postcondici�n: Devuelve true si en una cadena de la forma X&Y, X es el inverso de Y

bool ejercicio2(char* cad);
// Precondici�n: Recibe una cadena de caracteres que contiene uno o ningun #
// Postcondici�n: Devuelve true si en una cadena de la forma A#B#C#D, siendo A,B,C,D de la forma X&Y

Pila<int> ejercicio3(Pila<int>& P, unsigned a, unsigned b);
// Precondici�n: Recibe una pila no vacia y dos enteros
// Postcondici�n: Invierte los numeros de la pila que hay entre la primera aparicion de los enteros dados

void ejercicio4(char* name);
// Precondici�n: Recibe el nombre de un fichero
// Postcondici�n: Introduce en la fila 3 de un fichero la suma de las dos primeras

void ejercicio5();
// Precondici�n: ---
// Postcondici�n: Simula una linea de texto interactiva

#endif
