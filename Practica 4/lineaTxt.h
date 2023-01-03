#ifndef lineaTxt
#define lineaTxt

#include "pila2.h"

class linea
{
public:
	linea();
	void showline();
	void next();
	void prev();
	void end();
	void home();
	void del();
	void supr();
	void ins(char c);
	void overw(char c);
private:
	Pila<char> P,Q;
};

#endif
