#ifndef diccionario
#define diccionario

#include "ListaCab.h"

class Diccionario
{
public:
	/* Constructor */
	Diccionario();
	
	/* Modificadoras */
	void crear(char Ing[], char Esp[]);
	void eliminar(char Ing[], char Esp[]);
	
	/* Observadoras*/
	const Lista<char*>& consultar(char Ing[]) const;
	
	/* Destructor */
	~Diccionario();
private:
	struct traduccion
	{
		char Ing[64];
		Lista<char*> Esp;
	};
	
	Lista<traduccion> D;
};

#endif
