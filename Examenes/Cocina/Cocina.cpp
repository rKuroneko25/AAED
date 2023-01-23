#include "ListaCab.h"
#include "Cocina.h"

kitchen::kitchen(unsigned max): len(max){}

bool kitchen::Cabe(mueble M) const
{
	bool fin=false,cabe=true;
	Lista<mueble>::posicion p=C.primera(),q;
	mueble M_aux1,M_aux2;
	
	if(M.d_inic+M.ancho<=len)
	{
		cabe=false;
	}
	else
	{
		while(p!=C.fin() && fin==false) 
		{
			M_aux1=C.elemento(p);
			
			if(M_aux1.d_inic<M.d_inic)
			{
				p=C.siguiente(p);
			}
			else
			{
				if(M_aux1.d_inic=M.d_inic)
				{
					fin=true;
					cabe=false;
				}
				else
				{
					if(p==C.primera())
					{
						if((M.d_inic+M.ancho)<=M_aux1.d_inic)
						{
							cabe=true;
							fin=true;
						}
						else
						{
							cabe=false;
							fin=true;
						}
					}
					else
					{
						q=C.anterior(p);
						M_aux2=C.elemento(q);
						
						if((M_aux2.d_inic+M_aux2.ancho)<=M.d_inic && (M.d_inic+M.ancho)<=M_aux1.d_inic)
						{
							fin=true;
							cabe=true;
						}
						else
						{
							cabe=false;
						}
					}	
				}
			}
		}
	}
	
	return cabe;
}

void kitchen::meteh(mueble M)
{
	if(Cabe(M))
	{
		bool fin=false;
		Lista<mueble>::posicion p=C.primera();
		mueble M_aux;
		
		while(p!=C.fin() && fin==false)
		{
			M_aux = C.elemento(p);
			if(M_aux.d_inic>M.d_inic)
			{
				p=C.anterior(p);
				fin=true;
			}
			else
			{
				p=C.siguiente(p);				
			}
		}
		C.insertar(M,p);
	}
}

mueble kitchen::devorve(unsigned pos) const
{
	Lista<mueble>::posicion p=C.primera();
	while(pos!=1)
	{
		pos--;
		p=C.siguiente(p);
	}
	
	return C.elemento(p);
}

void kitchen::quitah(unsigned pos)
{
	Lista<mueble>::posicion p=C.primera();
	while(pos!=1)
	{
		pos--;
		p=C.siguiente(p);
	}
	
	C.eliminar(p);
}

void kitchen::moveh(unsigned pos)
{
	Lista<mueble>::posicion p=C.primera();
	mueble M_aux1,M_aux2;
	
	while(pos!=1)
	{
		pos--;
		p=C.siguiente(p);
	}
	
	M_aux1=C.elemento(p);
	M_aux2=C.elemento(C.anterior(p));
	
	M_aux1.d_inic=M_aux2.d_inic+M_aux2.ancho;
}

kitchen::~kitchen()
{
	len = 0;
	C.~Lista();
}

