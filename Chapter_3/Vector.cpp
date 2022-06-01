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
double& Vector::operator[](int i) 
{
    if (i < 0 || size() <= i) throw std::out_of_range{ "Vector::operation[]" };
    return elem[i];
}
int Vector::size() const { return sz; }