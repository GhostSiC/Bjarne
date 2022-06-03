#include "Vector.h"

Vector::Vector(int s) : elem{new double[s]}, sz{s}
{
	if (s < 0) throw std::length_error{ "length_error" };
	for (int i = 0; i != s; ++i) elem[i] = 0;
}
Vector::Vector(std::initializer_list<double> lst)
	: elem{ new double[lst.size()] }, sz{ static_cast<int>(lst.size()) }
{
	std::copy(lst.begin(), lst.end(), elem);
}
Vector::Vector(const Vector& a)	// copy constr uctor
	: elem{ new double[sz] },	// allocate space for elements
	sz{ a.sz }
{
	for (int i = 0; i != sz; ++i)	// copy elements
		elem[i] = a.elem[i];
}
Vector& Vector::operator=(const Vector& a)	// copy assignment
{
	double* p = new double[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;					// delete old elements
	elem = p;
	sz = a.sz;
	return *this;
}
double& Vector::operator[](int i) 
{
    if (i < 0 || size() <= i) throw std::out_of_range{ "Vector::operation[]" };
    return elem[i];
}
double& Vector::operator[](int i) const
{
	if (i < 0 || size() <= i) throw std::out_of_range{ "Vector::operation[]" };
	return elem[i];
}
int Vector::size() const { return sz; }

Vector operator + (const Vector& a, const Vector& b)
{
	//if (a.size() != b.size()) throw std::Vector_size_mismatch{};
	if (a.size() != b.size()) throw std::out_of_range{ "Vector::operation+" };

	Vector res(a.size());
	for (int i = 0; i != a.size(); ++i)
		res[i] = a[i] + b[i];
	return res;
}