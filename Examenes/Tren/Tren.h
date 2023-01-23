#ifndef Tren
#define Tren

#include "Piladin.h"

struct vagon
{
	unsigned id;
};

class tren
{
public:
	tren();
	void desp_izq();
	void desp_der();
	void BV();
	vagon OV() const;
	bool vacio() const;
private:
	Pila<vagon>Izq,Der;
};

#endif
