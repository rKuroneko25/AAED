#include "Piladin.h"
#include "coladin.h"
#include "colapse.h"
#include "Aerodromo.h"

#ifndef Oper_cola
#define Oper_cola

bool ejercicio1(Pila<int> P,Cola<int> C);
//Precondicion: Recibe una Pila y una Cola
//Postcondicion: Devuelve true si la pila es ismorfica y false si no lo es

Cola<int>& ejercicio2(Cola<int>& C,int a,int b);
//Precondicion: Recibe una cola de enteros y dos enteros
//Postcondicion: Invierte los elementos de la cola entre la primera aparicion de a y b

void ejercicio3(aerodromo& A,bool Op,int m);
//Precondicion: Recive la estructura aerodromo un bool de operacion y un matricula (entero)
//Postcondicion: Simula la entrada o la salida de una avioneta en el aerodromo

#endif
