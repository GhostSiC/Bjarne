
#include <iostream>

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

namespace Section_3 {

    struct Vector
    {
        int sz;
        double* elem;
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

int main()
{
    Section_3::main();

    return 0;
}

