#ifndef E_S_Pilas
#define E_S_Pilas

#include "pila2.h"

void Entrada_cad(char* cad);
// Precondici�n: ---
// Postcondici�n: Devuelve una cadena de caracteres

void Salida_cad(bool b);
// Precondici�n: Recibe un booleano
// Postcondici�n: Muestra si se ha cumplido la condici�n

Pila<int> Entrada_3(int& a, int& b);
// Precondici�n: Recibe dos enteros
// Postcondici�n: Devuelve una pila e inicializa los enteros

void Salida_3(Pila<int> P);
// Precondici�n: Recibe una pila
// Postcondici�n: Muestra por pantalla el contenido de la pila

void Entrada_4(char* name);
// Precondici�n: Recibe el nombre de un fichero
// Postcondici�n: Introduce datos en un fichero

void Salida_4(char* name);
// Precondici�n: Recibe el nombre de un fichero
// Postcondicc�n: Muestra el fichero por pantalla

#endif
