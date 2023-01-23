#ifndef TockenBus
#define TockenBus

#include "Coladin.h"
#include "ListaCab.h"

typedef char* trama;

struct Computer
{
	char id[9];
	Cola<trama> Buffer_entrada, Buffer_salida;
};

class Bus
{
public:
	Bus(Computer C);
	void incluir(Computer C);
	void eliminar();
	void pass();
	Computer tocken() const;
	void Enviar_trama(Computer A, Computer B);
private:
	Lista<Computer> B;
	Lista<Computer>::posicion Tocken;
	unsigned n_eltos;
};

#endif
