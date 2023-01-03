// BICOLA DINAMICA

#ifndef bicola
#define bicola

#include <cassert>

template<typename tElement> class Bicola
{
public:
	Bicola(); // Constructor
	Bicola(const Bicola<tElement>& B); // Constructor de copia
	Bicola<tElement>& operator =(const Bicola<tElement>& B); // Operador de asignacion
	void push_der(tElement x);
	void pop_der();
	const tElement& frente_izq() const;
	bool vacia() const;
	void push_izq(tElement x); 
	void pop_izq(); 
	const tElement& frente_der() const;
	~Bicola(); // Destructor
private:
	struct nodo
	{
		tElement elto;
		nodo *sig, *ant;
		nodo(const tElement& x, nodo* next=NULL, nodo* prev=NULL) : elto(x), sig(next), ant(prev) {}
	};
	nodo *inicio, *fin; 
};

// CONSTRUCTOR
template<typename tElement>
inline Bicola<tElement>::Bicola() : inicio(NULL), fin(NULL) {}

// CONSTRUCTOR DE COPIA
template<typename tElement>
inline Bicola<tElement>::Bicola(const Bicola<tElement>& B) :
inicio(NULL), fin(NULL)
{
	if(!B.vacia())
	{
		nodo *p,*q;
		inicio = fin = new nodo(B.inicio->elto);
		p = B.inicio->sig;
		while(p!=NULL)
		{
			fin->sig = new nodo(p->elto,NULL,fin);
			p = p->sig;
			fin = fin->sig;
		}
	}
}

// OPERADOR DE ASIGNACION
template<typename tElement>
inline Bicola<tElement>& Bicola<tElement>::operator =(const Bicola<tElement>& B)
{
	if(this != &B)
	{
		this->~Bicola();
		
		nodo *p,*q;
		inicio = fin = new nodo(B.inicio->elto);
		p = B.inicio->sig;
		while(p!=NULL)
		{
			fin->sig = new nodo(p->elto,NULL,fin);
			p = p->sig;
			fin = fin->sig;
		}
	}
	return *this;
}

// VACIA
template<typename tElement>
inline bool Bicola<tElement>::vacia() const
{
	return inicio == NULL ? true : false;
}

// INSERTAR POR LA DERECHA
template<typename tElement>
inline void Bicola<tElement>::push_der(tElement x)
{
	if(inicio==NULL)
	{
		inicio = fin = new nodo(x);
	}
	else
	{
		fin->sig = new nodo(x,NULL,fin);
		fin = fin->sig;
	}
}

// ELIMINAR POR LA IZQUIERDA
template<typename tElement>
inline void Bicola<tElement>::pop_izq()
{
	assert(!vacia());
	nodo *q;
	q = inicio;
	inicio = inicio->sig;
	delete q;
	if(inicio==NULL)
	{
		fin == NULL;
	}
	else
	{
		inicio->ant = NULL;
	}
}

// FRENTE IZQUIERDO
template<typename tElement>
inline const tElement& Bicola<tElement>::frente_izq() const
{
	return inicio->elto;
}

// INSERTAR POR LA IZQUIERDA
template<typename tElement>
inline void Bicola<tElement>::push_izq(tElement x)
{
	if(vacia())
	{
		fin = inicio = new nodo(x);
	}
	else
	{
		inicio->ant = new nodo(x,inicio,NULL);
		inicio=inicio->ant;		
	}
}

// ELIMINAR POR LA DERECHA
template<typename tElement>
inline void Bicola<tElement>::pop_der()
{
	assert(!vacia());
	nodo* q;
	q = fin;
	fin = fin->ant;
	delete q;
	if(fin=NULL)
	{
		inicio = NULL;
	}
	else
	{
		fin->sig = NULL;
	}
}

// FRENTE DERECHO
template<typename tElement>
inline const tElement& Bicola<tElement>::frente_der() const
{
	return fin->elto;
}

// DESTRUCTOR
template<typename tElement>
inline Bicola<tElement>::~Bicola()
{
	nodo *q;
	while (inicio!=NULL)
	{
		q = inicio;
		inicio = inicio->sig;
		delete q;
	}
	fin = NULL;
}

#endif 
