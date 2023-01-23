#include "ListaCab.h"
#include "hospital.h"

Hospital::Hospital(unsigned Max_Planta, unsigned Max_UCI):
Max_P(Max_Planta), Max_U(Max_UCI), P_eltos(0), U_eltos(0)
{}

void Hospital::Ingreso(Paciente P)
{
	if(P.g!=0)
	{
		if(P.g>5)
		{
			if(P_eltos==Max_P)
			{
				Lista<Paciente>::posicion p=Planta.primera(),salir;
				unsigned i=0;
				while(p!=Planta.fin())
				{
					if(Planta.elemento(p).g>i)
					{
						i = Planta.elemento(p).g;
						salir = p;
					}
					p = Planta.siguiente(p);
				}	
				Planta.eliminar(salir);
				Planta.insertar(P,Planta.fin());
			}
			else
			{
				Planta.insertar(P,Planta.fin());
				P_eltos++;
			}
		}
		else
		{
			if(U_eltos==Max_U)
			{
				Lista<Paciente>::posicion p=UCI.primera(),salir;
				unsigned i=0;
				while(p!=UCI.fin())
				{
					if(UCI.elemento(p).g>i)
					{
						i = UCI.elemento(p).g;
						salir = p;
					}
					p = UCI.siguiente(p);
				}	
				if(P_eltos==Max_P)
				{
					Lista<Paciente>::posicion q=Planta.primera(),salir2;
					unsigned j=0;
					while(q!=Planta.fin())
					{
						if(Planta.elemento(q).g>j)
						{
							j = Planta.elemento(q).g;
							salir2 = q;
						}
						q = Planta.siguiente(q);
					}	
					Planta.eliminar(salir2);
					Planta.insertar(UCI.elemento(salir),Planta.fin());
					UCI.eliminar(salir);
					UCI.insertar(P,UCI.fin());
				}
				else
				{
					Planta.insertar(UCI.elemento(salir),Planta.fin());
					P_eltos++;
					UCI.eliminar(salir);
					UCI.insertar(P,UCI.fin());
				}
			}
			else
			{
				UCI.insertar(P,UCI.fin());
				U_eltos++;
			}
		}
	}
}

void Hospital::Alta(Paciente P)
{
	Lista<Paciente>::posicion p=Planta.primera();
	bool encontrado = false;
	while(p!=Planta.fin() && !encontrado)
	{
		if(Planta.elemento(p).id == P.id)
		{
			encontrado=true;
		}
		else
		{
			p=Planta.siguiente(p);
		}
	}
	if(encontrado)
	{
		Planta.eliminar(p);
		P_eltos--;
	}
	else
	{
		p=UCI.primera();
		while(p!=Planta.fin() && !encontrado)
		{
			if(Planta.elemento(p).id == P.id)
			{
				encontrado=true;
			}
			else
			{
				p=Planta.siguiente(p);
			}
		}	
		if(encontrado)
		{
			UCI.eliminar(p);
			U_eltos--;
			
			encontrado=false;
			p=Planta.primera();
			while(p!=Planta.fin() && !encontrado)
			{
				if(Planta.elemento(p).g<6)
				{
					encontrado=true;
				}
				else
				{
					p=Planta.siguiente(p);
				}
			}
			if(encontrado)
			{
				UCI.insertar(Planta.elemento(p),UCI.fin());
				U_eltos++;
				Planta.eliminar(p);
				P_eltos--;
			}
		}
	}
}

void Hospital::Muerte(Paciente P)
{
	Lista<Paciente>::posicion p=Planta.primera();
	bool encontrado = false;
	while(p!=Planta.fin() && !encontrado)
	{
		if(Planta.elemento(p).id == P.id)
		{
			encontrado=true;
		}
		else
		{
			p=Planta.siguiente(p);
		}
	}
	if(encontrado)
	{
		Planta.elemento(p).g=0;
		Morgue.insertar(Planta.elemento(p),Morgue.fin());
		Planta.eliminar(p);
		P_eltos--;
	}
	else
	{
		p=UCI.primera();
		while(p!=Planta.fin() && !encontrado)
		{
			if(Planta.elemento(p).id == P.id)
			{
				encontrado=true;
			}
			else
			{
				p=Planta.siguiente(p);
			}
		}	
		if(encontrado)
		{
			UCI.elemento(p).g=0;
			Morgue.insertar(UCI.elemento(p),Morgue.fin());
			UCI.eliminar(p);
			U_eltos--;
			
			encontrado=false;
			p=Planta.primera();
			while(p!=Planta.fin() && !encontrado)
			{
				if(Planta.elemento(p).g<6)
				{
					encontrado=true;
				}
				else
				{
					p=Planta.siguiente(p);
				}
			}
			if(encontrado)
			{
				UCI.insertar(Planta.elemento(p),UCI.fin());
				U_eltos++;
				Planta.eliminar(p);
				P_eltos--;
			}
		}
	}	
}

const Lista<Paciente>& Hospital::Pacientes_Planta() const
{
	return Planta;
}

const Lista<Paciente>& Hospital::Pacientes_UCI() const
{
	return UCI;
}

Lista<Paciente> Hospital::Pacientes_gr(unsigned grav) const
{
	Lista<Paciente> G;
	Lista<Paciente>::posicion p;
	while(p!=Planta.fin())
	{
		if(Planta.elemento(p).g==grav)
		{
			G.insertar(Planta.elemento(p),G.fin());
		}
		p=Planta.siguiente(p);
	}
	
	p=UCI.primera();
	while(p!=UCI.fin())
	{
		if(UCI.elemento(p).g==grav)
		{
			G.insertar(UCI.elemento(p),G.fin());
		}
		p=UCI.siguiente(p);
	}
	
	return G;
}

Hospital::~Hospital(){}

