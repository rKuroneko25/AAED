#ifndef Oper_pila
#define Oper_pila

#include "pila2.h"

bool ejercicio1(char* cad);
// Precondición: Recibe una cadena de caracteres que contiene uno o ningun &
// Postcondición: Devuelve true si en una cadena de la forma X&Y, X es el inverso de Y

bool ejercicio2(char* cad);
// Precondición: Recibe una cadena de caracteres que contiene uno o ningun #
// Postcondición: Devuelve true si en una cadena de la forma A#B#C#D, siendo A,B,C,D de la forma X&Y

Pila<int> ejercicio3(Pila<int>& P, unsigned a, unsigned b);
// Precondición: Recibe una pila no vacia y dos enteros
// Postcondición: Invierte los numeros de la pila que hay entre la primera aparicion de los enteros dados

void ejercicio4(char* name);
// Precondición: Recibe el nombre de un fichero
// Postcondición: Introduce en la fila 3 de un fichero la suma de las dos primeras

void ejercicio5();
// Precondición: ---
// Postcondición: Simula una linea de texto interactiva

#endif
