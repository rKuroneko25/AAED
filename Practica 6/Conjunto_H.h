#ifndef Conjunto_H
#define Conjunto_H

#include "ListaCab.h"

template <typename T> class Conjunto
{
public:
	typedef typename Lista<T>::posicion posicion;
	
	// Constructor
	Conjunto(){};

	// Funciones de consulta
	bool vacio();

	// Funciones para modificar el conjunto
	void insertar(const T& x);
	void eliminar(const T& x);
	
	// Funciones para operar con conjuntos
	const Conjunto<T> union_(const Conjunto& C);
	const Conjunto<T> interseccion(const Conjunto& C);
	const Conjunto<T> diferencia(const Conjunto& C);
	
	// Funciones para acceder al conjunto
	const T& elemento(posicion p) const;
	posicion siguiente(posicion p) const;
	posicion anterior(posicion p) const;
	posicion primera() const;
	posicion fin() const;
	
private:
	Lista<T> L;
};

// VACIO
template <typename T>
inline bool Conjunto<T>::vacio()
{
	return (L.primera() == L.fin());
}

// INSERTAR
template <typename T>
inline void Conjunto<T>::insertar(const T& x)
{
	posicion p = L.primera();
	bool esta=false;
	
	while(p!=L.fin() && !esta)
	{
		if(L.elemento(p)==x)
		{
			esta = true;
		}
		p = L.siguiente(p);
	}
	
	if(!esta)
	{
		L.insertar(x,L.fin());
	}
}

// ELIMINAR
template <typename T>
inline void Conjunto<T>::eliminar(const T& x)
{
	posicion p = L.primera();
	while(p!=L.fin())
	{
		if(L.elemento(p)==x)
		{
			L.eliminar(p);
		}
		else
		{
			p = L.siguiente(p);
		}
	}
}

// UNION
template <typename T>
inline const Conjunto<T> Conjunto<T>::union_(const Conjunto& C)
{
	Conjunto<T> R;
	posicion p;
	bool esta;
	
	for(p = L.primera() ; p!=L.fin() ; p = L.siguiente(p))
	{
		R.insertar(L.elemento(p));
	}
	
	
	for(p = C.primera() ; p!=C.fin() ; p = C.siguiente(p))
	{	
		R.insertar(C.elemento(p));
	}
	
	return R;
}

// INTERSECCION
template <typename T>
inline const Conjunto<T> Conjunto<T>::interseccion(const Conjunto& C)
{
	Conjunto<T> R;
	posicion p,q;
	bool repe;
	
	for(p = L.primera() ; p!=L.fin() ; p = L.siguiente(p))
	{
		repe = false;
		for(q = C.primera() ; q!=C.fin() && !repe ; q = C.siguiente(q))
		{
			if(L.elemento(p)==C.elemento(q))
			{
				repe = true;
			}
		}
		
		if(repe)
		{
			R.insertar(R.elemento(p));
		}
	}
	
	return R;
}

// DIFERENCIA
template <typename T>
inline const Conjunto<T> Conjunto<T>::diferencia(const Conjunto& C)
{
	Conjunto<T> R;
	posicion p,q;
	bool repe;
	
	for(p = L.primera() ; p!=L.fin() ; p = L.siguiente(p))
	{
		repe = false;
		for(q = C.primera() ; q!=C.fin() && !repe ; q = C.siguiente(q))
		{
			if(L.elemento(p)==C.elemento(q))
			{
				repe = true;
			}
		}
		
		if(!repe)
		{
			R.insertar(R.elemento(p));
		}
	}
	
	return R;
}

// ELEMENTO
template<typename T>
inline const T& Conjunto<T>::elemento(posicion p) const
{
	return L.elemento(p);
}

// SIGUIENTE
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::siguiente(posicion p) const
{
	return L.siguiente(p);
}

// ANTERIOR
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::anterior(posicion p) const
{
	return L.anterior(p);
}

// PRIMERA
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::primera() const
{
	return L.primera();
}

// FIN
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::fin() const
{
	return L.fin();
}

#endif
