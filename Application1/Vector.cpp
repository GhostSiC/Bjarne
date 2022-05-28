#include "Vector.h"

Vector::Vector(int s)
    //: elem{ new double[s] }, sz{ s } - if stay then memory exhaustion
{
    if (s < 0) throw std::length_error{"length_error"};
    elem = new double[s];
    sz = s;
}
double& Vector::operator[](int i) {
    if (i < 0 || size() <= i) throw std::out_of_range{ "Vector::operation[]" };
    return elem[i]; 
}
int Vector::size() { return sz; }