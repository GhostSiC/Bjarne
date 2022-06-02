#include <iostream>
#include "Vector_container.h"
#include "Complex.h"

namespace Section_2_1_1 {

    void f(Complex z) {
        Complex a{ 2.3 };
        Complex b{ 1 / a };
        Complex c{ a + z * Complex{1,2.3} };
        if (c != b)
            c = -(b / a) + 2 * b;

        std::cout << z.real() << " | " << z.imag() << '\n';
    }

    int main() {

        Complex z{ 3.2,4.1 };

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

    /*
    void rotate_all(vector<Shape*>& v, int angel)
    {
        for (auto& p : v)
            p->rotate(angel);
    }*/

    int main() 
    {

        return 0;
    }
}

// Copy and Move    
namespace Section_3
{
    void test(Complex z1)
    {
        Complex z2{ z1 };   // copy initialization
        Complex z3;
        z3 = z2;            // copy assignment
    }

    int main() 
    {
        
        return 0;
    }
}

// Copying Containers   
namespace Section_3_1
{
    void bad_copy(Vector v1)
    {
        Vector v2 = v1; // copy v1’s representation into v2
        v2[0] = 2;      // v2[0] is now also 2!
        v2[1] = 3;      // v2[1] is now also 3!
    }

    int main() 
    {
        return 0;
    }
}

// Moving Containers 
namespace Section_3_2
{
    int main() 
    {
        std::cout << "a\n";

        return 0;
    }
}

int main()
{

    Section_3_2::main();

    return 0;
}

