#include <iostream>
#include "Vector_container.h"

namespace Section_2_1_1 {

    class complex {
        double re, im;
    public:
        complex(double r, double i) : re{r}, im{i}{}
        complex(double r) : re{ r }, im{ 0 } {}
        complex() : re{ 0 }, im{ 0 } {}

        double real() const { return re; }
        void real(double d) { re = d; }
        double imag() const { return im; }
        void imag(double d) { im = d; }

        complex& operator += (complex z) { re += z.re, im += z.im; return *this; } // inline definison
        complex& operator -= (complex z) { re -= z.re, im -= z.im; return *this; }

        complex& operator *= (complex z) { re *= z.re, im *= z.im; return *this; }
        complex& operator /= (complex z) { re /= z.re, im /= z.im; return *this; }


    };

    complex operator + (complex a, complex b) { return a += b; } // must be out of class
    complex operator - (complex a, complex b) { return a -= b; } 
    complex operator - (complex a) { return { a.real(), a.imag() }; }
    complex operator * (complex a, complex b) { return a *= b; } 
    complex operator / (complex a, complex b) { return a /= b; }
    bool operator == (complex a, complex b) {
        return a.real() == b.real() && a.imag() == b.imag();
    }
    bool operator != (complex a, complex b) {
        return !(a==b);
    }


    void f(complex z) {
        complex a{ 2.3 };
        complex b{ 1 / a };
        complex c{ a + z * complex{1,2.3} };
        if (c != b)
            c = -(b / a) + 2 * b;

        std::cout << z.real() << " | " << z.imag() << '\n';
    }

    int main() {

        complex z{ 3.2,4.1 };

        f(z);

        return 0;
    }
}

// A Container
namespace Section_2_1_2 {

    void fct(int n)
    {
        Vector v(n);
        // ... use v ...
        {
            Vector v2(n*2);
            // ... use v and v2 ...
        } // v2 is destroyed here
        // ... use v ..
    } // v is destroyed here

    int main() {

        return 0;
    }
}

// Initializing Containers
namespace Section_2_1_3 {

    int main() {

        Vector v1 = { 1.2,4.3,2.3,6.5 };

        return 0;
    }
}

// Abstract Types
namespace Section_2_2 
{

    void use(Container& c) 
    {
        const int sz = c.size();
        for (int i = 0; i != sz; ++i) std::cout << c[i] << '\n';
    }

    void g() 
    {
        // not working, wrong init
        //Vector_container vc{ 10,9,8,7,6,5,4,3,2,1,0 };
        // but
        // Vector vc = { 1,2,3,4,5,6,7,8,9 }; work
        //use(vc);
    }

    void h()
    {
        //Vector_container vc {}
        
        List_container lc = { 1,2,3,4,5,6,7,8,9 };
        use(lc);
    }

    int main() 
    {
        h();
        return 0;
    }
}

// Class Hierarchies
namespace Section_2_2_4
{

    /*void rotate_all(vector<Shape*>& v, int angel)
    {
        for (auto& p : v)
            p->rotate(angel);
    }*/

    int main() 
    {

        return 0;
    }
}

int main()
{

    Section_2_2_4::main();

    return 0;
}

