#include "Coladin.h"
#include "ListaCab.h"
#include "consultorio.h"

Consultorio::Consultorio(){}

void Consultorio::dadealta(medico med)
{
	Lista<medico>::posicion p=C.primera();
	bool esta=false;
	medico m_aux;
	
	while(p!=C.fin() && esta==false)
	{
		m_aux = C.elemento(p);
		if(m_aux.id == med.id)
		{	
			esta = true;
		}
		else
		{
			p=C.siguiente(p);
		}
	}
	
	if(!esta)
	{
		C.insertar(med,C.fin());
	}

}

void Consultorio::dadebaja(unsigned ID_m)
{
	Lista<medico>::posicion p=C.primera();
	medico m_aux;
	bool salir=false;
	
	while(p!=C.fin() && salir==false)
	{
		m_aux = C.elemento(p);
		if(m_aux.id == ID_m)
		{
			C.eliminar(p);
			salir = true;
		}
		else
		{
			p=C.siguiente(p);
		}
	}
}

void Consultorio::asecola(paciente pac, unsigned ID_m)
{
	Lista<medico>::posicion p=C.primera();
	bool salir=false;
	medico m_aux;
	
	while(p!=C.fin() && salir==false)
	{
		m_aux = C.elemento(p);
		if(m_aux.id == ID_m)
		{	
			m_aux.espera.push(pac);
			C.elemento(p) = m_aux;
			salir=true;
		}
		else
		{
			p=C.siguiente(p);
		}
	}
}

unsigned Consultorio::quienva(unsigned ID_m) const
{
	Lista<medico>::posicion p=C.primera();
	bool salir=false;
	medico m_aux;
	paciente p_aux;
	unsigned next=0;
	
	while(p!=C.fin() && salir==false)
	{
		m_aux = C.elemento(p);
		if(m_aux.espera.vacia())
		{
			salir=true;
		}
		else
		{
			if(m_aux.id == ID_m)
			{	
				p_aux=m_aux.espera.frente();
				next=p_aux.id;
				salir=true;
			}
			else
			{
				p=C.siguiente(p);
			}
		}
	}
	
	return next;
}

void Consultorio::pasamiloco(unsigned ID_m)
{
	Lista<medico>::posicion p=C.primera();
	bool salir=false;
	medico m_aux;
	unsigned next=0;
	
	while(p!=C.fin() && salir==false)
	{
		m_aux = C.elemento(p);
		if(m_aux.id == ID_m)
		{	
			m_aux.espera.pop();
			C.elemento(p) = m_aux;
			salir=true;
		}
		else
		{
			p=C.siguiente(p);
		}
	}
}

bool Consultorio::medicocupao(unsigned ID_m) const
{
	Lista<medico>::posicion p=C.primera();
	bool salir=false, vacio=false;
	medico m_aux;
	unsigned next=0;
	
	while(p!=C.fin() && salir==false)
	{
		m_aux = C.elemento(p);
		if(m_aux.id == ID_m)
		{	
			if(m_aux.espera.vacia())
			{
				vacio=false;
			}
			else
			{
				vacio=true;
			}
			salir=true;
		}
		else
		{
			p=C.siguiente(p);
		}
	}	

	return vacio;
}







