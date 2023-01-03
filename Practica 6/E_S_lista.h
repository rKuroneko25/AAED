#ifndef E_S_lista
#define E_S_lista

#include "ListaCab.h"
#include "Lista_Ord.h"

int Entrada_1(Lista<int>& L);
//Pre: Recibe una lista de enteros por referencia
//Post: Introduce datos en la lista y devuelve un entero

void Salida_lista(Lista<int> L);
//Pre: Recibe una lista de enteros
//Post: Muestra por pantalla su contenido

void Entrada_2(Listaord<int>& L1, Listaord<int>& L2);
//Pre: Recibe dos listas de enteros por referencia
//Post: Introduce datos en las dos listas

void Salida_listaord(Listaord<int> L);
//Pre: Recibe una lista ordenada de enteros
//Post: Muestra por pantalla su contenido

Lista<int>::posicion Entrada_3(Lista<int>& L);
//Pre: Recibe una lista de enteros "L"
//Post: Devuelve una posicion e introduce elementos a la lista "L"

void Entrada_7(Lista<Lista<int>>& L);
//Pre: Recibe una lista de listas de enteros "L"
//Post: Introduce elementos a la lista "L"

#endif
