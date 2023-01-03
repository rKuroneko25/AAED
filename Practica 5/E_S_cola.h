#include "Piladin.h"
#include "coladin.h"
#include "colapse.h"
#include "Aerodromo.h"

#ifndef E_S_cola
#define E_S_cola

void entrada_pila(Pila<int>&);
//Precondicion: Recibe una pila 
//Postcondicion: Mete valores a la pila

void entrada_cola(Cola<int>&);
//Precondicion: Recibe una cola 
//Postcondicion: Mete valores a la cola

void salida1(bool ta_bien);
//Precondicion: Recibe un booleano
//Postcondicion: Muestra por pantalla si es o no isomorfica

void entrada_2(Cola<int>& C, int& a, int& b);
//Precondicion: Recibe una cola y dos enteros por referencia
//Postcondicion: Mete valores a la cola y los enteros

void salida_2(Cola<int>& C);
//Precondicion: Recibe la cola
//Postcondicion: Muestra por pantalla la cola

bool entrada_3(int& a);
//Precondicion: Recibe un entero por referencia
//Postcondicion: Devuelve un booleano y cambia el valor del entero

void salida_3(aerodromo A);
//Precondion: Recibe la estructura aerodromo
//Postcondion: Muestra por pantalla las pilas de la clase aerodromo

#endif





