#include "Complex.h"

Complex operator + (Complex a, Complex b) { return a += b; } // must be out of class
Complex operator - (Complex a, Complex b) { return a -= b; }
Complex operator - (Complex a) { return { a.real(), a.imag() }; }
Complex operator * (Complex a, Complex b) { return a *= b; }
Complex operator / (Complex a, Complex b) { return a /= b; }
bool operator == (Complex a, Complex b) {
    return a.real() == b.real() && a.imag() == b.imag();
}
bool operator != (Complex a, Complex b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const aby& z)
{
    os << "x: " << z.x << " y: " << z.y;
    return os;
}