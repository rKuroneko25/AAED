#ifndef hospital
#define hospital

#include "ListaCab.h"

struct Paciente
{
	unsigned id;
	unsigned g;
};

class Hospital
{
public:
	/* Constructor */
	Hospital(unsigned Max_Planta, unsigned Max_UCI);
	
	/* Modificadoras */
	void Ingreso(Paciente P);
	void Alta(Paciente P);
	void Muerte(Paciente P);
	
	/* Observadoras */
	const Lista<Paciente>& Pacientes_UCI() const;
	const Lista<Paciente>& Pacientes_Planta() const;
	Lista<Paciente> Pacientes_gr(unsigned grav) const;
	
	/* Destructor */
	~Hospital();
private:
	Lista<Paciente> UCI, Planta,Morgue;
	unsigned Max_P, Max_U;
	unsigned P_eltos, U_eltos;
};

#endif



