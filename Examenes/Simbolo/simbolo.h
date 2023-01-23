#ifndef simbolo
#define simbolo

#include "ListaCab.h"

struct trazo
{
	unsigned dir; // 0=izquierda 1=arriba 2=derecha 3=abajo
};

class sim
{
public:
	sim();
	void insertar(trazo T);
	void ctrl_Z(unsigned n);
	sim sym_X() const;
	sim sym_Y() const;
	sim sym_XY() const;
	void salida();
private:
	Lista<trazo> S;
};

#endif
