#ifndef E_S_Pilas
#define E_S_Pilas

#include "pila2.h"

void Entrada_cad(char* cad);
// Precondición: ---
// Postcondición: Devuelve una cadena de caracteres

void Salida_cad(bool b);
// Precondición: Recibe un booleano
// Postcondición: Muestra si se ha cumplido la condición

Pila<int> Entrada_3(int& a, int& b);
// Precondición: Recibe dos enteros
// Postcondición: Devuelve una pila e inicializa los enteros

void Salida_3(Pila<int> P);
// Precondición: Recibe una pila
// Postcondición: Muestra por pantalla el contenido de la pila

void Entrada_4(char* name);
// Precondición: Recibe el nombre de un fichero
// Postcondición: Introduce datos en un fichero

void Salida_4(char* name);
// Precondición: Recibe el nombre de un fichero
// Postcondiccón: Muestra el fichero por pantalla

#endif
