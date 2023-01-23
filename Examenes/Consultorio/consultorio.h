#ifndef consultorio
#define consultorio

#include "Coladin.h"
#include "ListaCab.h"

struct paciente
{
	unsigned id;
};

struct medico
{
	unsigned id;
	Cola<paciente> espera;
};

class Consultorio
{
public:
	Consultorio();
	void dadealta(medico med);
	void dadebaja(unsigned ID_m);
	void asecola(paciente pac, unsigned ID_m);
	unsigned quienva(unsigned ID_m) const;
	void pasamiloco(unsigned ID_m);
	bool medicocupao(unsigned ID_m) const;
private:
	Lista<medico> C;
};

#endif
