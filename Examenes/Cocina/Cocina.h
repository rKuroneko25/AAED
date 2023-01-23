#ifndef cocina
#define cocina

#include "ListaCab.h"

struct mueble
{
	unsigned d_inic;
	unsigned ancho;
	mueble(unsigned dist=0, unsigned width=0): d_inic(dist), ancho(width){} 
};

class kitchen
{
public:
	kitchen(unsigned max);
	bool Cabe(mueble M) const;
	void meteh(mueble M);	
	mueble devorve(unsigned pos) const;
	void quitah(unsigned pos);
	void moveh(unsigned pos);
	~kitchen();
private:
	unsigned len;
	Lista<mueble> C;
};

#endif
