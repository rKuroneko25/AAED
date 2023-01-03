
#ifndef pila2
#define pila2
#include <cassert>

template <typename tElemento> class Pila
{
public:
	Pila();
	Pila(const Pila& P);
	Pila& operator =(const Pila& P);
	bool vacia() const;
	const tElemento tope() const;
	void push(const tElemento& x);
	void pop();
	~Pila();
private:
	struct nodo
	{
		tElemento elto;
		nodo* sig;
		nodo(tElemento el,nodo* punt=NULL) : elto(el), sig(punt) {}
	};
	nodo* tope_;
	void copiar(const Pila& P);
};

// METODO PRIVADO COPIA
template <typename tElemento>
void Pila<tElemento>::copiar(const Pila<tElemento>& P)
{
	if(!P.vacia())
	{
		tope_ = new nodo(P.tope());
		nodo* p = tope_;
		nodo* q = P.tope_->sig;
		while (q)
		{
			p->sig = new nodo(q->elto);
			p = p->sig;
			q = q->sig;
		}
	}
}

// CONSTRUCTOR DEFAULT
template <typename tElemento>
inline Pila<tElemento>::Pila() :
	tope_(NULL)
{}

// CONSTRUCTOR DE COPIA
template <typename tElemento>
inline Pila<tElemento>::Pila(const Pila<tElemento>& P) :
	tope_(NULL)
{
	copiar(P);
}

// OPERADOR DE ASIGNACIÓN
template <typename tElemento>
inline Pila<tElemento>& Pila<tElemento>::operator =(const Pila<tElemento>& P)
{
	if(this!=&P)
	{
		this->~Pila();
		copiar(P);
	}
	return *this;
}

// VACIA
template <typename tElemento>
inline bool Pila<tElemento>::vacia() const
{
	return tope_ == NULL ? true : false;
}

// TOPE
template <typename tElemento>
inline const tElemento Pila<tElemento>::tope() const
{
	assert(!vacia());
	return tope_->elto;
}

// PUSH
template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x)
{
	tope_ = new nodo(x,tope_);
}

// POP
template <typename tElemento>
inline void Pila<tElemento>::pop()
{
	assert(!vacia());
	nodo* p = tope_;
	tope_ = tope_->sig;
	delete p;
}

// DESTRUCTOR
template <typename tElemento>
inline Pila<tElemento>::~Pila()
{
	nodo* p;
	while(tope_)
	{
		p = tope_;
		tope_ = tope_->sig;
		delete p;
	}
}

#endif
