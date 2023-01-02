#ifndef Lista_Ord
#define Lista_Ord

#include "ListaCab.h"

template <typename T> class Listaord
{
public:
	typedef typename Lista<T>::posicion posicion;
	Listaord() {};
	void insertar(const T& x);
	void eliminar(posicion p);
	const T& elemento(posicion p) const;
	posicion siguiente(posicion p) const;
	posicion anterior(posicion p) const;
	posicion primera() const;
	posicion fin() const;
private:
	Lista<T> L;
};

template<typename T>
inline void Listaord<T>::insertar(const T& x)
{
	posicion p = L.primera();
	while(p!=L.fin() && L.elemento(p)<x)
	{
		p = L.siguiente(p);
	}
	L.insertar(x,p);
}

template<typename T>
inline void Listaord<T>::eliminar(posicion p)
{
	L.eliminar(p);
}

template<typename T>
inline const T& Listaord<T>::elemento(posicion p) const
{
	return L.elemento(p);
}

template<typename T>
inline typename Listaord<T>::posicion Listaord<T>::siguiente(posicion p) const
{
	return L.siguiente(p);
}

template<typename T>
inline typename Listaord<T>::posicion Listaord<T>::anterior(posicion p) const
{
	return L.anterior(p);
}

template<typename T>
inline typename Listaord<T>::posicion Listaord<T>::primera() const
{
	return L.primera();
}

template<typename T>
inline typename Listaord<T>::posicion Listaord<T>::fin() const
{
	return L.fin();
}

#endif
