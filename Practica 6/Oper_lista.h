#ifndef Oper_lista
#define Oper_lista

#include "ListaCab.h"
#include "Lista_Ord.h"

void obliterar(Lista<int>& L, unsigned x);
//Pre: Recibe una lista "L" de enteros y un entero "x"
//Post: Elimina todas las existencias del entero "x" en la lista "L"

Listaord<int> mezcla(Listaord<int>& L1, Listaord<int>& L2);
//Pre: Recibe dos listas de enteros
//Post: Devuelve una lista con la mezcla de los elementos de las dos listas

void ImprimeInverso(Lista<int>& L, Lista<int>::posicion p);
//Pre: Recibe una lista de enteros "L" y una posicion "p"
//Post: Imprime por pantalla de forma inversa los enteros de la lista "L" a partir de la posicion "p"

void conjunto();
//Pre: ---
//Post: ---

template <typename T> Lista<T> concatenar(const Lista<Lista<T>>& LInic);
//Pre: Recibe una Lista de Listas de enteros "LInic"
//Post: Devuelve una lista de enteros con los elementos concatenados de todas las listas de la lista "LInic"

void binary();
//Pre: ---
//Post: ---

#endif
