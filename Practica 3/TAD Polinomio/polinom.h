
#ifndef polinom
#define polinom

class polinomio{
public:
	explicit polinomio(unsigned Max);				//constructor
	polinomio(const polinomio& poli);				//constructor de copia
	polinomio& operator =(const polinomio& poli);	//operador de asignación
	unsigned grado() const;							//devuelve el grado
	double coeficiente(unsigned n) const;			//devuelve el coeficiente
	void coeficiente(unsigned n, double c);			//cambia el coeficiente del grado n
	~polinomio();									//destructor
private:
	double* pol;
	unsigned gradoMax;
};

#endif
