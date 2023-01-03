#ifndef rational
#define rational

class racional
{
public:
	racional(long nu = 0, long de = 1);
	long num() const {return n;}
	long den() const {return d;}
	// Operadores aritméticos externos
	friend racional operator +(const racional& r, const racional& s);
	friend racional operator *(const racional& r, const racional& s);
	friend racional operator -(const racional& r);
	friend racional inv(const racional& r);
private:
	long n, d;
	static long mcd(long, long);
	static long mcm(long, long);
};

inline bool operator ==(const racional& r, const racional& s)
{
	return (r.num() == s.num()) && (r.den() == s.den());
}

inline bool operator <(const racional& r, const racional& s)
{
	return racional(r + -s).num() < 0;
}

inline void operator +=(racional& r, const racional& s)
{
	r = r + s;
}

inline void operator -=(racional& r, const racional& s)
{
	r = r + -s;
}

inline void operator *=(racional& r, const racional& s)
{
	r = r * s;
}

inline void operator /=(racional& r, const racional& s)
{
	r = r * inv(s);
}

inline bool operator !=(const racional& r, const racional& s)
{
	return !(r==s);
}

inline bool operator > (const racional& r, const racional& s)
{
	return racional(r + -s).num() > 0;
}

inline bool operator <=(const racional& r, const racional& s)
{
	return !(r>s);
}

inline bool operator >=(const racional& r, const racional& s)
{
	return !(r<s);
}

#endif

















