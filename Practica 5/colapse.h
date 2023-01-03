#ifndef colapse
#define colapse
#include <cassert>

template <typename T> class Coca 
{
public:
	explicit Coca(size_t TamaMax); // Constructor, req. ctor. T()
	Coca(const Coca<T>& C); // Ctor. de copia, requiere ctor. T()
	Coca<T>& operator =(const Coca<T>& C); // Asig., req. ctor. T()
	bool vacia() const;
	bool llena() const; // Requerida por la implementación
	const T& frente() const;
	void pop();
	void push(const T& x);
	~Coca(); // Destructor
private:
	T *elementos; // Vector de elementos
	size_t Lmax; // Tamaño del vector
	size_t inicio, fin; // Posiciones de los extremos de la cola
};

template <typename T>
inline Coca<T>::Coca(size_t TamaMax) :
elementos(new T[TamaMax + 1]), // +1 para detectar cola llena
Lmax(TamaMax + 1),
inicio(0),
fin(TamaMax)
{}

template <typename T>
Coca<T>::Coca(const Coca<T>& C) :
elementos(new T[C.Lmax]),
Lmax(C.Lmax),
inicio(C.inicio),
fin(C.fin)
{
	// Copiar elementos
	for (size_t i = inicio; i != (fin + 1) % Lmax;
	i = (i + 1) % Lmax)
	elementos[i] = C.elementos[i];
}

template <typename T>
Coca<T>& Coca<T>::operator =(const Coca<T>& C)
{
	if (this != &C) // Evitar autoasignación
	{ 
		// Destruir el vector y crear uno nuevo si es necesario
		if (Lmax != C.Lmax) 
		{
			delete[] elementos;
			Lmax = C.Lmax;
			elementos = new T[Lmax];
		}
		inicio = C.inicio;
		fin = C.fin;
		// Copiar elementos
		for (size_t i = inicio; i != (fin + 1) % Lmax;
		i = (i + 1) % Lmax)
		elementos[i] = C.elementos[i];
	}
	return *this;
}

template <typename T>
inline bool Coca<T>::vacia() const
{
	return (inicio == (fin + 1) % Lmax);
}

template <typename T>
inline bool Coca<T>::llena() const
{
	return (inicio == (fin + 2) % Lmax);
}

template <typename T>
inline const T& Coca<T>::frente() const
{
	assert(!vacia());
	return elementos[inicio];
}

template <typename T>
inline void Coca<T>::pop()
{
	assert(!vacia());
	inicio = (inicio + 1) % Lmax;
}

template <typename T>
inline void Coca<T>::push(const T& x)
{
	assert(!llena());
	fin = (fin + 1) % Lmax;
	elementos[fin] = x;
}

template <typename T>
inline Coca<T>::~Coca()
{
	delete[] elementos;
}

#endif // colapse



