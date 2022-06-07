#pragma once
#include <stdexcept>
#include <list>
#include <string>

template<typename T>
class Vector
{
private:
	T* elem;
	int sz;
public:
	Vector(int s);
	//Vector(std::list<T> lst);
	~Vector() { delete[] elem; }

	Vector(const Vector& a);			// copy constr uctor
	Vector& operator=(const Vector& a);	// copy assignment

	Vector(Vector&& a);					// && rvalue
	Vector& operator=(const Vector&& a);

	T& operator[](int i);
	const T& operator[](int i) const;

	T* begin()
	{
		return &elem[0];			// pointer to first element
	}
	
	T const* begin() const
	{
		return &elem[0];			// pointer to first element
	}

	T* end()
	{
		return begin() + size();
	}
	
	T const* end() const
	{
		return begin() + size();
	}

	int size() const;
	void push_back(double);

};

//Vector operator + (const Vector& a, const Vector& b);

//		Init
template<typename T>
Vector<T>::Vector(int s)
{
	if (s < 0) throw std::length_error{ "length_error" };
	elem = new T[s];
	sz = s;
}

template<typename T>
Vector<T>::Vector(const Vector& a)	// copy constr uctor
	: elem{ new T[sz] },	// allocate space for elements
	sz{ a.sz }
{
	for (int i = 0; i != sz; ++i)	// copy elements
		elem[i] = a.elem[i];
}

//		Copy and move

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& a)	// copy assignment
{
	T* p = new T[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;					// delete old elements
	elem = p;
	sz = a.sz;
	return *this;
}

template<typename T>
Vector<T>::Vector(Vector&& a)			//private: we dont copy but change pointer
	: elem{ a.elem }, sz{ a.sz }
{
	a.elem = nullptr;
	a.sz = 0;
}

//		Operator []

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector&& a)
{
	T* p = new T[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

template<typename T>
T& Vector<T>::operator[](int i)
{
	if (i < 0 || size() <= i) throw std::out_of_range{ "Vector::operation[]" };
	return elem[i];
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	if (i < 0 || size() <= i) throw std::out_of_range{ "Vector::operation[]" };
	return elem[i];
}


//template<typename Container, typename Value>
//Value sum(const Container& c, Value v) 
//{
//	for (auto x : c)
//		v += x;
//	return v;
//}

template<typename T>
int Vector<T>::size() const { return sz; }

//Vector operator + (const Vector& a, const Vector& b)
//{
//	//if (a.size() != b.size()) throw std::Vector_size_mismatch{};
//	if (a.size() != b.size()) throw std::out_of_range{ "Vector::operation+" };
//
//	Vector res(a.size());
//	for (int i = 0; i != a.size(); ++i)
//		res[i] = a[i] + b[i];
//	return res;
//}