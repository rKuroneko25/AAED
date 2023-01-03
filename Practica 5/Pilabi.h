// TAD PILA MEDIANTE BICOLA

#ifndef pilabi
#define pilabi

#include "bicola.h"

template<typename tElement> class Pilabi
{
public:
	Pilabi() {}
	void push(const tElement& x);
	void pop();
	const tElement& tope() const;
	bool vacia() const;
private:
	Bicola<tElement> B;
};

template<typename tElement>
inline void Pilabi<tElement>::push(const tElement& x)
{ 
	B.push_izq(x);
}

template<typename tElement>
inline void Pilabi<tElement>::pop() 
{ 
	B.pop_izq();
}

template<typename tElement>
inline const tElement& Pilabi<tElement>::tope() const
{ 
	B.frente_izq();
}

template<typename tElement>
inline bool Pilabi<tElement>::vacia() const
{ 
	B.vacia();
}


#endif
