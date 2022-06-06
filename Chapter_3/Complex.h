#pragma once
#include <iostream>

class Complex {
    double re, im;
public:
    Complex(double r, double i) : re{ r }, im{ i }{}
    Complex(double r) : re{ r }, im{ 0 } {}
    Complex() : re{ 0 }, im{ 0 } {}

    double real() const { return re; }
    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }

    Complex& operator += (Complex z) { re += z.re, im += z.im; return *this; } // inline definison
    Complex& operator -= (Complex z) { re -= z.re, im -= z.im; return *this; }

    Complex& operator *= (Complex z) { re *= z.re, im *= z.im; return *this; }
    Complex& operator /= (Complex z) { re /= z.re, im /= z.im; return *this; }
};

Complex operator + (Complex a, Complex b); // must be out of class
Complex operator - (Complex a, Complex b);
Complex operator - (Complex a);
Complex operator * (Complex a, Complex b);
Complex operator / (Complex a, Complex b);
bool operator == (Complex a, Complex b);
bool operator != (Complex a, Complex b);


class aby {
private:
    int x, y;
public:
    aby(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void prt() { std::cout << "x: " << x << " | y:" << y; };

    friend std::ostream& operator << (std::ostream& os, const aby& z);
};