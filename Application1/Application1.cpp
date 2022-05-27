
#include <iostream>
#include "Vector.h"
#include <cmath>
#include <complex>


// Pointers, Arrays, and Loops
namespace Section_2 {

    int count_x(char* p, char x) {
        if (p == nullptr) return 0;
        int count = 0;
        for (; *p != 0; ++p)
            if (*p == x)
                ++count;
        return count;
    }

    int main() {

        char v[] = { 'a','b','c','d','e' };
        char* p = &v[3];
        char x = *p;

        std::cout << count_x(v, 's') << '\n';

        return 0;
    }
}

// Structures
namespace Section_3_1 {

    struct Vector
    {
        int sz;
        double* elem; // points to an array of sz double
    };

    void vector_init(Vector& v, int s) {
        v.elem = new double[s];
        v.sz = s;
    }

    double read_and_sum() {
        Vector v;
        int s = 4;
        int data[]{2, 3, 5, 10};
        vector_init(v, s);

        for (int i = 0; i != s; i++)
            v.elem[i] = data[i];
        
        double sum = 0;
        for (int i = 0; i != s; i++)
            sum += v.elem[i];
 
        return sum;
    }

    int main() {

        std::cout << read_and_sum() << '\n';

        return 0;
    }
}

// Classes
namespace Section_3_2 {

    class Vector {
    public:
        Vector(int s) : elem{ new double[s] }, sz{ s }{};
        double& operator[](int i) { return elem[i]; };
        int size() { return sz; };
    private:
        double* elem;
        int sz;
    };

    double read_and_sum() {
        int s = 4;
        Vector v(s);
        double data[]{2,3,5,10};
        for (int i = 0; i != s; ++i) {
            v[i] = data[i];
        }

        double sum = 0;
        for (int i = 0; i != s; ++i)
            sum += v[i];

        return sum;
    }

    int main() {

        std::cout << read_and_sum();

        return 0;
    }
}

// Enumerations
namespace Section_3_3 {

    enum class Color {red, blue, green};
    enum class Traffic_light {green, yellow, red};

    //prefix increment: ++
    Traffic_light& operator++(Traffic_light& t) {
        switch (t)
        {
        case Traffic_light::green: return t = Traffic_light::yellow;
        case Traffic_light::yellow: return t = Traffic_light::red;
        case Traffic_light::red: return t = Traffic_light::green;
        }
    }
    //print CLASS enum value
    std::ostream& operator << (std::ostream& os, const Traffic_light& t) {
        os << static_cast<std::underlying_type<Traffic_light>::type>(t);
        return os;
    }

    int main() {

        Color col = Color::red;
        Traffic_light light = Traffic_light::red;

        std::cout << light << '\n';
        std::cout << ++light << '\n';

        return 0;
    }
}

// Modularity - Modu³owoœæ
namespace Section_4_0 {

    double sqrt(double);

    class Vector {
    public:
        Vector(int s);
        double& operator[](int i);
        int size();
    private:
        double* elem;
        int sz;
    };

    double read_and_sum() {
        int s = 4;
        Vector v(s);
        double data[]{ 2,3,5,10 };
        for (int i = 0; i != s; ++i) {
            v[i] = data[i];
        }

        double sum = 0;
        for (int i = 0; i != s; ++i)
            sum += v[i];

        return sum;
    }

    Vector::Vector(int s)
        : elem{ new double[s] }, sz{ s }
    {
    }
    double& Vector::operator[](int i) { return elem[i]; }
    int Vector::size() { return sz; }


    int main() {

        std::cout << read_and_sum();

        return 0;
    }
}

// Separate Compilation
namespace Section_4_1 {

    double sqrt_sum(Vector& v) {

        double sum = 0;
        for (int i = 0; i <= v.size(); ++i)
            sum += std::sqrt(v[i]);
        return sum;
    }

    int main() {

        Vector v(4);
        double data[]{ 2,3,5,10 };
        for (int i = 0; i != 4; ++i) {
            v[i] = data[i];
        }

        std::cout << sqrt_sum(v);

        return 0;
    }
}

// Namespaces
namespace Section_4_2 {

    namespace My_code {
        class complex {};
        complex sqrt(complex);

        int main();
    }

    int My_code::main() {

        std::complex<double> z{ 1, 2};
        auto z2 = sqrt(z);
        std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";

        return 0;
    }
}

int main()
{
    Section_4_2::My_code::main();

    return 0;
}

