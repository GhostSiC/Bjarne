#include <iostream>
#include <vector>
//  #include "Vector_container_3.h"
//  #include "Complex_3.h"

#include "Vector_4.h"
#include <complex>


/*
* 
* Use here Vector_container_3 and Complex_3
* 
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

    //void rotate_all(vector<Shape*>& v, int angel)
    //{
    //    for (auto& p : v)
    //        p->rotate(angel);
    //}

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

// test unique_ptr and operator << 
namespace self_test_1
{
    int main()
    {
        std::unique_ptr<aby> yy(new aby(1, 2));
        std::cout << *yy << '\n';
        return 0;
    }
}

// test Inheritance
namespace self_test_2
{

    class A{
    public:
        A() { std::cout << "A"; }
        ~A() { std::cout << "~A"; }
    };

    class B : A{
    public:
        B() { std::cout << "B"; }
        ~B() { std::cout << "~B"; }
    };


    int main()
    {
        std::unique_ptr<B> b(new B());

        return 0;
    }
}

// Moving Containers
namespace Section_3_2
{
    Vector f() {
        Vector x(1000);
        Vector y(1000);
        Vector z(1000);

        z = x;
        y = std::move(x);

        return z;
    }

    int main()
    {
        f();

        return 0;
    }
}

// Suppressing Operations
namespace Section_3_4
{
    Vector f() {
        Vector x(1000);
        Vector y(1000);
        Vector z(1000);

        z = x;
        y = std::move(x);

        return z;
    }

    int main()
    {
        f();

        return 0;
    }
}

*/

// Templates

namespace Section_4_1
{
    void write(const Vector<std::string>& vs) {
        for (int i = 0; i != vs.size(); ++i)
            std::cout << vs[i] << '\n';
    }

    template<typename T>
    void f2(const Vector<T>& vs) {
        for (auto& s : vs)
            std::cout << s << '\n';
    }

    template<typename T>
    void f3(Vector<T>& vs) {
        for (int i = 0; i != vs.size(); ++i)
            vs[i] = "a";
    }

    int main()
    {
        Vector<char> vc(200);
        Vector<std::string> vs(200);
        Vector<std::list<int>> vli(200);

        //write(vs);
        f3(vs);
        f2(vs);

        return 0;
    }
}

namespace Section_4_2
{
    template<typename T>
    class Less_than {
        const T val;
    public:
        Less_than(const T& v) : val(v) {}
        bool operator()(const T& x) const { return x < val; }
    };

    template<typename C, typename P>
    int count(const C& c, P pred)
    {
        int cnt = 0;
        for (const auto& x : c)
            if (pred(x))
                ++cnt;
        return cnt;
    }

    void f(
        const Vector<int>& vec,
        const std::list<std::string>& lst,
        int x,
        const std::string& s
    )
    {
        std::cout << count(vec, Less_than<int>{x});
    }

    int main() {

        Less_than<int> lti{ 42 };
        Less_than<std::string> lts{"Backus"};

        bool b1 = lti(23);
        bool b2 = lts("ABackus");

        //std::cout << b1 << '\n';
        //std::cout << b2 << '\n';

        //f(lti, lts, 10, "ABackus");
        //std::cout << count(lti, Less_than<int>{12});

        return 0;
    }
}

namespace self_test_3 {

    int main() {

        int n = 12;
        char* buffer;

        buffer = (char*)malloc(n + 1);

        if (buffer == NULL) return 0;

        for (int i = 0; i < n; i++)
            buffer[i] = rand() % 26 + 'a';
        
        buffer[n] = '\0';

        free(buffer);

        return 0;
    }
}

int main()
{

    self_test_3::main();

    return 0;
}

